class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        front=[]
        back=[]
        same=[]
        for i in range(len(nums)):
            if nums[i]<pivot :
                front.append(nums[i])
            elif nums[i]==pivot :
                same.append(nums[i])
            else:
                back.append(nums[i])

        return(front+same+back)