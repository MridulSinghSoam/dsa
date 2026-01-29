class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        back(result,curr,candidates,0,target);
        return result;
    }
    void back(vector<vector<int>> &result,vector<int> &curr,vector<int> &candidates,int index, int target){
        if (target == 0) {
        result.push_back(curr);
        return;
        }

        for (int i=index;i<candidates.size();i++){
            if (i > index && candidates[i] == candidates[i - 1]) continue; // skip duplicates
            if (candidates[i] > target) break;
            curr.push_back(candidates[i]);
            back(result,curr,candidates,i + 1, target - candidates[i]); // ⛔ no reuse
            curr.pop_back();
        }
    }
};