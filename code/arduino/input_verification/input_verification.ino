#include <Wire.h>
#include "I2Cdev.h"
#include "MPU6050.h"
MPU6050 mpu;

void setup(){
  Wire.begin();
  Serial.begin(115200);
  mpu.initialize();
}

void loop(){
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
  Serial.print(ax); Serial.print(","); Serial.println(ay);
  delay(200);
}
