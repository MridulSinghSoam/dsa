class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(0,nums,curr,result);
        return result;
    }
    void backtrack(int index,vector<int> &nums,vector<int> &curr,vector<vector<int>> &result){
        result.push_back(curr);
        for (int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(i+1,nums,curr,result);
            curr.pop_back();
        }
        return;
    }
};