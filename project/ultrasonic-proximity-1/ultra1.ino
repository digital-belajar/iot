// Perangkat check jarak menggunakan ultrasound
// source: https://www.tinkercad.com/things/04XsHlKEBCE-copy-of-ultrasound-/editel?tenant=circuits

int batas=0; // dalam centimeter
int cm=0;
const int TRIGGER = 7;
const int ECHO = 6;

long bacaJarak() {
    // matikan ultrasound
    digitalWrite(TRIGGER, LOW);
    delayMicroseconds(2);
    
    // aktifkan ultrasound
    digitalWrite(TRIGGER,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER,LOW);
    
    long pulse=pulseIn(ECHO,HIGH);
    Serial.print(pulse);
    Serial.println("microseconds");

    return pulse;  
}

void setup() {
    Serial.begin(9600);
    pinMode(TRIGGER,OUTPUT);
    pinMode(ECHO,INPUT);

    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
}

void loop() {
    batas=300;
    cm=0.01715*bacaJarak(TRIGGER,ECHO);

    Serial.print(cm);
    Serial.print("cm, ");

    if(cm>batas) {
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);     
    }
    if(cm<=batas&&cm>10) {
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
    }
    if(cm<=batas&&cm>20) {
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
    }
    if(cm<=batas&&cm>35) {
        digitalWrite(2,HIGH);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
    }   
    delay(100);
}