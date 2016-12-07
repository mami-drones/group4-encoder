int aStar = 0, c = 0, bStar = 0, c1 = 0; //3.6 градусов за 1 итерацию
int A, l;
int AA;
int B;
int BB, f, f1;
int a, b, d;
#define sp 40 //напряжение на правом(5 пин) двигателе 34
#define sp1 30 //напряжение на левом(6 пин) двигателе 40
#define VOL LOW //выбор направления(7 пин)
#define VOL1 LOW //выбор направления(4 пин)

void setup() {
  delay(2000);
  Serial.print(9600);
  A = digitalRead(A2);
  AA = analogRead(A0);
  B = digitalRead(A3);
  BB = digitalRead(A1);

  if (AA < 500) //
  {
    AA = 0;
  }
  else {
    AA = 1;
  }

  a = B + A * 10;
  b = BB + AA * 10;
  aStar = a;
  bStar = b;
}

void loop() {

  //анализ энкодера
  
  A = digitalRead(A2);
  AA = analogRead(A0);
  B = digitalRead(A3);
  BB = digitalRead(A1);
  if (AA < 500)
  {
    AA = 0;
  }
  else
  {
    AA = 1;
  }

  a = B + A * 10;
  b = BB + AA * 10;



  if (a != aStar)
  {
    switch (a) {
      case 0: if (aStar == 1 && aStar != 11)
        {
          c = c + 1;
        }
        else
        {
          c = c - 1;
        }
        break;
      case 1: if (aStar == 11 && aStar != 10)
        {
          c = c + 1;
        }
        else
        {
          c = c - 1;
        }
        break;
      case 10: if (aStar == 0 && aStar != 1)
        {
          c = c + 1;
        }
        else
        {
          c = c - 1;
        }
        break;
      case 11: if (aStar == 10 && aStar != 0)
        {
          c = c + 1;
        }
        else
        {
          c = c - 1;
        }
        break;
    }
  }

  //another dynamo

  if (b != bStar)
  {
    switch (b) {
      case 0: if (bStar == 10 && bStar != 11)
        {
          c1++;
        }
        else
        {
          c1--;
        }
        break;
      case 1: if (bStar == 0 && bStar != 10)
        {
          c1++;
        }
        else
        {
          c1--;
        }
        break;
      case 10: if (bStar == 11 && bStar != 1)
        {
          c1++;
        }
        else
        {
          c1--;
        }
        break;
      case 11: if (bStar == 1 && bStar != 0)
        {
          c1++;
        }
        else
        {
          c1--;
        }
        break;
    }
  }

//анализ ситуации


  if (c == c1)
  {
    l = 1;
  }
  else
  {
    if (c1 == c - 2)
    {
      l = 0;
    }
  }


//анализ состояния
  
  if (l == 1)
  {
    digitalWrite(7, VOL);
    analogWrite(6, sp1); //40
    analogWrite(5 , 0);
  }
  else
  {
    digitalWrite(4, VOL1);
    analogWrite(5, sp); //34
    analogWrite(6, 0);
  }


  Serial.print(c);
  Serial.print(" ");
  Serial.println(c1);


  aStar = a;
  bStar = b;

}
