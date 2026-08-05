class Solution {
public:
    vector<vector<int>> res;

    void solve(
        vector<int>& candidates, 
        vector<int>& combination,
        int target, 
        int sum,
        int index
    ){
        if(sum == target){
            res.push_back(combination);
            return;
        
        }else if(sum > target || index >= candidates.size()) return;

        for(int i = index; i < candidates.size(); i++){
            combination.push_back(candidates[i]);
            solve(candidates, combination, target, sum + candidates[i], i);
            
            combination.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        solve(candidates, combination, target, 0, 0);
        
        return res;
    }
};