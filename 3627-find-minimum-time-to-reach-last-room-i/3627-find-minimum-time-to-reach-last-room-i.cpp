class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<pair<int, int>, int>> que;

        que.push({{0, 0}, 0});
        dist[0][0] = 0;

        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!que.empty()) {
            auto [coord, currDist] = que.front(); que.pop();
            int x = coord.first, y = coord.second;

            for (auto& d : dir) {
                int newX = x + d[0], newY = y + d[1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    int wait = max(0, moveTime[newX][newY] - currDist);
                    int newTime = currDist + wait + 1;
                    if (newTime < dist[newX][newY]) {
                        dist[newX][newY] = newTime;
                        que.push({{newX, newY}, newTime});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
