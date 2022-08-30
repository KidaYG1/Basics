int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;
int Trig = 9;
int Echo = 10;

void setup() {
  // put your setup code here, to run once:

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode (Trig, OUTPUT);
  pinMode (Echo, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  forward();
  digitalWrite(Trig, HIGH);
  delay(120);
  digitalWrite(Trig, LOW);
  int period = pulseIn(Echo, HIGH);
  int distance = (period / 2) / 29.1;
  Serial.println(distance);

  if (distance <= 30) {
    backward ();
    delayMicroseconds(1500);
    right();
    delay(1500);
  }
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float timeduration = pulseIn(Echo, HIGH);
  float distance = (0.017 * timeduration);
  Serial.println(distance);
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stp() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

//float getDistance(){
// digitalWrite(trig, HIGH);
// delayMicroseconds(10);
// digitalWrite(trig, LOW);
// delayMicroseconds(10);
// float timeduration= pulseIn(echo, HIGH);
// float distance = 0.017 * time duration
// return distance;
//
