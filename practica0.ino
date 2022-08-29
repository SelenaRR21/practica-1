//Arduino nano

const int bomba = 13; //Nivel al pin D13
const int nivel = 9; //Medir nivel de agua pin D9

void setup ()
{
  serial.begin(9600);
  pinMode(bomba,OUTPUT);
  pinMode(nivel, INPUT);
}

void loop ()
{
  int SensorNivel = digitalRead (nivel); //leemos lo que marca el nivel
  if (SensorNivel==1)
  {
    Serial.println("Nivel de agua correcto, se puede regar");
    digitalWrite(bomba, HIGH);
    delay(1000);
    digitalWrite(bomba,LOW);
    delay(500);
  }
  if (SensorNivel==0)
  {
   Serial.println("Nivel bajo de Agua, Rellenar el tanque");
   delay(1000);
  }
}

// Sensor de Luz LDR ¿?

int ledPin = 9; //Piezo en Pin 8
int ldrPin = 0; //LDR en el pin analogico 0

int ldrValue = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  Serial.print(ldrValue);
  if(ldrValue >= 1010){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(500);
}
