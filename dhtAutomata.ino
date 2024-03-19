#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPL6SqRK_Vw-"
#define BLYNK_TEMPLATE_NAME "sunflower"

#define relay1 D3  
#define relay2 D4  
#define relay3 D7  
#define relay4 D8  

#define DHTPIN1 D1  
#define DHTPIN2 D2  
#define DHTPIN3 D5  
#define DHTPIN4 D6  
#define DHTTYPE DHT11  

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
DHT dht4(DHTPIN4, DHTTYPE);

// WiFi connection configuration
char auth[] = "iyRMQPg9pCC1a6v_lKqaZ4EYQnQs8AUB"; //blynk auth
char ssid[] = "construction"; //wifi ssid
char password[] = "unavailable"; //wifi pass

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing DHT...");
  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
   }
  
  Serial.println("");
  Serial.println("WiFi connected");

  Blynk.begin(auth, ssid, password);
  Blynk.syncAll(); // Synchronize all widget values

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

}

void loop() {
  Blynk.run();
  // Display reading results
  sensor1();
  sensor2();
  sensor3();
  sensor4();
  checkAndControlRelay1();
  checkAndControlRelay2();
  checkAndControlRelay3();
  checkAndControlRelay4();
  delay(50);  // Delay for 2 seconds before next reading
}

void sensor1(){
  // Read humidity from DHT1 sensor
  float humidity1 = dht1.readHumidity();
  // Read temperature from DHT1 sensor in Celsius
  float temperature1 = dht1.readTemperature();

  //if (isnan(humidity1) || isnan(temperature1)){
  //Serial.println("Failed to read DHT sensor!");
  //return;
  //}
  Serial.println("Sensor 1:");
  Serial.print("Humidity: ");
  Serial.print(humidity1);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature1);
  Serial.println("°C");
  Blynk.virtualWrite(V0, temperature1);
  Blynk.virtualWrite(V1, humidity1);
}

void sensor2(){
  // Read humidity from DHT2 sensor
  float humidity2 = dht2.readHumidity();
  // Read temperature from DHT2 sensor in Celsius
  float temperature2 = dht2.readTemperature();

  //if (isnan(humidity2) || isnan(temperature2)){
  //Serial.println("Failed to read DHT sensor 2!");
  //return;
  //}

  Serial.println("Sensor 2:");
  Serial.print("Humidity: ");
  Serial.print(humidity2);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature2);
  Serial.println("°C");
  Blynk.virtualWrite(V2, temperature2);
  Blynk.virtualWrite(V3, humidity2);
}

void sensor3(){
  // Read humidity from DHT3 sensor
  float humidity3 = dht3.readHumidity();
  // Read temperature from DHT3 sensor in Celsius
  float temperature3 = dht3.readTemperature();

  //if (isnan(humidity3) || isnan(temperature3)){
  //Serial.println("Failed to read DHT sensor 3!");
  //return;
  //}

  Serial.println("Sensor 3:");
  Serial.print("Humidity: ");
  Serial.print(humidity3);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature3);
  Serial.println("°C");
  Blynk.virtualWrite(V4, temperature3);
  Blynk.virtualWrite(V5, humidity3);
}

void sensor4(){
  // read humid data from DHT4 sensor
  float humidity4 = dht4.readHumidity();
  // read temperature data from DHT4 sensor in Celsius
  float temperature4 = dht4.readTemperature();

  Serial.println("Sensor 4:");
  Serial.print("Humidity: ");
  Serial.print(humidity4);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature4);
  Serial.println("°C");
  Blynk.virtualWrite(V6, temperature4);
  Blynk.virtualWrite(V7, humidity4);
}

void checkAndControlRelay1() {
  float temperature1 = dht1.readTemperature();
  float humidity1 = dht1.readHumidity();
  
  if (temperature1 < 26 || humidity1 > 60) {
    // turn on relay 1 and relay 2
    digitalWrite(relay1, LOW);
  } else {
    // turn off relay 1 and relay 2
    digitalWrite(relay1, HIGH);
  }
}

void checkAndControlRelay2() {
  float temperature2 = dht2.readTemperature();
  float humidity2 = dht2.readHumidity();
  
  if (temperature2 < 26 || humidity2 > 60) {
    // turn on relay 1 and relay 2
    digitalWrite(relay2, LOW);
  } else {
    // turn off relay 1 and relay 2
    digitalWrite(relay2, HIGH);
  }
}

void checkAndControlRelay3() {
  float temperature3 = dht3.readTemperature();
  float humidity3 = dht3.readHumidity();
  
  if (temperature3 < 26 || humidity3 > 60) {
    // turn on relay 1 and relay 2
    digitalWrite(relay3, LOW);
  } else {
    // turn off relay 1 and relay 2
    digitalWrite(relay3, HIGH);
  }
}

void checkAndControlRelay4() {
  float temperature4 = dht4.readTemperature();
  float humidity4 = dht4.readHumidity();
  
  if (temperature4 < 26 || humidity4 > 60) {
    // turn on relay 1 and relay 2
    digitalWrite(relay4, LOW);
  } else {
    // turn off relay 1 and relay 2
    digitalWrite(relay4, HIGH);
  }
}
