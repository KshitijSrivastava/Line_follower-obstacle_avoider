//For Ultrasonic Sensor
const int trigPin = A5;
const int echoPin = A4;
// defines variables
long duration;
int distance;

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

int temp;

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

    //For Ultrasonic
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

    if (distance>30) {
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
    if (digitalRead(leftIR)==1 && digitalRead(rightIR)==1)
    {
    digitalWrite(I1, LOW);//LOW
    digitalWrite(I2, LOW);//HIGH
    digitalWrite(I3, LOW);//LOW
    digitalWrite(I4, LOW);//HIGH
    }
    
  }
  else
  {  
    digitalWrite(I1, LOW);//LOW
    digitalWrite(I2, HIGH);//HIGH
    digitalWrite(I3, LOW);//LOW
    digitalWrite(I4, HIGH);//HIGH
    
    //Turn 90 degree
      m1=100;//120
      m2=0;//150
      analogWrite(E1, m1); // Run in m1 Speed
      analogWrite(E2, m2); // Run in m2 speed
      delay(2200);
    
    //Go circular
    temp=1;
    while( (digitalRead(leftIR)==0 && digitalRead(leftIR)==0)|| temp==1 )
    {//Go left
      m1=110;//110
      m2=150;//150
      analogWrite(E1, m1); // Run in m1 Speed
      analogWrite(E2, m2); // Run in m2 speed
      delay(50);
      temp=0;
    }
    //Turn 90 degree
      m1=100;//120
      m2=0;//150
      analogWrite(E1, m1); // Run in m1 Speed
      analogWrite(E2, m2); // Run in m2 speed
      delay(2300);
      
  }
   
    m1=160;
    m2=165;
  analogWrite(E1, m1); // Run in m1 Speed
  analogWrite(E2, m2); // Run in m2 speed
}
