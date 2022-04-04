//check if there is new sms , parse it and receive the order

String cmgr = "AT+CMGR=";
String cmgda = "AT+CMGDA=DEL ALL\n\r";

//______________________________________________
boolean isThereNewSms()
{
  if (soft.readString().indexOf("CMTI") != -1) {
    
    return true;
  }
  else return false;
}
//____________________________________________
String getNewOrder()
{
  soft.write(cmgr.c_str());
  soft.print(index);
  soft.write("\r");
  delay (3000);
  order = soft.readString();
  Serial.println("raw order > " + order);
  delay(1000);
  soft.write(cmgda.c_str());
  soft.write("\r");
  delay(1000);
  return order;
}
//____________________________________
