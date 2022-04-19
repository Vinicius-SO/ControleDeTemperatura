#include <Arduino.h>

#define dataPin 2
#define latchPin 3
#define clockPin 4

#define led9 5
#define led10 6
#define ledCooler 7

#define selectSubtractButton 13
#define selectAddButton 12
#define turnOnCooler 11

int menu = 0;
bool ligaCooler = false;

byte acendeLed[10];

void setup() {
  //Inicia a serial para 9600 
  Serial.begin(9600);

  acendeLed[0] = 0; 
  acendeLed[1] = 1; 
  acendeLed[2] = 2; 
  acendeLed[3] = 4; 
  acendeLed[4] = 8; 
  acendeLed[5] = 16; 
  acendeLed[6] = 32; 
  acendeLed[7] = 64;
  acendeLed[8] = 128;

  //Define os leds de que representarão o menu, como saída
  DDRD = B11111111;
  
  //Define o pino de entrada dobotão
  pinMode(selectSubtractButton, INPUT);
  pinMode(selectAddButton, INPUT);
  pinMode(turnOnCooler,INPUT);
}

void loop() {

  if(digitalRead(selectAddButton)){
  	incrementMenu();
  }else if(digitalRead(selectSubtractButton)){
    decrementMenu();
  }

  if(digitalRead(turnOnCooler)){
    ligaCooler = !ligaCooler;
    digitalWrite(ledCooler, ligaCooler);
    if(ligaCooler){
      Serial.println("Cooler Ligado");
    }else{
      Serial.println("Cooler Desligado");
    }
    delay(200);
  }

}


void shiftRegisterValue(int value){

  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, value);
  
  digitalWrite(latchPin, HIGH);
}

void atualizateMenu(){

  if (menu == 9){
    digitalWrite(led10, LOW);
    digitalWrite(led9, HIGH);
    shiftRegisterValue(acendeLed[0]);
    Serial.println("Menu 9 acessado");
  }else if(menu == 10){
    digitalWrite(led9, LOW);
    digitalWrite(led10, HIGH);
    shiftRegisterValue(acendeLed[0]);
    Serial.println("Menu 10 acessado");
  }else{
    digitalWrite(led9, LOW);
    digitalWrite(led10, LOW);
    shiftRegisterValue(acendeLed[menu]);
    Serial.println("Menu acessado:");
    Serial.println(menu);
  }
  
  delay(200);
}

void incrementMenu(){
  //Verificação responsável por incrementar o menu e resetar ele apóschegar ao ultimo 
  if (menu <=9)
  {
    menu++;
  }
  atualizateMenu();
}

void decrementMenu(){
  //Verificação responsável por decrementar o menus
  if (menu >=1)
  {
    menu--;
  }
  atualizateMenu();
}

