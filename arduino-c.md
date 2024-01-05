# Arduino C

Kode yang dimasukan ke dalam Arduino ditulis dalam bahasa C. Untuk keperluan coding Arduino, kita bisa menggunakan Arduino IDE. Sofware ini bisa di download secara gratis di [www.arduino.cc](https://www.arduino.cc/en/software).

## Struktur Program

```
// deklarasi header yang akan digunakan
#include<Arduino.h>

// deklarasi variabel dan objek global


// deklarasi fungsi


// tahap persiapan
// void setup hanya akan di eksekusi 1x, pada saat perangkat dinyalakan
void setup() {
    // kode program, setup
}

// program utama/loop
// bagian program yang terus akan dieksekusi sebagai sebuah loop selama
// perangkat menyala.
void loop() {
    // kode program, loop
}

```

## Fungsi Dasar
Berikut fungsi/perintah dasar bahasa yang digunakan pada Arduino

### pinMode(_PIN_, _MODE_)
Fungsi ini digunakan untuk menginisialisasi sebuah pin, dan menentukan pin tersebut akan digunakansebagai input ataupun output. Nilai _MODE_ dapat diisi OUTPUT atau INPUT, tergantung dari kebutuhan. Sedangkan nilai pin adalah nomor pin pada mikrokontroler yang akan diset sebagai input atau output

Contoh:
```cpp
void setup() {
    pinMode(13, OUTPUT) // artinya kita menentukan pin
}
```

### digitalWrite(_PIN_, _VALUE_)
Fungsi ini digunakan untuk menuliskan nilai secara digital pada suatu pin. Nilai _VALUE_ dapat berupa HIGH (ON) atau LOW (OFF) dan nilai pin adalah nomor pin pada Arduino yang akan diset

Contoh:
```cpp
void loop() {
    digitalWrite(13, HIGH) // artinya pin digital 13 diset
}
```

### digitalRead(_PIN_)
Fungsi ini digunakan untuk membaca nilai input/masukan yang diberikan ke Arduino. Nilai yang terbaca oleh Arduino melalui `digitalRead()` bergantung pada voltase pada pin yang diatur. Kebergantungan pada nilai voltase ini disebut Logic Level. Pada Arduino, batasan nilai yang mencukupi untuk mencapai HIGH adalah di antara 5-3 volt, sedangkan batasan nilai yang mencapainilai LOW adalah di antara 0 1,5 volt.

Contoh:
```cpp
int nilai;
void loop(){
    nilai = digitalRead(13);
    Serial.println(nilai);
}
```

### analogRead(_PIN_)
Fungsi ini mirip dengan fungsi digitalRead(), yaitu membaca nilai masukan pada suatu pin. Bedanya adalah fungsi `analogRead()` akan menghasilkan nilai dari 0 hingga 1023, yang merepresentasikan voltase 0 v hingga 5 v.

Contoh:
```cpp
int nilai;
void loop(){
    nilai = digitalRead(0);
    Serial.println(nilai);
}
```

### delay(_TIME_)
Fungsi ini digunakan untuk memberikan jeda antar fungsi. Nilai time adalah waktu lamanya jeda dalam satuan _ms_ (milisekon), di mana 1 detik setara dengan 1.000
milidetik.

### begin(baudrate)
Pengguna dapat melakukan komunikasi serial antara Arduino dengan PC, dengan menggunakan Serial Monitor yang disediakan pada Arduino IDE. Pada Serial Monitor, kita bisa melihat data yang dikirim dari Arduino ke PC. Selain itu, kita juga bisa mengirim data ke Arduino dengan cara mengetikkannya pada textbox di bagian atas Arduino IDE. Untuk memakai serial, yang pertama harus dilakukan adalah melakukan inisiasi dengan menggunakan fungsi Serial.begin(baudrate). Variabel baudrate merupakan rasio modulasi, dan harus dicocokkan dengan baudrate hardware yang akan dikomunikasikan.

### available()
Fungsi untuk mengetes apakah ada input data dari hardware yang disambungkan ke serial port, misalnya dari PC. Fungsi ini akan menghasilkan 1 apabila
ada masukan, dan 0 apabila tidak ada masukan.

### read()
Fungsi ini berfungsi untuk membaca karakter pada serial port. Karakter yang dibaca akan disimpandalam bentuk ASCII (misalnya karakter ‘0’ memiliki representasi ASCII yaitu 48).

### print() dan Serial.println()
Fungsi ini digunakan untuk menuliskan suatu kalimat ke Serial Monitor, tetapi tidak mengirimkan dataapapun, alias hanya digunakan untuk memberikan teks visual pada pengguna. `Serial.print("text")` digunakan untuk menulis "text", sedangkan `Serial.println("text")` dipakai untuk menuliskan kata "text" dan diakhiri dengan enter (kalimat selanjutnya ada di baris berikutnya).

### write(_VALUE_)
Untuk mengirimkan data dari arduino ke PC, kita bisa menggunakan fungsi Serial.write(VAL). Nilai VAL adalah data yang ingin dikirimkan dari arduino ke PC, dengan ukuran 1 byte.
Setelah mempelajari fungsi dan instruksi pada pemrograman arduino mari kita coba mengimplementasikannya. Ini adalah program dasar 'hello world' yang digunakan untuk menyalakan atau mematikan sesuatu. Dalam contoh ini, LED terhubung ke pin D1, dan berkedip setiap detik. Resistor dapat dihilangkan pada pin ini karena Arduino memilikinya.

### tone(_PIN_, _frek_) & noTone()
Perintah untuk membunyikan buzzer (piezo) sesuai nilai _frek_. Fungsi ini hanya bisa implementasikan pada pada _PIN_ 3-11. Suara buzzer akan berhenti ketika dipanggil fungsi `noTone()`.


### map(_variabel_,_fromLow_,_fromHigh_,_toLow_,_toHigh_)
Fungsi map() adalah fungsi pada Arduino yang berfungsi untuk memetakan ulang suatu nilai (angka) dari rentang satu ke dalam rentang lainnya. Artinya, nilai _fromLow_ akan dipetakan ke _toLow_ , nilai _fromHigh_ ke _toHigh_ , nilai di antara akan dipetakan secara proporsional sesuai rentan.

## Kontrol _if_
Stetement `if` memeriksa kondisi dan mengeksekusi perintah-perintah didalamnya jika _kondisi_ bernilai _true_.

```cpp
if (kondisi) {
    //perintah
    //perintah
}
```

Contoh kode program:
```cpp
if (x > 120) digitalWrite(LEDpin, HIGH);

if (x > 120) digitalWrite(LEDpin, HIGH);

if (x > 120) {digitalWrite(LEDpin, HIGH);}

if (x > 120) {
    digitalWrite(LEDpin1, HIGH);
    digitalWrite(LEDpin2, HIGH);
}
```
_kondisi_ bisa berupa formula perbandingan nilai. Formula ini biasanya akan menggunakan _operator pembanding_.

| Formula | Keterangan |
| --- | --- |
| `x == y` | (x sama dengan y) |
| `x != y` | (x tidak sama dengan y) |
| `x < y` | (x kurang dari y) |
| `x > y` | (x lebih besar dari y) |
| `x <= y` | (x lebih kecil atau sama dengan y) |
| `x >= y` | (x lebih besar atau sama dengan y) |

Waspadalah terhadap penggunaan tanda sama dengan tunggal secara tidak sengaja (misalnya `if (x = 10)` ). Tanda sama dengan tunggal adalah operator penugasan, dan mengisi `x` menjadi `10`. Sebagai gantinya gunakan tanda _sama dengan ganda_ (misalnya `if (x == 10)` ). Pernyataan terakhir hanya benar jika `x` sama dengan `10`, namun pernyataan sebelumnya selalu benar.

sumber: https://www.arduino.cc/reference/en/language/structure/control-structure/if/

## Loop _while_

```cpp
while(kondisi) {
    // perintah 1
    // perintah 2
}
```