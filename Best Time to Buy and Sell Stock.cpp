  /// 122. Best Time to Buy and Sell Stock *************LEETCODE***********
  /*You are given an array prices where prices[i] is the price of a given stock on the i'th day.

You want to maximize your profit by choosing a SINGLE day to buy one stock and choosing a DIFFERENT day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0..*/

///Input: prices = [7,1,5,3,6,4]
/// Output: 5 ............which came from (6-1)

    #include <bits/stdc++.h>
    using namespace std;
    int maxProfit(int prices[],int n)
    {
        int min_so_far = prices[0];
        int maxprofit = 0;
        for(int i=0;i<n;i++)
        {
           min_so_far = min(min_so_far,prices[i]);
            int profit = prices[i]-min_so_far;
            maxprofit = max(maxprofit,profit);
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

  /// time complexity = O(n), space complexity = O(1)
