# COUNTER
# >> arduino + tombol + 7 segment
# setiap kali tombol diklik, maka angka pada 7 segment bertambah
# jika angka mencapai 9, tombol berikutnya di klik akan kembali ke
# angka 0

#include "7seg.h"

int pressed = 0;
int count = 0;

void setup () {
    pinMode (4, INPUT); 
    Serial.begin(9600);
}
 
void loop() {
  int x = digitalRead(4);

  if(x==HIGH) {
    pressed = true;
  }
  if(x==LOW && pressed) {
    pressed = false;
    if(count==9) {
      count = 0;
    } else {
      count++;
    }
    Serial.println(count);
    angka(count);
  }
    
}