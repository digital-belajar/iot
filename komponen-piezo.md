# Komponen: Piezo

Piezo speaker adalah speaker sederhana yang bisa digunakan untuk mengeluarkan suara dengan frekuensi tertentu.

Piezo memiliki 2 kaki:
1. Kaki + : untuk dihubungkan dengan pin OUTPUT
2. Kaki - : untuk dihubungkan ke GND

Contoh:
![](../res/piezo.png)

Tambahkan kode berikut dan coba pelajari:

```cpp
// pin output piezo
int pinPiezo = 8;

void setup() {
    pinMode(pinPiezo,OUTPUT);
}

void loop() {  	
    tone(pinPiezo,400);
    delay(1000);
    tone(pinPiezo,700);
    delay(1000);         
}
```

## FAQ

### Error: _tone was not declared in this scope_

Jika Anda menggunakan ESP32, untuk beberapa kondisi, Anda mungkin akan menemukan error  _tone was not declared in this scope_ ketika program di-_compile_. Untuk mengatasi itu, tambahkan kode ini pada file coding program Anda (contoh: Anda bisa menambahkan coding ini ke bagian sebelum `void setup()`).

```cpp
int playing = 0;
void tone(byte pin, int freq) {
  ledcSetup(0, 2000, 8); // setup beeper
  ledcAttachPin(pin, 0); // attach beeper
  ledcWriteTone(0, freq); // play tone
  playing = pin; // store pin
}
void noTone() {
  tone(playing, 0);
}
```