class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        typedef pair<int,pair<int,int>> P;
        int n=moveTime.size();
        int m=moveTime[0].size();

        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<P,vector<P>,greater<P>> pq;

        pq.push({0,{0,0}});
        result[0][0]=0;

        while (!pq.empty()){
            int t=pq.top().first;
            pair<int,int> currCell=pq.top().second;
            int i=currCell.first;
            int j=currCell.second;
            if (i==n-1 && j==m-1) return result[n-1][m-1];
            pq.pop();
            for (auto each:dir){
                int newI=i+each[0];
                int newJ=j+each[1];

                if (newI>=0 && newI<n && newJ>=0 && newJ<m){
                    int wait=max(0,moveTime[newI][newJ]-t);
                    int arrTime=t+wait+1;
                    if (result[newI][newJ]>arrTime){
                        result[newI][newJ]=arrTime;
                        pq.push({arrTime,{newI,newJ}});
                    }
                }
            }
        }

        return -1;
    }
};