

#include<FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    300
#define BRIGHTNESS  35
#define LED_TYPE    WS2812
#define COLOR_ORDER RGB
#define updateLEDS 10

CRGB leds[NUM_LEDS];


 int audio = A0;
void setup() { 
  Serial.begin(9600);
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

  pinMode(audio, INPUT);
  
    for(int i = 0; i < NUM_LEDS ; i++) {
      leds[i] = CRGB(0,0,0);
    }
    FastLED.show();
  }



 

void loop() {

 
 audio=analogRead(audio)/4;


CRGB Color=C(audio);
  for(int i = NUM_LEDS - 1; i >= updateLEDS; i--) {
    leds[i] = leds[i - updateLEDS];
  }
 
for(int i = 0; i < updateLEDS; i++) {
    leds[i] =Color ;
  }
  FastLED.show();

 
  delay(10);

}

 
CRGB C(int audio)
{
  
  CRGB Color;
 if( audio < 89)
 {
  Color=CRGB(0, 0, 0);
 
  
 }
  else if(audio>=89&& audio<=150)
  {

Color=CRGB(random8(),random8(),random8());
    
  }
else if(audio>150 && audio<=300)
  {

Color=CRGB(random8(),random8(),random8());
    
  }
  
  else if(audio>300 && audio<=450)
  {
Color=CRGB(random8(),random8(),random8());
    
  }
  
  else if(audio>450 && audio<=650)
  {

Color=CRGB(random8(),random8(),random8());
  }
  else if(audio>650 && audio<=800)
  {

Color=CRGB(random8(),random8(),random8());
  }
  else if(audio>800 && audio<=1000)
  {

Color=CRGB(random8(),random8(),random8());
    
  }
return Color;

  
}
