//validating sms sender phone number
boolean senderConfirmed(String phoneNumber)
{
  //compare phone number with valid numbers
  if (phoneNumber.equals(myPhoneNumber) || phoneNumber.equals(daddyPhoneNumber) ) {
    Serial.println("sender phone number is valid ");
    return true;
  }
  else {
    Serial.println("sender phone number is not valid  !!!! ");
    return false;
  }

}
