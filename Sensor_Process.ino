
//if silent mode isnt active >>>
//if movement detected by pir or ultrasonic sensors , report movement


double distance =0 ;
String stringDistance;

void sensorProcess()
{
  distance = distanceSensor.measureDistanceCm();
  stringDistance = String(distance);
  delay(100);
  
  //Serial.print(" Distance >>>");
  //Serial.print(distance);
  //Serial.println();

  //Serial.print(" sonicTimer >>>");
  //Serial.print(sonicTimer);
  //Serial.println();
    
  if (silentModeState == false)
  {
    boolean pirTemp = digitalRead (pir);
    delay(100); 
    if (pirTemp)
    {
      digitalWrite (pirLedIndicator,HIGH);
      delay(1000);
      digitalWrite (pirLedIndicator,LOW);
      
      pirTimer++;
      if (pirTimer > 4)
      {
        pirTimer = 0;
        //Serial.println("PIT >>> PIR Movement Detected !!! ");
        report (" PIT >>>PIR Movement Detected !!!");             
      }   
    }


    /*
    //if movement detected by sonic 20 times , this method send sms to admin onece
    // first time that sonic triggered , sms will set immediatly , after that , sms will send after 20 time that sonic triggers
    
       if (sonicMovementDetected() )
          {
            int tempTimer = sonicTimer;
            sonicTimer++;
            
            if (sonicTimer > 6)              
                  sonicTimer = 0;              
              
             if (tempTimer >= 6)              
                  {                   
                    //Serial.println("PIT >>> UltraSonic Movement Detected !!!");
                    report ("PIT>UltraSonic Movement Detected.value>" + stringDistance);
                  }
          }

    */
  }
}

//_______________________________________________________________
boolean sonicMovementDetected ()
{
  if ( distance  > 25.00 || distance == -1 || distance == 0)
    return true;
  else return false;
}
