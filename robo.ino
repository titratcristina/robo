// DE INLOCUIT PE PLACUTA LS 12 cu 13 si RS 11 cu 12 !!!

#define IRS 13      // Senzor infra-rosu

#define LDStrig 6       // OUT - Senzor distanta stanga
#define LDSecho 7       // IN - Senzor distanta stanga

#define RDStrig 8        // OUT - Senzor distanta dreapta
#define RDSecho 9        // IN - Senzor distanta dreapta

#define FDStrig 10       // OUT - Senzor distanta fata
#define FDSecho 11       // IN - Senzor distanta fata

/* Nu avem destui pini !!!
#define RDS 8       // Senzor distanga dreapta
#define FDS 9       // Senzor distanta frontal
*/

#define LM1 4       // Motor stanga
#define LM2 5       // Motor stanga
#define RM1 2       // Motor dreapta
#define RM2 3       // Motor dreapta

//Variabilele pentru senzorul de distanta din partea stanga (Am pus variabila globala ca sa fie direct 0 daca nu ia nicio valoare)
int Lduration;
int Ldistance;

int Rduration;
int Rdistance;

int Fduration;
int Fdistance;

void setup()
{
  pinMode(IRS, INPUT);
  
  pinMode(LDStrig, OUTPUT);       // Trimite semnal distanta
  pinMode(LDSecho, INPUT);        // Receptioneaza semnal distanta

  pinMode(RDStrig, OUTPUT);       // Trimite semnal distanta
  pinMode(RDSecho, INPUT);

  pinMode(FDStrig, OUTPUT);       // Trimite semnal distanta
  pinMode(FDSecho, INPUT);
  
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  Serial.begin(9600);

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
  leftDistance();
  rightDistance();
  forwardDistance();

  if (Fdistance > 10)
  {
    forward();
  }
  
  else if (Ldistance <= 3)
  {
    right();
  } 

  else if (Rdistance <= 3)
  {
    left();
  } 
  
  else 
  {
    stopNow();
  }
  
  
}

void leftDistance()       // Calculul distantei - Stanga
{
  digitalWrite(LDStrig, LOW);
  delayMicroseconds(20);

  digitalWrite(LDStrig, HIGH);
  delayMicroseconds(100);
  digitalWrite(LDStrig, LOW);


  Lduration = pulseIn(LDSecho, HIGH);

  Ldistance = Lduration * 0.034 / 2;        // Formula pentru distanta in centimetri
  Serial.print("Ldistance ");
  Serial.println(Ldistance);
}

void rightDistance()       // Calculul distantei - Dreapta
{
  digitalWrite(RDStrig, LOW);
  delayMicroseconds(20);

  digitalWrite(RDStrig, HIGH);
  delayMicroseconds(100);
  digitalWrite(RDStrig, LOW);


  Rduration = pulseIn(RDSecho, HIGH);

  Rdistance = Rduration * 0.034 / 2;        // Formula pentru distanta in centimetri
  Serial.print("Rdistance ");
  Serial.println(Rdistance);
}

void forwardDistance()       // Calculul distantei - Inainte
{
  digitalWrite(FDStrig, LOW);
  delayMicroseconds(20);

  digitalWrite(FDStrig, HIGH);
  delayMicroseconds(100);
  digitalWrite(FDStrig, LOW);


  Fduration = pulseIn(FDSecho, HIGH);

  Fdistance = Fduration * 0.034 / 2;        // Formula pentru distanta in centimetri
  Serial.print("Fdistance ");
  Serial.println(Fdistance);
}


void forward()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

void right()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void left()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
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
