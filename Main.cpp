#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40); // Default I2C address

#define SERVO1 0  // Servo on channel 0
#define SERVO2 1  // Servo on channel 1
#define SERVO3 2  // Servo on channel 0
#define SERVO4 3  // Servo on channel 1
#define SERVO5 4  // Servo on channel 0
#define SERVO6 5  // Servo on channel 1

#define STOP 300   // Neutral position (stops the servo)
#define MAX_SPEED 500  // Maximum speed 
// 400 slower forward
#define MIN_SPEED 100  // Maximum speed backward
// 200 slower backwards




void setup() {
  pwm.begin();
  pwm.setPWMFreq(50); // Set frequency to 50Hz
}

void straight(){
  // Phase 1
  pwm.setPWM(SERVO1, 0, MAX_SPEED);
  delay(1000);
  pwm.setPWM(SERVO3, 0, MAX_SPEED);
  delay(1000);
  pwm.setPWM(SERVO5, 0, MAX_SPEED);
  delay(1000);

  pwm.setPWM(SERVO2, 0, MAX_SPEED);
  delay(1000);
  pwm.setPWM(SERVO4, 0, MAX_SPEED);
  delay(1000);
  pwm.setPWM(SERVO6, 0, MAX_SPEED);
  delay(2000);

//--------------------------------------------------
  // Phase 2

  pwm.setPWM(SERVO1, 0, STOP);
  delay(1000);
  pwm.setPWM(SERVO3, 0, STOP);
  delay(1000);
  pwm.setPWM(SERVO5, 0, STOP);
  delay(1000);

  pwm.setPWM(SERVO2, 0, STOP);
  delay(1000);
  pwm.setPWM(SERVO4, 0, STOP);
  delay(1000);
  pwm.setPWM(SERVO6, 0, STOP);
  delay(2000);

//--------------------------------------------------
  // Phase 3

  pwm.setPWM(SERVO1, 0, MIN_SPEED);
  delay(1000);
  pwm.setPWM(SERVO3, 0, MIN_SPEED);
  delay(1000);
  pwm.setPWM(SERVO5, 0, MIN_SPEED);
  delay(1000);

  pwm.setPWM(SERVO2, 0, MIN_SPEED);
  delay(1000);
  pwm.setPWM(SERVO4, 0, MIN_SPEED);
  delay(1000);
  pwm.setPWM(SERVO6, 0, MIN_SPEED);
  delay(2000);

  // // Move Servo 1 and Servo 2 to Max Speed Backward
  // pwm.setPWM(SERVO1, 0, MIN_SPEED);
  // pwm.setPWM(SERVO2, 0, MIN_SPEED);
  // pwm.setPWM(SERVO3, 0, MIN_SPEED);
  // pwm.setPWM(SERVO4, 0, MIN_SPEED);
  // delay(2000);

  // // Stop both servos
  // pwm.setPWM(SERVO1, 0, STOP);
  // pwm.setPWM(SERVO2, 0, STOP);
  // delay(2000);
}

void loop() {
  straight();
}

/*
360 degree so no feedback system, no positional control. 
forward and backwards motiona dns fast and slow
*/