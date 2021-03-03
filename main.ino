/*
 * (C)2018-2020 SAS TECH CORPORATION 
 * Potentiometer INPUT device
 * 
 * 
 * WHAT IT DOES :
 * Read Pot's regulated voltage from Analog pins 
 * divide it to 1023 values 
 * create range from 0 - 1023 to 0 - 255
 * assign each char 10 points ie, for A = [0,10]; B = [11-20],...
 * read digital pin (7) to check 0 or 1
 * if 1 then prints the selected char on LCD and Serial monitor
 * if 0 then continue
 * Keeps looping
 * to reset the note or label ,press reset
 * 
 */

 
//START LCD CONFIGS
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
//END LCD CONFIGS

//START VAR MANAGEMENT
const int analogInPin = A0;  // POT
const int analogOutPin = 11; // Must be ~PWM
int x;
int sensorValue = 0;       
int outputValue = 0;        
int enterkey;
String chkey="";
String chnow="";
// END VAR MANAGEMENT

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  //tell pin 7 is for input
  pinMode(7,INPUT);
  // init LCD
  lcd.begin();
  lcd.backlight();//start backlight
  lcd.clear();//clear LCD
  lcd.setCursor(4,0);// set cursor to x=4 , y=0
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
   x=outputValue;
   
   //START CHAR AND INPUT CONFIGS
  if  (x>= 0 && x<=10){
Serial.println("selected Char : A");
chkey="A";
    } else if (x>= 11 && x<=20){
Serial.println("selected Char : B");
chkey="B"; }else if (x>= 21 && x<=30){
    Serial.println("selected Char : C");
    chkey="C";
    }else if (x>= 31 && x<=40){
  Serial.println("selected Char : D");
    chkey="D";}
    else if (x>= 41 && x<=50){
    Serial.println("selected Char : E");
    chkey="E";
    }
    else if (x>= 51 && x<=60){
 chkey="F";
 Serial.println("selected Char : F");
    }
    else if (x>= 61 && x<=70){
 chkey="G";
 Serial.println("selected Char : G");
    
    }else if (x>= 71 && x<=80){
   chkey="H";
   Serial.println("selected Char : H");
    
    }else if (x>= 81 && x<=90){
    Serial.println("selected Char : I");
   chkey="I" ;
    }else if (x>= 91 && x<=100){
    Serial.println("selected Char : J");
    chkey="J";
    }else if (x>= 101 && x<=110){
    Serial.println("selected Char : K");
    chkey="K";
    }else if (x>= 111 && x<=120){
    Serial.println("selected Char : L");
    chkey="L";
    }else if (x>= 121 && x<=130){
    Serial.println("selected Char : M");
    chkey="M";
    }else if (x>= 131 && x<=140){
    Serial.println("selected Char : N");
    chkey="N";
    }else if (x>= 141 && x<=150){
    Serial.println("selected Char : O");
    chkey="O";
    }else if (x>= 151 && x<=160){
    Serial.println("selected Char : P");
    chkey="P";
    }else if (x>= 161 && x<=170){
    Serial.println("selected Char : Q");
    chkey="Q";
    }else if (x>= 171 && x<=180){
    Serial.println("selected Char : R");
    chkey="R";
    }else if (x>= 181 && x<=190){
    Serial.println("selected Char : S");
    chkey="S";
    }else if (x>= 191 && x<=200){
    Serial.println("selected Char : T");
    chkey="T";
    }else if (x>= 201 && x<=210){
    Serial.println("selected Char : U");
    chkey="U";
    }else if (x>= 211 && x<=220){
    Serial.println("selected Char : V");
    chkey="V";
    }else if (x>= 221 && x<=230){
    Serial.println("selected Char : W");
    chkey="W";
    }else if (x>= 231 && x<=240){
    Serial.println("selected Char : X");
    chkey="X";
    }else if (x>= 241 && x<=250){
    Serial.println("selected Char : Y");
    chkey="Y";
    }
    else if (x>= 251 && x<=255){
    Serial.println("selected Char : Z");
    chkey="Z";
    }
    
    // END CHAR AND INPUT CONFIGS
    
    enterkey=digitalRead(7); //read digital pin 7
    //delay(100);
    Serial.println(enterkey); // print it is 0 or 1
    if (enterkey ==1){ // IF 1
      //digitalWrite(8,HIGH)
       lcd.clear(); // clear LCD
       lcd.setCursor(4,0);
      Serial.println(chnow+chkey); // add current char to previous word
      chnow=chnow+chkey;//change the previous word to new word 
      lcd.print(chnow); //print on LCD
      Serial.println("Enter pressed"); // tell user through serial
      delay(1000); //delay to clear digital pin's extra voltage 
      
      } else {
        //do nothing if enter not pressed
        
        }
      
  delay(100); //delay for clearing pot values and refreshing
}
