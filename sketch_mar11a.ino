#include <Wire.h>   // FOR I2C COMMUNICATION FOR LCD 
#include <LiquidCrystal_I2C.h>   // FOR LCD
#include <DHT.h>  // DHT22 TEMP AND MOISTURE SENSOR

#define LED_PIN 9  // LED CONNECTED TO DIGITAL PIN 9 
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD object
DHT dht(2, DHT22);  // DHT sensor connected to digital pin 2  

void setup() {
  Serial.begin(9600);  // FOR SERIAL MONITOR INITIALIZATION 

  pinMode(LED_PIN, OUTPUT);  // LED PIN INIT 
  lcd.init();  // LCD INIT 
  lcd.backlight();  // LCD BACK LIGHT ON 
  lcd.print(" WEATHER MONITORING ");
  delay(2000);
  lcd.clear();

  dht.begin();  // DHT SENSOR BEGIN
}

void loop() {
  float temp = dht.readTemperature();  // READ TEMPERATURE FROM SENSOR
  float hum = dht.readHumidity();  // READ HUMIDITY FROM SENSOR

  if (isnan(temp) || isnan(hum)) {  // CHECK FOR SENSOR ERROR
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    Serial.println("Sensor Error");
    return;  // Exit loop early if error occurs
  }

  // PRINTING RESULTS IN SERIAL MONITOR 
  Serial.print("Temp : ");
  Serial.print(temp);
  Serial.print(" C, ");

  Serial.print("Humi : ");
  Serial.print(hum);
  Serial.println(" %");

  // PRINTING RESULT ON LCD 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp : ");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum : ");
  lcd.print(hum);
  lcd.print(" %");

  // IF TEMP > 30, BLINK LED 5 TIMES
  if (temp > 30) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(500);
      digitalWrite(LED_PIN, LOW);
      delay(500);
    }
  } else {
    digitalWrite(LED_PIN, LOW);   
  }

  delay(2000);  // Wait 2 seconds before next reading
}
