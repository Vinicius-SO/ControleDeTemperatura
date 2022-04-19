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


void shiftRegisterValue(int value){

  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, value);
  
  digitalWrite(latchPin, HIGH);
}

void atualizateMenu(){
  //Switch case responsavel por ligar os leds conforme o menu selecionado
  switch (menu)
  {
    case 1 :
      shiftRegisterValue(1);
      Serial.println("Menu 1 acessado");
      break;

    case 2 :
      shiftRegisterValue(2);
      Serial.println("Menu 2 acessado");
      break;
    
    case 3 :
      shiftRegisterValue(4);
      Serial.println("Menu 3 acessado");
      break;
     
    case 4 :
     shiftRegisterValue(8);
      Serial.println("Menu 4 acessado");
      break;
    
    case 5 :
      shiftRegisterValue(16);
      Serial.println("Menu 5 acessado");
      break;
    case 6 :
      shiftRegisterValue(32);
      Serial.println("Menu 6 acessado");
      break;

    case 7 :
      shiftRegisterValue(64);
      Serial.println("Menu 7 acessado");
      break;
    
    case 8 :
      digitalWrite(led9, LOW);
      shiftRegisterValue(128);
      Serial.println("Menu 8 acessado");
      break;
     
    case 9 :  
      shiftRegisterValue(0);
      digitalWrite(led10, LOW);
      digitalWrite(led9, HIGH);
      Serial.println("Menu 9 acessado");
      break;
    
    case 10 :
      digitalWrite(led9, LOW);
      digitalWrite(led10, HIGH);
      Serial.println("Menu 10 acessado");
      break;
  
    default:
      Serial.println("Reset menu, temperature off");
      PORTD= B00000000;
      shiftRegisterValue(0);

      break;
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

void setup() {

  //Inicia a serial para 9600 
  Serial.begin(9600);

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