/*------ Arduino Line Fol0er Code----- */
/*-------definning Inputs------*/
#define LS 12      // left sensor
#define RS 11      // right sensor

/*-------definning Outputs------*/
#define AIA 4       // right motor
#define AIB 5       // right motor
#define BIA 2       // left motor
#define BIB 3       // left motor

int speed = 100;

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
}

void loop()
{
  if (!(analogRead(LS) && analogRead(RS)))     // Move Forward
  {
   forward();
  }
  
  if (!(analogRead(LS)) && analogRead(RS))     // Turn left
  {
   left();
  }
  
  if (analogRead(LS) && !(analogRead(RS)))     // turn right
  {
   right();
  }
  
  if (analogRead(LS) && analogRead(RS))     // stop
  {
   stop();
  }
}

void stop()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}

void backward()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}

void forward()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}

void left()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}

void right()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed); 
}
