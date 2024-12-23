
// Include the (new) library
#include <L298NX2.h>
#include <IBusBM.h>

// Pin definition
const unsigned int EN_A = 3;
const unsigned int IN1_A = 5;
const unsigned int IN2_A = 6;

const unsigned int EN_B = 9;
const unsigned int IN1_B = 7;
const unsigned int IN2_B = 8;


const unsigned int CH2 = 12; // right up/down
const unsigned int CH3 = 13; // left up/down

const unsigned int CH6 = 11; // switch?


//define receiver pin


/*
 * 1 - 6:
 * R up/down
 * R left/right
 * L up/down
 * L left/right
 * control VRA
 * control VRB
 */



// Initialize both motors
L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value;
int ch6Value;

// from https://dronebotworkshop.com/radio-control-arduino-car/

// Read the number of a specified channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

bool readSwitch(byte channelInput, bool defaultValue){
  int intDefaultValue = (defaultValue)? 100: 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 5);
}

void setup()
{
  // Used to display information
  Serial.begin(9600);

  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);

  // Wait for Serial Monitor to be opened
  // NEED?
  while (!Serial)
  {
    //do nothing
  }
  motors.setSpeed(0);
}


void loop()
{
  

  //Serial.println("Receiving...");
  ch2Value = readChannel(CH2, -100, 100, 0);
  ch3Value = readChannel(CH3, -100, 100, -100);


  Serial.print("Ch2: ");
  Serial.println(ch2Value);
  Serial.print("Ch3: ");
  Serial.println(ch3Value);
  

  // channel 2 affects motor B
  if(ch2Value > 50){
    motors.forwardB();
  }
  else{
    if(ch2Value < -50){
      motors.backwardB();
    }
    else{
      motors.stopB();
     // Serial.println("Stopping A");
    }
  }
  
  // channel 3 affects motor A
  if(ch3Value > 50){
    motors.forwardA();
  }
  else{
    if(ch3Value < -50){
      motors.backwardA();
    }
    else{
      motors.stopA();
      //Serial.println("Stopping B");

    }
  }

}

/*

Print some informations in Serial Monitor
*/
void printSomeInfo()
{
  Serial.print("Motor A is moving = ");
  Serial.print(motors.isMovingA() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(motors.getSpeedA());
  Serial.print("Motor B is moving = ");
  Serial.print(motors.isMovingB() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(motors.getSpeedB());
}
