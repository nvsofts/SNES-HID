#include <Joystick.h>

//RodentVienna-removed DATA2 and IO

#define P1_CLK (2) //actually used
#define P1_DATA1 (3) //actually used

#define P2_CLK (6) //actually used
#define P2_DATA1 (7) //actually used

#define P3_CLK (10) //actually used
#define P3_DATA1 (16) //actually used

#define P4_CLK (18) //actually used
#define P4_DATA1 (19) //actually used

#define P1234_LATCH (1) //actually used

Joystick_ joystick[4] = {
  Joystick_(0x03, JOYSTICK_TYPE_GAMEPAD, 12, 0, false, false, false, false, false, false, false, false, false, false, false),
  Joystick_(0x04, JOYSTICK_TYPE_GAMEPAD, 12, 0, false, false, false, false, false, false, false, false, false, false, false),
  Joystick_(0x05, JOYSTICK_TYPE_GAMEPAD, 12, 0, false, false, false, false, false, false, false, false, false, false, false),
  Joystick_(0x06, JOYSTICK_TYPE_GAMEPAD, 12, 0, false, false, false, false, false, false, false, false, false, false, false)
};

void setup() {
  joystick[0].begin();
  joystick[1].begin();
  joystick[2].begin();
  joystick[3].begin(); 
  
  pinMode(P1_CLK, OUTPUT);
  pinMode(P1_DATA1, INPUT_PULLUP);
  digitalWrite(P1_CLK, LOW);

  pinMode(P2_CLK, OUTPUT);
  pinMode(P2_DATA1, INPUT_PULLUP);
  digitalWrite(P2_CLK, LOW);

  pinMode(P3_CLK, OUTPUT);
  pinMode(P3_DATA1, INPUT_PULLUP);
  digitalWrite(P3_CLK, LOW);

  pinMode(P4_CLK, OUTPUT);
  pinMode(P4_DATA1, INPUT_PULLUP);
  digitalWrite(P4_CLK, LOW);
  
  pinMode(P1234_LATCH, OUTPUT);
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

void pulseWrite(int port, int port2, int port3, int port4)
{
  digitalWrite(port, HIGH);
  digitalWrite(port2, HIGH);
  digitalWrite(port3, HIGH);
  digitalWrite(port4, HIGH);
  digitalWrite(port, LOW);
  digitalWrite(port2, LOW);
  digitalWrite(port3, LOW);
  digitalWrite(port4, LOW);
}

void pulseWrite(int port, int port2, int port3, int port4, int port5)
{
  digitalWrite(port, HIGH);
  digitalWrite(port2, HIGH);
  digitalWrite(port3, HIGH);
  digitalWrite(port4, HIGH);
  digitalWrite(port5, HIGH);
  digitalWrite(port, LOW);
  digitalWrite(port2, LOW);
  digitalWrite(port3, LOW);
  digitalWrite(port4, LOW);
  digitalWrite(port5, LOW);
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

  pulseWrite(P1234_LATCH, P1_CLK, P2_CLK, P3_CLK, P4_CLK);
  joyWrite(0, 0, digitalRead(P1_DATA1));
  joyWrite(1, 0, digitalRead(P2_DATA1));
  joyWrite(2, 0, digitalRead(P3_DATA1));
  joyWrite(3, 0, digitalRead(P4_DATA1));
  
  for (i = 1; i < 16; i++) {
    pulseWrite(P1_CLK);
    pulseWrite(P2_CLK);
    pulseWrite(P3_CLK);
    pulseWrite(P4_CLK);
    
    joyWrite(0, i, digitalRead(P1_DATA1));
    joyWrite(1, i, digitalRead(P2_DATA1));
    joyWrite(2, i, digitalRead(P3_DATA1));
    joyWrite(3, i, digitalRead(P4_DATA1));
  }

  delay(10);
}
