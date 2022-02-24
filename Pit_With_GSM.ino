// this project is about controling a Water Pit remotelly with a gsm module and 
// an arduino board and
// ultrasonic and pir sensors as an anti Theaft 
// here is how it works >>>>>

    // if there is new sms , read it and do orders
    // if movemet detected , report sensor data 
    // if pit goes on or off , report pit status changes
    // there is a method to toggle silent mode (mute reporter or enable reporter)
    // logger method , send most recent log file changes to admin if requested 
    
//________________________________________________________
#include <SoftwareSerial.h>
#include <HCSR04.h> // martin sonic library

//<<<<<<<<<<<<< Pins >>>>>>>>>>>>>>>
int pir =9; 
int pitInput =8;
int pitOutputOn =7;
int pitOutputOff =6;
int echoPin = 12;
int triggerPin = 13;
int pirLedIndicator = 5;

//<<<<<<<<<<<<< Variables >>>>>>>>>>>>>>>
int sonicTimer = 6;//for initializing Sonic (For controling send sms timing)
int pirTimer = 4; //for initializing PIR (For controling send sms timing) 
uint8_t index =1;// receive sms index 1 from inbox 
String cmgf1 = "AT+CMGF=1\r";  //for initializing gsm
boolean silentModeState = false ;
boolean pitLastState = false ;
boolean pitReporter = true ;

//<<<<<<<<<<<<< Objects >>>>>>>>>>>>>>>
SoftwareSerial soft (10,11) ;   // RX TX 
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);  // initializing ultrasonic sensor

//________________________________________________________________________
void setup() {
  
  //Serial.begin(9600);
  soft.begin(4800);

  pinMode (pir,INPUT);
  pinMode (pitInput,INPUT);
  pinMode(pitOutputOn,OUTPUT);
  pinMode(pitOutputOff,OUTPUT);
  pinMode(pirLedIndicator,OUTPUT);

  //in this case , cause i dont have high level trigger relay , i have to use 
  // low level trigger relay 
  digitalWrite(pitOutputOn , HIGH);
  digitalWrite(pitOutputOff , HIGH);

  pitLastState =  digitalRead(pitInput);
 
  //initializing gsm
  boolean check = true ; 
  
  while(check)
    {
      soft.write(cmgf1.c_str());
      String str = soft.readString();
      if (str.indexOf("OK")!= -1)         
           check=false; 
      delay (200);                
    }

  //Serial.println (" ______pit initialized_______" );
  report ("pit initialized");
  delay(3000);
    
}
//________________________________________________________________________

void loop() {

     doOrders();
     delay(500);
     sensorProcess();
     delay(500);
     realtimePitStatus();           
     delay(500);
}
