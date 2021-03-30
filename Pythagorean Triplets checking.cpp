#include <iostream>
#include <algorithm>
using namespace std;
/// Pythagorean Triplets ----------------
bool check(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
    arr[i] = arr[i]*arr[i];
  }
  sort(arr,arr+n);
 for(int i=n-1;i>=2;i--)
 {
  int j=0;
  int  k = i-1;
  while(j<k)
  {
      if(arr[j]+arr[k] == arr[i])
        {
          return  true;
        }
      else
      {
          ( arr[j] + arr[k] < arr[i] ) ? j++ : k--;
      }
  }

 }

 return false;/// it means no triplets found

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

    if(check(arr,n))
    {
      cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
  }

  return 0;
}
