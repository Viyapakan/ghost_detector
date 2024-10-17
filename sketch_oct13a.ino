int led[]={2,3,4,5,6,7,8,9,10};// here i used 8 leds
int detect_pin= A0; //antenna connected to the A2
int detected_val=0; //variable for the antena reading
#define antena_redings 25 //random readings needed, so i plan to get 25 readings
int index=0; //ots for indexing purpose of the above 25 
int readings[antena_redings]; //here we store the readings from the antena
int total;
int average;
int sensing_limit=1023; //setting the limit of the antenna

void setup(){
  for(int this_led=0;this_led<8; this_led++){
    pinMode (led[this_led],OUTPUT);//setting all the leds as output
    //since a2  automatically considered as an input no need to write it
    Serial.begin(9600);
    for(int i=0; i<antena_redings; i++){
        readings[i]; //getting 25 readings(initializing the readings)
    }
  }
}

void loop(){
  detected_val=analogRead(detect_pin); //
  if(detected_val>1){
    detected_val=constrain(detected_val, 1, 1023);//limiting the maximum as 1023
    detected_val=map(detected_val,1,sensing_limit,1,1023);//again mapping 
    total-= readings[index];
    readings[index]=detected_val;
    total += readings[index];
    index=(index+1);

    if(index>=antena_redings)
      index=0;
    average=total/antena_redings;
    
  
    if(average>50){
      digitalWrite (led[0],HIGH);
    }
    else {
      digitalWrite(led[0],  LOW);
    }
    if(average>150){
      digitalWrite (led[1],HIGH);
    }
    else {
      digitalWrite(led[1],  LOW);
    }

    if(average>250){
      digitalWrite (led[2],HIGH);
    }
    else {
      digitalWrite(led[2],  LOW);
    }

    if(average>350){
      digitalWrite (led[3],HIGH);
    }
    else {
      digitalWrite(led[3],  LOW);
    }

    if(average>450){
      digitalWrite (led[4],HIGH);
    }
    else {
      digitalWrite(led[4],  LOW);
    }

    if(average>550){
      digitalWrite (led[5],HIGH);
    }
    else {
      digitalWrite(led[5],  LOW);
    }

    if(average>650){
      digitalWrite (led[6],HIGH);
    }
    else {
      digitalWrite(led[6],  LOW);
    }
    
    if(average>750){
      digitalWrite (led[7],HIGH);
    }
    else {
      digitalWrite(led[7],  LOW);
    }
    Serial.println(detected_val);
  }
  
}
