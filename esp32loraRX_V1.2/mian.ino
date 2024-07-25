void setup() {

  Wire. begin () ;
  Serial.begin(115200);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
 
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  Lcd.Init();
  Lcd.testPixel(2);                   //use to test LCD screen. Parameter is velocity.
  for(int a=0; a<64; a++){
  Lcd.DisplayPixel(a,a);              //display one pixel. X=0-31, Y=0-127
  delay(5);
  }
  for(int a=0; a<64; a++){
  Lcd.ClearPixel(a,a);                //Does not display a pixel. X=0-31, Y=0-127
  delay(5); }

WiFiManager wm;
Lcd.Cursor(2, 3);  
  Lcd.Display("Plz Connet WiFi");
  wm.setTimeout(60);
  bool res;
  res = wm.autoConnect("ESP๓๒");
  if(!res) 
  {
        Lcd.Clear(false);
        Lcd.Cursor(2, 3);  
        Lcd.Display("Failed to connect..");
        delay(3000);
          Lcd.Clear(false);
    } 
    else {
        //if you get here you have connected to the WiFi 
        Lcd.Clear(false);
        Lcd.Display("connected...");
 }

  delay(4000);
  Lcd.Clear(false);
  timeClient.begin();
  while (!Serial);
  Serial.println("LoRa Receiver");
  LoRa.setPins(SS_PIN, RST_PIN, DI0_PIN);    //setup LoRa transceiver module
  while (!LoRa.begin(433E6))     //433E6 - Asia, 866E6 - Europe, 915E6 - North America
  {
    Lcd.Cursor(0, 3);
    Lcd.Display("check Lora module");
    delay(3000);
    Lcd.Clear(false);
  }
  LoRa.setSyncWord(0xA5);
  Lcd.Cursor(3, 3);
  Lcd.Display("Lora module");
  Lcd.Cursor(5, 4);
  Lcd.Display("checked");
  delay(3000);
  Lcd.Clear(false);
}
//////////////////////////////////////////