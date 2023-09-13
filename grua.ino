#include <Arduino.h>
#include <IRremote.h>
#include <Servo.h>

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

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int servo_one_angle = 90;
int servo_two_angle = 90;
int servo_three_angle = 90;
int servo_four_angle = 90;
int servo_five_angle = 90;
int servo_six_angle = 90;

int pinReceptor = 2;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(pinReceptor, DISABLE_LED_FEEDBACK);
  servo1.attach(3,500,2500);
  servo2.attach(5,500,2500);
  servo3.attach(6,500,2500);
  servo4.attach(9,500,2500);
  servo5.attach(10,500,2500);
  servo6.attach(11,500,2500);
  set_angle_servo();
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode())
  {
    // Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    if(IrReceiver.decodedIRData.decodedRawData == boton_0) {
      servo_one_angle += 10;
      if(servo_one_angle > 180) servo_one_angle = 180;
      servo1.write(servo_one_angle);
    } else if(IrReceiver.decodedIRData.decodedRawData == boton_1) {
      servo_one_angle -= 10;
      if(servo_one_angle < 0) servo_one_angle = 0;
      servo1.write(servo_one_angle);
    } else if(IrReceiver.decodedIRData.decodedRawData == boton_2) {
      servo_two_angle += 10;
      if(servo_two_angle > 180) servo_two_angle = 180;
      servo2.write(servo_two_angle);
    } else if(IrReceiver.decodedIRData.decodedRawData == boton_3) {
      servo_two_angle -= 10;
      if(servo_two_angle < 0) servo_two_angle = 0;
      servo2.write(servo_two_angle);
    } else if(IrReceiver.decodedIRData.decodedRawData == boton_4) {
      servo_three_angle += 10;
      if(servo_three_angle > 180) servo_three_angle = 180;
      servo3.write(servo_three_angle);
    }else if(IrReceiver.decodedIRData.decodedRawData == boton_5) {
      servo_three_angle -= 10;
      if(servo_three_angle < 0) servo_three_angle = 0;
      servo3.write(servo_three_angle);
    }else if(IrReceiver.decodedIRData.decodedRawData == boton_6) {
      servo_four_angle += 10;
      if(servo_four_angle > 180) servo_four_angle = 180;
      servo4.write(servo_four_angle);
    }else if(IrReceiver.decodedIRData.decodedRawData == boton_7) {
      servo_four_angle -= 10;
      if(servo_four_angle < 0) servo_four_angle = 0;
      servo4.write(servo_four_angle);
    }else if(IrReceiver.decodedIRData.decodedRawData == boton_8) {
      servo_five_angle += 10;
      if(servo_five_angle > 180) servo_five_angle = 180;
      servo4.write(servo_five_angle);
    }else if(IrReceiver.decodedIRData.decodedRawData == boton_9) {
      servo_five_angle -= 10;
      if(servo_five_angle < 0) servo_five_angle = 0;
      servo4.write(servo_five_angle);
    }else if(IrReceiver.decodedIRData.decodedRawData == boton_more) {
      servo_six_angle += 10;
      if(servo_six_angle > 180) servo_six_angle = 0;
      servo4.write(servo_six_angle);
    }else if(IrReceiver.decodedIRData.decodedRawData == boton_less) {
      servo_six_angle -= 10;
      if(servo_six_angle < 0) servo_six_angle = 0;
      servo4.write(servo_six_angle);
    }
    IrReceiver.resume();
  }
}


void set_angle_servo() {
  servo_one_angle = servo1.read();
  servo_two_angle = servo2.read();
  servo_three_angle = servo3.read();
  servo_four_angle = servo4.read();
  servo_five_angle = servo5.read();
  servo_six_angle = servo6.read();
  servo1.write(servo_one_angle);
  servo2.write(servo_two_angle);
  servo3.write(servo_three_angle);
  servo4.write(servo_four_angle);
  servo5.write(servo_five_angle);
  servo6.write(servo_six_angle);
}