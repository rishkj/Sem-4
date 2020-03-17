#include <Keypad.h>
#include <Password.h>
#include <Servo.h>
int lpin = 12;
int pos = 0; 
Servo myservo; 
String newPasswordString; //hold the new password
char newPassword[6]; //charater string of newPasswordString
//initialize password to 1234
//you can use password.set(newPassword) to overwrite it
char passwordstring[5]="1234";
char *myReallyEasyToGuessPassword = passwordstring;
Password password = Password(myReallyEasyToGuessPassword);
byte maxPasswordLength = 6; 
byte currentPasswordLength = 0;
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Four columns
//Define the keymap
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
//// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = {6,7,8,9}; //connect to row pinouts
// Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins.
byte colPins[COLS] = {2,3,4}; //connect to column pinouts
// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



const int trigPin = A4;
const int echoPin = A5;
long duration;
int distance;


void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(lpin,OUTPUT);
    myservo.attach(10); 
}
void loop()
{
  /*
    //digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration=pulseIn(echoPin,HIGH);
    distance=duration*0.034/2;
    //Serial.print("Distance:");
    //Serial.println(distance);

       */
    char key = keypad.getKey();
    if (key != NO_KEY){
    delay(60); 
    switch (key){
    //case '0': changePassword(); break; 
    case '#': checkPassword(); break;
    case '*': resetPassword(); break;
    default: processNumberKey(key);
          }
       }
}
void processNumberKey(char key) {
   Serial.print(key);
   currentPasswordLength++;
   password.append(key);
if (currentPasswordLength == maxPasswordLength) {
checkPassword();
   } 
}
void checkPassword() 
{
  
   if (password.evaluate())
   {
      Serial.println(" OK.");
      char entryOp = keypad.getKey();
      //digitalWrite(LED_BUILTIN, HIGH); 
      while(entryOp == NO_KEY)
      {
          entryOp = keypad.getKey();
      }
      if(entryOp == '*')
      {
          changePassword();
      }
      else 
      {
          Serial.println("door opening");

          //run servo motor to open door 
          opendoor();
      }
   } 
   else 
   {
      Serial.println(" Wrong password!");
      digitalWrite(lpin, LOW); 
   } 
resetPassword();
}
void resetPassword() {
   password.reset(); 
   currentPasswordLength = 0; 
   Serial.println("");

}
void changePassword() {
   newPasswordString = "";
   int setflag = 0;
   char newkey;
   int paslen = 0;
   Serial.println("Changing Password");
   do{
   newkey = keypad.getKey();
   }while(newkey == NO_KEY);
   while (newkey != '*' and newkey != '#' and newkey!= '0' and paslen<5)
   {         
       //Serial.println("appending");   
       if (newkey != NO_KEY){ 
         delay(60);   
         newPasswordString += newkey;
         paslen += 1;
         Serial.println(newPasswordString);
         //Serial.println(paslen);
       }
       if(paslen<5){
        newkey = keypad.getKey();
       }
   }
       newPasswordString.toCharArray(newPassword, newPasswordString.length()+1); //convert string to char array
       password.set(newPassword);
       resetPassword();
       Serial.print("Password changed to ");
       Serial.println(newPasswordString);
}

void opendoor()
{
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  char closekey; 
  do{
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration=pulseIn(echoPin,HIGH);
    distance=duration*0.034/2;
    if(distance<=3)
    {
      digitalWrite(lpin, HIGH); 
    }
    else
    {
      digitalWrite(lpin, LOW);
    }

   closekey = keypad.getKey();
   }while(closekey != '#');
   digitalWrite(lpin, LOW);
   Serial.println("door closing");

  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
