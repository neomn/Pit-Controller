//give me a text and ill send it to andmin for u , not a problem . ur welcome

void report(String text)
    { 
      soft.print(F("AT+CMGS=\""));      
      soft.print("09178448254");
      soft.print(F("\"\r"));
      delay(500);
      soft.print(text);
      soft.print("\r");
      soft.print((char)26);
      delay(3000);

      soft.print(F("AT+CMGS=\""));      
      soft.print("09177424182");
      soft.print(F("\"\r"));
      delay(500);
      soft.print(text);
      soft.print("\r");
      soft.print((char)26);
      delay(3000);
      
    }
  
