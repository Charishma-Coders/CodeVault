//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        typedef pair<int,int> P;
        
        vector<int> result(V,INT_MAX);
        result[src]=0;
        
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,src}); // {dist,src}
        
        vector<vector<P>> adj(V);
        for (auto each:edges){
            int u=each[0],v=each[1],value=each[2];
            adj[u].push_back({v,value});
            adj[v].push_back({u,value});
        }
        
        while (!pq.empty()){
            int currDist=pq.top().first;
            int currNode=pq.top().second;
            pq.pop();
            for (auto each:adj[currNode]){
                int totalDist=each.second+currDist;
                int destNode=each.first;
                if (totalDist<result[destNode]){
                    result[destNode]=totalDist;
                    pq.push({totalDist,destNode});
                }
            }
        }
        
        return result;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends