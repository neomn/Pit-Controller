//run commands

void runCommand(String command) {
  command.trim();
  Serial.println(" trying to run command > ");
  if (command.equals("06F1\0") || command.equals("31\0") ) {
    Serial.println("command recived > pit goes on");
    digitalWrite (pitRelay , HIGH);
  }
  else if (command.equals("06F0\0") || command.equals("30\0")) {
    Serial.println("command recived > pit goes off");
    digitalWrite (pitRelay , LOW);
  }
  else if (command.equals("06F2\0") || command.equals("32\0")) {
    Serial.println("command recived > current pit status >> " + String(pitStatus));
    if (pitStatus)
      report("06860627064700200631064806340646002006270633062A");
    else report("0686062706470020062E0627064506480634002006270633062A");    
  }
  else {
    Serial.println("bad command");
  }
}
