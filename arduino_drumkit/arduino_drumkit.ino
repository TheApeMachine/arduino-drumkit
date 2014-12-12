#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define SNARETHRESHOLD 10

unsigned long snareInterval       = 2;
unsigned long previousSnareMillis = 0;

int kickPin  = A0;
int snarePin = A1;

int kickValue  = 0;
int snareValue = 0;

// MAPPING FOR ADDICTIVE DRUMS
byte KICK                  = 36;
byte SNARE_RIMCLICK        = 44;
byte SNARE_SHALLOW_HIT     = 43;
byte SNARE_SIDESTICK       = 42;
byte SNARE_SHALLOW_RIMSHOT = 41;
byte SNARE_FLAM_HIT        = 40;
byte SNARE_FLAM_RIM        = 39;
byte SNARE_OPEN_HIT        = 38;
byte SNARE_RIMSHOT         = 37;
byte HIHAT_PEDAL_OPEN      = 59;
byte HIHAT_OPEN_BELL       = 58;
byte HIHAT_OPEN_D          = 57;
byte HIHAT_OPEN_C          = 56;
byte HIHAT_OPEN_B          = 55;
byte HIHAT_OPEN_A          = 54;
byte HIHAT_CLOSED_BELL     = 53;
byte HIHAT_CLOSED2_SHAFT   = 52;
byte HIHAT_CLOSED2_TIP     = 51;
byte HIHAT_CLOSED1_SHAFT   = 50;
byte HIHAT_CLOSED1_TIP     = 49;
byte HIHAT_PEDAL_CLOSED    = 48;
byte EXTRA                 = 47;
byte TOM1_RIMSHOT          = 72;
byte TOM1_HIT              = 71;
byte TOM2_RIMSHOT          = 70;
byte TOM2_HIT              = 69;
byte TOM3_RIMSHOT          = 68;
byte TOM3_HIT              = 67;
byte TOM4_RIMSHOT          = 68;
byte TOM4_HIT              = 67;

void setup() {
  MIDI.begin();
  Serial.begin(115200);
}

boolean noteReady(unsigned long previousMillis, unsigned long interval) {
  if((unsigned long)(millis() - previousMillis) >= interval) {
    return true;
  }
  else {
    return false;
  }
}

void hitNote(int value, byte note) {
  int velocity = value * 3;
  
  if(velocity > 127) {
    velocity = 127;
  }
  
  MIDI.sendNoteOn(note, velocity, 1);
  MIDI.sendNoteOff(note, 0, 1);
}

void loop() {
  snareValue = analogRead(snarePin);
  
  if(snareValue >= SNARETHRESHOLD && noteReady(previousSnareMillis, snareInterval)) {
    previousSnareMillis = millis();
    hitNote(snareValue, SNARE_OPEN_HIT);
  }
}

