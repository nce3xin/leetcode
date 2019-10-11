def findKthLargest(nums, k):
    nums=sorted(nums,reverse=True)
    return nums[k-1]

if __name__=='__main__':
    nums=[3,2,1,5,6,4]
    k=2
    res=findKthLargest(nums,k)
    print(res)