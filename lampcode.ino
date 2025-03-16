int collockbtn = 13;
int dmodebtn = 8;
int cadjustbtn = 2;

int collockval = 100;
int dmodeval = 100;
int cadjustval = 100;


int collock= 0;
int dmode = 0;
int cadjust = 0;

int switchedon = 0;


int trigpin = 4;
int echopin = 5;
int pingtraveltime;
int distance;

int whiteval = 0;

int red = 0; 
int green = 0; 
int blue = 0;

void setup() {

  Serial.begin(9600);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(collockbtn, INPUT);
  pinMode(dmodebtn, INPUT);
  pinMode(cadjustbtn, INPUT);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  digitalWrite(collockbtn, HIGH);
  digitalWrite(dmodebtn, HIGH);
  digitalWrite(cadjustbtn, HIGH);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
   digitalWrite(trigpin, LOW);
   delayMicroseconds(10);
   digitalWrite(trigpin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigpin, LOW);
   pingtraveltime = pulseIn(echopin, HIGH);
   delay(25);
   distance = (pingtraveltime * 0.034) / 2;

   Serial.println(distance);
   

   collockval = digitalRead(collockbtn);
   dmodeval =digitalRead(dmodebtn);
   cadjustval = digitalRead(cadjustbtn);

   //Serial.println(cadjustval);


   if(dmodeval == 0)
   {
    dmode = 1;
    collock = 0;
    cadjust = 0;
   }

   
   if(cadjustval == 0)
   {
    dmode = 0;
    collock = 0;
    cadjust = 1;
   }

   if(collockval == 0)
   {
     dmode = 0;
     collock = 1;
     cadjust = 0;
   }



   if(dmode == 1){
    if(distance <= 20){
      if(switchedon == 0){
        switchedon = 1;
        red = 255;
        blue = 255;
        green = 255;
        delay(500);
      }
      else{
        switchedon = 0;
        red = 0;
        blue = 0;
        green = 0;
        delay(500);
      }
    }
   }

   

   if(cadjust == 1){
       if(distance >= 2 && distance <= 8){
             if(red == 250){
                 red = 250;
             }
             else{
                 red = red + 1;
             }
       }
       if(distance >= 9 && distance <= 15){
              if(red == 0){
                  red = 0;
              }
              else{
                  red = red - 1;
              }
       }

       if(distance >= 16 && distance <= 22){
             if(green == 250){
                   green = 250;
             }
             else{
                  green = green + 1;
             }
       }

       if(distance >= 23 && distance <= 29){
             if(green == 0){
                  green = 0;
             }
             else{
                  green = green - 1;
             }
       }

       if(distance >= 30 && distance <= 36){
             if(blue == 250){
                   blue = 250;
             }
             else{
                   blue = blue + 1;
             }
       }

       if(distance >= 37 && distance <= 43){
             if(blue == 0){
                   blue = 0;
             }
             else{
                   blue = blue - 1;
             }
        }
   }

   if(collock == 1){
    
   }
  

   analogWrite(redpin, red);
   analogWrite(bluepin, green);
   analogWrite(greenpin, blue);
  // put your main code here, to 
}
