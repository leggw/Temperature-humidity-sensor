// include library for lcd display
#include <LiquidCrystal.h>

// include DHT library sensor from adafruit
#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11

LiquidCrystal lcd(11, 9, 6, 5, 4, 3);

// identify pin for DHT sensor
DHT HT(2, Type);

void  setup()
{
  Serial.begin(9600);
  HT.begin();
  lcd.begin(16,2);
}

void loop()
{
  float humidity = HT.readHumidity();
  float tempC = HT.readTemperature();
  float tempF = tempC * (9.0/5.0) + 32.0;
  float tempK = tempC + 273.0;

  lcd.setCursor(0, 0);
  lcd.print("Hum(%): ");
  lcd.print(humidity);

  lcd.setCursor(0, 1);
  lcd.print("Temp(F): ");
  lcd.print(tempF);
  delay(1000); // update every 1000 milliseconds

}
