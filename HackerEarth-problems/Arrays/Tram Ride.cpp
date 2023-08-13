// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/tram-ride-d7ff3a92/

#include<bits/stdc++.h>
using namespace std;
//////// complete the below function
long long solve (int N, int start, int finish, vector<int> Ticket_cost) {
if(finish  < start) {
    swap(start,finish);
} 
int start_anticlock = finish - 1;
int finish_anticlock = N+start-1;
int start_clock = start-1;
int finish_clock = finish-1;

int sum1 = 0 , sum2 = 0;

for(int i = start_anticlock;i<finish_anticlock;i++) {
    int j = i%N;
    sum1 += Ticket_cost[j];
}

for(int i = start_clock;i<finish_clock;i++) {
    sum2 += Ticket_cost[i];
}
return min(sum1,sum2);
}
//////////////////////Driver function
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int start;
    cin >> start;
    int finish;
    cin >> finish;
    vector<int> Ticket_cost(N);
    for(int i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
    {
    	cin >> Ticket_cost[i_Ticket_cost];
    }

    long long out_;
    out_ = solve(N, start, finish, Ticket_cost);
    cout << out_;
}
