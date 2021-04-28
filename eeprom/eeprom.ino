#include "EEPROM.h"
#define EEPROM_SIZE 128

int modeW = 0;
String another;
String x;
void setup() {
  Serial.begin(115200);
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM"); delay(1000000);
  }
}
void loop() {
  while (!Serial.available())
  {
    
  }
  x = Serial.readString();
  if(x=="read")
  {
    Serial.print(readEEPROM());
  }
  else
  {
    write_EEPROM(x);
    Serial.print("asd");
  }
  
}
void write_EEPROM(String strData)
{
  // erase eeprom
  for(int i = 0; i < EEPROM_SIZE; i++)
  {
    EEPROM.write(i, NULL);
  }
  EEPROM.commit();
  // start writting
  for(int i = 0; i < strData.length(); i++)
  {
    EEPROM.write(i, strData[i]);
  }
  EEPROM.commit();
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
