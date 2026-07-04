class Solution {
public:

    int Find(int x, vector<int> &parent){
        if(parent[x] == x) return x;
        parent[x] = Find(parent[x], parent);

        return parent[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n);
        vector<vector<int>> result;

        for(int i = 0; i < n; i++) parent[i] = i;
    
        for(vector<int> v: edges){
            int a = Find(v[0] - 1, parent), b = Find(v[1] - 1, parent);
            if(a == b){
                result.push_back(v);
                continue;
            }
            parent[a] = b;
        }

        return result[result.size() - 1];
    }
};