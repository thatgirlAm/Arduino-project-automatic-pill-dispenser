
/*                      SMC : Projet pilulier 
                       
  - Tâche 2 :         Prise
  - User :            Patient et personnel soignant
  - Description  :    Remplissage du bac, délivrance des médicaments, alarme sonore 
                      */


//--Imports de librairies--//

#include <Servo.h>
#include <Keypad.h>

//--Variables--//

Servo servoTrappe1; //---Grande trappe---// 
Servo servoTrappe2;

char message;

int speaker = 3;
int compteur =0;
int pos = 90;
int stade = 0; 
int a = 1;

const int led_rouge = 12; 
const int led_verte = 11; 

char code[3]; 
const byte Ligne = 2; //--3 lignes sur le digicode--//
const byte Colonne = 2; //--3 colonnes sur le digicode--//

//--On définit maintenant les symboles correspondant à chaque bouton--//
char hexaBouton[Ligne][Colonne] = {
  {'1','2'},
  {'4','5'},
};
byte Ligne_Pins[Ligne] = {9, 8}; //--On connecte les lignes du digicode aux pins correspondants--// 
byte Colonne_Pins[Colonne] = {7, 6}; //--On connecte les colonnes du digicode aux pins correspondants--//


Keypad mon_keypad = Keypad( makeKeymap(hexaBouton), Ligne_Pins, Colonne_Pins, Ligne, Colonne); 

//--Initialisations--// 
void setup() {
  
  Serial.begin(9600); 

  pinMode(led_rouge,OUTPUT); 
  pinMode(speaker, OUTPUT);
  pinMode(led_verte,OUTPUT); 
  digitalWrite(led_rouge, HIGH); 
  
  servoTrappe2.attach(10);
  servoTrappe2.write(0);
  
  servoTrappe1.attach(13);
  servoTrappe1.write(pos);
}


//--Boucle--//

void loop() {
  a= 1;
  char keypad_matrix = mon_keypad.getKey(); // Récupère la touche appuyé

  //--Si il nous est transmit une info--//
  if(Serial.available()>0){
    message = Serial.read();
    
    //--Affichage de notre message dans la console--//
    Serial.print(message);
    Serial.print("/n");

    //--Actions découlant des instructions données--//

        //--Si le message est '1', on positionne le servo à 90 degrès (ouverture trappe)--//
        if(message=='1'){
          servoTrappe1.write(90);}
          
       //--Si le message est '0', on positionne le servo à 0 degrès (fermeture trappe)--//
        else if (message == '0'){
   
         tone(speaker, 500);
         servoTrappe1.write(0);
         delay(100);
         noTone(speaker);
          }
          
           if(message=='7' and a == 1){ //--Notification heure de prise--//
          tone(speaker, 1000);
          delay (1000);
          noTone(speaker);
          tone(speaker, 1000);
          delay (1000);
          noTone(speaker);
          tone(speaker, 1000);
          delay (1000);
          noTone(speaker);
          tone(speaker, 1000);
          delay (1000);
          noTone(speaker);
          tone(speaker, 1000);
          delay (1000);
          noTone(speaker);
          tone(speaker, 1000);
          delay (1000);
          noTone(speaker);
          delay(2000);
          tone(speaker, 500);
          delay(2000);
          noTone(speaker); 
          a=0;
          
          }
          
          }
      

      //---stockage du code dans la matrice code---//

      if (keypad_matrix){ 
        code[compteur] =keypad_matrix; 
        compteur+=1; 
       
    if (compteur ==3){ //--Si on a 3 valeurs, on vérifie si le code est bon sinon on remet le compteur à 0--//
      if ( code[0] =='1' && code[1] =='1' && code[2] =='1'){ //--Cas où le code est bon--//
        digitalWrite(led_rouge, LOW); // Eteint la led rouge
        digitalWrite(led_verte, HIGH); // Allume la led verte
        stade = 1;
        Serial.print("5");
      }
      
      if ( code[0] !='1' || code[1] !='1' || code[2] !='1'){ //--Cas où le code n'est pas bon--//
        digitalWrite(led_verte, LOW); 
        digitalWrite(led_rouge, LOW);
         delay(500);
         tone(speaker, 500);
         delay(2000);
         noTone(speaker);
         digitalWrite(led_rouge, HIGH);
           }
//---commande servo moteur2---//
  //--ouverture de la trappe2---//
      if (stade ==1){
        servoTrappe2.write(90);
        delay(2000);
        Serial.print("5");
        Serial.print("\n");
        delay(5000);
        servoTrappe2.write(0);
        digitalWrite(led_verte, LOW); 
        digitalWrite(led_rouge, HIGH); 
        }
  
      else if(stade ==0){
        delay(100);
        servoTrappe2.write(0);
        }
      
      compteur=0;
      stade =0;

     
      }
  }
    
    

    

}
