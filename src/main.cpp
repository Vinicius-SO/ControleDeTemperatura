#include <Arduino.h>

#define menu_1 1
#define menu_2 2
#define menu_3 3
#define menu_4 4
#define menu_5 5

// #define ledMenu_1 3
// #define ledMenu_2 4
// #define ledMenu_3 5
// #define ledMenu_4 6
// #define ledMenu_5 7

#define Cooler 10

#define selectSubtractButton 13
#define selectAddButton 12
#define turnOnCooler 11

int menu = 0;
bool ligaCooler = false;

void atualizateMenu(){
  //Switch case responsavel por ligar os leds conforme o menu selecionado
  switch (menu)
  {
    case menu_1 :
      PORTD = B00001000;
      Serial.println("Menu 1 acessado");
      break;

    case menu_2 :
      PORTD = B00010000;
      Serial.println("Menu 2 acessado");
      break;
    
    case menu_3 :
      PORTD= B00100000;
      Serial.println("Menu 3 acessado");
      break;
     
    case menu_4 :  
      PORTD= B01000000;
      Serial.println("Menu 4 acessado");
      break;
    
    case menu_5 :
      PORTD= B10000000;
      Serial.println("Menu 5 acessado");
      break;
  
    default:
      Serial.println("Reset menu, temperature off");
      PORTD= B00000000;

      break;
  }
  delay(200);
}


void incrementMenu(){
  
  //Verificação responsável por incrementar o menu e resetar ele apóschegar ao ultimo 
  if (menu <=4)
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

  pinMode(Cooler,OUTPUT);
}

void loop() {

  if(digitalRead(selectAddButton)){
  	incrementMenu();
  }else if(digitalRead(selectSubtractButton)){
    decrementMenu();
  }

  if(digitalRead(turnOnCooler)){
    ligaCooler = !ligaCooler;
    digitalWrite(Cooler, ligaCooler);
    if(ligaCooler){
      Serial.println('Cooler Ligado');
    }else{
      Serial.println('Cooler Desligado');
    }
    delay(200);
  }

}