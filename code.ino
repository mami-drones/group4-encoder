int c, c1; //переменные для подсчета итераций(c-левый, с1-правый)
int l; //переменная для условия
int AA, BB; //1 энкодер 1 датчик, 1 энкодер 2 датчик
int A, B; //2 энкодер 1 датчик, 2 энкодер 2 датчик
int f, f1; //переменные для расчета расстояния в сантиметрах
int a, b, d; //переменные текущей позиции(a=A, B; b=AA, BB)
int aOLD, bOLD; //переменные для предыдущей позиции(для каждого из моторов)


int turn(int x, int y, int z, int n, boolean p, boolean m) //входящие переменные: 1.расстояние для поворота 1 мотора, 2. расстояние для поворота 2 мотора, 3. наряжение для 1 мотора 4. напряжение для 2 мотора 5. напряжение для направления 1 мотора(True || False) 6. напряжение для направления 2 мотора(True || False)
{
  while (c > x && c1 < y)
  {
    //анализ энкодера

    A = analogRead(A2);
    AA = analogRead(A0);
    B = analogRead(A3);
    BB = analogRead(A1);

    if (AA < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
    {
      AA = 0;
    }
    else {
      AA = 1;
    }


    if (A < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
    {
      A = 0;
    }
    else {
      A = 1;
    }


    if (B < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
    {
      B = 0;
    }
    else {
      B = 1;
    }


    if (BB < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
    {
      BB = 0;
    }
    else {
      BB = 1;
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
    //анализ состояния

    //c
    digitalWrite(7, p);
    analogWrite(6, z);

    //c1
    digitalWrite(4, m);
    analogWrite(5, n);

    aOLD = a;
    bOLD = b;
  }
  c = 0;
  c1 = 0;
}


int forward(int x, int y, int z, int n, boolean p, boolean m) //входящие переменные: 1.расстояние для 1 мотора, 2. расстояние для 2 мотора, 3. наряжение для 1 мотора 4. напряжение для 2 мотора 5. напряжение для направления 1 мотора(True || False) 6. напряжение для направления 2 мотора(True || False)
{
  while (f < x && f1 < y)
  {

    //анализ энкодера

    A = analogRead(A2);
    AA = analogRead(A0);
    B = analogRead(A3);
    BB = analogRead(A1);

    if (AA < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
    {
      AA = 0;
    }
    else {
      AA = 1;
    }


    if (A < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
    {
      A = 0;
    }
    else {
      A = 1;
    }


    if (B < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
    {
      B = 0;
    }
    else {
      B = 1;
    }


    if (BB < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
    {
      BB = 0;
    }
    else {
      BB = 1;
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

    f = ((3.14 * 36) / (480)) * c;
    f1 = ((3.14 * 36) / (480)) * c1;

    //анализ ситуации



    if (c == c1)
    {
      l = 1;
    }
    else
    {
      if (c == c1 + 1  )
      {
        l = 0;
      }

    }


    //анализ состояния

    if (l == 1)
    {
      //мотор с
      digitalWrite(7, p);
      analogWrite(6, z);
      analogWrite(5 , 0);

    }
    else
    {
      //мотор с1
      digitalWrite(4, m);
      analogWrite(5, n);
      analogWrite(6, 0);

    }


    aOLD = a;
    bOLD = b;
  }
  c = 0;
  c1 = 0;
  f = 0;
  f1 = 0;
}

void setup() {
  delay(2000);
  Serial.print(9600);
  A = analogRead(A2);
  AA = analogRead(A0);
  B = analogRead(A3);
  BB = analogRead(A1);

  if (AA < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
  {
    AA = 0;
  }
  else {
    AA = 1;
  }


  if (A < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
  {
    A = 0;
  }
  else {
    A = 1;
  }


  if (B < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
  {
    B = 0;
  }
  else {
    B = 1;
  }


  if (BB < 500) //т.к энкодер не выдает 0, переделывает аналоговый сигнал в 0 или 1
  {
    BB = 0;
  }
  else {
    BB = 1;
  }

  a = B + A * 10;
  b = BB + AA * 10;
  aOLD = a;
  bOLD = b;
}

void loop() //LOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP
{
  //движение вперед 50 55 LOW LOW
  //поворот налево на 90 градусов итерации: -24 24, напряжение:35 35
  forward(50, 50, 50, 55, false, false); //входящие данные это расстояние в сантиметрах, которое проедет робот
  turn(-75, 75, 40, 40, true, false);
  forward(50, 50, 50, 55, false, false);

  while (d == 0)
  {
    analogWrite(5, 0);
    analogWrite(6, 0);
  }
}

