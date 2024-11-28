#define SensorA 34

void setup() {
  pinMode(SensorA, INPUT);

  Serial.begin(9600);

}

void loop() {
  if (analogRead(SensorA) > 3400) {
    Serial.println("Sem Chuva, varal para fora.");
    Serial.println(analogRead(SensorA));
    delay(1000);
  }
  else{
    Serial.println("Está Chovendo, varal para dentro.");
    Serial.println(analogRead(SensorA));
    delay(1000);
  }

}
