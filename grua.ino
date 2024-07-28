#include <Arduino.h>
#include <IRremote.h>
#include <Servo.h>

// Define the IR codes for the buttons
#define boton_0 0xE916FF00
#define boton_1 0xF30CFF00
#define boton_2 0xE718FF00
#define boton_3 0xA15EFF00
#define boton_4 0xF708FF00
#define boton_5 0xE31CFF00
#define boton_6 0xA55AFF00
#define boton_7 0xBD42FF00
#define boton_8 0xAD52FF00
#define boton_9 0xB54AFF00
#define boton_more 0xEA15FF00
#define boton_less 0xF807FF00

// Servo objects
Servo servos[6];
int servo_angles[6] = {90, 90, 90, 90, 90, 90};

// IR receiver pin
int pinReceptor = 2;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(pinReceptor, DISABLE_LED_FEEDBACK);
  
  // Attach the servos
  int servo_pins[6] = {3, 5, 6, 9, 10, 11};
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servo_pins[i], 500, 2500);
    servos[i].write(servo_angles[i]);
  }
}

void loop() {
  if (IrReceiver.decode()) {
    handleIR(IrReceiver.decodedIRData.decodedRawData);
    IrReceiver.resume();
  }
}

void handleIR(unsigned long irCode) {
  switch (irCode) {
    case boton_0: adjustServo(0, 10); break;
    case boton_1: adjustServo(0, -10); break;
    case boton_2: adjustServo(1, 10); break;
    case boton_3: adjustServo(1, -10); break;
    case boton_4: adjustServo(2, 10); break;
    case boton_5: adjustServo(2, -10); break;
    case boton_6: adjustServo(3, 10); break;
    case boton_7: adjustServo(3, -10); break;
    case boton_8: adjustServo(4, 10); break;
    case boton_9: adjustServo(4, -10); break;
    case boton_more: adjustServo(5, 10); break;
    case boton_less: adjustServo(5, -10); break;
  }
}

void adjustServo(int servoIndex, int angleChange) {
  servo_angles[servoIndex] += angleChange;
  servo_angles[servoIndex] = constrain(servo_angles[servoIndex], 0, 180);
  servos[servoIndex].write(servo_angles[servoIndex]);
}
