class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> result(n,INT_MAX);
        result[k-1]=0;
        typedef pair<int,int> P;
        vector<vector<P>> adj(n);

        for (auto time:times){
            int u=time[0],v=time[1],value=time[2];
            adj[u-1].push_back({v-1,value});
        }

        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,k-1});

        while (!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for (auto each:adj[node]){
                int total=dist+each.second;
                int destNode=each.first;
                if (total<result[destNode]){
                    result[destNode]=total;
                    pq.push({total,destNode});
                }
            }
        }

        int maxi=*max_element(result.begin(),result.end());
        return maxi==INT_MAX?-1:maxi;
    }
};