#include <Wire.h>
#include <dht11.h> // dht11 kütüphanesini kodlarımıza dahil ediyoruz.
 
int DhtPin=2; // DhtPin olarak Dijital 2'yi belirliyoruz.
dht11 dht_sensor; // dht_sensor adında bir DHT11 nesnesi oluşturduk.
 
void setup()
{
  Wire.begin(1);
  Wire.onRequest(olcum);
  Serial.begin(9600); // Seri iletişimi başlatıyoruz.
  Serial.println("www.arduinomedia.com");
  Serial.println("*********************");
}
 
void loop(void)
{
  // Sensör konrol ediliyor. 
 delay(100);
 olcum();

 
}
void olcum()
{
    int chk = dht_sensor.read(DhtPin);
 
  // Sensörden okunan değerleri serial ekranda yazdırıyoruz.
  Serial.print("Nem Orani (%): ");
  Serial.println((float)dht_sensor.humidity, 2);
 
  Serial.print("Sicaklik (Celcius): ");
  Serial.println((float)dht_sensor.temperature, 2);
 

 
  // Çiğ Oluşma Noktası
  Serial.print("Cig Olusma Noktasi: ");
  Serial.println(dht_sensor.dewPoint(), 2);
  Serial.println("------------------");
  
  // Veriler her 1 saniyede bir veriler ekrana yazdırılacak.
  delay(1000);
   Wire.beginTransmission(1);
   byte olcum[]=(highByte(dht_sensor.humidity),lowByte(dht_sensor.humidity));
  // byte olcum[]=(highByte(dht_sensor.temperature),lowByte(dht_sensor.temperature));
  // Wire.write(dht_sensor.temperature,2);
   Wire.write(dht_sensor.humidity,2);
   
   Wire.endTransmission();
  
}
