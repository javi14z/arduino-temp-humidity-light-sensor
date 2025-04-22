#include <LiquidCrystal.h>

#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 7
#define DHTTYPE DHT11
#define LDR_PIN A3
#define BUTTON_PIN 4

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int pantalla = 0;

void setup() {
  //Bloque boton
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  //Bloque lcd
  lcd.init();
  lcd.backlight();
  //Bloque sensor de humedad y temperatura
  dht.begin();
}

void loop() {
  //Leemos temperatura y humedad
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  //Leemos nivel de luz y normalizamos
  int luz_analog = analogRead(LDR_PIN);
  int luz_normalizada = map(luz_analog, 0,1023,0,100);

  //Lógica botón: Si se pulsa el botón, cambiar pantalla
  if (digitalRead(BUTTON_PIN) == LOW) {
    pantalla = 1 - pantalla;  // alterna entre 0 y 1
    lcd.clear();
    delay(500); // anti-rebote simple
  }

  if (pantalla == 0) {
    //Actualizamos la pantalla para temperatura y humedad
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(t, 1);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(h, 1);
    lcd.print(" %");
  } else {
    //Actualizamos la pantalla para el nivel de luz
    lcd.setCursor(0, 0);
    lcd.print("Sensor de Luz");
    lcd.setCursor(0, 1);
    lcd.print("Nivel: ");
    lcd.print(luz_normalizada);
  }

  delay(500); // Actualiza cada medio segundo
}
