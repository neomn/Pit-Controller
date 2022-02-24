//give me a text and ill send it to andmin for u , not a problem . ur welcome

void realtimePitStatus()
  {
     //report new status whenever pit goes on or off , doesnt matter status changes with gsm command or manual
     //report will sent if silent mode isnt activated
    
     
     if (pitReporter==true) 
        {
          
          if ( pitStatusChanged() )                
                {                                                  
                  if (pitIsOn())
                        {
                          //Serial.println("pit is on");
                          //delay(500);
                          report("pit is on");
                        }
                  else if (!pitIsOn()) 
                        {
                          //Serial.println("pit is off");
                          //delay(500);
                          report("pit is off"); 
                        }
                 }
         }        
        
  }
