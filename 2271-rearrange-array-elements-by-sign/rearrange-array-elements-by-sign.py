class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        neg=[]
        pos=[]
        ans=nums
        for i in nums:
            if i<0:
                neg.append(i)
            else:
                pos.append(i)
        k=0
        m=1
        i=0
        while (k<=len(nums) and m<=len(nums)):
            
            ans[k]=pos[i]
            k+=2
            
            ans[m]=neg[i]
            m+=2
            i+=1
        return(ans)
        
