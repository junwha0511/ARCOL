#include<Servo.h>??
#define TRIG 10?
#define ECHO 9
Servo servo;
int m=1;?
int M=179;?
int pos=M;?
int a=1;
void setup() {
? pinMode(TRIG,OUTPUT);
? pinMode(ECHO,INPUT);
? Serial.begin(9600);
? servo.attach(11);?
}
void loop() {
??? servo.write(pos);
? Serial.print(pos);
? Serial.print(",");
? Serial.print(distancee());
? Serial.print(".");?
? pos=pos-a;
? if(pos<=m||pos>=M) {
? a*=-1;?
? }
? delay(25);
}
unsigned long distancee(){?
? unsigned long distance;?
? digitalWrite(TRIG, HIGH);?
? delayMicroseconds(10);?
? digitalWrite(TRIG, LOW);?
? distance = pulseIn(ECHO, HIGH)/58.2;?
? return distance;
}
?