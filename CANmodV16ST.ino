//≪*************************************************************************************************************************************************************************************≫//
//≪***************************************************************[<<< MEGASQUIRT REAL BROADCAST CAN REALDASH >>>]**********************************************************************≫//
//≪*************************************************************************************************************************************************************************************≫//
#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <mcp_can.h>
#include <TaskScheduler.h>
#include "display.h"
#include "canbus.h"
#include "SHT31Helper.h"

#if !defined(__AVR_ATmega2560__)
#error "This code is intended for an Arduino Mega 2560 only!"
#endif

#if DISP1_ACTIVE && defined DISP1_USE_ST7735_SPI
extern Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
#endif

MCP_CAN CAN0(CAN0_CS);
MCP_CAN CAN1(CAN1_CS);

Scheduler ts;

float prevTemp = 0.0;
float prevHum = 0.0;
unsigned long lastUpdateTime = 0;

const int TOTAL_DIGITAL_PINS = 49;
const int TOTAL_ANALOG_PINS = 16;

int digitalPins[TOTAL_DIGITAL_PINS] = {0};
int analogPins[TOTAL_ANALOG_PINS] = {0};

int digitalPinsBuffer[TOTAL_DIGITAL_PINS] = {0};
int analogPinsBuffer[TOTAL_ANALOG_PINS] = {0};

bool checkDigitalPinsChanged() {
  for (int i = 22; i <= TOTAL_DIGITAL_PINS; i++) {
    if (digitalPinsBuffer[i] != digitalPins[i]) {
      return true;
    }
  }
  return false;
}

bool checkAnalogPinsChanged() {
  for (int i = 0; i < TOTAL_ANALOG_PINS; i++) {
    if (analogPinsBuffer[i] != analogPins[i]) {
      return true;
    }
  }
  return false;
}

void updateDigitalBufferAndSave() {
  for (int i = 22; i <= TOTAL_DIGITAL_PINS; i++) {
    digitalPinsBuffer[i] = digitalPins[i];
  }
  saveStateToEEPROM();
}

void updateAnalogBufferAndSave() {
  for (int i = 0; i < TOTAL_ANALOG_PINS; i++) {
    analogPinsBuffer[i] = analogPins[i];
  }
  saveAnalogStatesToEEPROM();
}

void saveStateToEEPROM() {
  for (int i = 22; i <= TOTAL_DIGITAL_PINS; i++) {
    EEPROM.write(i - 22, digitalPins[i]);
  }
}

void saveAnalogStatesToEEPROM() {
  for (int i = 0; i < TOTAL_ANALOG_PINS; i++) {
    int value = analogPins[i];
   // EEPROM.write(28 + i * 2, value & 0xFF);
   // EEPROM.write(28 + i * 2 + 1, (value >> 8) & 0xFF);
  }
}

void setup() {
  initialise_display();

  if (CAN0_ACTIVE) {
    initialiseCAN0();
  }
  if (CAN1_ACTIVE) {
    initialiseCAN1();
  }
  if (!initSHT31()) {
    // Обработка ошибки инициализации SHT31
  }

  const int SERIAL_SPEED = 115200;
  Serial.begin(SERIAL_SPEED);
  Serial1.begin(SERIAL_SPEED);
  Serial2.begin(SERIAL_SPEED);
  Serial3.begin(SERIAL_SPEED);

  pinMode(CAN0_INT, INPUT);
  pinMode(CAN1_INT, INPUT);

  for (int i = A0; i < A0 + TOTAL_ANALOG_PINS; i++) {
    pinMode(i, INPUT);
  }
  for (int i = 22; i <= TOTAL_DIGITAL_PINS; i++) {
    pinMode(i, INPUT);
  }
}

void loop() {
  ts.execute();
}

void ReadDigitalStatuses() {
  for (int i = 22; i <= TOTAL_DIGITAL_PINS; i++) {
    digitalPins[i] = digitalRead(i);
  }
  if (checkDigitalPinsChanged()) {
    updateDigitalBufferAndSave();
  }
}

void ReadAnalogStatuses() {
  for (int i = 0; i < TOTAL_ANALOG_PINS; i++) {
    analogPins[i] = analogRead(i);
  }
  if (checkAnalogPinsChanged()) {
    updateAnalogBufferAndSave();
  }
}

void driveDisplayTask() {
  driveDisplay();
}

void CAN0Task() {
  if (CAN0_ACTIVE && !digitalRead(CAN0_INT)) {
    CAN0_INT_routine();
  }
}

void CAN1Task() {
  if (CAN1_ACTIVE && !digitalRead(CAN1_INT)) {
    CAN1_INT_routine();
  }
}

void SHT31Task() {
  float temp = readTemperature();
  float hum = readHumidity();

  if (abs(temp - prevTemp) >= 0.1) {
    prevTemp = temp;
    //displayTemperature(temp);
  }

  if (abs(hum - prevHum) >= 0.1) {
    prevHum = hum;
    //displayHumidity(hum);
  }
}

Task t1(500, TASK_FOREVER, &driveDisplayTask, &ts, true);
Task t2(50, TASK_FOREVER, &CAN0Task, &ts, true);
Task t3(50, TASK_FOREVER, &CAN1Task, &ts, true);
Task t4(500, TASK_FOREVER, &ReadDigitalStatuses, &ts, true);
Task t5(500, TASK_FOREVER, &ReadAnalogStatuses, &ts, true);
Task t6(500, TASK_FOREVER, &SHT31Task, &ts, true);


//≪*************************************************************************************************************************************************************************************≫//
//≪*************************************************************************************************************************************************************************************≫//
//≪*************************************************************************************************************************************************************************************≫//
//≪*************************************************************************************************************************************************************************************≫//
