class Solution {
public:
    int search(vector<int>& nums, int target) {
            int i=0;
            int j=nums.size()-1;
            int mid=j/2;
            while(i<=j){
                mid=i+(j-i)/2;
                if (target==nums[mid]){
                    return mid;
                }else if(target>nums[mid]){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
            }
            return -1;
    }
};