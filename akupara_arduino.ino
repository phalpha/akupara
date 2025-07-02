// Final Project

// Components: 



 #include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16


static const int led1 = 3;
static const int led2 = 5;
static const int led3 = 6;
static const int led4 = 9;
static const int led5 = 10;
static const int brightness = 0;    // how bright the LED is
static const int led1fadeAmount = 5;    // how many points to fade the LED by

static const int buzzer = 8;
static const int turtle = 11;
static const int photocell = 0;

static const int button1 = 12;
static const int button2 = 2;
static const int button3 = 7;
static const int button4 = 4;
static const int button5 = 13;


#include "pitches.h"
 
// notes in the melody:
static const int melodyCS[] = {
  NOTE_CS2, NOTE_CS3, NOTE_CS4, NOTE_CS5, NOTE_CS6, NOTE_CS7};
static const int melodyDS[] = {
  NOTE_DS2, NOTE_DS3, NOTE_DS4, NOTE_DS5, NOTE_DS6, NOTE_DS7};
static const int melodyFS[] = {
  NOTE_FS2, NOTE_FS3, NOTE_FS4, NOTE_FS5, NOTE_FS6, NOTE_FS7};
static const int melodyGS[] = {
  NOTE_GS2, NOTE_GS3, NOTE_GS4, NOTE_GS5, NOTE_GS6, NOTE_GS7};
static const int melodyAS[] = {
  NOTE_AS2, NOTE_AS3, NOTE_AS4, NOTE_AS5, NOTE_AS6, NOTE_AS7};

int duration = 500;  // 500 miliseconds



bool buttonPressed(int button) {
    int buttonvalue = digitalRead(button);
    if (buttonvalue == HIGH) {
      return false;
    }
    return true;  
}


void initialDisplay(void) {


 display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println("Akupara");
  

   display.setTextSize(1);             // Normal 1:1 pixel scale
  display.println("The Boundless");
  display.println("World Turtle");

  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  display.println("Project by");
  display.println("Poojit Hegde");
  

  display.display();
  //delay(2000);
}

void politicalMessage(void) {


 display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.print("dare ");
  
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  display.println("to struggle");
    display.setTextColor(SSD1306_WHITE);        // Draw white text

 display.print("dare ");
  
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  display.println("to win");
  
  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.println(F("ALL POWER TO THE"));
  display.println(F("PEOPLE!"));

  display.display();
  //delay(2000);
}

void instructions(void) {


   display.setTextSize(1);  
   display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);
  display.println("today we sing with the world turtle");

     display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        // Draw white text

   //   display.println("rules:");

    display.println("be respectful!");
    
   // display.println("be authentic!");

    //    display.println("be compassionate!");



        display.setTextColor(SSD1306_WHITE);        // Draw white text

      display.println("together we taste");

            display.println("the eternal wisdom");


            display.println("of the universe");          
            display.display();
            


}

void setup() {
  // put your setup code here, to run once:

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  //pinMode(button6, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  //pinMode(led6, OUTPUT);

  pinMode(buzzer, OUTPUT); // set pin 8 as output

  Serial.begin(9600);


  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.display();


 initialDisplay();
  delay(5000);
  display.clearDisplay();
  display.display();

  politicalMessage();
 delay(5000);
  display.clearDisplay();
  display.display();

  instructions();
  delay(5000);

  display.clearDisplay();
  display.display();
  

  // timeNothing = millis();
  Serial.println("here");

}

int currentscaleCS = 0;

//mode 1: user communicates
//mode 2: turtle communicates
//mode 3: turtle guides user to communicate together


int turtleawake = true; 

unsigned long lengthoflastinteraction = 0; 

unsigned long sleeptime = 0;





