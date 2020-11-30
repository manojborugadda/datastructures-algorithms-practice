#include <iostream>
using namespace std;

int dec2bin(int number)//defining---------
{
  int bin =0;
  int i = 1;
  while(number>0)
  {
    bin += (number%2)*i;
    number = number/2;
    i = i*10;
  }
  return bin;
}

// calling
int main()
{
  int bin = dec2bin(22);
  cout<<"binary"<<bin<<endl;
  return 0;

}





