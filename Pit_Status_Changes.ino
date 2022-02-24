//if pit status (on or off) changed , report changes

 

  boolean pitIsOn()
  {

    boolean pitTemp = digitalRead(pitInput);
    delay(100);
    
    if(pitTemp)
        {           
           return true ;
        }
    return false;    
  } 
//_____________________________________________  
  boolean pitStatusChanged ()
  {        
     if ( pitIsOn()!= pitLastState )
          {            
            pitLastState = ! pitLastState;
            //Serial.println("pit Status has changed");            
            return true ; 
          }
     return false;         
  }
