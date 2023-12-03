// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// https://www.youtube.com/watch?v=icVJUN45f1E&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=27

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int>distance(n+1,INT_MAX);//initialising distance to INFINITY initially
        vector<int>parent(n+1);
        
        //initialising each node as its own parent
        for(int i=0;i<n+1;i++) {
            parent[i] = i;
        }
        
        //creating adjacency list for the graph
        vector<vector<pair<int, int>>> adj(n + 1);
        //filling the adjacecny list with edges and their weights
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            adj[u].push_back(make_pair(v,weight));
            adj[v].push_back(make_pair(u,weight));
        }
        
        //initialising SET to keep track of NODES and their MINIMUM distances from the SOURCE
        set<pair<int,int>>st;
        //inserting the starting node with distance 0 into set. Because distance of any node to itself is ZERO
        st.insert(make_pair(0,1));
        distance[1] = 0;
        
        //performing DIJKSTRA'S Algorithm to find the Shortest path 
        while(!st.empty()) {
            //get the node with minimum distance
            auto &current = *st.begin();
            int currentNode = current.second;
            int currentDistance = current.first;
            st.erase(current);
            
            //traversing neighbours of current node
            for(auto neighbour : adj[currentNode]) {
                int nextNode = neighbour.first;
                int edgeWeight = neighbour.second;
                //if we found the shortest path we update the distance
                if(currentDistance + edgeWeight < distance[nextNode]) {
                    //removing the old entry from the set if it exists
                    if(distance[nextNode] != INT_MAX) {
                        st.erase(make_pair(distance[nextNode],nextNode));
                    }
                    //updating the parent vector and distance, inserting the new entry into the set
                    distance[nextNode] = currentDistance + edgeWeight;
                    parent[nextNode] = currentNode;
                    st.insert(make_pair(currentDistance + edgeWeight ,nextNode));
                }
            }
        }
        
        //if there is no path to the destination node return {-1}
        if(distance[n] == INT_MAX) return {-1};
        
        //constructing the shortest path from the parent vector
        vector<int>path;
        int currentNode = n;
        
        while(parent[currentNode] != currentNode) {
            path.push_back(currentNode);
            currentNode = parent[currentNode];
        }
        
        path.push_back(1);//adding the first element
        reverse(begin(path),end(path));
        return path;
        
    }
};
