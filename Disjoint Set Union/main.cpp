#include<bits/stdc++.h>
using namespace std;
//amortized time complexity is O(alpha(n))
const int N = 1e5+10;
int parent[N];
int size[N];

void make(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find(int v) {
  if(v == parent[v]) return v;
  //Path Compression
  return parent[v] = find(parent[v]);
}

void Union(int a,int b) {
  //we connect the small tree into the Large tree always
  //here 'a' is the LARGE tree and 'b' is the SMALL tree
  //we connect on the basis of SIZE and RANK usually
  a = find(a);
  b = find(b);
  if(a != b) {
    //UNION by SIZE
    if(size[a] < size[b]){
      swap(a,b);
    }
    parent[b] = a;
    size[a] += size[b];
  }
}


//DRIVER CLASS
int main() {
  int n,k;
  cin>>n>>k;
  for(int i = 1;i<=n;i++) {
    make(i);
  }
  while(k--) {
    int u , v;
    cin>>u>>v;
    Union(u, v);
  }

  int connected_count = 0;
  for(int i = 1;i<=n;i++) {
    if(find(i) == i){
      connected_count++;
    }
  }
cout<< connected_count<<endl;
 // return  connected_count;
  
}





//use case of DISJOINT SET UNION
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
//REFER this video(     https://www.youtube.com/watch?v=L8SuKrpNc2Q        )
