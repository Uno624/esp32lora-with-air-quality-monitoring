#include <LoRa.h>
#include <SPI.h>
 
#define ss 5
#define rst 14
#define dio0 2
 
int counter = 0;
 
void setup() 
{
  Serial.begin(115200); 
  while (!Serial);
  Serial.println("LoRa Sender");
 
  LoRa.setPins(ss, rst, dio0);    //setup LoRa transceiver module
  
  while (!LoRa.begin(433E6))     //433E6 - Asia, 866E6 - Europe, 915E6 - North America
  {
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xA5);
  Serial.println("LoRa Initializing OK!");
}
 
void loop() 
{
  Serial.print("Sending packet: ");
  Serial.println(counter);
 
  LoRa.beginPacket();   //Send LoRa packet to receiver
  LoRa.print("p=56&p1=8&p5=11&p10=11&T=31.51&AA=10.46&P=1011.99&La=13.860665&Lo=100.519366&AF=-11.15&Sk=0.58");
  LoRa.print(counter);
  LoRa.endPacket();
 
  counter++;
 
  delay(10000);
}