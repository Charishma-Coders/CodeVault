class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> result(n,INT_MAX);
        result[src]=0;

        typedef pair<int,int> P;
        vector<vector<P>> adj(n);
        for (auto flight:flights){
            int u=flight[0],v=flight[1],value=flight[2];
            adj[u].push_back({v,value});
        }
        queue<vector<int>> pq;
        pq.push({0,src,k});
        while (!pq.empty()){
            int currDist=pq.front()[0];
            int currNode=pq.front()[1];
            int currK=pq.front()[2];
            pq.pop();

            if (currK<0) continue;

                for (auto flight:adj[currNode]){
                    int destNode=flight.first;
                    int destValue=flight.second+currDist;
                    if (destValue<result[destNode]){
                        result[destNode]=destValue;
                        pq.push({destValue,destNode,currK-1});
                    }
                }
        }
        return result[dst]==INT_MAX?-1:result[dst];
    }
};