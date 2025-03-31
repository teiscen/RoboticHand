#include "hand.h"
#include "gestures.h"

void setup() {
	pwm.begin();
	pwm.setPWMFreq(50); // Set frequency to 50Hz
}
  
int main(void){
	setup();
	
	Hand hand;
	hand.update(rock);
	hand.update(paper);
	hand.update(scissor);

	hand.update(come_closer);

	return 0;
}
