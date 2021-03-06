
# define LMF 2 // Motor stanga inainte
# define LMB 3 // Motor stanga inapoi
# define RMB 4 // Motor dreapta inapoi
# define RMF 5 // Motor dreapta inainte

# define ldsTrig 6 // OUT - Senzor distanta stanga
# define ldsEcho 7 // IN - Senzor distanta stanga
# define rdsTrig 8 // OUT - Senzor distanta dreapta
# define rdsEcho 9 // IN - Senzor distanta dreapta
# define fdsTrig 10 // OUT - Senzor distanta fata
# define fdsEcho 11 // IN - Senzor distanta fata

# define IRS 13 // Senzor infra-rosu

//Variabilele pentru senzorii de distanta
int Ldistance;
int Rdistance;
int Fdistance;

int direction; // Variabila pentru alegerea directie de baza (RANDOM)

void setup() {
  pinMode(IRS, INPUT); // Receptioneaza semnal infra-rosu

  pinMode(ldsTrig, OUTPUT); // Trimite semnal distanta stanga
  pinMode(ldsEcho, INPUT); // Receptioneaza semnal distanta

  pinMode(rdsTrig, OUTPUT);
  pinMode(rdsEcho, INPUT);

  pinMode(fdsTrig, OUTPUT);
  pinMode(fdsEcho, INPUT);

  pinMode(RMB, OUTPUT);
  pinMode(RMF, OUTPUT);
  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);

  direction = rand() % 2; // Alegerea unui numar pentru directia de baza in mod aleator (0 sau 1)

  Serial.begin(9600); // Porneste comunicarea Arduino->consola PC
}

void loop() {
  // Senzorul IR returneaza 0 => negru (sfarsit)

  // Initializeaza functiile pentru calculul distantei
  leftDistance();
  //rightDistance();
  forwardDistance();
  Serial.println("");

  //if(digitalRead(IRS) == 0)     // Verifica daca robotul a ajuns la sfarsit
  //{ stopNow(); }
  //else
  //{

    
    if(Ldistance > 5 && Fdistance > 5)
    goLeft();
    
    else
    turnRight();
    //}
    
  
  

} // Final LOOP

// --------------------------------------------------------- Calcul distante
void leftDistance() // Calculul distantei - Stanga
{
  digitalWrite(ldsTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(ldsTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ldsTrig, LOW);

  int Lduration = pulseIn(ldsEcho, HIGH);
  Ldistance = Lduration * 0.034 / 2;

  Serial.print("Ldistance: ");
  Serial.println(Ldistance);
}


void rightDistance() // Calculul distantei - Dreapta
{
  digitalWrite(rdsTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(rdsTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(rdsTrig, LOW);

  int Rduration = pulseIn(rdsEcho, HIGH);
  Rdistance = Rduration * 0.034 / 2;

  Serial.print("Rdistance: ");
  Serial.println(Rdistance);
}

void forwardDistance() // Calculul distantei - Inainte
{
  digitalWrite(fdsTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(fdsTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(fdsTrig, LOW);

  int Fduration = pulseIn(fdsEcho, HIGH);
  Fdistance = Fduration * 0.034 / 2;

  Serial.print("Fdistance: ");
  Serial.println(Fdistance);
}


void goForward() { // ----------------------------------- Miscarile robotului
  digitalWrite(RMF, HIGH);
  digitalWrite(LMF, HIGH);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, LOW);
}

void goRight() {
  digitalWrite(RMF, LOW);
  digitalWrite(LMF, HIGH);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, LOW);
}

void goLeft() {
  digitalWrite(RMF, HIGH);
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, LOW);
}

void turnRight() {
  digitalWrite(RMF, LOW);
  digitalWrite(LMF, HIGH);
  digitalWrite(RMB, HIGH);
  digitalWrite(LMB, LOW);
}

void turnLeft() {
  digitalWrite(RMF, HIGH);
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, HIGH);
}

void stopNow() {
  digitalWrite(RMF, LOW);
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, LOW);
}

