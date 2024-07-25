void loop() {
  timeClient.update();
 int minutes = timeClient.getMinutes(); // ให้ตัวแปร minutes เก็บค่านาที (ตัวเลขจำนวนเต็ม)
  char MfirstDigit = (char)(minutes / 10) + '0'; // หาตัวอักษรของหลักร้อย
  char MsecondDigit = (char)(minutes % 10) + '0'; // หาตัวอักษรของหลักหน่วย
  int Hour = timeClient.getHours(); // ให้ตัวแปร minutes เก็บค่านาที (ตัวเลขจำนวนเต็ม)
  char HfirstDigit = (char)(Hour / 10) + '0'; // หาตัวอักษรของหลักร้อย
  char HsecondDigit = (char)(Hour % 10) + '0'; // หาตัวอักษรของหลักหน่วยtimeClient.getSeconds
   int Seconds = timeClient.getSeconds(); // ให้ตัวแปร minutes เก็บค่านาที (ตัวเลขจำนวนเต็ม)
  char SfirstDigit = (char)(Seconds / 10) + '0'; // หาตัวอักษรของหลักร้อย
  char SsecondDigit = (char)(Seconds % 10) + '0'; // หาตัวอักษรของหลักหน่วยtimeClient.getSeconds
 int packetSize = LoRa.parsePacket();
  if (packetSize) {
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
        client.setCACert(root_ca);
     if (!client.connect(server, 443))
    Serial.println("Connection failed!");
  else {
    Serial.println("Connected to server!");
    Lcd.Cursor(10, 0);
    Lcd.Display("DTS");
    String httpRequest = "GET https://XXXXXXXX.tech/TEST/h.php?" + LoRaData + " HTTP/1.0";
    client.println(httpRequest);
    Serial.println(httpRequest);
    client.println("Host: airflowxbill.tech");
    client.println("Connection: close");
    client.println();
    client.stop();
  }
      // Input data in the form of a string
      String data = (LoRaData);
      // Split the input data using '&'
      int numPairs = 0;
      for (size_t i = 0; i < data.length(); i++) {
        if (data.charAt(i) == '&') {
          numPairs++;
        }
      }
      numPairs++; // To account for the last pair

      // Create an array to store the pairs
      String pairs[numPairs];
      int lastIndex = -1;
      for (int i = 0; i < numPairs; i++) {
        int nextIndex = data.indexOf('&', lastIndex + 1);
        if (nextIndex == -1) {
          nextIndex = data.length();
        }
        pairs[i] = data.substring(lastIndex + 1, nextIndex);
        lastIndex = nextIndex;
      }  
      // Extract and store specific name-value pairs as integers or floats
      int p, p1, p5, p10;
      double T, AA, P, La, Lo, AF, Sk; // Declare integer and float variables to store the values
      for (int i = 0; i < numPairs; i++) {
        int separatorIndex = pairs[i].indexOf('=');
        if (separatorIndex != -1) {
          String name = pairs[i].substring(0, separatorIndex);
          String valueString = pairs[i].substring(separatorIndex + 1);
          if (valueString.indexOf('.') != 1) {
            float value = valueString.toDouble(); 
            if (name == "p") {
              p = value;
              char phundredDigit = (char)((p / 100) % 10) + '0';
              char ptensDigit = (char)((p / 10) % 10) + '0';
              char punitsDigit = (char)(p % 10) + '0';
              Lcd.Cursor(0, 0);
              Lcd.Display("P = ");
              Lcd.Pintchartype(phundredDigit);
              Lcd.Cursor(1, 0);
              Lcd.Pintchartype(ptensDigit);
              Lcd.Cursor(2, 0);
              Lcd.Pintchartype(punitsDigit);
            } else if (name == "p1") {
              p1 = value;
              char p1ThousandsDigit = (char)((p1 / 1000) % 10) + '0'; 
              char p1hundredDigit = (char)((p1 / 100) % 10) + '0';
              char p1tensDigit = (char)(p1 / 10) + '0'; // หาตัวอักษรของหลักร้อย
              char p1unitsDigit = (char)(p1 % 10) + '0';
              Lcd.Cursor(0, 2);
              Lcd.Display("PM1 =   ");
              Lcd.Cursor(9, 2);
              Lcd.Pintchartype(p1ThousandsDigit);
              Lcd.Cursor(10, 2);
              Lcd.Pintchartype(p1hundredDigit);
              Lcd.Cursor(11, 2);
              Lcd.Pintchartype(p1tensDigit);
              Lcd.Cursor(12, 2);
              Lcd.Pintchartype(p1unitsDigit);
              Lcd.Cursor(13, 2);
              Lcd.Display("ug/m3");
            } else if (name == "p5") {
              p5 = value;
              char p5ThousandsDigit = (char)((p5 / 1000) % 10) + '0'; 
              char p5hundredDigit = (char)((p5 / 100) % 10) + '0';
              char p5tensDigit = (char)(p5 / 10) + '0'; // หาตัวอักษรของหลักร้อย
              char p5unitsDigit = (char)(p5 % 10) + '0';
              Lcd.Cursor(0, 3);
              Lcd.Display("PM2.5 = ");
              Lcd.Cursor(9, 3);
              Lcd.Pintchartype(p5ThousandsDigit);
              Lcd.Cursor(10, 3);
              Lcd.Pintchartype(p5hundredDigit);
              Lcd.Cursor(11, 3);
              Lcd.Pintchartype(p5tensDigit);
              Lcd.Cursor(12, 3);
              Lcd.Pintchartype(p5unitsDigit);
              Lcd.Cursor(13, 3);
              Lcd.Display("ug/m3");
            }else if (name == "p10") {
              p10 = value;
              char p10ThousandsDigit = (char)((p10 / 1000) % 10) + '0'; 
              char p10hundredDigit = (char)((p10 / 100) % 10) + '0';
              char p10tensDigit = (char)(p10 / 10) + '0'; // หาตัวอักษรของหลักร้อย
              char p10unitsDigit = (char)(p10 % 10) + '0';  
              Lcd.Cursor(0, 4);
              Lcd.Display("PM10 =  ");
              Lcd.Cursor(9, 4);
              Lcd.Pintchartype(p10ThousandsDigit);
              Lcd.Cursor(10, 4);
              Lcd.Pintchartype(p10hundredDigit);
              Lcd.Cursor(11, 4);
              Lcd.Pintchartype(p10tensDigit);
              Lcd.Cursor(12, 4);
              Lcd.Pintchartype(p10unitsDigit);
              Lcd.Cursor(13, 4);
              Lcd.Display("ug/m3");   
            }
             else {
              float value = valueString.toDouble();
            // Store the float value in the appropriate variable
            if (name == "T") {
              int TintegerPart = (int)value; // หารายการที่ไม่มีทศนิยม
          double TfractionalPart = value - TintegerPart; // หารายการที่มีทศนิยม 
          char ThundredDigit = (char)((TintegerPart / 100) % 10) + '0';                //100
          char TtensDigit = (char)((TintegerPart / 10) % 10) + '0';                   //10
          char TunitsDigit = (char)(TintegerPart % 10) + '0';                        //1
          char TdecimalDigit1 = (char)((int)(TfractionalPart * 10) % 10) + '0';
          char TdecimalDigit2 = (char)((int)(TfractionalPart * 100) % 10) + '0'; 
               Lcd.Cursor(0, 5);
          Lcd.Display("Temp =  ");
          Lcd.Pintchartype(ThundredDigit);
          Lcd.Pintchartype(TtensDigit);
          Lcd.Pintchartype(TunitsDigit);
          Lcd.Cursor(11, 5);
          Lcd.Display(".");
          Lcd.Pintchartype(TdecimalDigit1);
          Lcd.Pintchartype(TdecimalDigit2);
          Lcd.Cursor(16, 5);
          Lcd.Display("*C");
            } else if (name == "AA") {
              AA = value;
            } else if (name == "P") {
               int PintegerPart = (int)value; // หารายการที่ไม่มีทศนิยม
          double PfractionalPart = value - PintegerPart; // หารายการที่มีทศนิยม 
          char PThousandsDigitl = (char)((PintegerPart / 1000) % 10) + '0';
          char PThousandsDigit = PThousandsDigitl;            //1000 
          char PhundredDigit = (char)((PintegerPart / 100) % 10) + '0';                //100
          char PtensDigit = (char)((PintegerPart / 10) % 10) + '0';                   //10
          char PunitsDigit = (char)(PintegerPart % 10) + '0';                        //1
          char PdecimalDigit1 = (char)((int)(PfractionalPart * 10) % 10) + '0';
          char PdecimalDigit2 = (char)((int)(PfractionalPart * 100) % 10) + '0';
          Lcd.Cursor(0, 7);
          Lcd.Display("sure");
          Lcd.Cursor(0, 6);
          Lcd.Display("Pres =  ");
          Lcd.Pintchartype(PThousandsDigit);
          Lcd.Pintchartype(PhundredDigit);
          Lcd.Pintchartype(PtensDigit);
          Lcd.Pintchartype(PunitsDigit);
          Lcd.Cursor(11, 6);
          Lcd.Display(".");
          Lcd.Pintchartype(PdecimalDigit1);
          Lcd.Pintchartype(PdecimalDigit2);
          Lcd.Cursor(15, 6);
          Lcd.Display("hPa");
          delay (5000); 
          Lcd.Clear(false); 
            } else if (name == "AF") {
              int AFintegerPart = (int)value; // หารายการที่ไม่มีทศนิยม
          double AFfractionalPart = value - AFintegerPart; // หารายการที่มีทศนิยม 
          int AFhundredDigit = (char)((AFintegerPart / 100) % 10) + '0';
          int AFtensDigit = (char)((AFintegerPart / 10) % 10) + '0';                   //10
          int AFunitsDigit = (char)(AFintegerPart % 10) + '0';                        //1
          char AFdecimalDigit1 = (char)((int)(AFfractionalPart * 10) % 10) + '0';
          char AFdecimalDigit2 = (char)((int)(AFfractionalPart * 100) % 10) + '0';
          Lcd.Cursor(0, 4);
          Lcd.Display("Alt     ");
          Lcd.Cursor(9, 4);
          Lcd.Pintchartype(AFhundredDigit);
          Lcd.Cursor(10, 4);
          Lcd.Pintchartype(AFtensDigit);
          Lcd.Cursor(11, 4);
          Lcd.Pintchartype(AFunitsDigit);
          Lcd.Cursor(12, 4);
          Lcd.Display(".");
          Lcd.Cursor(13, 4);
          Lcd.Pintchartype(AFdecimalDigit1);
          Lcd.Cursor(14, 4);
          Lcd.Pintchartype(AFdecimalDigit2);
          Lcd.Cursor(16, 4);
          Lcd.Display("Ft");
            } else if (name == "Sk") {
              int SKintegerPart = (int)value; // หารายการที่ไม่มีทศนิยม
          double SKfractionalPart = value - SKintegerPart; // หารายการที่มีทศนิยม 
          char SKhundredDigit = (char)((SKintegerPart / 100) % 10) + '0';
          char SKtensDigit = (char)((SKintegerPart / 10) % 10) + '0';                   //10
          char SKunitsDigit = (char)(SKintegerPart % 10) + '0';                        //1
          char SKdecimalDigit1 = (char)((int)(SKfractionalPart * 10) % 10) + '0';
          char SKdecimalDigit2 = (char)((int)(SKfractionalPart * 100) % 10) + '0';
          char SKdecimalDigit3 = (char)((int)(SKfractionalPart * 1000) % 10) + '0';
          char SKdecimalDigit4 = (char)((int)(SKfractionalPart * 10000) % 10) + '0';
          char SKdecimalDigit5 = (char)((int)(SKfractionalPart * 100000) % 10) + '0';
          char SKdecimalDigit6 = (char)((int)(SKfractionalPart * 1000000) % 10) + '0';
            } else if (name == "La") {
              int LaintegerPart = (int)value; // หารายการที่ไม่มีทศนิยม
          double LafractionalPart = value - LaintegerPart; // หารายการที่มีทศนิยม 
          int LahundredDigit = (char)((LaintegerPart / 100) % 10) + '0';
          int LatensDigit = (char)((LaintegerPart / 10) % 10) + '0';                   //10
          int LaunitsDigit = (char)(LaintegerPart % 10) + '0';                        //1
          char LadecimalDigit1 = (char)((int)(LafractionalPart * 10) % 10) + '0';
          char LadecimalDigit2 = (char)((int)(LafractionalPart * 100) % 10) + '0';
          char LadecimalDigit3 = (char)((int)(LafractionalPart * 1000) % 10) + '0';
          char LadecimalDigit4 = (char)((int)(LafractionalPart * 10000) % 10) + '0';
          char LadecimalDigit5 = (char)((int)(LafractionalPart * 100000) % 10) + '0';
          char LadecimalDigit6 = (char)((int)(LafractionalPart * 1000000) % 10) + '0';
          Lcd.Cursor(0, 2);
          Lcd.Display("Lat     ");
          Lcd.Pintchartype(LahundredDigit);
          Lcd.Cursor(9, 2);
          Lcd.Pintchartype(LatensDigit);
          Lcd.Cursor(10, 2);
          Lcd.Pintchartype(LaunitsDigit);
          Lcd.Cursor(11, 2);
          Lcd.Display(".");
          Lcd.Cursor(12, 2);
          Lcd.Pintchartype(LadecimalDigit1);
          Lcd.Cursor(13, 2);
          Lcd.Pintchartype(LadecimalDigit2);
          Lcd.Cursor(14, 2);
          Lcd.Pintchartype(LadecimalDigit3);
          Lcd.Cursor(15, 2);
          Lcd.Pintchartype(LadecimalDigit4);
          Lcd.Cursor(16, 2);
          Lcd.Pintchartype(LadecimalDigit5);
          Lcd.Cursor(17, 2);
          Lcd.Pintchartype(LadecimalDigit6);
            } else if (name == "Lo") {
              int LointegerPart = (int)value; // หารายการที่ไม่มีทศนิยม
          double LofractionalPart = value - LointegerPart; // หารายการที่มีทศนิยม
          char LohundredDigit = (char)((LointegerPart / 100) % 10) + '0'; 
          char LotensDigit = (char)((LointegerPart / 10) % 10) + '0';                   //10
          char LounitsDigit = (char)(LointegerPart % 10) + '0';                        //1
          char LodecimalDigit1 = (char)((int)(LofractionalPart * 10) % 10) + '0';
          char LodecimalDigit2 = (char)((int)(LofractionalPart * 100) % 10) + '0';
          char LodecimalDigit3 = (char)((int)(LofractionalPart * 1000) % 10) + '0';
          char LodecimalDigit4 = (char)((int)(LofractionalPart * 10000) % 10) + '0';
          char LodecimalDigit5 = (char)((int)(LofractionalPart * 100000) % 10) + '0';
          char LodecimalDigit6 = (char)((int)(LofractionalPart * 1000000) % 10) + '0';
          Lcd.Cursor(0, 3);
          Lcd.Display("long    ");
           Lcd.Cursor(8, 3);
          Lcd.Pintchartype(LohundredDigit);
          Lcd.Cursor(9, 3);
          Lcd.Pintchartype(LotensDigit);
          Lcd.Cursor(10, 3);
          Lcd.Pintchartype(LounitsDigit);
          Lcd.Cursor(11, 3);
          Lcd.Display(".");
          Lcd.Cursor(12, 3);
          Lcd.Pintchartype(LodecimalDigit1);
          Lcd.Cursor(13, 3);
          Lcd.Pintchartype(LodecimalDigit2);
          Lcd.Cursor(14, 3);
          Lcd.Pintchartype(LodecimalDigit3);
          Lcd.Cursor(15, 3);
          Lcd.Pintchartype(LodecimalDigit4);
          Lcd.Cursor(16, 3);
          Lcd.Pintchartype(LodecimalDigit5);
          Lcd.Cursor(17, 3);
          Lcd.Pintchartype(LodecimalDigit6);     
            }
          }
        }
      }
    }
  }
}
Lcd.Cursor(0, 0);
  Lcd.Display("");
  Lcd.Pintchartype(HfirstDigit);
  Lcd.Cursor(1, 0);
  Lcd.Pintchartype(HsecondDigit);
  Lcd.Cursor(2, 0);
  Lcd.Display(":");
  Lcd.Cursor(3, 0);
  Lcd.Pintchartype(MfirstDigit);
  Lcd.Cursor(4, 0);
  Lcd.Pintchartype(MsecondDigit);
  Lcd.Cursor(5, 0);
  Lcd.Display(":");
  Lcd.Cursor(6, 0);
  Lcd.Pintchartype(SfirstDigit);
  Lcd.Cursor(7, 0);
  Lcd.Pintchartype(SsecondDigit);  
}

void skipButtonPressed() {
  skipExecution = true; // กำหนดค่า skipExecution เป็น true เพื่อข้ามการทำงาน
  // คุณอาจใส่โค้ดเพิ่มเติมที่นี่หากต้องการทำงานเมื่อปุ่มถูกกด
}