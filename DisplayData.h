#include<Arduino.h>
byte shiftRegisterBytes[4];

byte* PowerOne(){
  shiftRegisterBytes[0] = 0x44;
  shiftRegisterBytes[1] = 0x44;
  shiftRegisterBytes[2] = 0x44;
  shiftRegisterBytes[3] = 0x44;
  return shiftRegisterBytes;
}
//*************************************
// data for Girds
//****************
byte gridsData_35DotMatrix[14][4] ={
  // Gird number
  //G 1        G2         G3            G4       G5        G6        G7          G8         G9       G10
  {128,0,0,0},{64,0,0,0},{32,0,0,0},{16,0,0,0},{8,0,0,0},{4,0,0,0},{2,0,0,0},{1,0,0,0},{0,128,0,0},{0,64,0,0},
  // G11        G12       G13         G14      
  {0,32,0,0},{0,16,0,0},{0,8,0,0},{0,4,0,0}};//
  //                                        G15       G16         G17        G18       G19         G20 
 byte gridData_Row2_IconAndNumber[6][4]= {{0,2,0,0},{0,1,0,0},{0,0,128,0},{0,0,64,0},{0,0,32,0},{0,0,16,0}};

//**************************
// Alphabet_14Segments lift hand digit
// work only from grid 16 to 19 row 2
//******************************
byte* Alphabet_14Segments_L(char c){
if(isspace(c)){
  shiftRegisterBytes[0]=0;
  shiftRegisterBytes[1]=0;
  shiftRegisterBytes[2]=0;
  shiftRegisterBytes[3] =0;
}
 switch(c){
  case 'a':
 shiftRegisterBytes[0]=32;
 shiftRegisterBytes[1]=37;
 shiftRegisterBytes[2]=32;
 shiftRegisterBytes[3]=40;
 break;
 case 'b':
 shiftRegisterBytes[0]=160;
 shiftRegisterBytes[1]=37;
 shiftRegisterBytes[2]=32;
 shiftRegisterBytes[3]=0;
 break;
 case 'c':
 shiftRegisterBytes[0]=160;
 shiftRegisterBytes[1]=0;
 shiftRegisterBytes[2]=32;
 shiftRegisterBytes[3]=8;
 break;
 case 'd':
 shiftRegisterBytes[0]=160;
 shiftRegisterBytes[1]=37;
 shiftRegisterBytes[2]=1;
 shiftRegisterBytes[3]=32;
 break;
 case 'e':
 shiftRegisterBytes[0]=160;
 shiftRegisterBytes[1]=4;
 shiftRegisterBytes[2]=32;
 shiftRegisterBytes[3]=8;
 break;
 case 'f':
 shiftRegisterBytes[0]=32;
 shiftRegisterBytes[1]=4;
 shiftRegisterBytes[2]=32;
 shiftRegisterBytes[3]=0;
 break;
  case 'p':
  shiftRegisterBytes[0]=32;
  shiftRegisterBytes[1]=5;
  shiftRegisterBytes[2]=32;
  shiftRegisterBytes[3]=40;
  break;
 case 'm':
 shiftRegisterBytes[0]=32;
 shiftRegisterBytes[1]=32;
 shiftRegisterBytes[2]=34;
 shiftRegisterBytes[3]=40;
 break;
 
 }
 return shiftRegisterBytes;
}
//****************************
// alphabet 14 segments right-hand digit only row 2 
//from grid 16 to 19
//***************************************
byte* Alphabet_14Segments_R(char c){
if(isspace(c)){
  shiftRegisterBytes[0]=0;
  shiftRegisterBytes[1]=0;
  shiftRegisterBytes[2]=0;
  shiftRegisterBytes[3] =0;
}
 switch(c){
  case 'a':
  shiftRegisterBytes[0]=16;
  shiftRegisterBytes[1]=18;
  shiftRegisterBytes[2]=144;
  shiftRegisterBytes[3]=20;
  break;
  case 'b':
  shiftRegisterBytes[0]=80;
  shiftRegisterBytes[1]=18;
  shiftRegisterBytes[2]=144;
  shiftRegisterBytes[3]=0;
  break;
  case 'c':
  shiftRegisterBytes[0]=80;
  shiftRegisterBytes[1]=0;
  shiftRegisterBytes[2]=16;
  shiftRegisterBytes[3]=4;
  break;
  case 'd':
  shiftRegisterBytes[0]=80;
  shiftRegisterBytes[1]=18;
  shiftRegisterBytes[2]=128;
  shiftRegisterBytes[3]=16;
  break;
  case 'e':
  shiftRegisterBytes[0]=80;
  shiftRegisterBytes[1]=2;
  shiftRegisterBytes[2]=144;
  shiftRegisterBytes[3]=4;
  break;
  case 'f':
  shiftRegisterBytes[0]=16;
  shiftRegisterBytes[1]=2;
  shiftRegisterBytes[2]=144;
  shiftRegisterBytes[3]=0;
  break;
  case 'p':
  shiftRegisterBytes[0]=16;
  shiftRegisterBytes[1]=2;
  shiftRegisterBytes[2]=144;
  shiftRegisterBytes[3]=20;
  break;
  case 'm':
  shiftRegisterBytes[0]=0;
  shiftRegisterBytes[1]=0;
  shiftRegisterBytes[2]=17;
  shiftRegisterBytes[3]=20;
  break;
 // default:
 // shiftRegisterBytes[0]=80;
 // shiftRegisterBytes[1]=16;
 // shiftRegisterBytes[2]=16;
 // shiftRegisterBytes[3]=20;
 // break;

 }
 return shiftRegisterBytes;
}
//***************************************
// digits data for 14 segments 9 digits
// Note it work only from grid 16 to grid 20
// Note for the left hand digit only from grid 16 to 20
//****************************************************
byte* Number_14SegmentsDigit_1L(uint8_t number){
  switch (number)
  {
  case 0:
    shiftRegisterBytes[0] = 160;
    shiftRegisterBytes[1] = 32;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 40;
    break;
  case 1:
    shiftRegisterBytes[0] = 32;
    shiftRegisterBytes[1] = 0;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 0;
    break;
    case 2:
    shiftRegisterBytes[0] = 160;
    shiftRegisterBytes[1] = 5;
    shiftRegisterBytes[2] = 0;
    shiftRegisterBytes[3] = 40;
    break;
    case 3:
    shiftRegisterBytes[0] = 128;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 0;
    shiftRegisterBytes[3] = 40;
    break;
    case 4:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 32;
    break;
    case 5:
    shiftRegisterBytes[0] = 128;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 8;
    break;
    case 6:
    shiftRegisterBytes[0] = 160;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 8;
    break;
    case 7:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 32;
    shiftRegisterBytes[2] = 0;
    shiftRegisterBytes[3] = 40;
    break;
    case 8:
    shiftRegisterBytes[0] = 160;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 40;
    break;
    case 9:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 37;
    shiftRegisterBytes[2] = 32;
    shiftRegisterBytes[3] = 40;
    break;

  }

 return shiftRegisterBytes;
}
//***************************************
// Numbers data for 14 segments 9 digits
// Note it works only from grid 16 to grid 20
// Note for the right hand digit only from grid 16 to 20
//****************************************************
byte* Number_14SegmentsDigit_2R(uint8_t number){
 
  switch (number)
  {
  case 0:
    shiftRegisterBytes[0] = 80;
    shiftRegisterBytes[1] = 16;
    shiftRegisterBytes[2] = 16;
    shiftRegisterBytes[3] = 20;
    break;
  case 1:
    shiftRegisterBytes[0] = 16;//16
    shiftRegisterBytes[1] = 0;
    shiftRegisterBytes[2] = 16;//16
    shiftRegisterBytes[3] = 0;
    break;
    case 2:
    shiftRegisterBytes[0] = 80;
    shiftRegisterBytes[1] = 2;
    shiftRegisterBytes[2] = 128;
    shiftRegisterBytes[3] = 20;
    break;
    case 3:
    shiftRegisterBytes[0] = 64;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 128;
    shiftRegisterBytes[3] = 20;
    break;
    case 4:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 144;
    shiftRegisterBytes[3] = 16;
    break;
    case 5:
    shiftRegisterBytes[0] = 64;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 144;
    shiftRegisterBytes[3] = 4;
    break;
    case 6:
    shiftRegisterBytes[0] = 80;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 144;
    shiftRegisterBytes[3] = 4;
    break;
    case 7:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 16;
    shiftRegisterBytes[2] = 0;
    shiftRegisterBytes[3] = 20;
    break;
    case 8:
    shiftRegisterBytes[0] = 80;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 144;
    shiftRegisterBytes[3] = 20;
    break;
    case 9:
    shiftRegisterBytes[0] = 0;
    shiftRegisterBytes[1] = 18;
    shiftRegisterBytes[2] = 144;
    shiftRegisterBytes[3] = 20;
    break;

  }

 return shiftRegisterBytes;
}
//*****************************************
// digits data for 7 segments one digit
// note work only in right-hand digit in gird 15 only
//****************************************************
byte* Number_7SegmentsGird_15R(uint8_t number){

  switch(number){
  case 0:
  shiftRegisterBytes[0] = 0;
  shiftRegisterBytes[1] = 29;
  shiftRegisterBytes[2] = 192;
  shiftRegisterBytes[3] = 0;
  break;
  case 1:
  shiftRegisterBytes[0] = 0;
  shiftRegisterBytes[1] = 4;
  shiftRegisterBytes[2] = 128;
  shiftRegisterBytes[3] = 0;
  break;
  case 2:
  shiftRegisterBytes[0] = 0;
  shiftRegisterBytes[1] = 26;
  shiftRegisterBytes[2] = 192;
  shiftRegisterBytes[3] =0;
  break;
  case 3:
  shiftRegisterBytes[0] = 0;
  shiftRegisterBytes[1] = 22;
  shiftRegisterBytes[2] = 192;
  shiftRegisterBytes[3] = 0;
  break;
  case 4:
  shiftRegisterBytes[0] = 0;
  shiftRegisterBytes[1] = 7;
  shiftRegisterBytes[2] = 128;
  shiftRegisterBytes[3] = 0;
  break;
  case 5:
  shiftRegisterBytes[0] = 0;
  shiftRegisterBytes[1] = 23;
  shiftRegisterBytes[2] = 64;
  shiftRegisterBytes[3] = 0;
  break;
  case 6:
  shiftRegisterBytes[0] =0;
  shiftRegisterBytes[1] = 31;
  shiftRegisterBytes[2] = 64;
  shiftRegisterBytes[3] = 0;
  break;
  case 7:
  shiftRegisterBytes[0] = 0;
  shiftRegisterBytes[1] = 4;
  shiftRegisterBytes[2] = 192;
  shiftRegisterBytes[3] = 0;
  break; 
  case 8:
  shiftRegisterBytes[0] = 0;
  shiftRegisterBytes[1] = 31;
  shiftRegisterBytes[2] = 192;
  shiftRegisterBytes[3] = 0;
  break;
  case 9:
  shiftRegisterBytes[0] = 0;
  shiftRegisterBytes[1] = 7;
  shiftRegisterBytes[2] = 192;
  shiftRegisterBytes[3] = 0;
  break;
  }

 return shiftRegisterBytes;
}
//*****************************************
// digits data for 7 segments one digit
// note work only in left-hand digit in gird 15 only
//****************************************************
byte* Number_7SegmentsGird_15L(uint8_t number){

  switch(number){
  case 0:
  shiftRegisterBytes[0] = 29;
  shiftRegisterBytes[1] = 192;
  shiftRegisterBytes[2] = 0;
  shiftRegisterBytes[3] = 0;
  break;
  case 1:
  shiftRegisterBytes[0] = 4;
  shiftRegisterBytes[1] = 128;
  shiftRegisterBytes[2] = 0;
  shiftRegisterBytes[3] = 0;
  break;
  case 2:
  shiftRegisterBytes[0] = 26;
  shiftRegisterBytes[1] = 192;
  shiftRegisterBytes[2] = 0;
  shiftRegisterBytes[3] =0;
  break;
  case 3:
  shiftRegisterBytes[0] = 22;
  shiftRegisterBytes[1] = 192;
  shiftRegisterBytes[2] = 0;
  shiftRegisterBytes[3] = 0;
  break;
  case 4:
  shiftRegisterBytes[0] = 7;
  shiftRegisterBytes[1] = 128;
  shiftRegisterBytes[2] = 0;
  shiftRegisterBytes[3] = 0;
  break;
  case 5:
  shiftRegisterBytes[0] = 23;
  shiftRegisterBytes[1] = 64;
  shiftRegisterBytes[2] = 0;
  shiftRegisterBytes[3] = 0;
  break;
  case 6:
  shiftRegisterBytes[0] =31;
  shiftRegisterBytes[1] = 64;
  shiftRegisterBytes[2] = 0;
  shiftRegisterBytes[3] = 0;
  break;
  case 7:
  shiftRegisterBytes[0] = 4;
  shiftRegisterBytes[1] = 192;
  shiftRegisterBytes[2] = 0;
  shiftRegisterBytes[3] = 0;
  break; 
  case 8:
  shiftRegisterBytes[0] = 31;
  shiftRegisterBytes[1] = 192;
  shiftRegisterBytes[2] = 0;
  shiftRegisterBytes[3] = 0;
  break;
  case 9:
  shiftRegisterBytes[0] = 7;
  shiftRegisterBytes[1] = 192;
  shiftRegisterBytes[2] = 0;
  shiftRegisterBytes[3] = 0;
  break;
  }
return shiftRegisterBytes;
}
//**********************************
// Icon data work in gird 15 only
//**********************************
byte* Icon_Gired_15(String iconp){ // only work in grid number 15
 
  
  // VOL icon
 if(iconp == "vol"){
   shiftRegisterBytes[0] = 128;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
 }

  //mute icon
  if(iconp == "mute"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 32;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
  }

   // .db icon
  if(iconp == "db"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 32;
   shiftRegisterBytes[3] = 0;
  }
  
  // - 
  if(iconp =="-"){
   shiftRegisterBytes[0] = 64;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
  }

  // ::.
  if(iconp == "::"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 2;
   shiftRegisterBytes[3] = 0;
  }
 // Addaptive drc icon
   if(iconp =="addaptive"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 1;
   shiftRegisterBytes[3] = 0;
   }
 // virtual icon
  if(iconp == "virtual"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 128;
  }
//SL Icon
  if(iconp == "sl"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 64;
  }
 // SW icon
  if(iconp == "sw"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 32;
  }
 // SR icon
  if(iconp =="sr"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 16;
  }
 // SBL icon
   if(iconp == "sbl"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 8;
   }
 // SB icon
  if(iconp == "sb"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 4;
  }
// SBR Icon
   if(iconp == "sbr"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 2;
   }
// number one in grid 15
   if(iconp == "1"){
   shiftRegisterBytes[0] = 32;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
   }
return shiftRegisterBytes;
}
//*****************************
// on digit grid 15 
//*****************************
 byte* Fan_Grid_15(){

 // switch(f){
   //case 1:
   shiftRegisterBytes[0] =0;
   shiftRegisterBytes[1] = 0 ;
   shiftRegisterBytes[2] = 28;
   shiftRegisterBytes[3] = 0;
 //  break;
  //}

 return shiftRegisterBytes;
}
byte * WIFIiconStatue(int p){
  switch (p)
  {
  case 1:
    shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 64;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
  break;
  case 2:
    shiftRegisterBytes[0] = 16;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
  break;
  case 3:
    shiftRegisterBytes[0] = 4;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
  break;
  case 4:
    shiftRegisterBytes[0] = 1;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
  break;
case 5:
    shiftRegisterBytes[0] = 16;
   shiftRegisterBytes[1] = 64;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
  break;
  case 6:
    shiftRegisterBytes[0] = 20;
   shiftRegisterBytes[1] = 64;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
  break;
  case 7:
    shiftRegisterBytes[0] = 21;
   shiftRegisterBytes[1] = 64;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
  break;
  }
 return shiftRegisterBytes;
}
//***********************************
// Icon data work in grid 16 only
//***********************************
byte* Icon_Gird_16(String iconp){ // only work in grid number 16

 
   //WIFI icon
   if(iconp == "wifi"){
   shiftRegisterBytes[0] = 21;
   shiftRegisterBytes[1] = 64;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
   }
 //bluetooth icon
 if(iconp =="bluetooth"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 16;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
 }
    //ZONE 2 A icon
    if(iconp =="zone2A"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 8;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
    }

    //Zone 3 B icon
    if(iconp == "zone3B"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 2;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
    }
  // Sleep icon
  if(iconp =="sleep"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 1;
   shiftRegisterBytes[3] = 0;
  }
    //party icon
    if(iconp =="party"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 64;
    }
    // Tuned icon
    if(iconp=="tuned"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 16;
    }
    // Stereo icon
    if(iconp == "stereo"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 4;
    }
    //Enhancer icon
    if(iconp == "enhancer"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 2;
    }
    // Cinema DSP icon
    if(iconp == "cinema"){
   shiftRegisterBytes[0] = 64;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
    }
  
return shiftRegisterBytes;
}
//*********************************
// icon in grid 20
// work only in grid 20
//************************************
byte* Icon_Grid_20(String icon){

  // HDMI icon
  if(icon =="HDMI"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 8;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
  }
    // Charge icon
    if(icon =="charge"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 64;
   shiftRegisterBytes[3] = 0;
    }
  // squar 1
  if(icon == "squar1"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 1;
  }
   // squar 2
   if(icon == "squar2"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 2;
   }
   
    // OUT icon
    if(icon == "OUT"){
   shiftRegisterBytes[0] = 0;
   shiftRegisterBytes[1] = 0;
   shiftRegisterBytes[2] = 0;
   shiftRegisterBytes[3] = 0;
    }
   
return shiftRegisterBytes;

}
uint8_t FontCharMap[128] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,
	35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,
	67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,
 };

