![IMG_20230831_004114_1](https://github.com/Ms3pro/CAN2/assets/133560006/51f11215-58cc-4a6e-8920-ac02111bddf5)
![IMG_20230830_205134](https://github.com/Ms3pro/CAN2/assets/133560006/bdf51859-0a73-49bc-b1eb-bf6bc82612b4)
![IMG_20230827_192158](https://github.com/Ms3pro/CAN2/assets/133560006/bcbfeb4f-cfbf-4dee-b15f-3496ad7325c1)
![IMG_20230827_192208](https://github.com/Ms3pro/CAN2/assets/133560006/6ca40ba6-2a82-4fdb-80f9-b733edd510f9)
Документация к коду:

Этот код предназначен для платы Arduino Mega 2560 и предоставляет функции для множества компонентов, включая считывание данных с различных пинов, взаимодействие с CAN-шинами  (CAN не работает!)  и работу с датчиком SHT31.

Библиотеки:

EEPROM.h: для работы с EEPROM памятью на плате Arduino.
Adafruit_GFX.h и Adafruit_ST7735.h: для работы с дисплеем ST7735.
mcp_can.h: для работы с CAN-шинами.
TaskScheduler.h: для планирования и выполнения различных задач.
RealDash.h, SHT31Helper.h, canbus.h и display.h: пользовательские библиотеки (необходимо подключить их исходники).
Определения:

TFT_LED: пин для управления подсветкой дисплея.
EGT1_LED - EGT6_LED: пины для индикации (предположительно, относятся к термопарам).
TOTAL_DIGITAL_PINS и TOTAL_ANALOG_PINS: общее количество цифровых и аналоговых пинов для чтения.
Переменные:

CAN0 и CAN1: объекты для работы с CAN-шинами.
ts: планировщик задач для регулярного запуска функций.
Переменные для хранения состояния пинов, данных с датчиков и др.
Функции и их назначение:

initialiseRealDash(): инициализация параметров для RealDash.
updateRealDashData(): обновление или отправка данных в RealDash.
checkDigitalPinsChanged() и checkAnalogPinsChanged(): проверяют, изменилось ли состояние цифровых или аналоговых пинов соответственно.
updateDigitalBufferAndSave() и updateAnalogBufferAndSave(): сохраняют текущее состояние пинов и записывают их в EEPROM.
saveStateToEEPROM() и saveAnalogStatesToEEPROM(): сохранение состояний пинов в EEPROM.
RealDashUpdateTask(): обновление данных для RealDash.
setup(): инициализация начального состояния, пинов, CAN, датчиков и др.
loop(): основной цикл выполнения, в котором планировщик задач ts выполняет запланированные задачи.
driveDisplayTask(): обновление дисплея.
ReadDigitalStatuses() и ReadAnalogStatuses(): чтение состояний цифровых и аналоговых пинов.
CAN0Task() и CAN1Task(): обработка данных с CAN-шин CAN0 и CAN1.
SHT31Task(): чтение и обработка данных с датчика SHT31.
Задачи:

t1 - t7: это экземпляры задач, которые регулярно выполняются в основном цикле. Задачи включают в себя обновление дисплея, чтение данных с пинов, обработку данных CAN и SHT31, обновление данных для RealDash.
Документация к коду (часть дисплея и EGT):

Функции отображения:

driveDisplay(): Эта функция используется для обновления дисплея на основе последних считанных значений от EGT (Exhaust Gas Temperature, температура отработавших газов). Она определяет цвет рамки, основываясь на значениях EGT, отображает рамку и отображает полосы EGT.

updateEgtLeds(): Эта функция обновляет светодиодные индикаторы на основе значений EGT. Если значение EGT превышает 800, соответствующий светодиод зажигается.

determineFrameColor(): Определяет цвет рамки на основе значений EGT. Рамка будет красной, если любое из значений EGT превышает 800, желтой, если значение находится между 300 и 800, и синей в противном случае.

readEGTValues(): Чтение значений EGT с аналоговых входов и их масштабирование.

DrawBarChartV(): Эта функция используется для отображения вертикального столбчатого графика на дисплее. Она принимает множество параметров, таких как позиция, размеры, значения, цвета и др., для настройки отображения графика.

Format(): Эта функция используется для форматирования числовых значений для отображения на дисплее.

initialise_display(): Эта функция инициализирует дисплей, устанавливая начальные параметры и выводя начальные данные на дисплей.

tcaselect(): Пустая функция. Вероятно, предназначена для выбора определенного дисплея или канала при использовании множественных дисплеев или мультиплексирования.

Значения и переменные:

barBlinking[]: Массив, используемый для определения, должны ли мигать полосы EGT на дисплее.

lastBlinkTime[]: Массив, хранящий последнее время мигания для каждой полосы EGT.

egtValues[]: Массив значений EGT, считанных с аналоговых входов.

rawEgt1 - rawEgt6: Переменные для хранения сырых аналоговых значений EGT.

egt1 - egt6: Переменные для хранения масштабированных значений EGT.

Условные директивы:

#if DISP1_ACTIVE == 1: Это условие проверяет, активен ли первый дисплей. Если это так, код внутри этого блока будет включен в компиляцию.

#if DISP2_ACTIVE == 1: Похоже на предыдущее условие, но для второго дисплея. Тем не менее, код внутри этого блока закомментирован.

Этот код предоставляет функции для чтения и отображения данных с датчиков температуры отработавших газов (EGT) на дисплее, а также управления светодиодами на основе этих данных.

![IMG_20230830_205129](https://github.com/Ms3pro/CAN2/assets/133560006/810cc9db-df73-40b5-afbe-ef9d334ac109)
![IMG_20230830_205127](https://github.com/Ms3pro/CAN2/assets/133560006/d7d8d79e-3ffc-4c60-9a35-a89526c2d889)
![IMG_20230830_205124](https://github.com/Ms3pro/CAN2/assets/133560006/b210969e-0e7d-40a9-ba30-7bb43334976f)
![IMG_20230830_205123](https://github.com/Ms3pro/CAN2/assets/133560006/ffae4b4a-7c8b-4f5b-bd7d-a4b9dbfdec65)
![IMG_20230830_205101](https://github.com/Ms3pro/CAN2/assets/133560006/2ca85683-e66f-4966-8eba-64967d23d024)
![IMG_20230831_004117](https://github.com/Ms3pro/CAN2/assets/133560006/74515340-0c72-487b-9aa4-d26c99a698fe)
