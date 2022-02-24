//check if there is new sms , parse it and receive the order

String cmgr = "AT+CMGR=";
String cmgda = "AT+CMGDA=DEL ALL\n\r";

//------------------------------------------

boolean isThereNewSms()
            {
              if(soft.readString().indexOf("CMTI")!= -1)
                  return true;
              else return false;
            }
//------------------------------------------

String getNewOrder()
          {
              soft.write(cmgr.c_str());
              soft.print(index);
              soft.write("\r"); 
              delay (3000);
              String order = soft.readString();
              //Serial.println(order);
              delay(1000);
              soft.write(cmgda.c_str());

              if (order.indexOf("piton")!=-1)  return "piton";
              else if (order.indexOf("pitoff")!=-1)  return "pitoff";  
              else if (order.indexOf("silenton")!=-1)  return "silenton"; 
              else if (order.indexOf("silentoff")!=-1)  return "silentoff"; 
              else if (order.indexOf("silentstate")!=-1)  return "silentstate";  
              else if (order.indexOf("pitreporteron")!=-1)  return "pitreporteron";  
              else if (order.indexOf("pitreporteroff")!=-1)  return "pitreporteroff";  
              else return "Bad Formmat";                
          }
