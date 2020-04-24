const int PWMA = 5;  // define the left motor speed pin D5
const int PWMB = 9;  // define the right motor speed pin D9
const int INT_A = 4;  // define the left motor control pin D4
const int INT_B = 2;  // define the right motor control pin D2

const int TONE = 11;

void setup()
{
   Serial.begin(9600);   // set the serial port baud rate to 9600

   pinMode(PWMA,OUTPUT);  // set the motor control pin as OUTPUT 
   pinMode(PWMB,OUTPUT);
   pinMode(INT_A,OUTPUT);
   pinMode(INT_B,OUTPUT);
   pinMode(TONE,OUTPUT);
}

void loop()
{
  int val = 83;    // define the variable, used to save the Bluetooth signal value read.

  if (Serial.available())
  {
    val = Serial.read();

    Serial.println(val);

    switch(val)   //val data, corresponds to the data of the case statement below, then perform the corresponding data function. 
    {
      case 70:
      case 87:
        front(); break;   // receive the val value U, and perform front(); then use break; to exit the current statement.
      case 66:
      case 90:
        back(); break;
      case 76:
      case 81:
        left(); break;
      case 82:
      case 69:
        right(); break;
      case 83:
        Stop(); break;

      // melodies
      case 49: // DO
        tone(TONE,264); break;
      case 50: // RE
        tone(TONE,297); break;
      case 51: // ME
        tone(TONE,330); break;
      case 52: // FA
        tone(TONE,352); break;
      case 53: // SO
        tone(TONE,396); break;
      case 54: // LA
        tone(TONE,440); break;
      case 55: // SI
        tone(TONE,495); break;
      case 56: // DO
        tone(TONE,528); break;
      default:
        Serial.println(val);    // if no corresponding data, print the error on serial monitor
    }
  }
}

// WHEELS
// forward
void front()
{
  digitalWrite(INT_A,HIGH);  // left motor turns forward
  digitalWrite(INT_B,HIGH);   // right motor turns forward 
  analogWrite(PWMA,255);   // speed of left motorï¼ˆPWM=255)
  analogWrite(PWMB,255);   // speed of right motorï¼ˆPWM=255)
}
// backward
void back()
{
  digitalWrite(INT_A,LOW);   // left motor turns reverse
  digitalWrite(INT_B,LOW);  // right motor turns reverse 
  analogWrite(PWMA,255);   // speed of left motor ï¼ˆPWM=255)
  analogWrite(PWMB,255);   // speed of right motor ï¼ˆPWM=255)
  // bool tn = true;
  //do
  //{
  //  tone(TONE,528);
  //  delay(500);
  //  noTone(TONE);
  //  delay(500);
  //} while(true);
}
// turn left 
void left()
{
  digitalWrite(INT_A,LOW);  // left motor turns reverse
  digitalWrite(INT_B,HIGH);  // right motor turns forward
  analogWrite(PWMA,200);   // speed of left motorï¼ˆPWM=200)
  analogWrite(PWMB,200);   // speed of right motorï¼ˆPWM=200)
}
// turn right 
void right()
{
  digitalWrite(INT_A,HIGH);   // left motor turns forward
  digitalWrite(INT_B,LOW);   // right motor turns reverse
  analogWrite(PWMA,200);   // speed of left motor ï¼ˆPWM=200)
  analogWrite(PWMB,200);   // speed of right motor ï¼ˆPWM=200)
}
// stop
void Stop()
{
  digitalWrite(INT_A,LOW);
  digitalWrite(INT_B,LOW);
  analogWrite(PWMA,0);  // speed of left motorï¼ˆPWM=0)
  analogWrite(PWMB,0);  // speed of right motorï¼ˆPWM=0)
  noTone(TONE);
}