unsigned long mode1() {
    unsigned long actualstart = millis();
    unsigned long starttime = millis(); 
    unsigned long currenttime = millis(); 

    int led1brightness = 0;
    int led2brightness = 0;
    int led3brightness = 0;
    int led4brightness = 0;
    int led5brightness = 0;

    
      display.clearDisplay();
  display.setCursor(0,0);

  display.setTextColor(SSD1306_WHITE);
  display.println(F("the turtle is listening."));
    display.println(F("press the parts of the shell"));

    display.println(F("and play your song!"));
        display.println(F("stop when you are done"));


  
  display.display();
    delay(5000);


    while (currenttime - starttime < 10000){
      currenttime = millis();
      //analogWrite(led1, led1brightness);
     // analogWrite(led2, led2brightness);

      //analogWrite(led3, led3brightness);

      //analogWrite(led4, led4brightness);

      //analogWrite(led5, led5brightness);


      if (buttonPressed(button1) ) {
        Serial.println("button 1");
        tone(turtle, melodyCS[4], 1);
        starttime = currenttime;
        if (led1brightness < 255) {
          led1brightness += 50;
        }
        if (led2brightness > 0) {
          led2brightness -= 50;
        }
         if (led3brightness > 0) {
          led3brightness -= 50;
        }
         if (led4brightness > 0) {
          led4brightness -= 50;
        }
         if (led5brightness > 0) {
          led5brightness -= 50;
        }
        analogWrite(led1, 255);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);




        
      }
      else if (buttonPressed(button2) ) {
                Serial.println("button 2");

        tone(turtle, melodyDS[4], 1);
        starttime = currenttime;

                if (led2brightness < 255) {
          led2brightness += 50;
        }
        if (led1brightness > 0) {
          led1brightness -= 50;
        }
         if (led3brightness > 0) {
          led3brightness -= 50;
        }
         if (led4brightness > 0) {
          led4brightness -= 50;
        }
         if (led5brightness > 0) {
          led5brightness -= 50;
        }

        analogWrite(led1, 0);
                analogWrite(led2, 255);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);

      }
      else if (buttonPressed(button3) ) {
                Serial.println("button 3");

        tone(turtle, melodyFS[4], 1);
        starttime = currenttime;
                if (led3brightness < 255) {
          led3brightness += 50;
        }
        if (led2brightness > 0) {
          led2brightness -= 50;
        }
         if (led1brightness > 0) {
          led1brightness -= 50;
        }
         if (led4brightness > 0) {
          led4brightness -= 50;
        }
         if (led5brightness > 0) {
          led5brightness -= 50;
        }


        analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 255);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);
      }
      else if (buttonPressed(button4) ) {
                Serial.println("button 4");

        tone(turtle, melodyGS[4], 1);
        starttime = currenttime;
                if (led4brightness < 255) {
          led4brightness += 50;
        }
        if (led2brightness > 0) {
          led2brightness -= 50;
        }
         if (led3brightness > 0) {
          led3brightness -= 50;
        }
         if (led1brightness > 0) {
          led1brightness -= 50;
        }
         if (led5brightness > 0) {
          led5brightness -= 50;
        }



        analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 255);
                                                                analogWrite(led5, 0);
      }
      else if (buttonPressed(button5) ){
                Serial.println("button 5");

        tone(turtle, melodyAS[4], 1);
        starttime = currenttime;
                if (led5brightness < 255) {
          led5brightness += 50;
        }
        if (led2brightness > 0) {
          led2brightness -= 50;
        }
         if (led3brightness > 0) {
          led3brightness -= 50;
        }
         if (led4brightness > 0) {
          led4brightness -= 50;
        }
         if (led1brightness > 0) {
          led1brightness -= 50;
        }



        analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 255);
      }
      else {
        analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);
      }
    }
    return (currenttime - actualstart);
  
}




unsigned long mode2(unsigned long maxlength) {

  unsigned long starttime = millis(); 
  unsigned long currenttime = millis(); 

  
    
      display.clearDisplay();
  display.setCursor(0,0);

  display.setTextColor(SSD1306_WHITE);
  display.println(F("now the turtle is talking."));
    display.println(F("listen to the turtle"));

    display.println(F("see the turtle"));

  
  display.display();
    delay(5000);




  while (currenttime - starttime < maxlength) {

    while (buttonPressed(button1) or buttonPressed(button2) or buttonPressed(button3) or buttonPressed(button4) or buttonPressed(button5)) {
            display.clearDisplay();
  display.setCursor(0,0);

  display.setTextColor(SSD1306_WHITE);
  display.println(F("RESPECT THE TURTLE"));
    display.println(F("DO NOT PLAY - LISTEN!"));
  
  display.display();
    delay(1);


    }

    
    
          display.clearDisplay();
  display.setCursor(0,0);

  display.setTextColor(SSD1306_WHITE);
  display.println(F("now the turtle is."));
    display.println(F("singing to you."));

    display.println(F("listen to the turtle"));

    display.println(F("see the turtle"));

        display.println(F("become the turtle"));


  
  display.display();
    delay(1000);

    int note = random(5);
    int lengths[6] = {1,2,3,4,6,8};
    if (note == 0) {
                      analogWrite(led1, 255);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);


       tone(turtle, melodyCS[2], 250*lengths[random(6)]);
    }
    else if (note == 1) {
                            analogWrite(led1, 0);
                analogWrite(led2, 255);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);


       tone(turtle, melodyDS[2], 250*lengths[random(6)]);
    }
    else if (note == 2) {
                            analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 255);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);


       tone(turtle, melodyFS[2], 250*lengths[random(6)]);
    }
    else if (note == 3) {
                            analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 255);


       tone(turtle, melodyGS[2], 250*lengths[random(6)]);
    }
    else if (note == 4) {
        analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 255);

       tone(turtle, melodyAS[2], 250*lengths[random(6)]);
    }
    currenttime = millis();
  }
  
  return (currenttime - starttime);

}

