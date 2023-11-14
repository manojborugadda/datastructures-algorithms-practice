
//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
/*
Time Complexity: O(ElogV)
The time complexity is O(ElogV) where E is the number of edges and V is the number of vertices. 
This is because, for each vertex, we need to traverse all its adjacent vertices and update their distances, which takes O(E) time.
Also, we use a Priority Queue which takes O(logV) time for each insertion and deletion.

Space Complexity: O(V)
The space complexity is O(V) as we need to maintain a visited array of size V, a map of size V, and a Priority Queue of size V.
*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans(V,INT_MAX);
        ans[source] = 0;
        pq.push({0,source});//pushing { weight , node}  keeping weight in FIRST Index pair (feasible for minHeap on the basis of weight)
        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &vec : adj[node]) {
                int dist1 = vec[1];
                int adjNode = vec[0];
                if(dist1 + dist < ans[adjNode]) {
                    ans[adjNode]  = dist + dist1;
                    pq.push(make_pair(dist1 + dist , adjNode));
                }
            }
        }
        return ans;
    }
};
