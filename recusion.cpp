// subset sum is e

#include <iostream>
#include <vector>
using namespace std;

void subsetSumHelper(const vector<int>& nums, int index, int currentSum, int targetSum,int array[] ,int n) {
    if (index == n) {
        if (currentSum == targetSum) {
            for(auto it:nums) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    
    // Include the current number
    nums.push_back(nums[index],);
    subsetSumHelper(nums, index + 1, currentSum + nums[index], targetSum, array ,n);
    
    // Exclude the current number
    nums.pop_back(nums[index],);
    subsetSumHelper(nums, index + 1, currentSum, targetSum, array ,n);
}

int main(){

}




