#include <MLX90615.h>
#include <Wire.h>

TwiMaster i2c(false);
MLX90615 mlx90615(DEVICE_ADDR, &i2c);

void setup() {
  Serial.begin(115200);
  
  // pullups
  //pinMode(SDA, INPUT_PULLUP);
  //pinMode(SCL, INPUT_PULLUP);
  if (digitalRead(SDA) == 0)
    Serial.println("SDA forced low");
  else if (digitalRead(SCL) == 0)
    Serial.println("SCL forced low");
  else
    Serial.println("LIFE");
}

void loop() {
  float t_obj = mlx90615.getTemperature(MLX90615_OBJECT_TEMPERATURE);
  float t_amb = mlx90615.getTemperature(MLX90615_AMBIENT_TEMPERATURE);

  Serial.print(t_obj);
  Serial.print(" ");
  Serial.print(t_amb);
  Serial.println();

  delay(500);
}
