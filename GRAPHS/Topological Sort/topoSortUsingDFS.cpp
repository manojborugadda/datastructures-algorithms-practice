//https://www.geeksforgeeks.org/problems/topological-sort/1

// Topological Sorting using DFS

// https://www.youtube.com/watch?v=5lZ0iJMrUMk



class Solution {
  public:
    void DFS(int node , stack<int>&st, vector<int>&vis,vector<int>adj[]) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                DFS(it,st,vis,adj);
            }
            // st.push(node);
        }
        st.push(node); // ✅ push after exploring all neighbors
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& input) {
        stack<int>st;
        vector<int>vis(V,0);
        vector<int>adj[V];
        //build adj list
        for(int i =0;i<input.size();i++) {
            int a = input[i][0];
            int b = input[i][1];
            adj[a].push_back(b);
        }
        
        //DFS
        for(int i =0;i<V;i++) {
            if(!vis[i]) {
                DFS(i,st,vis,adj);
            } 
        }
        
        vector<int>ans;
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
