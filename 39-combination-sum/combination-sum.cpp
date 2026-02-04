class Solution {
public:
    void rec(vector<int>& candidates, int target , int index ,vector<vector<int>> &ans,vector<int> &small){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(small);
            }
            return ;
        }
        if(target>=candidates[index]){
            small.push_back(candidates[index]);
            rec(candidates,target-candidates[index],index,ans,small);
            small.pop_back();
        }
        rec(candidates,target,index+1,ans,small);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> small;
        vector<vector<int>> ans;
        rec(candidates,target,0,ans,small);
        return ans;
    }
};