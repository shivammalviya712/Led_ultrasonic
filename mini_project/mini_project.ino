#include<NewPing.h>

//HyperParameter
const int max_dist = 4000;
const int median_sample = 3;
const int threshold_change = 20;   

//Pins
const int echo = 8;          //Input Pin w.r.t. Arduino
const int trig = 9;          //Output Pin w.r.t Arduino 
const int led_positive  = 6; //Output Pin w.r.t Arduino
const int led_negative = 7;  //Input Pin w.r.t. Arduino

double distance1, duration1;
double distance2, duration2;


NewPing ultra_sonic(trig, echo, max_dist);


void setup() {
    
  Serial.begin(9600);

  pinMode(led_positive, OUTPUT);
  pinMode(led_negative, OUTPUT);
  duration1 = ultra_sonic.ping_median(median_sample);
  distance1 = ultra_sonic.convert_cm(duration1);
}

void loop() {

  double change;

  duration2 = ultra_sonic.ping_median(median_sample);
  distance2 = ultra_sonic.convert_cm(duration2);

  change = abs(distance1-distance2);
  if (change > threshold_change)
  {
      digitalWrite(led_positive, HIGH);
      digitalWrite(led_negative, LOW);
      delay(500);
      digitalWrite(led_positive, LOW);
      digitalWrite(led_negative, LOW);
  }

  distance1 = distance2;
  
}
