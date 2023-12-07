class Solution {
public:
    typedef pair<int,int> pi;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //creating adjacency list
        unordered_map<int,vector<pi>>adj;
        for(auto &vec : times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back(make_pair(v,w));
        }


        vector<int>time(n+1 , INT_MAX);//initialising time vector to INFINITY initially
        set<pi>st;
        st.insert({0,k}); // inserting the { distance , source node }
        time[k] = 0;
        //performing DIJKSTRA'S Algorithm to find the Shortest path
        while(!st.empty()) {
            auto current = *st.begin();
            int currentNode = current.second;
            int currentTime = current.first;
            st.erase(current);
            for(auto neighbour : adj[currentNode]) { //traversing neighbours of current node
                int nextNode = neighbour.first;
                int edgeWeight = neighbour.second;
                if(edgeWeight + currentTime < time[nextNode] ) {//if we found the shortest path we update the time
                    if(time[nextNode] != INT_MAX) {//removing the old entry from the set if it exists
                        st.erase(make_pair(time[nextNode],nextNode));
                    }
                    time[nextNode] = edgeWeight + currentTime;
                    //updating the parent vector and distance, inserting the new entry into the set
                    st.insert(make_pair( edgeWeight + currentTime,nextNode));
                }
            }
        }
        //if(time[n-1] == INT_MAX) return -1;
        //fetching for the highestTime duration in the time vector
        int ans = -1;
        for(int i = 1;i<n+1;i++) {
            if(time[i] == INT_MAX) return -1;
            ans = max(ans , time[i]);
        }
        return ans;
    }
};
