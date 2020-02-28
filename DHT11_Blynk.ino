#include "DHT.h"        
#define DHTTYPE DHT11  
#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial   
#include <BlynkSimpleEsp8266.h>
#define dht_dpin D3
DHT dht(dht_dpin, DHTTYPE); 
char auth[] = "eqgju9ARz8JVN8zsWc580LdTxmwxKiAc";
char ssid[] = "IoT";
char pass[] = "88899922";
void setup(void)
{ 
  dht.begin();
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  Serial.println("Humidity and temperature \n\n");
  Serial.println("==========================================");
  delay(700);
}
WidgetLCD lcd(V1);
void loop() {
    Blynk.run();
    float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
    Blynk.virtualWrite(V0, t);
    lcd.print(0,0,t);
    Blynk.virtualWrite(V2,t);
    if(t>=39){
      Blynk.notify("Kebakaran Kantor Anda");
    }
    delay(800);
  
}
