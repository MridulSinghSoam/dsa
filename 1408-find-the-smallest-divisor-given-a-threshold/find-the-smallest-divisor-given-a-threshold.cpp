class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        int i=1;
        int j=mx;
        int mid=(i+j)/2;
        int ans=0;
        while(i<=j){
            mid=(i+j)/2;
            if (possible(nums,threshold,mid)){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
    private:
    bool possible(vector<int>&nums,int threshold,int j){
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum += (nums[i] + j - 1) / j;
        }
        return sum<=threshold;
    }
};