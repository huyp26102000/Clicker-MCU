#include "EEPROM.h"
#define EEPROM_SIZE 128

int mode = 0;
struct deviceConfig()
{
    String ssid = "";
    String password = "";
    String ID = "";
}
deviceConfig DCongig;
void setup()
{
  Serial.begin(115200);
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM"); delay(1000000);
  }

}
void loop()
{
  Serial.print(readEEPROM());
  Serial.println();
  delay(2000);
}
deviceConfig 
String readEEPROM()
{
  String tmpstr = "";
  for(int i = 0; EEPROM.read(i)!=NULL; i++)
  {
    char tmp[1];
    sprintf(tmp, "%c", EEPROM.read(i));
    tmpstr += tmp;
  }
  return tmpstr;
}
