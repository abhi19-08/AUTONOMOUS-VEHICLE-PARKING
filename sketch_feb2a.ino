// -------- Motor Pins --------
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5
#define ENB 6

int speedVal = 85;   // Half speed (0–255)

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  delay(2000);  // Start delay
}

void loop() {

  // Forward
  forward();
  delay(3000);

  stopMotors();
  delay(500);

  // Left 90°
  left();
  delay(700);   // Adjust for exact 90°

  stopMotors();
  delay(500);

  // Forward again
  forward();
  delay(2000);

  stopMotors();
  delay(500);

  // Right 90°
  right();
  delay(700);   // Adjust if needed

  stopMotors();

  while(1);
}

// -------- Movement Functions --------

void forward() {
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left() {
 analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);

  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() {
 analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);

  // Left motor backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
