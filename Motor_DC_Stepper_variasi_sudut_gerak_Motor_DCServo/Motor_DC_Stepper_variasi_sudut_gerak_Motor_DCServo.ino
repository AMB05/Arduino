int A=8; 
int B=9;
int C=10;
int D=11; 
 
void setup()
{
  pinMode(A,OUTPUT); pinMode(B,OUTPUT);
  pinMode(C,OUTPUT); pinMode(D,OUTPUT);
}
 
void pergerakan_1()
{
  digitalWrite(A,1); 
  digitalWrite(D,00);
  digitalWrite(B,1);
  digitalWrite(C,00); 
}
 
void pergerakan_2()
{
  digitalWrite(A,00); 
  digitalWrite(D,00);
  digitalWrite(B,1);
  digitalWrite(C,1); 
}
 
void pergerakan_3()
{
  digitalWrite(A,00); 
  digitalWrite(D,1);
  digitalWrite(B,00);
  digitalWrite(C,1);
}
 
void pergerakan_4()
{
  digitalWrite(A,1); 
  digitalWrite(D,1);
  digitalWrite(B,00);
  digitalWrite(C,00);
}
 
void pergerakan()
{
//pergerakan dari 00, 90', 180', 270', 360'
  pergerakan_1(); delay(1000);  //90'
  pergerakan_2(); delay(1000);  //180'
  pergerakan_3(); delay(1000);  //270'
  pergerakan_4(); delay(1000);  //360'
}
 
void loop()
{
  pergerakan();
}
