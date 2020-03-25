#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int kk=0;
byte m[20][4];
byte bul[20][4];
unsigned long timp;
unsigned long oldt;
unsigned long olda;
byte cst[] = {
  B00111,
  B11000,
  B01100,
  B10111,
  B10111,
  B01100,
  B11000,
  B00111
};
byte csa[] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000
};
byte csb[] = {
  B00000,
  B00000,
  B00110,
  B01001,
  B01001,
  B01001,
  B00110,
  B00000
};
byte csc[] = {
  B00000,
  B00000,
  B01010,
  B10101,
  B10001,
  B01010,
  B00100,
  B00000
};
byte csd[] = {
  B00110,
  B01100,
  B01101,
  B11110,
  B11110,
  B01101,
  B01100,
  B00110
};
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // initialize the serial communications:
  Serial.begin(9600);
  lcd.createChar(0, cst);
  lcd.createChar(1, csa);
  lcd.createChar(2, csb);
  lcd.createChar(3, csc);
  lcd.createChar(4, csd);
  randomSeed(analogRead(0));
}


void loop() {
  int i,j,r,rr,oldk;
  int p=0;
  int in=4;
  int dir;
  int c[3];
  kk=1;
  for(i=0;i<=3;++i)
  {
      lcd.setCursor(17,i);
      lcd.write(B10100101);
  }
  lcd.setCursor(18,2);
  lcd.print("P");
  
  while(in>=0){
  dir=0;
  for(i=0;i<=3;++i)
  {
      lcd.setCursor(0,i);
      if(kk==i)
      lcd.write(byte(0));
  }
  if(digitalRead(6)==HIGH and c[0]==0)
    dir=1;
  if(digitalRead(8)==HIGH and c[2]==0)
    dir=2;
  if(digitalRead(7)==HIGH and c[1]==0)
    dir=3;
  if(kk<3 and dir==1) {kk++;}
  if(kk>0 and dir==2) {kk--;}
  if(dir==3) {bul[1][kk]=1;}
  c[0]=digitalRead(6);
  c[1]=digitalRead(7);
  c[2]=digitalRead(8);
  lcd.setCursor(18,3);
  lcd.print(p%10);
  lcd.setCursor(18,0);
  if(in>=1){
  lcd.write(3);
  }
  else lcd.write(" ");
  lcd.setCursor(19,0);
  if(in>=2){
  lcd.write(3);
  }
  else lcd.write(" ");
  lcd.setCursor(18,1);
  if(in>=3){
  lcd.write(3);
  }
  else lcd.write(" ");
  lcd.setCursor(19,1);
  if(in>=4){
  lcd.write(3);
  }
  else lcd.write(" ");
  if (p/100==1)
  {
  lcd.setCursor(19,2);
  lcd.print("+");
  }
  if (p/100==2)
  {
  lcd.setCursor(19,2);
  lcd.print("*");
  }
  if (p/100==3)
  {
  lcd.setCursor(19,2);
  lcd.write(B10101011);
  }
  delay(1);
  timp=millis();
  r=0;
  if((timp-oldt)>500)
  {
    for(i=0;i<=3;++i)
    {
      for(j=0;j<19;++j)
      {
        m[j][i]=m[j+1][i];
      }
  
    }
    for(i=0;i<=3;++i)
    {
        r=random(0, 8);
        if(r==0){
          rr=random(1,20);
          if(rr<4) m[19][i]=2;
          else if(rr==6 and in<4)
          m[19][i]=3;
          else
          m[19][i]=1;
          if(rr==7 or rr==8 or rr==9)
          m[19][i]=4;
        }
        else
        m[19][i]=0;
  
    }
    if(m[0][kk]==2) p++;
    if(m[0][kk]==1) in--;
    if(m[0][kk]==3) in++;
    oldt=millis();
    }

    timp=millis();
    if((timp-oldt)>100)
    {
      for(i=0;i<=3;++i)
      {
        for(j=2;j<19;++j)
        {
          if(bul[j][i]==1 and m[i][j]!=0)
          {
            bul[j][i]=0;
            m[j][i]=0;
          }
          bul[j][i]=bul[j-1][i];
        }
    
      }
      olda=millis();
    }
    for(i=0;i<=3;++i)
    {
      for(j=0;j<17;j++)
      {
        lcd.setCursor(j,i);
        if(!(kk==i and j==0))
        if(m[j][i]!=0)
        {
        lcd.write(byte(m[j][i]));
        }
        else
        lcd.write(" ");
        if(bul[j][i]==1) lcd.write(B10100101);
      }
    }
  for(i=0;i<=3;++i)
  {
      lcd.setCursor(0,i);
      if(kk==i)
      lcd.write(byte(0));
  }
  }
  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print("Scorul final:");
  lcd.setCursor(8,2);
  lcd.print(p);
  delay(10000);
}
