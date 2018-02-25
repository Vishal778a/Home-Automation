// Mini Project:-Bluetooth Controlled Home Automation Using Android APP

// 
 
/* Components Required:-
 *  
 * Arduino UNO 
 * LCD 16*2 Display
 * Bluetooth HC05 Module
 * 4 Channel Relay Module
 * 
 */

/* Pins Connections
 *  
 *  LCD connections to Arduino
 *  VDD to +5V
 *  Vss to GND
 *  RW to GND
 *  RS to D12
 *  EN to D11
 *  D4 to D10
 *  D5 to D9
 *  D6 to D8
 *  D7 to D7
 *  
 *  HC05 Bluetooth Module Connectons
 *  +3.3Vcc to +3.3v
 *  Tx to Rx
 *  Rx to Tx
 *  GND to GND
 *  
 *  4 Channel Relay Module 
 *  Vcc to 5V
 *  GND to GND
 *  IN1 to D2
 *  IN2 to D3
 *  IN3 to D4
 *  IN4 to D5
 *  
 *  -VCC to +VCC Connected to 9V Battery
 */

 
#define R1 2
#define R2 3
#define R3 4
#define R4 5
#define AT 13

#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);
char Input;

void ch1() // Relay channel IN1 ON :
{
  digitalWrite(R1,HIGH);
  delay(1000);
  
  lcd.clear();
  lcd.print("Fan : ON");
  lcd.setCursor(0,1);
  lcd.print("Return in 3 Seconds");
  delay(3000);
};

void ch2() // Relay channel IN2 ON :
{
  digitalWrite(R2,HIGH);
  delay(1000);
  
  lcd.clear();
  lcd.print("Light2 is ON");
  lcd.setCursor(0,1);
  lcd.print("Return in 3 Sec");
  delay(3000);
};

void ch3() // Relay channel IN3 ON :
{
  digitalWrite(R3,HIGH);
  delay(1000);
  
  lcd.clear();
  lcd.print("Light3 is ON");
  lcd.setCursor(0,1);
  lcd.print("Return in 3 Sec");
  delay(3000);
};

void ch4()  // Relay channel IN4 ON :
{
  digitalWrite(R4,HIGH);
  delay(1000);
  
  lcd.clear();
  lcd.print("Light4 is ON");
  lcd.setCursor(0,1);
  lcd.print("Return in 3 Sec");
  delay(3000);
};

void O1() // Relay channel IN1 OFF :
{
  digitalWrite(R1,LOW);
  delay(1000);
  
  lcd.clear();
  lcd.print("Fan is ON");
  lcd.setCursor(0,1);
  lcd.print("Return in 3 Sec");
  delay(3000);
};

void O2() // Relay channel IN2 OFF :
{
  digitalWrite(R2,LOW);
  delay(1000);
  
  lcd.clear();
  lcd.print("Light2 is OFF");
  lcd.setCursor(0,1);
  lcd.print("Return in 3 Sec");
  delay(3000);
};

void O3() // Relay channel IN3 OFF :
{
  digitalWrite(R3,LOW);
  delay(1000);
  
  lcd.clear();
  lcd.print("Light3 is OFF");
  lcd.setCursor(0,1);
  lcd.print("Return in 3 Sec");
  delay(3000);
};

void O4() // Relay channel IN4 OFF :
{
  digitalWrite(R4,LOW);
  delay(1000);
  
  lcd.clear();
  lcd.print("Light4 is OFF");
  lcd.setCursor(0,1);
  lcd.print("Return in 3 Sec");
  delay(3000);
};

void all_off() // All Relay goes in OFF State:
{
  digitalWrite(R1,LOW);
  delay(100);
  digitalWrite(R2,LOW);
  delay(100);
  digitalWrite(R3,LOW);
  delay(100);
  digitalWrite(R4,LOW);
  delay(100);

  lcd.clear();
  lcd.print("All Appliances");
  lcd.setCursor(0,1);
  lcd.print("OFF");
  lcd.print("Return in 3 Sec");
  delay(3000);
};

void all_on() // All Relay goes in ON State:
{
  digitalWrite(R1,HIGH);
  delay(500);
  digitalWrite(R2,HIGH);
  delay(500);
  digitalWrite(R3,HIGH);
  delay(500);
  digitalWrite(R4,HIGH);
  delay(500);

  lcd.clear();
  lcd.print("All App. ON");
  lcd.setCursor(0,1);
  lcd.print("Return in 3 Sec");
  delay(3000);
};

void Start()
{
  if(Serial.available()>0)
  {
    Input = Serial.read();

    switch(Input)
    {
       case 'A' : ch1();
                  break;
                  
       case 'a' : O1();
                  break;
                  
       case 'B' : ch2();
                  break;

       case 'b' : O2();
                  break;
                  
       case 'C' : ch3();
                  break;

       case 'c' : O3();
                  break;
                  
       case 'D' : ch4();
                  break;

       case 'd' : O4();
                  break;
                  
       case 'O' : all_on();
                  break;

       case 'o' : all_off();
                  break;
                  
                  
       default : lcd.clear();
                 lcd.print("Invalid Input");
                 lcd.setCursor(0,1);
                 lcd.print("Press Any Key");
                 if(Input>0)
                 break;
    }
  }
};

void setup() 
{
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);

  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() 
{
  Start();
  lcd.clear();
  lcd.print("Mini Project on");
  lcd.setCursor(0,1);
  lcd.print("Home Automation");
  delay(1000);

  Start();
  lcd.clear();
  lcd.print("Vivek Dubey");
  lcd.setCursor(0,1);
  lcd.print("Jayanti Prasad");
  delay(1000);
  
  Start();
  lcd.clear();
  lcd.print("Press A for ON");
  lcd.setCursor(0,1);
  lcd.print("Light 1");
  delay(1000);
  
  Start();
  lcd.clear();
  lcd.print("Press B for ON");
  lcd.setCursor(0,1);
  lcd.print("Light 2");
  delay(1000);
  
  Start();
  lcd.clear();
  lcd.print("Press C for ON");
  lcd.setCursor(0,1);
  lcd.print("Light 3");
  delay(1000);
  
  Start();
  lcd.clear();
  lcd.print("Press D for ON");
  lcd.setCursor(0,1);
  lcd.print("Light 4");
  delay(1000);
  
  Start();
  lcd.clear();
  lcd.print("Press a for OFF");
  lcd.setCursor(0,1);
  lcd.print("Light 1");
  delay(1000);
  
  Start();
  lcd.clear();
  lcd.print("Press b for OFF");
  lcd.setCursor(0,1);
  lcd.print("Light 2");
  delay(1000);
  
  Start();
  lcd.clear();
  lcd.print("Press c for OFF");
  lcd.setCursor(0,1);
  lcd.print("Light 3");
  delay(1000);
  
  Start();
  lcd.clear();
  lcd.print("Press d for OFF");
  lcd.setCursor(0,1);
  lcd.print("Light 4");
  delay(1000);
  
  Start();
  lcd.clear();
  lcd.print("Press O for ON");
  lcd.setCursor(0,1);
  lcd.print("ALL LIGHTS");
  delay(1000);
  
  Start();
  lcd.clear();
  lcd.print("Press o for OFF");
  lcd.setCursor(0,1);
  lcd.print("ALL LIGHTS");
  delay(1000);
}
