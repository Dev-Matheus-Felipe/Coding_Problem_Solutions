class Solution {
public:
    #define ii pair<int, int>
    const int INF = 1e9;

    int BFORD(vector<vector<int>>& times, int n , int k){
        vector<int> dist(n + 1, INF);
        dist[k] = 0;
        dist[0] = 0;

        for(int i = 0; i < n - 1; i++){
            int x = -1;
            for(vector<int> edge: times){
                int u = edge[0], v = edge[1], w = edge[2];

                if(dist[u] != INF && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    x = v;
                }
            }

            if(x == -1) break;
        }

        for(int i = 1; i <= n; i++){
            if(dist[i] == INF){
                return -1;
            }
        }

        return *max_element(dist.begin(), dist.end());
    }


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int result = BFORD(times, n, k);

        return result;
    }
};