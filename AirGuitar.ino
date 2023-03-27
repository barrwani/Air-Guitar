#include <CapacitiveSensor.h>  // Courtesy of Paul Badger 2009
#define COMMON_PIN 2       // The common 'send' pin for all keys
#define NUM_OF_SAMPLES 13   // Higher number whens more delay but more consistent readings
#define CAP_THRESHOLD 100  // Capactive reading that triggers a note (adjust to fit your needs)
#define NUM_OF_KEYS 11    // Number of keys that are on the keyboard

// This macro creates a capacitance "key" sensor object for each key on the piano keyboard:
#define CS(Y) CapacitiveSensor(2, Y)

// Each key corresponds to a note, which are defined here.
int notes[] = {69, 71, 72, 74, 76, 79, 76, 78, 79, 81, 83, 86};  // Notes used for Seven Nation Army (Over bar chord)
//int notes[]={NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4}; // Standard tuning, first 5 frets of A and D strings

// Defines the pins that the keys are connected to:
CapacitiveSensor keys[] = {CS(13), CS(3), CS(4), CS(5), CS(6), CS(7), CS(8), CS(9), CS(10), CS(11), CS(12)};

void setup() {
  ///Initialise Serial Communication
  Serial.begin(115200);

  // Turn off autocalibrate on all channels:
  for (int i = 0; i <11; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
}

void loop() {
    ///A String; 0 is open, 1 is first fret and so on...
  if ((keys[0].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD)) {
    if ((keys[1].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD)) {
          digitalWrite(LED_BUILTIN, HIGH);
          MIDI(0x90, notes[1], 127);
    } else if ((keys[4].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD)) {
      digitalWrite(LED_BUILTIN, HIGH);
      MIDI(0x90, notes[4], 127);
    } else if ((keys[3].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD)) {
      digitalWrite(LED_BUILTIN, HIGH);
      MIDI(0x90, notes[3], 127);
    } else if ((keys[2].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD )) {
      digitalWrite(LED_BUILTIN, HIGH);
      MIDI(0x90, notes[2], 127);
    }else if ((keys[5].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD-30)) {
      digitalWrite(LED_BUILTIN, HIGH);
      MIDI(0x90, notes[5], 127);
    }else {
      digitalWrite(LED_BUILTIN, HIGH);
      MIDI(0x90, notes[0], 127);
    }
  }
    ///D String; 6 is open, 7 is first fret and so on...
  if ((keys[6].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD)) {
    if ((keys[10].capacitiveSensor(NUM_OF_SAMPLES) > (CAP_THRESHOLD))) {
      digitalWrite(LED_BUILTIN, HIGH);
      MIDI(0x90, notes[10], 127);
    } else if ((keys[9].capacitiveSensor(NUM_OF_SAMPLES) > (CAP_THRESHOLD))) {
      digitalWrite(LED_BUILTIN, HIGH);
      MIDI(0x90, notes[9], 127);
    } else if ((keys[8].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD)) {
      digitalWrite(LED_BUILTIN, HIGH);
      MIDI(0x90, notes[8], 127);

    }else if ((keys[7].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD)) {
      digitalWrite(LED_BUILTIN, HIGH);
      MIDI(0x90, notes[7], 127);      
    } else{
      digitalWrite(LED_BUILTIN, HIGH);
      MIDI(0x90, notes[6], 127);
    }
  }
}
  
void MIDI(int channel, int pitch, int velocity){
  ///Writes MIDI Data to Serial Channel
    Serial.write(channel);
    Serial.write(pitch);
    Serial.write(velocity);
    delay(200);
}
