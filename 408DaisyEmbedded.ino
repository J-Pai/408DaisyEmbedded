#include <Daisy.h>

Daisy daisy;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 400; i++) {
    daisy.forward(100);
    delay(1);
  }
  for (int i = 0; i < 400; i++) {
    daisy.backward(100);
    delay(1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

};
