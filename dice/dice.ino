// Dice for Arduino.
// (C) 2012 Tris Linnell
// http://canthack.org
//
//LEDs attached in a dice pattern to pins:
//  2   3
//  4 5 6
//  7   8
//
// Switch on pin 12

boolean numbers[6][7] = {
  {false, false, false, true, false, false, false}, //1
  {true, false, false, false, false, false, true}, //2
  {true, false, false, true, false, false, true}, //3
  {true, true, false, false, false, true, true}, //4
  {true, true, false, true, false, true, true}, //5
  {true, true, true, false, true, true, true}  //6
};

void setup() {                
  // initialize the digital pins as an outputs.
  for(int i = 2; i<=8; i++){
    pinMode(i, OUTPUT);     
  }
  
  pinMode(12, INPUT);  
  randomSeed(analogRead(0));
}

void loop() { 
  while(true){
    if(digitalRead(12)==HIGH){
      roll();
    }
  }
}

//Do the roll
void roll(){
  int num=random(1,7);
  roulette();
  disp(num);
}

//Cool animation
void roulette(){
  int del = 100;
  int pins[] = {2,3,6,8,7,4};
  
  while(del>0){
    //spinny spinny spinny
    for(int i=0; i<=5 ; i++){
  
      for(int j = 2; j<=8; j++){
        digitalWrite(j, LOW);  
      }
    
      digitalWrite(pins[i], HIGH);
      if(del >0){
        delay(del);
      }
      del-=2;  
    }
  }
}

//Display the number
void disp(int num){
  int x=0;
  for(int i = 2; i<=8; i++){
   //all pins
    
    if(numbers[num-1][x]){
      digitalWrite(i, HIGH);  
    }
    else{
      digitalWrite(i, LOW);  
    }
    x++;
  }
}
