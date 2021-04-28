#include "EEPROM.h"
#define EEPROM_SIZE 64

int mode = 0;
void setup()
{
  Serial.begin(9600);
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM"); delay(1000000);
  }

}
void write_EEPROM(String strData)
{
  for(int i = 0; i < strData.length(); i++)
  {
    EEPROM.write(i, strData[i]);
  }
}
void loop()
{
  Serial.print(readEEPROM());
  Serial.println();
  delay(2000);
}
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
