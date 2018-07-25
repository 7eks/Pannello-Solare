  //PARAMETRI
  int SCARTO = 15;
  int TALLARME = 85;
  int DIR_START = 2;
  int T_APERTURA = 10;
  //********
  
  int photo1 = 0;
  int photo2 = 1;
  int rtd = 2;
  int out1 = 2;
  int out2 = 3;
  int out3 = 13;
  float photoval1 = 0;
  float photoval2 = 0;
  float scrt = SCARTO * 10;
  float rtdtemp = 0;
  int tpausa = 10000;
  int movimento = 0;


void setup() { 
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
  digitalWrite(out3, LOW);
  Serial.begin(9600);
  digitalWrite(DIR_START, HIGH);
  delay(T_APERTURA * 1000);
  digitalWrite(DIR_START, LOW);
  delay(5000);
  digitalWrite(DIR_START, HIGH);
  delay(T_APERTURA * 1000);
  digitalWrite(DIR_START, LOW);
  delay(5000);
  digitalWrite(DIR_START, HIGH);
  delay(T_APERTURA * 1000);
  digitalWrite(DIR_START, LOW);
}

void loop() {

  photoval1 = analogRead(photo1);
  photoval2 = analogRead(photo2);

      if(photoval1 > photoval2){

      if(photoval1 > (photoval2 + scrt)) movePanel(1);

    }else{

      if(photoval2 > (photoval1 + scrt)) movePanel(2);
      else movePanel(0);

  
    }
    Serial.println(photoval1);
    Serial.println(photoval2);
    Serial.println(movimento);
  }

void movePanel(int x){

  switch(x){
    case 0: if (movimento != x){
      digitalWrite(out1, LOW);
      digitalWrite(out2, LOW);
      delay(tpausa);
      movimento = 0;
      }
      break;
    case 1: if (movimento != x){
      digitalWrite(out2, LOW);
      digitalWrite(out1, HIGH);
      movimento = 1;
      }
      break;
    case 2: if (movimento != x){
      digitalWrite(out1, LOW);
      digitalWrite(out2, HIGH);
      movimento = 2;
      }
      break;
    default: break;

}
}

  
