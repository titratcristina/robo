#define LS 12      // Senzor infra-rosu stanga
#define RS 11      // Senzor infra-rosu dreapta

#define LM2 5       // Motor stanga +
#define LM1 4       // Motor stanga -
#define RM1 2       // Motor dreapta +
#define RM2 3       // Motor dreapta -


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
  // Daca senzorul returneaza valoarea 0 => Senzorul este pe negru
  // Daca senzorul returneaza valoarea 1 => Senzorul este pe alb
  
  if(digitalRead(LS) && digitalRead(RS))     // Inainteaza (LS=0, RS=0)
  {
    forward();
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Viraj dreapta (LS=1, RS=0)
  {
    right();
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // Viraj stanga (LS=0, RS=1)
  {
    left();
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // Stop (LS=1, RS=1)
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
