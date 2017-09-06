const int sensorPin=A0;
const float baselineTemp=30.0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);   //open a serial port
for(int pinNumber=2;pinNumber<5;pinNumber++){   //turn off led 2-4
  pinMode(pinNumber,OUTPUT);      //initialize pin mode
digitalWrite(pinNumber,LOW);      //initialize pins to LOW     
}
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorVal=analogRead(sensorPin);
Serial.print("Sensor Value: ");
Serial.print(sensorVal);
float voltage=(sensorVal/1024.0)*5.0;
Serial.print(", Volts: ");
Serial.print(voltage);
Serial.print(", degrees C: ");
//convert the voltage to temperature in degrees
float temperature =(voltage -.5) * 100;
Serial.println(temperature);

if(temperature< baselineTemp+2){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
}
else if(temperature >= baselineTemp+1 && temperature <baselineTemp+2 && temperature < baselineTemp+3){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
}
else if(temperature >=baselineTemp+4 && temperature < baselineTemp+5){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
}
else if(temperature >=baselineTemp+6){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
}
delay(1);
}
