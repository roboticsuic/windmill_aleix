const int switchPin1 = 2;
const int switchPin2 = 4;
const int motorPin = 9; 
int switchState1 = 0;
int switchState2 = 0;
int pinLedR=13; //LED RED
int pinLedG=12; //LED BLUE
int pinLedB=11; //LED GREEN
int motorDirection = 0;
int pause = 1000;
void setup() {
  Serial.begin (9600);// inicializa el puerto seria a 9600 baudios
  pinMode(motorPin, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(pinLedR, OUTPUT);
  pinMode(pinLedG, OUTPUT);
  pinMode(pinLedB, OUTPUT);
}

void loop() {
  //digitalWrite(pinLedR, LOW); //blue
  //digitalWrite(pinLedG, HIGH); 
  //digitalWrite(pinLedB, LOW); 
  //delay (pause); 
  switchState1 = digitalRead(switchPin1);
  if (switchState1 == HIGH) {
    digitalWrite(motorPin, HIGH);
    Serial.println("Red button just pressed");          
    motorDirection = !motorDirection;
    digitalWrite(pinLedR, HIGH); //red
    digitalWrite(pinLedG, LOW); 
  	digitalWrite(pinLedB, LOW); 
  	delay (pause); 
  }
  else {
    digitalWrite(motorPin, LOW);
    digitalWrite(pinLedR, LOW); //white
    digitalWrite(pinLedG, LOW); 
    digitalWrite(pinLedB, LOW); 
    //delay (pause);
  }
  switchState2 = digitalRead(switchPin2);
  if (switchState2 == HIGH) {
    digitalWrite(motorPin, HIGH);
    Serial.println("Green button just pressed");
    digitalWrite(pinLedR, LOW); //green
    digitalWrite(pinLedG, LOW); 
    digitalWrite(pinLedB, HIGH); 
    delay (pause); 
  }
  else {
    digitalWrite(motorPin, LOW);
    digitalWrite(pinLedR, LOW); //white
    digitalWrite(pinLedG, LOW); 
    digitalWrite(pinLedB, LOW); 
    //delay (pause);
  }
  //Security system
  switchState1 = digitalRead(switchPin1); 
  switchState2 = digitalRead(switchPin2);
  if (switchState1 == HIGH && switchState2 == HIGH){
    Serial.println("Becareful, press just one button");
    digitalWrite(motorPin, LOW);
    digitalWrite(pinLedR, LOW); //white
    digitalWrite(pinLedG, LOW); 
    digitalWrite(pinLedB, LOW);
  }
}

//void motorclockwise(){
  //digitalWrite(10,HIGH);
  //digitalWrite(8,LOW);
//}
//void motoranticlockwise(){
  //digitalWrite(10,LOW);
  //digitalWrite(8,HIGH);
//}
