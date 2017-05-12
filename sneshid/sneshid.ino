#include <Joystick.h>

#define P1_CLK (10)
#define P1_DATA1 (8)
#define P1_DATA2 (9)
#define P1_IO (4)

#define P2_CLK (16)
#define P2_DATA1 (6)
#define P2_DATA2 (7)
#define P2_IO (5)

#define P12_LATCH (14)

Joystick_ joystick[2] = {
  Joystick_(0x03, JOYSTICK_TYPE_GAMEPAD, 12, 0, false, false, false, false, false, false, false, false, false, false, false),
  Joystick_(0x04, JOYSTICK_TYPE_GAMEPAD, 12, 0, false, false, false, false, false, false, false, false, false, false, false)
};

void setup() {
  joystick[0].begin();
  joystick[1].begin();
  
  pinMode(P1_CLK, OUTPUT);
  pinMode(P1_DATA1, INPUT_PULLUP);
  pinMode(P1_DATA2, INPUT_PULLUP);
  pinMode(P1_IO, INPUT_PULLUP);
  digitalWrite(P1_CLK, LOW);

  pinMode(P2_CLK, OUTPUT);
  pinMode(P2_DATA1, INPUT_PULLUP);
  pinMode(P2_DATA2, INPUT_PULLUP);
  pinMode(P2_IO, INPUT_PULLUP);
  digitalWrite(P2_CLK, LOW);

  pinMode(P12_LATCH, OUTPUT);
}

void pulseWrite(int port)
{
  digitalWrite(port, HIGH);
  digitalWrite(port, LOW);
}

void pulseWrite(int port, int port2)
{
  digitalWrite(port, HIGH);
  digitalWrite(port2, HIGH);
  digitalWrite(port, LOW);
  digitalWrite(port2, LOW);
}

void pulseWrite(int port, int port2, int port3)
{
  digitalWrite(port, HIGH);
  digitalWrite(port2, HIGH);
  digitalWrite(port3, HIGH);
  digitalWrite(port, LOW);
  digitalWrite(port2, LOW);
  digitalWrite(port3, LOW);
}

void joyWrite(int num, int btn, int digital)
{
  if (!digital) {
    joystick[num].pressButton(btn);
  }else{
    joystick[num].releaseButton(btn);
  }
}

void loop() {
  int i;

  pulseWrite(P12_LATCH, P1_CLK, P2_CLK);
  joyWrite(0, 0, digitalRead(P1_DATA1));
  joyWrite(1, 0, digitalRead(P2_DATA1));

  for (i = 1; i < 16; i++) {
    pulseWrite(P1_CLK);
    pulseWrite(P2_CLK);

    joyWrite(0, i, digitalRead(P1_DATA1));
    joyWrite(1, i, digitalRead(P2_DATA1));
  }

  delay(10);
}
