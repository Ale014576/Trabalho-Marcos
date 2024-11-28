/* const int motIn1 = 5;
const int motIn2 = 2; 

void setup() {
  pinMode(motIn1, OUTPUT);
  pinMode(motIn2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(motIn1, 1);
  delay(2000);
  digitalWrite(motIn1, 0);
  digitalWrite(motIn2, 1);
  delay(2000);
  digitalWrite(motIn2, 0);
  
} */
//------------------------------------------------------------------//

const int motIn1 = 5;
const int motIn2 = 2; 

void setup() {
  pinMode(motIn1, OUTPUT);
  pinMode(motIn2, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(motIn1, HIGH);
  digitalWrite(motIn2, LOW);
  delay(2000);  


  digitalWrite(motIn1, LOW);
  digitalWrite(motIn2, LOW);
  delay(1000);  
  
  digitalWrite(motIn1, LOW);
  digitalWrite(motIn2, HIGH);
  delay(2000);
  
  digitalWrite(motIn1, LOW);
  digitalWrite(motIn2, LOW);
  delay(1000); 
} 
