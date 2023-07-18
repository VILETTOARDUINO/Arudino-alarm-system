boolean Go;

#define Micro A0 //Аналоговый сигнал микрофона 
#define button 2 // Цифровой сигнал кнопки выключения
#define zymm 4 // Цифровой сигнал зуммера(пищалки)
#define light 3 // Цифровой сигнал светодиода

 
 void setup() {
  Serial.begin(9600);    
  pinMode(Micro, INPUT);
  pinMode(button, INPUT);
  pinMode(light, OUTPUT);
  pinMode(zymm, OUTPUT);
  Go = false;
}

void loop() {
  Serial.print(analogRead(A0));
  Serial.print("\t");
  Serial.println(digitalRead(2));
  delay(100);
  if (analogRead(Micro) > 29) {
    Go = !Go;
    while (Go == true) {
      digitalWrite(light, HIGH);
      tone(zymm, 1000);
      delay(500);
      digitalWrite(light, LOW);
      noTone(zymm);
      if (digitalRead(button) == 1) {
        Go = !Go;
      }
      delay(500);
    }
  }
}
