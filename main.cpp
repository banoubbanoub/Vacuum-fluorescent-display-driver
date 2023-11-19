#include <Arduino.h>
#include<SPI.h>
#include<Display.h>

#define powerSwitch 4
#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>               
#include <TimeLib.h> 
 


const char *ssid     = "";
const char *password = "";
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "asia.pool.ntp.org", 20700, 60000);
 
char Time[ ] = "TIME:00:00:00";
char Date[ ] = "DATE:00/00/2000";
byte last_second, second_, minute_, hour_, day_, month_;
int year_;

int getStrength(int points){
    long rssi = 0;
    long averageRSSI = 0;
    
    for (int i=0;i < points;i++){
        rssi += WiFi.RSSI();
        //delay(20);
    }

   averageRSSI = rssi/points;
    return averageRSSI;
}


void SPItask(){
SPIinit();

pinMode(powerSwitch,OUTPUT);
digitalWrite(powerSwitch,LOW);
digitalWrite(seg_strob,HIGH);
digitalWrite(grid_strob,HIGH);
delay(50);
digitalWrite(powerSwitch,HIGH);
delay(50);
}

void taskt(void* p){
  SPItask();
  int t=0;
int f=14;
while (1)
{
 
      timeClient.update();
  unsigned long unix_epoch = timeClient.getEpochTime();    // Get Unix epoch time from the NTP server
 
  second_ = second(unix_epoch);
  if (last_second != second_) {
 
    t++;
    if(t >=999999)t=0;
    f--;
    if(f <0)f=14;
    minute_ = minute(unix_epoch);
    hour_   = hour(unix_epoch);
    day_    = day(unix_epoch);
    month_  = month(unix_epoch);
    year_   = year(unix_epoch);
 
 
 
    Time[12] = second_ % 10 + 48;
    Time[11] = second_ / 10 + 48;
    Time[9]  = minute_ % 10 + 48;
    Time[8]  = minute_ / 10 + 48;
    Time[6]  = hour_   % 10 + 48;
    Time[5]  = hour_   / 10 + 48;

 

    Date[5]  = day_   / 10 + 48;
    Date[6]  = day_   % 10 + 48;
    Date[8]  = month_  / 10 + 48;
    Date[9]  = month_  % 10 + 48;
    Date[13] = (year_   / 10) % 10 + 48;
    Date[14] = year_   % 10 % 10 + 48;
    last_second = second_;
    getStrength(2);
  }
  /*
SetCours(5,2);
DisplayRow_2_Number(hour_);
SetCours(4,2);
DisplayRow_2_Number(minute_);
SetCours(3,2);
DisplayRow_2_Number(second_);
SetCours(0,2);
Display_G_15_Number(second_);
SetCours(1,2);
DisplayIconGrid_16("wifi");
*/
//SetCours(0,1);
//Display(t*9);

SetCours(4,1);
//Display("{Hello world}");



}
}

void setup() {
 SPItask();
 digitalWrite(seg_strob,LOW);
digitalWrite(grid_strob,LOW);
/*
  xTaskCreatePinnedToCore(taskt,"t",4096,(void *)1,2,NULL,1);
   WiFi.begin(ssid, password);
 while ( WiFi.status() != WL_CONNECTED ) {
   // delay(500);
   // Serial.print(".");
  }

  timeClient.begin();
  */
}


void loop() {
  
SetCours(0,1);
Display("{Hello world} ");

 
}

