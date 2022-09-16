  /// 122. Best Time to Buy and Sell Stock  II *************LEETCODE***********
  /*You are given an array prices where prices[i] is the price of a given stock on the i'th day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again)..*/

///Input: prices = [7,1,5,3,6,4]
/// Output: 7 ............which came from addition of 5-1,6-3..........


    #include <bits/stdc++.h>
    using namespace std;
    int  maxProfit(int prices[],int n)
    {
        int maxprofit = 0;
        for( int i=1;i<n;i++)
        {
           if(prices[i]>prices[i-1])
              {
                maxprofit = maxprofit+(prices[i]-prices[i-1]);
              }
        }
        return maxprofit;
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
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxProfit(arr,n)<<endl;
  }
  return 0;
  }
