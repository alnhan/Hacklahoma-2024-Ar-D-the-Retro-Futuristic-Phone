#include <HCSR04.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {38, 40, 42, 44}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {46, 48, 50, 52}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// Laser position
int pos = 0;

// Create variables to store the trigger and echo pins of the ultrasonic sensor.
const int triggerPin = 28;
const int echoPin = 30; 

// Create an instance of the HCSR04 class to represent the ultrasonic sensor. 
UltraSonicDistanceSensor UltraSonic(triggerPin, echoPin);

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Laser module
  pinMode(2, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Print a message to the LCD.
  lcd.print("Hi, I'm Ar-D!");

  // set the cursor to column 0, line 1.
  lcd.setCursor(0, 1);

  // Prompt the user for a command.
  lcd.print("Enter command: ");

  while(true)
  {
    char customKey = customKeypad.getKey();

    if (customKey == 'A')
    {
      Serial.println(customKey);
      lcd.print(customKey);
      delay(3000);
      lcd.clear();
      ACommand();
      break;
    }
    else if (customKey == 'B')
    {
      Serial.println(customKey);
      lcd.print(customKey);
      delay(3000);
      lcd.clear();
      BCommand();
      break;
    }
    else if (customKey == 'C')
    {
      Serial.println(customKey);
      lcd.print(customKey);
      delay(3000);
      lcd.clear();
      CCommand();
      break;
    }
  }

  delay(1000);

}

char receiveCommand()
{
  char command;

  while(command)
  {
    char command = customKeypad.getKey();
  }

  delay(2000);
  lcd.clear();
  return command;
}

void ACommand()
{
  int phoneDigitCount = 0;

  lcd.print("Enter phone #:");
  lcd.setCursor(0, 1);

  while (phoneDigitCount < 10)
  {
    char digit = customKeypad.getKey();

    if (digit)
    {
      switch (digit)
      {
        case '1':
          lcd.print(digit);
          phoneDigitCount += 1;
          delay(500);
          break;
        case '2':
          lcd.print(digit);
          phoneDigitCount += 1;
          delay(500);
          break;
        case '3':
          lcd.print(digit);
          phoneDigitCount += 1;
          delay(500);
          break;
        case '4':
          lcd.print(digit);
          phoneDigitCount += 1;
          delay(500);
          break;
        case '5':
          lcd.print(digit);
          phoneDigitCount += 1;
          delay(500);
          break;
        case '6':
          lcd.print(digit);
          phoneDigitCount += 1;
          delay(500);
          break;
        case '7':
          lcd.print(digit);
          phoneDigitCount += 1;
          delay(500);
          break;
        case '8':
          lcd.print(digit);
          phoneDigitCount += 1;
          delay(500);
          break;
        case '9':
          lcd.print(digit);
          phoneDigitCount += 1;
          delay(500);
          break;
        case '0':
          lcd.print(digit);
          phoneDigitCount += 1;
          delay(500);
          break;
      }
    }
  }

  // Calling process
  lcd.setCursor(0, 0);
  lcd.print("Calling...      ");

  delay(10000);

  lcd.clear();
}

// DISTANCE MEASURER
void BCommand()
{
  for (pos = 0; pos <= 14; pos += 1) 
  { 
    lcd.print("Distance in CM:");
    lcd.setCursor(0, 1);
    lcd.print(UltraSonic.measureDistanceCm());
    analogWrite(2,pos);              
    delay(1000);
    lcd.clear();                       
  }
  for (pos = 14; pos >= 0; pos -= 1) 
  { 
    lcd.print("Distance in CM:");
    lcd.setCursor(0, 1);
    lcd.print(UltraSonic.measureDistanceCm());
    analogWrite(2,pos);             
    delay(1000);
    lcd.clear();                      
  }
 
  lcd.clear();
}

// SELF-DEFENSE LASER
void CCommand()
{
  lcd.print("Activating Self-");
  lcd.setCursor(0, 1);
  lcd.print("Defense Laser...");

  for (pos = 0; pos <= 255; pos += 1) 
  { 

    analogWrite(2,pos);              
    delay(25);                       
  }
  for (pos = 255; pos >= 0; pos -= 1) 
  { 
    analogWrite(2,pos);             
    delay(25);                      
  }

  lcd.clear();
}