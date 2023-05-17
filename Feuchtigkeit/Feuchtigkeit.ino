#include <dht.h>

dht DHT;

#define DHT11_PIN 7
int red = 4;
int green = 5;
int yellow = 6;
void setup(){

  Serial.begin(9600);
    pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT); 
  
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temerature: ");
  Serial.print(DHT.temperature);
  Serial.println("C°");
  
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity);
  Serial.println("%");
  int humidity = DHT.humidity;
  if(humidity <= 38 ){
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
    }
  else if(humidity >= 62){
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
    }
  else if(humidity <= 45 || humidity >= 58){
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
    }
  else{
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
    }
  

  delay(1500);




}
