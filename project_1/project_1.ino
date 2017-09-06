int switchState=0;

void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);//green led, //output means light
pinMode(4,OUTPUT);//red led     //output is light
pinMode(5,OUTPUT);//red led       //output is light
pinMode(2,INPUT); //switch        //input is the switch button      
}

void loop() {
  // put your main code here, to run repeatedly:
switchState=digitalRead(2);

if(switchState==LOW){
//the button is not pressed
digitalWrite(3,HIGH);     //green LED
digitalWrite(4,LOW);      //red LED
digitalWrite(5,LOW);      //red LED
}
else{
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);

  delay(250);//wait for a quarter second 
  //toggle the LED
 
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  delay(250); //wait for a quarter second
}


}
