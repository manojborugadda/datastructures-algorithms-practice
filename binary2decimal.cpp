#include <iostream>
using namespace std;
//defining the function

int bin2dec(int num)
{
  int dec = 0,i = 1;
  while(num>0)
  {
     dec = dec + (num%2)*i;
     num = num/10;
     i = i*2;

  }
  return dec;
}

// calling the function


 int main()
 {

   int dec = bin2dec(11101);
   cout<<"decimal number is "<<dec<<endl;
   return 0;
 }
}





