class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            //remove from front jase he fisrt element aaya ga
            if (!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            //remove smaller down 
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            //add element curr
            dq.push_back(i);

            //max ko add kro ans me
            if( i>= k-1 ){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};