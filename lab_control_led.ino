int sensorPin = A0;
int led = 8;
int sensorValue = 0;

int statusLed = 2;

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  sensorValue = analogRead(sensorPin); // 0 -> 1023
  
  while (Serial.available() > 0) {
    statusLed = Serial.parseInt();
  }
  
  switch(statusLed){
   case 0:
     digitalWrite(led, LOW);
     break;
   case 1:
     digitalWrite(led, HIGH);
     break;
   default:
     senzorLumina();
     break;
   }
   
  delay(200); // 500 ms => 0.5s
}

void senzorLumina(){
  if(sensorValue < 100){
    digitalWrite(led, HIGH); // 1 logic, 5V electric
  }else{
    digitalWrite(led, LOW); // 0 logic, 0V electric
  }
}
