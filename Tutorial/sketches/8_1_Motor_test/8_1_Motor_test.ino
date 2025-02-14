/*****************************************************
 
 * This code applies to cokoino smart robot car kit
 * Through this link you can download the source code:
 * https://github.com/Cokoino/CKK0002
 * Company web site:
 * http://cokoino.com/
 
*****************************************************/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

void setup(){
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50); // Set the PWM frequency               
}
  
void loop(){ 
     //pwm.setPWM(pwmnum,on, off);
     //(pwmnum, on, off) function is mainly to adjust the output PWM duty cycle.
     // Usually, on is set to 0 and off can be changed.
     // Because the PCA9685 is a 12-bit resolution
     // the value of 0 to 4096 off represents a duty cycle of 0 to 100.
     //***************************************************************
     // drive M1 Motror forward
     pwm.setPWM(2,0,2000); //set pwm signal to BIN2 of DRV8833
     pwm.setPWM(3,0,-2000);//set pwm signal to BIN1 of DRV8833
      //drive M4 Motror forward
     pwm.setPWM(4,0,-2000);//set pwm signal to AIN1 of DRV8833
     pwm.setPWM(5,0,2000);//set pwm signal to AIN2 of DRV8833
     delay(2000);
     // drive M1 Motror backward
     pwm.setPWM(2,0,-2000);//set pwm signal to BIN2 of DRV8833
     pwm.setPWM(3,0,2000);//set pwm signal to BIN1 of DRV8833
     // drive M4 Motror backward
     pwm.setPWM(4,0,2000);//set pwm signal to AIN1 of DRV8833
     pwm.setPWM(5,0,-2000);//set pwm signal to AIN2 of DRV8833
     delay(2000);
     //set M1/M4 Motor stop
     pwm.setPWM(2,0,0);//set pwm signal to BIN2 of DRV8833
     pwm.setPWM(3,0,0);//set pwm signal to BIN1 of DRV8833
     pwm.setPWM(4,0,0);//set pwm signal to AIN1 of DRV8833
     pwm.setPWM(5,0,0);//set pwm signal to AIN2 of DRV8833
     delay(500);
     //***************************************************************
}
