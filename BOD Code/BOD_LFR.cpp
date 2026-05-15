// Line Following Car - 6 IR Sensor Array - 2WD
// Motor1 = Left wheel (port 1)
// Motor2 = Right wheel (port 2)

#include <AFMotor.h>

// 6 IR sensor pins (S1 = leftmost, S6 = rightmost)
#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3
#define S5 A4
#define S6 A5

#define THRESHOLD   350   // below = line detected
#define BASE_SPEED  140   // full speed
#define TURN_SPEED  110   // inner wheel gentle curve
#define SHARP_SPEED  70   // inner wheel sharp turn (can also BACKWARD)

// 2WD: only two motors
AF_DCMotor motorL(1, MOTOR12_1KHZ);  // Left  wheel
AF_DCMotor motorR(2, MOTOR12_1KHZ);  // Right wheel

// ─── helpers ────────────────────────────────────────────────────────────────

bool sensorRead(uint8_t pin) {
  return analogRead(pin) <= THRESHOLD;  // true = line detected
}

void setMotors(int leftSpeed, uint8_t leftDir,
               int rightSpeed, uint8_t rightDir) {
  motorL.setSpeed(leftSpeed);
  motorL.run(leftDir);
  motorR.setSpeed(rightSpeed);
  motorR.run(rightDir);
}

void goForward()  { setMotors(BASE_SPEED,  FORWARD,  BASE_SPEED,  FORWARD);  }
void stopCar()    { motorL.run(RELEASE);   motorR.run(RELEASE);               }

// Gentle curve: slow down the inner wheel
void curveLeft()  { setMotors(TURN_SPEED,  FORWARD, BASE_SPEED,  FORWARD); }
void curveRight() { setMotors(BASE_SPEED,  FORWARD, TURN_SPEED,  FORWARD); }

// Sharp turn: reverse the inner wheel
void sharpLeft()  { setMotors(SHARP_SPEED, BACKWARD, BASE_SPEED,  FORWARD); }
void sharpRight() { setMotors(BASE_SPEED,  FORWARD,  SHARP_SPEED, BACKWARD); }

// ─── setup ──────────────────────────────────────────────────────────────────

void setup() {
  pinMode(S1, INPUT); pinMode(S2, INPUT);
  pinMode(S3, INPUT); pinMode(S4, INPUT);
  pinMode(S5, INPUT); pinMode(S6, INPUT);
  Serial.begin(9600);
}

// ─── main loop ──────────────────────────────────────────────────────────────

void loop() {
  bool s1 = sensorRead(S1), s2 = sensorRead(S2), s3 = sensorRead(S3);
  bool s4 = sensorRead(S4), s5 = sensorRead(S5), s6 = sensorRead(S6);

  // Debug
  Serial.print(s1); Serial.print(s2); Serial.print(s3);
  Serial.print(s4); Serial.print(s5); Serial.println(s6);

  // Weighted position: negative = line is left, positive = line is right
  int weights[6]  = {-3, -2, -1, 1, 2, 3};
  bool sensors[6] = { s1,  s2,  s3, s4, s5, s6};

  int activeCount = 0, weightSum = 0;
  for (int i = 0; i < 6; i++) {
    if (sensors[i]) { activeCount++; weightSum += weights[i]; }
  }

  // No sensor: lost line → stop
  if (activeCount == 0) { stopCar(); return; }

  // All sensors: junction or end marker → stop
  if (activeCount == 6) { stopCar(); return; }

  float position = (float)weightSum / activeCount;

  if      (position <= -2.5) sharpLeft();
  else if (position <= -0.5) curveLeft();
  else if (position >=  2.5) sharpRight();
  else if (position >=  0.5) curveRight();
  else                       goForward();
}