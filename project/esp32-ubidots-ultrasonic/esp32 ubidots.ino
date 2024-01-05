#include "UbidotsEsp32Mqtt.h"

/****************************************
 * Define Constants
 ****************************************/
const char *UBIDOTS_TOKEN = "BBFF-7ZrDpBFKDpPeAk5nl5rEjLv0wckuef";  // Put here your Ubidots TOKEN
const char *WIFI_SSID = "En Tay's";      // Put here your Wi-Fi SSID
const char *WIFI_PASS = "12345678";      // Put here your Wi-Fi password
const char *DEVICE_LABEL = "A";   // Put here your Device label to which data  will be published
const char *VARIABLE_LABEL = "Level"; // Put here your Variable label to which data  will be published

const int PUBLISH_FREQUENCY = 5000; // Update rate in milliseconds

unsigned long timer;
int x;

int pinTrigger = 5;
int pinEcho = 18;

Ubidots ubidots(UBIDOTS_TOKEN);

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}



// function untuk membaca jarak
double bacaJarak()
{
    // pastikan ultrasound dalam keadaan mati
    digitalWrite(pinTrigger, LOW);
    delayMicroseconds(2);
    
    // kirim sinyal suara
    // 10 Microsecond adalah standard durasi pengiriman standard untuk melakukan pengukuran menggunakan ultrasound
    digitalWrite(pinTrigger,HIGH);
    delayMicroseconds(10);
    // matikan
    digitalWrite(pinTrigger,LOW);
    
    // baca pulsa suara
    long pulse=pulseIn(pinEcho,HIGH);
    
    return pulse/58; // rumus konversi hasil pembacaan sensor (pulse) ke sentimeter  
}

/****************************************
 * Main Functions
 ****************************************/

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // ubidots.setDebug(true);  // uncomment this to make debug messages available
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASS);
  ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();

  timer = millis();

  pinMode(pinTrigger,OUTPUT);
  pinMode(pinEcho,INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (!ubidots.connected())
  {
    ubidots.reconnect();
  }
  x = millis() - timer;
  if(x<0) x*=-1;
  if (x > PUBLISH_FREQUENCY) // triggers the routine every 5 seconds
  {
    float value = bacaJarak();
    ubidots.add(VARIABLE_LABEL, value); // Insert your variable Labels and the value to be sent
    ubidots.publish(DEVICE_LABEL);
    timer = millis();
  Serial.println(value);
  }
  ubidots.loop();
}