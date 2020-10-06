#include <Oregon_NR.h>

Oregon_NR oregon(2, 0);
byte t_sum = 0;
byte t_crc = 0;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Утилита для поиска параметров расчёта CRC8 для датчиков Oregon Scientific
// используется при добавлении новых датчиков в базу библиотеки
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
  Serial.begin(115200);     
  Serial.println();

//THN132  
  byte data1[] = {0xE, 0xC, 0x4, 0x0, 0x1, 0xB, 0x1, 0x8, 0x3, 0x5, 0x2, 0x0, 0xD, 0x3, 0x3, 0xF};
  byte data2[] = {0xE, 0xC, 0x4, 0x0, 0x1, 0xB, 0x1, 0x8, 0x2, 0x5, 0x2, 0x0, 0xC, 0x3, 0x4, 0xA};
  byte data3[] = {0xE, 0xC, 0x4, 0x0, 0x1, 0xA, 0xD, 0x2, 0x7, 0x2, 0x2, 0x0, 0x3, 0x4, 0x4, 0x4};
  byte packet_size = 16;

//THGR810
// byte data1[] = {0xF, 0x8, 0x2, 0x4, 0x2, 0x8, 0x3, 0x0, 0x7, 0x3, 0x2, 0x0, 0x3, 0x1, 0x8, 0x2, 0x4, 0x5, 0xE}; 
// byte data2[] = {0xF, 0x8, 0x2, 0x4, 0x2, 0x8, 0x3, 0x0, 0x7, 0x3, 0x2, 0x0, 0x3, 0x1, 0x8, 0x2, 0x4, 0x5, 0xE}; 
// byte data3[] = {0xF, 0x8, 0x2, 0x4, 0x2, 0x8, 0x3, 0x0, 0x8, 0x3, 0x2, 0x0, 0x3, 0x1, 0x8, 0x3, 0x4, 0x7, 0x3};  
// byte packet_size = 19;

//THGN132  
//  byte data1[] = {0x1, 0xD, 0x2, 0x0, 0x4, 0xB, 0xB, 0xC, 0x0, 0x0, 0x5, 0x8, 0x8, 0x9, 0x8, 0xC, 0x5, 0xE, 0x5};
//  byte data2[] = {0x1, 0xD, 0x2, 0x0, 0x1, 0x1, 0xB, 0x0, 0x4, 0x3, 0x2, 0x0, 0x5, 0x2, 0x8, 0x5, 0x3, 0x0, 0xF};
//  byte data3[] = {0x1, 0xD, 0x2, 0x0, 0x1, 0xB, 0xF, 0x8, 0x5, 0x6, 0x2, 0x0, 0x5, 0x2, 0x8, 0xF, 0x4, 0x3, 0xF};
//  byte packet_size = 19;
 
//UVN800
//  byte data1[] = {0xD, 0x8, 0x7, 0x4, 0x1, 0x5, 0x6, 0x0, 0x0, 0x0, 0xF, 0x6, 0x0, 0x1, 0x4, 0x5, 0xB};
//  byte data2[] = {0xD, 0x8, 0x7, 0x4, 0x1, 0x5, 0x6, 0x0, 0x1, 0x0, 0x5, 0x8, 0x0, 0xa, 0x3, 0x2, 0xf};
//  byte data3[] = {0xD, 0x8, 0x7, 0x4, 0x1, 0x5, 0x6, 0x0, 0x1, 0x0, 0x5, 0x8, 0x0, 0xa, 0x3, 0x2, 0xf};
//  byte packet_size = 17;

//WGR800
// byte data1[] = {0x1, 0x9, 0x8, 0x4, 0x0, 0x0, 0x1, 0x0, 0x7, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xA, 0x2, 0x4, 0xC};
// byte data2[] = {0x1, 0x9, 0x8, 0x4, 0x0, 0x0, 0x1, 0x0, 0x8, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xB, 0x2, 0x4, 0xF};
// byte data3[] = {0x1, 0x9, 0x8, 0x4, 0x0, 0x0, 0x1, 0x0, 0x2, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x2, 0x9, 0x2};
// byte packet_size = 21;

// PCR800
// byte data1[] = {0x2, 0x9, 0x1, 0x4, 0x0, 0xE, 0xC, 0x0, 0x5, 0x5, 0x0, 0x0, 0x3, 0x6, 0x2, 0x5, 0x1, 0x0, 0x5, 0x4, 0x6, 0x6};
// byte data2[] = {0x2, 0x9, 0x1, 0x4, 0x0, 0xE, 0xC, 0x0, 0x2, 0x7, 0x9, 0x0, 0x0, 0x2, 0x2, 0x5, 0x1, 0x0, 0x6, 0x4, 0x0, 0x2};
// byte data3[] = {0x2, 0x9, 0x1, 0x4, 0x0, 0xE, 0xC, 0x0, 0x4, 0x9, 0x0, 0x0, 0x5, 0x8, 0x3, 0x5, 0x1, 0x0, 0xD, 0x4, 0xC, 0x7};
// byte packet_size = 22;

// RTGN318
// byte data1[] = {0xB, 0xC, 0xC, 0x3, 0x1, 0x1, 0x9, 0x0, 0x2, 0x3, 0x0, 0x0, 0x0, 0x8, 0xC, 0xA, 0x4, 0x9, 0xA};
// byte data2[] = {0xA, 0xC, 0xC, 0x3, 0x3, 0xE, 0x8, 0x8, 0x4, 0x3, 0x2, 0x0, 0x0, 0x3, 0x8, 0xA, 0x5, 0x4, 0x2};
// byte data3[] = {0xC, 0xC, 0xC, 0x3, 0x2, 0xE, 0xA, 0x8, 0x0, 0x5, 0x2, 0x0, 0x0, 0x3, 0x8, 0xB, 0x5, 0x7, 0x1};
// byte packet_size = 19;


  int j, k;
  Serial.println("POLY\tSTART_SUM");
  for(j = 0; j < 256; j++) 
  {
    for(k = 0; k < 256; k++) 
    {
      if (oregon.check_oregon_crcsum(data1, t_crc, t_sum, packet_size) && oregon.check_oregon_crcsum(data2, t_crc, t_sum, packet_size) && oregon.check_oregon_crcsum(data3, t_crc, t_sum, packet_size))
      {
      Serial.print(t_crc,HEX);
      Serial.print('\t');
      Serial.print(t_sum,HEX);
      Serial.println();
      }
      t_sum++;
    }
    t_crc++;
  }
  Serial.println("DONE");
}

void loop()
{
 delay(100); 
}

