#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Bounce2.h>

/**********************************************************/
char array1[]=" SunFounder               "; //the string to print on the LCD
char array2[]="hello, world!             "; //the string to print on the LCD
int tim = 250; //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
/*********************************************************/

#define BUTTON_HALF_POT 2
#define BUTTON_ENTER 4
#define BUTTON_UP 7
#define BUTTON_DOWN 8
#define BUTTON_BREW 12

Bounce bHalf = Bounce(); 
Bounce bEnter = Bounce(); 
Bounce bUp = Bounce(); 
Bounce bDown = Bounce(); 
Bounce bBrew = Bounce(); 

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    lcd.init(); //initialize the lcd
    lcd.backlight(); //open the backlight 

    // buttons
    pinMode(BUTTON_HALF_POT, INPUT_PULLUP);
    pinMode(BUTTON_ENTER, INPUT_PULLUP);
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_BREW, INPUT_PULLUP);

    bHalf.attach(BUTTON_HALF_POT);
    bHalf.interval(5); 

    bEnter.attach(BUTTON_ENTER);
    bEnter.interval(5); 

    bUp.attach(BUTTON_UP);
    bUp.interval(5); 

    bDown.attach(BUTTON_DOWN);
    bDown.interval(5); 

    bBrew.attach(BUTTON_BREW);
    bBrew.interval(5); 
}

void loop() {
    bHalf.update();
    bEnter.update();
    bUp.update();
    bDown.update();
    bBrew.update();

    
    // digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    // delay(1000);                       // wait for a second
    // digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    // delay(1000); 

    lcd.setCursor(15,0); // set the cursor to column 15, line 0
    for (int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)
    {
        lcd.scrollDisplayLeft(); //Scrolls the contents of the display one space to the left.
        lcd.print(array1[positionCounter1]); // Print a message to the LCD.
        delay(tim); //wait for 250 microseconds
    }
    lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left  corner.
    
    lcd.setCursor(15,1); // set the cursor to column 15, line 1

    for (int positionCounter = 0; positionCounter < 26; positionCounter++)
    {
        lcd.scrollDisplayLeft(); //Scrolls the contents of the display one space to the left.
        lcd.print(array2[positionCounter]); // Print a message to the LCD.
        delay(tim); //wait for 250 microseconds
    }

    lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left corner.
}