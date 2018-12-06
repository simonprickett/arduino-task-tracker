#include <Bounce2.h>

#define LED_1 1
#define LED_2 3
#define LED_3 5
#define LED_4 7
#define LED_5 9
#define LED_6 11
#define LED_7 13

#define BUTTON_1 0
#define BUTTON_2 2
#define BUTTON_3 4
#define BUTTON_4 6
#define BUTTON_5 8
#define BUTTON_6 10
#define BUTTON_7 12

bool isCompleted = false;
bool task1 = false;
bool task2 = false;
bool task3 = false;
bool task4 = false;
bool task5 = false;
bool task6 = false;
bool task7 = false;

Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();
Bounce debouncer3 = Bounce();
Bounce debouncer4 = Bounce();
Bounce debouncer5 = Bounce();
Bounce debouncer6 = Bounce();
Bounce debouncer7 = Bounce();

void setAllLights(bool turnOn) {
  unsigned int ledState = (turnOn ? HIGH : LOW);
  
  digitalWrite(LED_1, ledState);
  digitalWrite(LED_2, ledState);
  digitalWrite(LED_3, ledState);
  digitalWrite(LED_4, ledState);
  digitalWrite(LED_5, ledState);
  digitalWrite(LED_6, ledState);  
  digitalWrite(LED_7, ledState); 
}

void success() {
  isCompleted = true;
  
  setAllLights(false);

  for (unsigned int n = 0; n < 6; n++) {
    unsigned int ledState = (n % 2 == 0 ? HIGH : LOW);
    digitalWrite(LED_1, ledState);
    delay(200);
    digitalWrite(LED_2, ledState);
    delay(200);
    digitalWrite(LED_3, ledState);
    delay(200);
    digitalWrite(LED_4, ledState);
    delay(200);
    digitalWrite(LED_5, ledState);
    delay(200);
    digitalWrite(LED_6, ledState);
    delay(200);
    digitalWrite(LED_7, ledState); 
    delay(200); 
  }

  setAllLights(true);
}

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_7, OUTPUT);

  debouncer1.attach(BUTTON_1, INPUT_PULLUP);
  debouncer1.interval(30);
  debouncer2.attach(BUTTON_2, INPUT_PULLUP);
  debouncer2.interval(30);
  debouncer3.attach(BUTTON_3, INPUT_PULLUP);
  debouncer3.interval(30);
  debouncer4.attach(BUTTON_4, INPUT_PULLUP);
  debouncer4.interval(30);
  debouncer5.attach(BUTTON_5, INPUT_PULLUP);
  debouncer5.interval(30);
  debouncer6.attach(BUTTON_6, INPUT_PULLUP);
  debouncer6.interval(30);
  debouncer7.attach(BUTTON_7, INPUT_PULLUP);
  debouncer7.interval(30);
  
  for (unsigned int n = 0; n < 4; n++) {
    setAllLights(false); 
    delay(400);
    setAllLights(true);
    delay(400);
  }

  setAllLights(false);
}

void loop() {
  if (! isCompleted) {
    debouncer1.update();
    debouncer2.update();
    debouncer3.update();
    debouncer4.update();
    debouncer5.update();
    debouncer6.update();
    debouncer7.update();

    if (debouncer1.fell()) {
      task1 = ! task1;
      digitalWrite(LED_1, task1 ? HIGH : LOW);
    }

    if (debouncer2.fell()) {
      task2 = ! task2;
      digitalWrite(LED_2, task2 ? HIGH : LOW);
    }

    if (debouncer3.fell()) {
      task3 = ! task3;
      digitalWrite(LED_3, task3 ? HIGH : LOW);
    }

    if (debouncer4.fell()) {
      task4 = ! task4;
      digitalWrite(LED_4, task4 ? HIGH : LOW);
    }

    if (debouncer5.fell()) {
      task5 = ! task5;
      digitalWrite(LED_5, task5 ? HIGH : LOW);
    }

    if (debouncer6.fell()) {
      task6 = ! task6;
      digitalWrite(LED_6, task6 ? HIGH : LOW);
    }

    if (debouncer7.fell()) {
      task7 = ! task7;
      digitalWrite(LED_7, task7 ? HIGH : LOW);
    }
    
    if (task1 && task2 && task3 && task4 && task5 && task6 && task7) {
      isCompleted = true;
      delay(2000);
      success();
    }
  }
}
