class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr ;
        back(1,result,curr,n,k);
        return result;
    }
    void back(int start,vector<vector<int>>&result ,vector<int> &curr,int n,int k){
        if(k==0 && n==0){
            result.push_back(curr);
            return ;
        }
        if(k<0||n<0)return;
        for(int i=start;i<=9;i++){
            curr.push_back(i);
            back(i+1,result,curr,n-i,k-1);
            curr.pop_back();
        }
    }
};