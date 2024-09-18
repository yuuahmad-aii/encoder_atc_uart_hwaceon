#include <Arduino.h>
// verbose
#define verbose 1

int nilai_input[8] = {0, 0, 0, 0, 0, 0, 0, 0};
String allChar;
bool parsing_serial1 = false;

// pin output digital
#define input_1 13
#define input_2 12
#define input_3 11
#define input_4 5
#define input_5 9
#define input_6 8
#define input_7 7
#define input_8 6
int input_pins_digital[8] = {input_1, input_2, input_3, input_4, input_5, input_6, input_7, input_8};

void setup()
{
  for (size_t i = 0; i < 8; i++) // ada 10 buah output
    pinMode(input_pins_digital[i], INPUT_PULLUP);

// init serial
#if defined(verbose)
  Serial.begin(115200);
#endif // verbose
}

void loop()
{
  for (int i = 0; i < 8; i++)
  {
    int reading;
    reading = digitalRead(input_pins_digital[i]);
    nilai_input[i] = reading;
  }

// tampilkan nilai
#if defined(verbose)
  // Serial.print("inp: ");
  for (size_t i = 0; i < 8; i++)
    Serial.print(nilai_input[i]);
  Serial.println();
#endif // verbose
}