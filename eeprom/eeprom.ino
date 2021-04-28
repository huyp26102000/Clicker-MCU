#include "EEPROM.h"
#define EEPROM_SIZE 128

int mode = 0;
String another;
String x;
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM"); delay(1000000);
  }
}
void loop() {
  
  while(!Serial.available())
  {
    x = Serial.readString();
  }
  if(x.toInt()==1)
  {
    Serial.println(readEEPROM());
  }
  else
  {
    write_EEPROM(x);
//    delay(1000);
    Serial.println(readEEPROM());
  }

}
void eraser_EEPROM()
{
  EEPROM.begin(EEPROM_SIZE);
  for (int i = 0; i < 512; i++)
  {
    EEPROM.write(i, 0);
  }
  EEPROM.commit();
  //delay(500);
}
void write_EEPROM(String strData)
{
  eraser_EEPROM();
  /*
  EEPROM.begin(EEPROM_SIZE);
  
  for(int i = 0; i < EEPROM_SIZE; i++)
  {
    EEPROM.write(i, NULL);
  }
  EEPROM.commit();
  */
  EEPROM.begin(EEPROM_SIZE);
  for(int i = 0; i < strData.length(); i++)
  {
    EEPROM.write(i, strData[i]);
  }
  EEPROM.commit();
  //delay(500);
}
String readEEPROM()
{
  String tmpstr = "";
  for(int i = 0; i<128; i++)
  {
    char tmp[1];
    sprintf(tmp, "%c", EEPROM.read(i));
    tmpstr += tmp;
  }
  return tmpstr;
}
