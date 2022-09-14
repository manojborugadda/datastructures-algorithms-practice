#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// A utility function to add an edge in a Directed graph.
void addEdge(vector<int>adj[],int u , int v) {
    adj[u].push_back(v);
}


// A utility function to do BFS of graph
// from a given vertex u.
void BFSUtil(int s , vector<int>adj[] , vector<bool> &visited) {
  queue<int> q;
  visited[s] = true;
  q.push(s);
  while( q.empty() == false) {
    int u = q.front();
    q.pop();
    cout << u << " ";
    for(auto  x : adj[u]) {
      if(visited[x] == false) {
        visited[x] = true;
        q.push(x);
      }
    }
  }
}

// This function does BFSUtil() for all
// unvisited vertices.
void BFS(vector<int>adj[],int V) {
  vector<bool>visited(V,false);
  for(int i = 0;i<V;i++) {
    if(visited[i] == false) {
      BFSUtil(i,adj,visited);
    }
  }
}
//driver code

int main() {
int V = 5;
vector<int>adj[V];
//adding the edges
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

BFS(adj,V);
  return 0;
}


/// https://www.youtube.com/watch?v=pQTbrRhuWXI&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=6
