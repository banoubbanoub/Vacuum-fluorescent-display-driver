#include<Arduino.h>
#include<DisplayData.h>
#include<SPI.h>
#define seg_latch 16
#define seg_strob  2
#define grid_latch 15
#define grid_strob 17

byte gridArray[4];
uint8_t gridNumber;


void SPIinit(){
pinMode(seg_latch,OUTPUT);
pinMode(seg_strob,OUTPUT);
pinMode(grid_latch,OUTPUT);
pinMode(grid_strob,OUTPUT);
SPI.begin();
SPI.beginTransaction(SPISettings(1000000,LSBFIRST,SPI_MODE3));

}

void ClearDisplay(){
  //digitalWrite(seg_strob,HIGH);
  digitalWrite(seg_latch,HIGH);
 //digitalWrite(grid_strob,HIGH);
 digitalWrite(grid_latch,HIGH);
  digitalWrite(seg_latch,LOW);
  digitalWrite(grid_latch,LOW);
  //digitalWrite(seg_strob,LOW);
  //digitalWrite(grid_strob,LOW);
}

void powerOnDisplay(){
 
   ClearDisplay();
   shiftRegisterBytes[0]=0XFF;
   shiftRegisterBytes[1]=0XFF;
   shiftRegisterBytes[2]=0XFF;
   shiftRegisterBytes[3]=0XFF;
   for(int16_t y=3;y>=0;y--){
    SPI.transfer(shiftRegisterBytes[y]);
   }
    for(int16_t x=3;x>=0;x--){
     SPI.transfer(PowerOne()[x]);
    }
}


                         

 


String rS;
char  rc;
uint8_t q;


////***********************************
// grids data method
//*******************************
byte* GridsData(uint8_t gridNumber){
  uint8_t index=0;
  for(uint8_t x=0; x< 4;x++){
   gridArray[x] = gridData_Row2_IconAndNumber[gridNumber][x];

   if(q ==2 && gridNumber >=14&& gridNumber!=19){
    gridArray[3] = 0;
   }
  if(q==2&&gridNumber==19){
    gridArray[3]=0;
  }
  }
    return gridArray;
}
 void SetCours(uint8_t col,uint8_t row){
 switch (row)
 {
 case 1:
  //if(col >=14 || col < sizeof(gridsData)-6) gridNumber = 14;
  break;
  case 2:
  //if(col > sizeof(gridsData) || col < sizeof(gridsData)-6)gridNumber = 19 ;
   break;
 }
gridNumber = col;
}


//****************************
//Method to display string 
// note from grid 1 to 14 only row 1
//******************************
void Display(const char * str /*String str*/){
uint8_t index =0; 
uint8_t plac=0;
char c;
uint8_t gridnum = 0;
//ClearDisplay();
while (str[plac])
//for(int xy=0;xy< str.length();xy++)
{
    c = str[plac];
    //c = str.charAt(xy);
    index = FontCharMap[c&0x7f];

    ClearDisplay();
   for(int16_t y=3;y>=0;y--){
    gridsData_35DotMatrix[gridNumber+gridnum][3] = FontCharForDotMatrix35[index][0]+16; // 16 is for the red line in the first row
    SPI.transfer(gridsData_35DotMatrix[gridNumber+gridnum][y]);
   }

    for(int16_t x=3;x>=0;x--){
     SPI.transfer(FontCharForDotMatrixData[index][x]);
    }
      gridnum++;
      plac++;
    if(gridNumber + gridnum >= 14){gridnum=0;return;}
    if( gridnum >= 14){gridnum=0;}
   
     if(plac > 14)
     {
     
      //return;
  
     }
    
  }
}

//******************************
//Display number first row 35 dot matrix
//**********************************
void Display(int number){
uint8_t gridnum=0;
uint8_t index =0; 
char c;
String num = String(number);
for(int x=0;x <  num.length() ;x++){
  c = num.charAt(x);
  index = FontCharMap[c&0x7f];
      ClearDisplay();
   for(int16_t y=3;y>=0;y--){
     gridsData_35DotMatrix[gridNumber+gridnum][3] = FontCharForDotMatrix35[index][0]+16; // 16 is for the red line in the first row
    SPI.transfer(gridsData_35DotMatrix[gridNumber+gridnum][y]);
   }
    for(int16_t x=3;x>=0;x--){
     SPI.transfer(FontCharForDotMatrixData[index][x]);
    }
    gridnum++;
    if( gridnum >=14){gridnum=0;}
}
 if(num.length() > 14){return;}
 }




