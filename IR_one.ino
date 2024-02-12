
int front_R = 0; //value to store input
int front_L = 0;
int side_R = 0;
int side_L = 0;

bool stop_fR = true; //boolean for deadend
bool stop_fL= true;  
bool stop_sR = true;
bool stop_sL = true;

bool slow_fR = true; //boolean for deadend
bool slow_fL= true;  
bool slow_sR = true;
bool slow_sL = true;

//make booleans for start slowing down?


//if were over half way then go back

void check_fR(){
  if(front_R <= 500 ){
    stop_fR = false;
    //Serial.println(" FR: false");
  }
    else{
      stop_fR = true;
      //Serial.println("  FR: true");
    }

   if(front_R <= 700 ){
    slow_fR = false;
    //Serial.println(" FR: false");
  }
    else{
      stop_fR = true;
      //Serial.println("  FR: true");
    }
  



}

void check_fL(){
  if(front_L <= 500 ){
    stop_fL = false;
    //Serial.println(" FR: false");
  }
    else{
      stop_fL = true;
      //Serial.println("  FR: true");
    }
}

void check_sR(){
  if(side_R <= 500 ){
    stop_sR = false;
    //Serial.println(" FR: false");
  }
    else{
      stop_sR = true;
      //Serial.println("  FR: true");
    }
}

void check_sL(){
  if(side_L <= 500 ){
    stop_sL = false;
    //Serial.println(" FR: false");
  }
    else{
      stop_sL = true;
      //Serial.println("  FR: true");
    }
}


void setup() {  
  pinMode(A0, INPUT); //input pin declared
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

   pinMode(4, OUTPUT); //input pin declared
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(6, OUTPUT);

  Serial.begin(300);
  
}

void loop() {
  front_L = analogRead(A0); //sets IR to A0's input
  side_L = analogRead(A1);
  front_R = analogRead(A2);
  side_R = analogRead(A3);
  Serial.print(front_L); // Front left A0           prints IR value/input value
  Serial.print("  ");     
  Serial.print(side_L);  // side left A1
  Serial.print("  ");
  Serial.print(front_R); // Front right A2
  Serial.println("  ");
  Serial.println(side_R); // side right A3

 
  check_fR();
  check_fL();
  check_sL();
  check_sR();

  if(stop_fR == false || stop_fL == false){
    analogWrite(4,0);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(7,0);
  }
  
  analogWrite(4,100);
  analogWrite(5,100);
  analogWrite(6,100);
  analogWrite(7,100);
}

/* length stuff:

  2 inches from wall = 920 
*/
