class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        back(0,result,curr,candidates,target);
        return result;
    }
    void back(int index,vector<vector<int>> &result,vector<int> &curr,vector<int> &candidates,int target){
        if(target==0){
            result.push_back(curr);
            return ;
        }

        if(target<0) return ;
        for(int i=index;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            back(i, result, curr, candidates,  target - candidates[i]);
            curr.pop_back();
        }
    }
};