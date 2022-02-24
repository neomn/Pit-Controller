//apply received orders from gsm module

void doOrders()
{ 
  
  if (isThereNewSms())     // if there is new order , do it
  {

     String receivedOrder = getNewOrder();
  
     //Serial.print ("new order >>> ");
     //Serial.print(receivedOrder);
     //Serial.println();
    
    //---------------------------------------------------------
    //turn pit on or off
    if (receivedOrder.indexOf("piton") != -1)
          { 
            digitalWrite(pitOutputOn, LOW);
            delay(1000);
            digitalWrite(pitOutputOn, HIGH);
            //Serial.println("order received >>> pit is on");           
          }
    if (receivedOrder.indexOf("pitoff") != -1)
          {
            digitalWrite(pitOutputOff, LOW);
            delay(1000);
            digitalWrite(pitOutputOff, HIGH);
            //Serial.println("order received >>> pit is off");            
          }
    //--------------------------------------------------------------------------------
     //switching silent mode on or off . dedault >>> off
     //admin can request for current silent mode state
     
     if(receivedOrder.indexOf("silenton")!=-1)
          {
              silentModeState=true;
              report("silent mode Activated !!!");
          }
     if(receivedOrder.indexOf("silentoff")!=-1)
          {
            silentModeState=false; 
            report("silent mode DeActivated !!!");
          }
     if(receivedOrder.indexOf("pitreporteron")!=-1)
          {
            pitReporter=true; 
            report("pit reporter activated");
          }  
     if(receivedOrder.indexOf("pitreporteroff")!=-1)
          {
            pitReporter=false; 
            report("pit reporter DeActivated");
          }       
     if(receivedOrder.indexOf("silentstate")!=-1) 
          {
            if (silentModeState)
                {                           
                  //Serial.println("Silent State >>> on ");                  
                  report("Silent State >>> on");
                }
            else 
                {
                    //Serial.println("Silent State >>> off "); 
                    report("Silent State >>> off");            
                }
          }  
  }//else  //Serial.println("no new sms!!!");

}
