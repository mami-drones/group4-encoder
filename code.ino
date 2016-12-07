int c, c1; //переменные для подсчета итераций
int l; //переменная для условия
int AA, BB; //1 энкодер 1 датчик, 1 энкодер 2 датчик
int A, B; //2 энкодер 1 датчик, 2 энкодер 2 датчик
int f, f1; //переменные для расчета расстояния в сантиметрах
int a, b; //переменные текущей позиции(для каждого из моторов)
int aOLD, bOLD; //переменные для предыдущей позиции(для каждого из моторов)
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

  if (AA < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
  {
    AA = 0;
  }
  else {
    AA = 1;
  }

  a = B + A * 10;
  b = BB + AA * 10;
  aOLD = a;
  bOLD = b;
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



  if (a != aOLD)
  {
    switch (a) {
      case 0: if (aOLD == 1 && aOLD != 11)
        {
          c = c + 1;
        }
        else
        {
          c = c - 1;
        }
        break;
      case 1: if (aOLD == 11 && aOLD != 10)
        {
          c = c + 1;
        }
        else
        {
          c = c - 1;
        }
        break;
      case 10: if (aOLD == 0 && aOLD != 1)
        {
          c = c + 1;
        }
        else
        {
          c = c - 1;
        }
        break;
      case 11: if (aOLD == 10 && aOLD != 0)
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

  if (b != bOLD)
  {
    switch (b) {
      case 0: if (bOLD == 10 && bOLD != 11)
        {
          c1++;
        }
        else
        {
          c1--;
        }
        break;
      case 1: if (bOLD == 0 && bOLD != 10)
        {
          c1++;
        }
        else
        {
          c1--;
        }
        break;
      case 10: if (bOLD == 11 && bOLD != 1)
        {
          c1++;
        }
        else
        {
          c1--;
        }
        break;
      case 11: if (bOLD == 1 && bOLD != 0)
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


  aOLD = a;
  bOLD = b;

}
