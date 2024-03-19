#include <dht.h>         // Include ბრძანება ბიბლიოთეკების შემოტანა
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;
#define DHT11_PIN 7
void setup(){
  lcd.begin(16, 2);   //ჰორიზონტალების რაოდენობა, ვერტიკალების რაოდენობა
  Serial.begin(9600);
  
}
void loop(){
 
  int sen = DHT.read11(DHT11_PIN);
  
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  Serial.print("Temp: ");
  lcd.print(DHT.temperature);
  Serial.print(DHT.temperature);
  
  lcd.print((char)223);
  lcd.print("C");
  Serial.print("C");
  Serial.println(); // new line 
  
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity);
  Serial.print("%");
  delay(1000);
}