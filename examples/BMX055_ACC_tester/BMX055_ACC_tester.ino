/*
    Code written by Chia Jiun Wei @ 31-8-2017
    This code test the BMX055_ACC library
*/

/*  PIN connection for a MSP432 LaunchPad board:
    P6.0 - > BMX055 CSA, define P6.0 as SPI chip select
*/

#include "BMX055_ACC.h"

DSPI master;        // used EUSCI_B0
BMX055_ACC imu_acc(&master, 2);

s16 acc_data[3];

void setup()
{
  // initialize the UART
  Serial.begin(115200);
  delay(300);

  // initialise SPI:
  master.begin();
  delay(300);

  Serial.print("**** Start BMX055 Accelerometer test ****");
  Serial.println();

  //initalise BMX055 Accelerometer
  imu_acc.init();

  Serial.print("BMX055 Accelerometer initialised");
  Serial.println();
  Serial.print("Pinging BMX055 Accelerometer...");
  Serial.println();

  if (imu_acc.ping() == 1)
  {
    Serial.print("Ping sucess");
    Serial.println();
  }
  else
  {
    Serial.print("Ping fail");
    Serial.println();
  }
}

void loop()
{
  Serial.print("Reading Accelerometer data");
  Serial.println();
  imu_acc.get_acc(acc_data);

  Serial.print("Acc x: ");
  Serial.print(acc_data[0], DEC);
  Serial.print("  ");
  Serial.print("Acc y: ");
  Serial.print(acc_data[1], DEC);
  Serial.print("  ");
  Serial.print("Acc z: ");
  Serial.print(acc_data[2], DEC);
  Serial.print("  ");
  Serial.println();
}

