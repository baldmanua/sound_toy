#include <Arduino.h>

#include "GyverEncoder.h"
#include "GyverButton.h"
#include "HID-Project.h"

Encoder enc1(9, 8, 7);

GButton play_pause_but(A1);
GButton next_but(A0);
GButton prev_but(A2);

void setup() {
  enc1.setType(TYPE2);
  Consumer.begin();
  pinMode(0, OUTPUT);
  digitalWrite(0,HIGH);
}

void loop() {
  enc1.tick();
  play_pause_but.tick();
  next_but.tick();
  prev_but.tick();

  if (enc1.isRight()) {
    Consumer.write(MEDIA_VOLUME_DOWN);
    Consumer.write(MEDIA_VOLUME_DOWN);
  }
  if (enc1.isLeft()) {
    Consumer.write(MEDIA_VOLUME_UP);
    Consumer.write(MEDIA_VOLUME_UP);
  }

  if (enc1.isClick()) {
    Consumer.write(MEDIA_VOLUME_MUTE);
  }

  if (play_pause_but.isClick()) {
    Consumer.write(MEDIA_PLAY_PAUSE);
  }

  if (next_but.isClick()) {
    Consumer.write(MEDIA_NEXT);
  }

  if (prev_but.isClick()) {
    Consumer.write(MEDIA_PREV);
  }

}
