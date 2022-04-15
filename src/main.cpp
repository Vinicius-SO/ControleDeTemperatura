#include <Arduino.h>

#define menu_1 1
#define menu_2 2
#define menu_3 3
#define menu_4 4
#define menu_5 5

#define ledMenu_1 2
#define ledMenu_2 3
#define ledMenu_3 4
#define ledMenu_4 5
#define ledMenu_5 6

#define selectMenuButton 12

int menu = 0;

void setup() {

  //Inicia a serial para 9600 
  Serial.begin(9600);

  //Define os leds de que representarão o menu como saída
  pinMode(ledMenu_1, OUTPUT);
  pinMode(ledMenu_2, OUTPUT);
  pinMode(ledMenu_3, OUTPUT);
  pinMode(ledMenu_4, OUTPUT);
  pinMode(ledMenu_5, OUTPUT);
  
  //Define o pino de entrada dobotão
  pinMode(selectMenuButton, INPUT);
}

void loop() {

  // const bool buttonHasPressed = digitalRead(selectMenuButton);
  // buttonHasPressed

}

void incrementMenu(){
  
  //Verificação responsavel por atribuir 
  if (menu <=4)
  {
    menu++;
  }else{
    menu=0;
  }
  
  switch (menu)
  {
    case menu_1 :
      digitalWrite(ledMenu_1, HIGH);
      Serial.println("Menu 1 acessado");
      break;

    case menu_2 :
      digitalWrite(ledMenu_2, HIGH);
      Serial.println("Menu 2 acessado");
      break;
    
    case menu_3 :
      digitalWrite(ledMenu_3, HIGH);
      Serial.println("Menu 3 acessado");
      break;
     
    case menu_4 :  
      digitalWrite(ledMenu_4, HIGH);
      Serial.println("Menu 4 acessado");
      break;
    
    case menu_5 :
      digitalWrite(ledMenu_5, HIGH);
      Serial.println("Menu 5 acessado");
      break;
  
    default:
      Serial.println("That value is not allowed");
      break;
  }
}