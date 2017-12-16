//For motor control
#define E1 3  // Enable Pin for motor 1
#define E2 5  // Enable Pin for motor 2
 
#define I1 4  // Control pin 1 for motor 1
#define I2 2  // Control pin 2 for motor 1
#define I3 8  // Control pin 1 for motor 2
#define I4 7  // Control pin 2 for motor 2

// Wheel 1
int m1=0; // Signal to Wheel 1 ->left wheel
// Wheel 2
int m2=0; // Signal to Wheel 2 -> right wheel

int leftIR=12;
int rightIR=11;

void setup() {
  // put your setup code here, to run once:
  //For motor control
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
 
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);

    digitalWrite(I1, LOW);//LOW
    digitalWrite(I2, HIGH);//HIGH
    digitalWrite(I3, LOW);//LOW
    digitalWrite(I4, HIGH);//HIGH

    //For IR
    pinMode(leftIR,INPUT);
    pinMode(rightIR,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
//  Serial.println(digitalRead(leftIR));
//  Serial.println(digitalRead(rightIR));
//  delay(1000);

  if (digitalRead(leftIR)==0 && digitalRead(rightIR)==0) {
    digitalWrite(I1, LOW);//LOW
    digitalWrite(I2, HIGH);//HIGH
    digitalWrite(I3, LOW);//LOW
    digitalWrite(I4, HIGH);//HIGH
  }
  if (digitalRead(leftIR)==0 && digitalRead(rightIR)==1)
  {
    digitalWrite(I1, LOW);//LOW
    digitalWrite(I2, HIGH);//HIGH
    digitalWrite(I3, LOW);//LOW
    digitalWrite(I4, LOW);//HIGH
   }
   if (digitalRead(leftIR)==1 && digitalRead(rightIR)==0)
  {
    digitalWrite(I1, LOW);//LOW
    digitalWrite(I2, LOW);//HIGH
    digitalWrite(I3, LOW);//LOW
    digitalWrite(I4, HIGH);//HIGH
   }
   if (digitalRead(leftIR)==1 && digitalRead(rightIR)==1) {
    digitalWrite(I1, LOW);//LOW
    digitalWrite(I2, LOW);//HIGH
    digitalWrite(I3, LOW);//LOW
    digitalWrite(I4, LOW);//HIGH
  }
  
    m1=160;
    m2=165;
  analogWrite(E1, m1); // Run in m1 Speed
  analogWrite(E2, m2); // Run in m2 speed
}
