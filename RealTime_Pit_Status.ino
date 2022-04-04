//report new status whenever pit goes on or off , doesnt matter status changes with gsm command or manual
void realtimePitStatus()
{
  boolean realTimeStatus = digitalRead(pitInput);
  if (pitStatus != realTimeStatus && realTimeStatus == true) {
    pitStatus = true ;
    Serial.println("pit status has changed > on ");
    report("0686062706470020063106480634064600200634062f");
  }
  else  if (pitStatus != realTimeStatus && realTimeStatus == false) {
    pitStatus = false ;
    Serial.println("pit status has changed > off ");
    report("0686062706470020062E062706450648063400200634062F");
  }
}
