void setup(){
  pinMode(8, OUTPUT);
}

void loop(){
  if(analogRead(A0) < 1000) {
    tone(8,261,200);
    delay(10);
  }
  if(analogRead(A1) < 1000) { 
    tone(8,277,200);
    delay(10);
  }
  if(analogRead(A2) < 1000) {
    tone(8,294,200);
    delay(10);
  }
  if(analogRead(A3) < 1000) {
    tone(8,311,200);
    delay(10);
  }
  if(analogRead(A4) < 1000) { 
    tone(8,330,200);
    delay(10);
  }
  if(analogRead(A5) < 1000) {
    tone(8,349,200);
    delay(10);
    }
  }
