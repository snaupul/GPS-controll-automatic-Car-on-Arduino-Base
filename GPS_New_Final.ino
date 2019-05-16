 
#include <Adafruit_GPS.h> //Load the GPS Library. Make sure you have installed the library form the adafruit site above
#include <SoftwareSerial.h> //Load the Software Serial Library. This library in effect gives the arduino additional serial ports
#include <LiquidCrystal.h>

int rs = 8;
int en = 9;
int d4 = 10;
int d5 = 11;
int d6 = 12;
int d7 = 13;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

SoftwareSerial mySerial(3, 2); //Initialize SoftwareSerial, and tell it you will be connecting through pins 2 and 3
Adafruit_GPS GPS(&mySerial); //Create GPS object

String NMEA1;  //We will use this variable to hold our first NMEA sentence
String NMEA2;  //We will use this variable to hold our second NMEA sentence

double x,y;
long a,b,c,d;
long latdegree,latmin,latsec;
long londegree,lonmin,lonsec;
char e;       //Used to read the characters spewing from the GPS module

void setup()  
{
  Serial.begin(115200);  //Turn on the Serial Monitor
  GPS.begin(9600);       //Turn GPS on at baud rate of 9600
  GPS.sendCommand("$PGCMD,33,0*6D"); // Turn Off GPS Antenna Update
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); //Tell GPS we want only $GPRMC and $GPGGA NMEA sentences
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);  // 1 Hz update rate
  lcd.begin(16,2);

  
  delay(1000);  //Pause
}


void loop()                     // run over and over again
{
readGPS();  //This is a function we define below which reads two NMEA sentences from GPS

  
//Serial.print("Latitude ==");
x=GPS.latitude;
a=x*100;
latsec=a%100;
latsec=latsec/100.0*60.0;
a=a/100;
latmin=a%100;
a=a/100;
latdegree=a%100;

lcd.setCursor(0,0);
lcd.print("Lat= ");


//lcd.setCursor(5,0);
lcd.print(latdegree);
lcd.print(" ");
//lcd.setCursor(9,0);
lcd.print(latmin);
lcd.print(" ");
//lcd.setCursor(13,0);
lcd.print(latsec);
lcd.print(" ");
//lcd.setCursor(15,0);
lcd.print(GPS.lat);
lcd.print(" ");

Serial.println("Latitude Degree are ");
Serial.println(latdegree);
Serial.println("Latitude Minutes are ");
Serial.println(latmin);
Serial.println("Latitude Seconds are ");
Serial.println(latsec);
Serial.print(GPS.lat);




y=GPS.longitude;
a=y*100;
lonsec=a%100;
lonsec=lonsec/100.0*60.0;
a=a/100;
lonmin=a%100;
a=a/100;
londegree=a%100;

lcd.setCursor(0,1);
lcd.print("Lon= ");

//lcd.setCursor(5,1);
lcd.print(londegree);
lcd.print(" ");
//lcd.setCursor(9,1);
lcd.print(lonmin);
lcd.print(" ");
//lcd.setCursor(13,1);
lcd.print(lonsec);
lcd.print(" ");
//lcd.setCursor(15,1);
lcd.print(GPS.lon);
lcd.print(" ");

delay(1000);
lcd.clear();

Serial.println("Longitude Degree are ");
Serial.println(londegree);
Serial.println("Longitude Minutes are ");
Serial.println(lonmin);
Serial.println("Longitude Seconds are ");
Serial.println(lonsec);

//Serial.println(GPS.latitude);


//serial.print("Longitude ==");
//Serial.println(GPS.longitude);
//Serial.print(GPS.lon);
//Serial.println(GPS.altitude);


//y=GPS.longitude;

//Serial.println(x);
//Serial.println(y);




}
void readGPS(){  //This function will read and remember two NMEA sentences from GPS
  clearGPS();    //Serial port probably has old or corrupt data, so begin by clearing it all out
  while(!GPS.newNMEAreceived()) { //Keep reading characters in this loop until a good NMEA sentence is received
  e=GPS.read(); //read a character from the GPS
  }
GPS.parse(GPS.lastNMEA());  //Once you get a good NMEA, parse it
NMEA1=GPS.lastNMEA();      //Once parsed, save NMEA sentence into NMEA1
while(!GPS.newNMEAreceived()) {  //Go out and get the second NMEA sentence, should be different type than the first one read above.
  e=GPS.read();
  }
GPS.parse(GPS.lastNMEA());
NMEA2=GPS.lastNMEA();
  Serial.println(NMEA1);
  Serial.println(NMEA2);
  Serial.println("");
}
void clearGPS() {  //Since between GPS reads, we still have data streaming in, we need to clear the old data by reading a few sentences, and discarding these
while(!GPS.newNMEAreceived()) {
  e=GPS.read();
  }
GPS.parse(GPS.lastNMEA());
while(!GPS.newNMEAreceived()) {
  e=GPS.read();
  }
GPS.parse(GPS.lastNMEA());

}
