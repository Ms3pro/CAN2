
#if DISP1_ACTIVE == 1

void driveDisplay() {
    readEGTValues();

    // Определяем цвет рамки на основе значений EGT
    unsigned int frameColor = determineFrameColor();

    // Отображаем рамку нужного цвета
    for (int i = 0; i < 3; i++) {
        tft.drawRect(i, i, tft.width() - i*2, tft.height() - i*2, frameColor);
    }

    // Отображаем значения EGT
  DrawBarChartV(tft, 103,  76, 15, 50, 0, 1023 , 200, egt6 , 4 , 0, RED ,  GREEN, BLACK, WHITE, BLACK, "EGT6", graph_1);
  DrawBarChartV(tft, 83,  76, 15, 50, 0, 1023 , 200, egt5 , 4 , 0, RED ,  GREEN, BLACK, WHITE, BLACK, "EGT5", graph_1);
  DrawBarChartV(tft, 63,  76, 15, 50, 0, 1023 , 200, egt4 , 4 , 0, RED ,  GREEN, BLACK, WHITE, BLACK, "EGT4", graph_1);
  DrawBarChartV(tft, 43,  76, 15, 50, 0, 1023 , 200, egt3 , 4 , 0, RED ,  GREEN, BLACK, WHITE, BLACK, "EGT3", graph_1);
  DrawBarChartV(tft, 23,  76, 15, 50, 0, 1023 , 200, egt2 , 4 , 0, RED ,  GREEN, BLACK, WHITE, BLACK, "EGT2", graph_1);
  DrawBarChartV(tft, 3,  76, 15, 50, 0, 1023 , 200, egt1 , 4 , 0, RED ,  GREEN, BLACK, WHITE, BLACK, "EGT1", graph_1);
}

unsigned int determineFrameColor() {
    if (egt1 > 800 || egt2 > 800 || egt3 > 800 || egt4 > 800 || egt5 > 800 || egt6 > 800) {
        return ST7735_RED;
    } else if ((egt1 >= 300 && egt1 < 800) || 
               (egt2 >= 300 && egt2 < 800) || 
               (egt3 >= 300 && egt3 < 800) || 
               (egt4 >= 300 && egt4 < 800) || 
               (egt5 >= 300 && egt5 < 800) || 
               (egt6 >= 300 && egt6 < 800)) {
        return ST7735_YELLOW;
    } else {
        return ST7735_BLUE;
    }
}

void readEGTValues() {
  egt1 = analogRead(A0);
  egt2 = analogRead(A1);
  egt3 = analogRead(A2);
  egt4 = analogRead(A3);
  egt5 = analogRead(A4);
  egt6 = analogRead(A5);
}
void DrawBarChartV(Adafruit_ST7735 & d, double x , double y , double w, double h , double loval , double hival , double inc , double curval ,  int dig , int dec, unsigned int barcolor, unsigned int voidcolor, unsigned int bordercolor, unsigned int textcolor, unsigned int backcolor, String label, boolean & redraw)
{

  double stepval, range;
  double my, level;
  double i, data;
  // draw the border, scale, and label once
  // avoid doing this on every update to minimize flicker
  if (redraw == true) {
    redraw = false;

    d.drawRect(x - 1, y - h - 1, w + 2, h + 2, bordercolor);
    d.setTextColor(textcolor, backcolor);
    d.setTextSize(1);
    d.setCursor(x , y + 10);
    //d.println(label);
    // step val basically scales the hival and low val to the height
    // deducting a small value to eliminate round off errors
    // this val may need to be adjusted
    stepval = ( inc) * (double (h) / (double (hival - loval))) - .001;
    for (i = 0; i <= h; i += stepval) {
      my =  y - h + i;
      d.drawFastHLine(x + w + 1, my,  5, textcolor);
      // draw lables
      d.setTextSize(1);
      d.setTextColor(textcolor, backcolor);
      d.setCursor(x + w + 12, my - 3 );
      data = hival - ( i * (inc / stepval));
      d.println(Format(data, dig, dec));
    }
  }
  // compute level of bar graph that is scaled to the  height and the hi and low vals
  // this is needed to accompdate for +/- range
  level = (h * (((curval - loval) / (hival - loval))));
  // draw the bar graph
  // write a upper and lower bar to minimize flicker cause by blanking out bar and redraw on update
  d.fillRect(x, y - h, w, h - level,  voidcolor);
  d.fillRect(x, y - level, w,  level, barcolor);
  // write the current value
  d.setTextColor(textcolor, backcolor);
  d.setTextSize(1.6);
  d.setCursor(x , y - h - 23);
  //d.println(Format(curval, dig, dec)); ///////////////////////////////////////////////////ВКЛЮЧИТЬ ЕСЛИ НУЖНО ОТОБРАЖЕНИЕ ЦИВРАМИ!!!!!!
  d.println("EGT");///////////////////////////////////////////////////
}




String Format(double val, int dec, int dig ) {
  int addpad = 0;
  char sbuf[20];
  String condata = (dtostrf(val, dec, dig, sbuf));


  int slen = condata.length();
  for ( addpad = 1; addpad <= dec + dig - slen; addpad++) {
    condata = " " + condata;
  }
  return (condata);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif

  //#if DISP2_ACTIVE == 1
  //u8g2_2.setFont(u8g2_font_ncenB14_tr);
  // u8g2_2.firstPage();
  //do {
  /* start your user display code for display2 here */
  //u8g2_2.setFont(u8g2_font_logisoso58_tr);
  // u8g2_2.drawStr(0,63,"1");
  //  } while ( u8g2_2.nextPage() );
  //#endif
}

void initialise_display()
{
#if DISP1_ACTIVE == 1

  tft.initR(INITR_MINI160x80_PLUGIN);
  tft.invertDisplay(true);
  tft.setRotation(3);
  tft.fillScreen(WHITE);
  tft.drawRGBBitmap (0, 0, epd_bitmap_BMW_1, 160, 80);
  tft.drawRGBBitmap (0, 0, epd_bitmap_BMW_2, 160, 80);
  //tft.drawRGBBitmap (0,15, epd_bitmap_BMW_3, 160, 80);
  //tft.drawRGBBitmap (0,0, epd_bitmap_BMW_4, 160, 80);
  tft.invertDisplay(true);
  tft.fillScreen(BLACK);
  // Draw yellow border frame
  //int borderWidth = 1; // Задаем толщину рамки
  //tft.drawRect(0, 0, tft.width(), tft.height(), ST7735_YELLOW); // Внешняя рамка
  tft.setTextColor(ORANGE);
  tft.setTextSize(2);
  tft.setCursor(125, 5);
  tft.println("C+");
  tft.fillRect(0, 16, 120, 2, BLUE);  // color bar 05 ПОЛОСА РАЗДЕЛИТЕЛЬНАЯ
  tft.invertDisplay(false);
#endif

  //#if DISP2_ACTIVE == 1
  //u8g2_2.begin();
  //#endif
}

void tcaselect(uint8_t i, uint8_t dispnum) {
}
