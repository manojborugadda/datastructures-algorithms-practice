#include <iostream>
#include <algorithm>
using namespace std;
/// Find a triplet such that sum of two equals to third element---------------
/*         Input : {5, 32, 1, 7, 10, 50, 19, 21, 2}
           Output : 21, 2, 19

           Input : {5, 32, 1, 7, 10, 50, 19, 21, 0}
           Output : no such triplet exist*/

void findTriplet(int arr[],int n)
{
  sort(arr,arr+n);
 for(int i=n-1;i>=0;i--)
 {
  int j=0;
  int  k = i-1;
  while(j<k)
  {
      if(arr[j]+arr[k] == arr[i])
        {
          cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
          return;
        }
      else
      {
          ( arr[j] + arr[k] < arr[i] ) ? j++ : k--;
      }
  }

 }

 cout<<-1<<endl;/// it means no triplets found

}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }

    findTriplet(arr,n);
  }
  return 0;
}
