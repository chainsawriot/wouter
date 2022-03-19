int switchstate = 0;
int cur_epoch = 0;
int bluestate = 0;

const int y1 = 3;
const int y2 = 4;
const int y3 = 5;
const int y4 = 6;
const int y5 = 7;
const int y6 = 8;
const int r1 = 9;
const int b1 = 10;

const int buzz1 = 12;

void setup() {
    // yellow LEDs
    pinMode(y1, OUTPUT);
    pinMode(y2, OUTPUT);
    pinMode(y3, OUTPUT);
    pinMode(y4, OUTPUT);
    pinMode(y5, OUTPUT);
    pinMode(y6, OUTPUT);

    // red
    pinMode(r1, OUTPUT);
    // blue
    pinMode(b1, OUTPUT);
    // buzzer
    pinMode(buzz1, OUTPUT);
    //switch
    pinMode(2, INPUT);
    pinMode(13, INPUT);
}

const int delay_ms = 1000;
const int max_epoch = 420;

void blink (int b1 = 10, int times = 4, int delay_ms = 1000) {
    for (int i = 0; i < times; i++) {
	int bluestate = digitalRead(b1);
	if (bluestate == HIGH) {
	    digitalWrite(b1, LOW);
	} else {
	    digitalWrite(b1, HIGH);
	}
	delay(delay_ms / times);
    }
}

void loop() {
    switchstate = digitalRead(2);
    cur_epoch = 0;
    if (switchstate == LOW) {
	digitalWrite(r1, HIGH);
	digitalWrite(b1, LOW);
	digitalWrite(y1, LOW);
	digitalWrite(y2, LOW);
	digitalWrite(y3, LOW);
	digitalWrite(y4, LOW);
	digitalWrite(y5, LOW);
	digitalWrite(y6, LOW);
    } else {
	digitalWrite(r1, LOW);
	digitalWrite(b1, LOW);
	digitalWrite(y1, HIGH);
	digitalWrite(y2, HIGH);
	digitalWrite(y3, HIGH);
	digitalWrite(y4, HIGH);
	digitalWrite(y5, HIGH);
	digitalWrite(y6, HIGH);
	while(cur_epoch <= max_epoch) {
	    blink(b1, 16, delay_ms);
	    int remain = (max_epoch - cur_epoch) / 60;
	    if (remain == 5) {
		digitalWrite(y1, LOW);
	    }
	    if (remain == 4) {
		digitalWrite(y2, LOW);
	    }
	    if (remain == 3) {
		digitalWrite(y3, LOW);
	    }
	    if (remain == 2) {
		digitalWrite(y4, LOW);
	    }
	    if (remain == 1) {
		digitalWrite(y5, LOW);
	    }
	    if (remain == 0) {
		digitalWrite(y6, LOW);
	    }
	    cur_epoch = cur_epoch + 1;
	}
	/* end game */
	tone(buzz1, 1000, 1000);
	digitalWrite(r1, HIGH);
	digitalWrite(b1, LOW);
	
    }
}