//**********************
// Display digits row 2 from grid 16 to 19
//************************************
void DisplayRow_2_Number(uint8_t number){
  //SPI.beginTransaction(SPISettings(1000000,LSBFIRST,SPI_MODE3));
  uint8_t a[] = {(number /10)%10,number %10};
      ClearDisplay();
    for(int16_t y=3;y>=0;y--){
    SPI.transfer(GridsData(gridNumber)[y]);
   }
     for(int16_t x=3;x>=0;x--){
     SPI.transfer(Number_14SegmentsDigit_1L(a[0])[x]);
     }

      ClearDisplay();
    for(int16_t y=3;y>=0;y--){
    SPI.transfer(GridsData(gridNumber)[y]);
   }
      for(int16_t x=3;x>=0;x--){
     SPI.transfer(Number_14SegmentsDigit_2R(a[1])[x]);
    } 
}
//************************************
// dispaly alphabet row 2 from grid 16 to 19 only
//************************************
void DisplayAlphaBet_14SegmentsRow_2(String str){
  //SPI.beginTransaction(SPISettings(1000000,LSBFIRST,SPI_MODE3));
  char c1 ;
  char c2;  
   // for(uint8_t x=0;x< str.length();x++){
      ClearDisplay();
    for(int16_t y=3;y>=0;y--){
      SPI.transfer(GridsData(gridNumber)[y]);
    }
       c1 = str.charAt(0);
        for(int16_t y =3;y>=0;y--){
        SPI.transfer(Alphabet_14Segments_L(c1)[y]);
       }
       ClearDisplay();
    for(int16_t y=3;y>=0;y--){
      SPI.transfer(GridsData(gridNumber)[y]);
    }
       c2 = str.charAt(1);
        for(int16_t y =3;y>=0;y--){
        SPI.transfer(Alphabet_14Segments_R(c2)[y]);
       }
   // }
}
//*******************************************
//Display digits in grid 15 only 
//note only two digit
//********************************************
void Display_G_15_Number(uint8_t number){
  //SPI.beginTransaction(SPISettings(1000000,LSBFIRST,SPI_MODE3));
  uint8_t a[] ={(number /10)%10,number %10};
      ClearDisplay();
    for(int16_t y=3;y>=0;y--){
    SPI.transfer(GridsData(gridNumber)[y]);
   }
     for(int16_t x=3;x>=0;x--){
     SPI.transfer(Number_7SegmentsGird_15L(a[0])[x]);
    } 
      ClearDisplay();
    for(int16_t y=3;y>=0;y--){
    SPI.transfer(GridsData(gridNumber)[y]);
   }
     for(int16_t x=3;x>=0;x--){
     SPI.transfer(Number_7SegmentsGird_15R(a[1])[x]);
    }     
}
//********************************
// Display icons in grid 15 only row 2
//*********************************
void DisplayIconGrid_15(String icon){
  //SPI.beginTransaction(SPISettings(1000000,LSBFIRST,SPI_MODE3));
      ClearDisplay();
    for(int16_t y=3;y>=0;y--){
    SPI.transfer(GridsData(gridNumber)[y]);
   }
    for(int16_t x=3;x>=0;x--){
     SPI.transfer(Icon_Gired_15(icon)[x]);
    }
}
void DisplayWIFI(int p){
  ClearDisplay();
   for(int16_t y=3;y>=0;y--){
    SPI.transfer(GridsData(gridNumber)[y]);
   }
    for(int16_t x=3;x>=0;x--){
     SPI.transfer(WIFIiconStatue(p)[x]);
    }
}
//********************************
// Display icons in grid 16 only row 2
//*********************************
void DisplayIconGrid_16(String icon){
  //SPI.beginTransaction(SPISettings(1000000,LSBFIRST,SPI_MODE3));
      ClearDisplay();
    for(int16_t y=3;y>=0;y--){
    SPI.transfer(GridsData(gridNumber)[y]);
   }
    for(int16_t x=3;x>=0;x--){
     SPI.transfer(Icon_Gird_16(icon)[x]);
    }
}
 //********************************
// Display icons in grid 20 only row 2
//*********************************
void DisplayIconGrid_20(String icon){
  //SPI.beginTransaction(SPISettings(1000000,LSBFIRST,SPI_MODE3));
   rS = icon;
    ClearDisplay();
    for(int16_t y=3;y>=0;y--){
    SPI.transfer(GridsData(gridNumber)[y]);
   }
    for(int16_t x=3;x>=0;x--){
     SPI.transfer(Icon_Grid_20(icon)[x]);
    }
}
