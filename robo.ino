/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LS 12      // left sensor
#define RS 11      // right sensor

/*-------definning Outputs------*/
#define LM1 4       // left motor
#define LM2 5       // left motor
#define RM1 2       // right motor
#define RM2 3       // right motor

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop()
{
  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
    right();
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
    left();
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
   stopNow();
  }
}

void forward()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void right()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void left()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void stopNow()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

