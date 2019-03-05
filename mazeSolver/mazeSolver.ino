#define IRS 13      // Senzor infra-rosu

#define ldsTrig 6       // OUT - Senzor distanta stanga
#define ldsEcho 7       // IN - Senzor distanta stanga

#define rdsTrig 8        // OUT - Senzor distanta dreapta
#define rdsEcho 9        // IN - Senzor distanta dreapta

#define fdsTrig 10       // OUT - Senzor distanta fata
#define fdsEcho 11       // IN - Senzor distanta fata

#define LM1 4       // Motor stanga
#define LM2 5       // Motor stanga
#define RM1 2       // Motor dreapta
#define RM2 3       // Motor dreapta


//Variabilele pentru senzorii de distanta
int Lduration;
int Ldistance;

int Rduration;
int Rdistance;

int Fduration;
int Fdistance;


void setup()
{
  pinMode(IRS, INPUT);       // Receptioneaza semnal infra-rosu
  
  pinMode(ldsTrig, OUTPUT);       // Trimite semnal distanta stanga
  pinMode(ldsEcho, INPUT);        // Receptioneaza semnal distanta

  pinMode(rdsTrig, OUTPUT);
  pinMode(rdsEcho, INPUT);

  pinMode(fdsTrig, OUTPUT);
  pinMode(fdsEcho, INPUT);
  
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  Serial.begin(9600);       // Porneste comunicarea Arduino->Consola PC
}


void loop()
{
  // Daca senzorul infra-rosu returneaza valoarea 0 => Senzorul este pe negru
  // Daca senzorul infra-rosu returneaza valoarea 1 => Senzorul este pe alb
  
  if(!(digitalRead(IRS)))       // Verifica daca robotul a ajuns la finish
  {
  // Initializeaza functiile pentru calculul distantei
  leftDistance();
  rightDistance();
  forwardDistance();

  // Rezolvarea labirintului
  if (Fdistance > 10 && Ldistance <=10 && Rdistance <=10)
  {
    forward();

  } else if (Fdistance <=10 && Ldistance >10 && Rdistance <=10) 
  {
    left();

  } else if (Fdistance <=10 && Ldistance <=10 && Rdistance >10)
  {
    right();
  
  } else if (Fdistance >10 && Ldistance >10 && Rdistance >10)
  {
    left();

  } else if (Fdistance <=10 && Ldistance <=10 && Rdistance <=10)
  {
    fullLeft();
  }


  } else { stopNow(); }       // Robotul a ajuns la finish
  
}       // Final LOOP


// Calcul distante
void leftDistance()       // Calculul distantei - Stanga
{
  digitalWrite(ldsTrig, LOW);       // Ne asiguram ca senzorul nu este deja pornit
  delayMicroseconds(2);

  digitalWrite(ldsTrig, HIGH);       // Trimite semnal
  delayMicroseconds(10);
  digitalWrite(ldsTrig, LOW);

  Lduration = pulseIn(ldsEcho, HIGH);

  Ldistance = Lduration * 0.034 / 2;        // Formula pentru distanta in centimetri

  Serial.print("Ldistance: ");       // Afiseaza in consola valorile date de senzor
  Serial.println(Ldistance);
}

void rightDistance()       // Calculul distantei - Dreapta
{
  digitalWrite(rdsTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(rdsTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(rdsTrig, LOW);


  Rduration = pulseIn(rdsEcho, HIGH);

  Rdistance = Rduration * 0.034 / 2;

  Serial.print("Rdistance: ");
  Serial.println(Rdistance);
}

void forwardDistance()       // Calculul distantei - Inainte
{
  digitalWrite(fdsTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(fdsTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(fdsTrig, LOW);


  Fduration = pulseIn(fdsEcho, HIGH);

  Fdistance = Fduration * 0.034 / 2;

  Serial.print("Fdistance: ");
  Serial.println(Fdistance);
}


// Miscarile robotului
void forward()
{
   digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
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
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

void fullLeft()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

void fullRight()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void stopNow()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
