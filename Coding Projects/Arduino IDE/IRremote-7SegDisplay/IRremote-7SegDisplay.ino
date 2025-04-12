#define IR_USE_TIMER1
#include <IRremote.hpp>
#include "SevSeg.h"
SevSeg sevseg; 

const int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
unsigned long key_value = 0;

void setup(){
  // IR receiver
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  irrecv.blink13(true);

  //7-LED setup
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  sevseg.setNumber('.');
}

void loop(){
  if (IrReceiver.decode())
  {
    if (IrReceiver.decodedIRData.decodedRawData != 0XFFFFFFFF)
    {
      key_value = IrReceiver.decodedIRData.decodedRawData;

      switch(key_value)
      {
        case 0xE916FF00: //0
          sevseg.setNumber(0);
          break ;
        case 0xF30CFF00: //1
          sevseg.setNumber(1);
          Serial.println("1");
          break ;
        case 0xE718FF00: //2
          sevseg.setNumber(2);
          Serial.println("2");
          break ;
      case 0xA15EFF00: //3
          sevseg.setNumber(3);
          Serial.println("3");
          break ;
      case 0xF708FF00: //4
          sevseg.setNumber(4);
          Serial.println("4");
          break ;
      case 0xE31CFF00: //5
          sevseg.setNumber(5);
          Serial.println("5");
          break ;
      case 0xA55AFF00: //6
          sevseg.setNumber(6);
          Serial.println("6");
          break ;
      case 0xBD42FF00: //7
          sevseg.setNumber(7);
          Serial.println("7");
          break ;
      case 0xAD52FF00: //8
          sevseg.setNumber(8);
          Serial.println("8");
          break ;
      case 0xB54AFF00: //9
          sevseg.setNumber(9);
          Serial.println("9");
          break ; 
      default:
Serial.println("unknown value");
          break;
      }
    }
    IrReceiver.resume();
  }
  sevseg.refreshDisplay();
}