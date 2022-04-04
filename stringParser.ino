
//parse recived order
void phoneParser(String text) {

  text = text.substring(33);
  char buff[28];
  for (int i = 0 ; i < 28 ; i++) 
    buff[i] = text.charAt(i);
  String x;
  for (int i = 0 ; i < 26 ; i++) 
    x.concat(buff[i]);
  phoneNumber = x;
  Serial.println("parsed phone Number > " + phoneNumber);
}

void commandParser(String s) {
  s = s.substring(88);
  char buf[5];
  for (int i = 0 ; i < 4 ; i++)
    buf[i] = s.charAt(i);
  buf[4]='\0';//end of string  
  command =String(buf);
  Serial.println("parsed command > " + command);
}
