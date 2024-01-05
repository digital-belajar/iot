# IR Proximity + Header File

Pada latihan ini kita akan belajar membuat file header pada project sederhana.
Project yang akan dibuat adalah sebagai berikut: _membuat IR Proximity yang akan membunyikan jingle setiap kali ada objek. Jingle ini akan dibuat pada file header._

Ikut langkah berikut:
1. Siapkan sirkuit yang terdiri dari Arduino
2. Copy text untuk file header dari link berikut: [pitches.h](https://gist.githubusercontent.com/mikeputnam/2820675/raw/bbe995aa22826a8fbbb6b56ccd56513f9db6cb00/pitches.h)
3. Di Arduino IDE, tekan: _Ctrl+Shirt+N_ untuk membuat file. Beri nama _pitches.h_.
4. Paste text (yang dicopy pada langkah 1)
5. Buat file baru lagi (seperti langkah 2). Beri nama _jingle.h_
6. Pada _jingle.h_ paste code berikut:

```cpp
#include "pitches.h"
void jingle1(int pin) {
    tone(pin, NOTE_G5);
    delay(500);
    tone(pin, NOTE_C5);
    delay(1000);
    noTone(pin);
}
```

6. Pada program utama (file _.ino_), copy-paste program berikut:
```cpp
#include "jingle.h"

int adabenda;
int pinPiezo = 13; //ESP32: 32; ESP8266: 5
int pinIr = 12; //ESP32: 33; ESP8266: 4

void setup() {
    pinMode(pinPiezo, OUTPUT);
    pinMode(pinIr, INPUT);
    Serial.begin(9600);
}

void loop() {
    adabenda = digitalRead(pinIr);
    Serial.println(adabenda);

    if(adabenda==LOW) {
        jingle1(pinPiezo);
    }
    delay(500);
}
```
7. Upload program.
