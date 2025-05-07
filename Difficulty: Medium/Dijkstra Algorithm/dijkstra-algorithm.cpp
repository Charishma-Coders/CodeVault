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
        vector<vector<P>> adj(V);
        result[src]=0;
        for (auto row:edges){
            int u=row[0],v=row[1],w=row[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        set<P> st;
        st.insert({0,src});
        while (!st.empty()){
            auto it=*st.begin();
            int dist=it.first;
            int i=it.second;
            st.erase(it);
            for (auto each:adj[i]){
                int total=dist+each.second;
                if (total<result[each.first]){
                    if (result[each.first]!=INT_MAX){
                        st.erase({result[each.first],each.first});
                    }
                    result[each.first]=total;
                    st.insert({total,each.first});
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