unsigned long mode3() {

  unsigned long starttime = millis(); 
        display.clearDisplay();
  display.setCursor(0,0);

  display.setTextColor(SSD1306_WHITE);
  display.println(F("play a song with the turtle"));
    display.println(F("follow the lights"));

    display.println(F("creating together"));

    display.println(F("forever"));

 
  display.display();
    delay(5000);


  
  for (int i = 0; i < random(10)+5; i++) {
    bool correctbutton = false;
    int notechoice = random(5);
    int scalechoice = random(2) +2;

    
    while (not correctbutton) {
      if (notechoice == 0) {
        
        analogWrite(led1, 255);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);

        tone(turtle, melodyCS[2], 10);
        while (buttonPressed(button1)) {
                  tone(buzzer, melodyCS[4], 1);

          correctbutton = true;
        }
      }
      if (notechoice == 1) {
        analogWrite(led1, 0);
                analogWrite(led2, 255);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);

        tone(turtle, melodyDS[2], 10);
        while (buttonPressed(button2)) {
              tone(buzzer, melodyDS[4], 1);

          correctbutton = true;
        }
      }
      if (notechoice == 2) {
        analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 255);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);

        tone(turtle, melodyFS[2], 10);
        while (buttonPressed(button3)) {
                        tone(buzzer, melodyFS[4], 1);

          correctbutton = true;
        }
      }
      if (notechoice == 3) {
        analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 255);
                                                                analogWrite(led5, 0);

        tone(turtle, melodyGS[2], 10);
        while (buttonPressed(button4)) {
                        tone(buzzer, melodyGS[4], 1);

          correctbutton = true;
        }
      }
      if (notechoice == 4) {
        analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 255);

        tone(turtle, melodyAS[2], 10);
        while (buttonPressed(button5)) {
                        tone(buzzer, melodyAS[4], 1);

          correctbutton = true;
        }
      }
    }
  }

  unsigned long currenttime = millis(); 
  return (currenttime - starttime);

  
}




void loop() {
  
  // turtle dormant
 if (not turtleawake) {
  analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 0);
  display.clearDisplay();
  display.setCursor(0,0);

  display.setTextColor(SSD1306_WHITE);
  display.println(F("turtle is dormant. please respect the turtle and return later."));

  display.display();
    delay(1);

  
  //delay(2000);
    unsigned long currenttime = millis();
    int photocellReading = analogRead(photocell);  
          Serial.println(photocellReading);

    
    while (photocellReading > 100) {
       photocellReading = analogRead(photocell);  

      unsigned long time1 = millis();
      // display here
        display.clearDisplay();
  display.setCursor(0,0);

  display.setTextColor(SSD1306_WHITE);
  display.println(F("DO NOT DISTURB TURTLE. TURTLE ANGRY."));

  display.display();
      delay(1);

    unsigned long time2 = millis();
      lengthoflastinteraction += time2-time1;
    }
    if (currenttime > sleeptime + lengthoflastinteraction) {
      turtleawake = true;
    }

    // display
 }

 // turtle active
 else if (turtleawake) {

    // you may come see the turtle, the turtle awaits
    lengthoflastinteraction = 0;

      display.clearDisplay();
  display.setCursor(0,0);

  display.setTextColor(SSD1306_WHITE);
  display.println(F("welcome to the abode of the turtle."));

  display.display();
      delay(5000);
    int photocellReading2 = analogRead(photocell);  
    Serial.println(photocellReading2);
    unsigned long length1 = 0;
        unsigned long length2 = 0;
    unsigned long length3 = 0;

    if (photocellReading2 > 100) {
             photocellReading2 = analogRead(photocell);  

       length1 = mode1();
         analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 255);
       length2 = mode2(length1);
         analogWrite(led1, 0);
                analogWrite(led2, 0);
                                analogWrite(led3, 0);
                                                analogWrite(led4, 0);
                                                                analogWrite(led5, 255);
       length3 = mode3();
       turtleawake = false;

             display.clearDisplay();
  display.setCursor(0,0);

  display.setTextColor(SSD1306_WHITE);
  display.println(F("the turtle is going back to sleep."));

  display.display();
      delay(5000);

    }
    else {
              if (photocellReading2 < 100) {
                             photocellReading2 = analogRead(photocell);  

              //tone(turtle, melodyCS[2], 10);
              } 
    }
    lengthoflastinteraction = length1 + length2 + length3;
    sleeptime = millis();
 }
   
}