const byte FontCharForDotMatrixData[][4]={
0,0,0,0, //    space
33,8,66,0,  //    !
82,148,0,0, //    "
82,190,175,169,// #
35,232,226,248,// $
198,68,68,76,//   %
100,168,138,201,//&
33,8,00,00,//     '
17,16,132,16,//   (
65,4,32,17,//     )
1,42,234,144,//   *
1,9,242,16,//    +
00,00,6,17,//    ,
0,1,240,00,//    -
00,00,00,49,//   .
00,68,68,64,//   /
116,103,92,197,//0
35,8,66,17,//    1
116,66,34,35,//  2
248,136,32,197,//3
17,149,47,136,// 4
252,60,16,197,// 5
50,33,232,197,// 6
248,68,68,33,//  7
116,98,232,197,//8
116,98,240,137,//9
00,8,2,0,//      :
3,24,6,17,//     ;
17,17,4,16,//    <
0,62,15,128,//   =
65,4,17,17,//    >
116,66,34,00,//  ?
116,64,218,213,//@
116,99,248,198,//A
244,99,232,199,//B
116,97,8,69,//  C
228,163,24,203,//D
252,33,232,67,//E
252,33,232,66,// F
116,97,120,197,//G
140,99,248,198,//H
113,8,66,17,//   I
56,132,33,73,//  J
140,169,138,74,//K
132,33,8,67,//  L
142,235,88,198,//M
140,115,89,198,//N
116,99,24,197,// O
244,99,232,66,// P
116,99,26,201,//  Q
244,99,234,74,// R
124,32,224,135,//S
249,8,66,16, //  T
140,99,24,197,// U
140,99,24,168,//  V
140,99,90,213,// W
140,84,69,70,//  X
140,98,162,16,// Y
248,68,68,67,// Z
114,16,132,33,// [
138,190,79,144,//   *\*
112,132,33,9,// ]
1,21,16,0,//    ^
00,00,00,3,// _
00,00,2,16,//    ,
0,28,23,197,//   a
132,33,232,199,//b
0,31,8,65,//     c
8,66,248,197,//  d
0,29,31,193,//   e
17,72,226,16,//  f
0,31,23,135,//   g
132,33,232,198,//h
1,0,66,16,//     i
16,4,33,73,//    j
66,18,166,41,//  k
97,8,66,17,//    l
0,55,90,214,//   m
0,45,152,198,//  n
0,29,24,197,//   o
0,61,31,66,//    p
0,31,23,132,//   q
0,45,152,66,//   r
0,31,7,7,//      s
33,62,66,20,//   t
0,35,24,197,//   u
0,35,24,168,//   v
0,35,26,213,//   w
0,34,162,42,//   x
0,34,162,17,//   y
0,62,34,35,//    z
50,17,4,32,//    {
33,8,2,16,//     |
96,132,17,9,//    }
11,160,00,00,//   ~
};
//********************************************
//The shift register is 32-bit, but the display is 5x7 DOT matrix = 35-bit
//So I did use 3 more bits from the second shift register 
//****************************************************
const byte FontCharForDotMatrix35[][1]={
0,//   space
2,//      !
0,//      "
4,//      #
2,//      $
12,//     %
10,//     &
0,//      '
4,//      (
0,//      )
0,//      *
0,//      +
0,//      ,
0,//      -
2,//      .
0,//      /
6,//      0
6,//      1
14,//     2
6,//      3
4,//      4
6,//      5
6,//      6
0,//      7
6,//      8
2,//      9
0,//      :
0,//      ;
4,//      <
0,//      =
0,//      >
2,//      ?
6,//      @
8,//      A
6,//      B
6,//      C
2,//      D
14,//     E
0,//      F
14,//     G
8,//      H
6,//      I
2,//      J
8,//      K
14,//     L
8,//      M
8,//      N
6,//      O
0,//      P
10,//     Q
8,//      R
6,//      S
2, //     T
6,//      U
2,//      V
4,//      W
8,//      X
2,//      Y
14,//     Z
6,//     [
2,//     *\*
6,//      ]
0,//      ^
14,//     _
0,//      ,
14,//     a
6,//     b
14,//     c
14,//     d
14,//     e
2,//      f
6,//      g
8,//      h
2,//     i
2,//     j
8,//     k
6,//     l
8,//     m
8,//     n
6,//    o
0,//     p
8,//     q
0,//      r
6,//      s
4,//      t
6,//   u
2,//   v
4,//   w
8,//   x
0,//   y
14,//    z
6,//    {
2,//     |
2,//    }
0,//   ~
};
