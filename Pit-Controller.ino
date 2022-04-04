#include <SoftwareSerial.h>


//<<<<<<<<<<<<< Pins >>>>>>>>>>>>>>>
int pitInput = 9;
int pitRelay = 12;

//<<<<<<<<<<<<< Variables >>>>>>>>>>>>>>>
//i have to hard code these cuze of memory lack
//String pitOn = "0686062706470020063106480634064600200634062f"; // چاه روشن شد
//String pitOff = "0686062706470020062E062706450648063400200634062F";  // چاه خاموش شد
//String pitIsOn="06860627064700200631064806340646002006270633062A";// چرا روشن است   
//String pitIsOff="0686062706470020062E0627064506480634002006270633062A";// چاه خاموش است 
//String initializeText="063306CC0633062A06450020063106480634064600200634062F"; //سیستم روشن شد

String phoneNumber = "";
String command = "";
String cmgf1 = "AT+CMGF=1\r";  //for initializing gsm
uint8_t index = 1; // receive sms index 1 from inbox
String order = ""; //recived order from gsm . not parsed yet
//valid phone numbers
String myPhoneNumber = "2B393839313738343438323534";//8254
String daddyPhoneNumber = "2B393839313737343234313832";//4182
boolean pitStatus;



//<<<<<<<<<<<<< Objects >>>>>>>>>>>>>>>
SoftwareSerial soft(10, 11); //rx  tx

void setup() {
  Serial.begin(9600);
  soft.begin(9600);

  pinMode (pitInput, INPUT);
  pinMode(pitRelay, OUTPUT);

  digitalWrite(pitRelay , LOW);
  pitStatus = digitalRead(pitInput);

  //initializing gsm
  boolean check = true ;
  while (check)
  {
    soft.write(cmgf1.c_str());
    String str = soft.readString();
    if (str.indexOf("OK") != -1)
      check = false;
    delay (200);
  }
  delay(3000);
  soft.print("AT+CSCS=\"HEX\"\r");
  delay(3000);
  soft.print("AT+CSMP=49,167,0,8\r");  //set gsm in unicode utf-8 mode
  delay(3000);
  Serial.println(" -------- system initilized --------- ");
  report("063306CC0633062A06450020063106480634064600200634062F");
}

void loop() {

  if (isThereNewSms()) {
    Serial.println("new sms recived !");
    order = getNewOrder();
    phoneParser(order);
    commandParser(order);
    if (senderConfirmed(phoneNumber))
      runCommand(command);
  }
  realtimePitStatus();
}
