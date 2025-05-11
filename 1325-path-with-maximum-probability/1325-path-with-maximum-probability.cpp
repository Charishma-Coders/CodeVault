class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        typedef pair<double,int> P;
        vector<double> result(n,0.0);
        result[start_node]=1.0;
        vector<vector<pair<int,double>>> adj(n);
        for (int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

        priority_queue<P> pq;
        pq.push({1.0,start_node});

        while (!pq.empty()){
            double currProb=pq.top().first;
            int currNode=pq.top().second;
            pq.pop();
            for (auto each:adj[currNode]){
                double destProb=currProb*each.second;
                int destNode=each.first;

                if (result[destNode]<destProb){
                    result[destNode]=destProb;
                    pq.push({destProb,destNode});
                }
            }
        }

        return result[end_node];
    }
};