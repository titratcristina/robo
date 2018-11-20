#define LS 12      // Senzor infra-rosu stanga
#define RS 11      // Senzor infra-rosu dreapta

#define LDStrig 6       // OUT - Senzor distanta stanga
#define LDSecho 7       // IN - Senzor distanta stanga

/* Nu avem destui pini !!!
#define RDS 8       // Senzor distanga dreapta
#define FDS 9       // Senzor distanta frontal
*/

#define LM1 4       // Motor stanga
#define LM2 5       // Motor stanga
#define RM1 2       // Motor dreapta
#define RM2 3       // Motor dreapta

//Variabilele pentru senzorul de distanta din partea stanga (Am pus variabila globala ca sa fie direct 0 daca nu ia nicio valoare)
long Lduration;
int Ldistance;

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  
  pinMode(LDStrig, OUTPUT);       // Trimite semnal distanta
  pinMode(LDSecho, INPUT);        // Receptioneaza semnal distanta
  
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}



void loop()
{
  /*
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
  */
  
  if (Ldistance > 10 && Fdistance <= 10)        // Inca nu am setat Fdistance !!!
  {
    left();
  }
  
  
  
}

void leftDistance()       // Calculul distantei - Stanga
{
  digitalWrite(LDStrig, LOW);
  delayMicroseconds(2);

  digitalWrite(LDStrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(LDStrig, LOW);


  Lduration = pulseIn(LDSecho, HIGH);

  Ldistance = Lduration*0.034/2;        // Formula pentru distanta in centimetri
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
