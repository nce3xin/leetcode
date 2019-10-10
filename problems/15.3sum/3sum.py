def threeSum(nums):
    res=[]
    if len(nums)<3:
        return []
    nums=sorted(nums)
    for i in range(len(nums)):
        cur=nums[i]
        target=0-cur
        p=i+1
        q=len(nums)-1
        # skip already computed values
        if i>0 and cur==nums[i-1]:
            continue
        while p<q:
            if nums[p]+nums[q]==target:
                res.append([nums[i],nums[p],nums[q]])
                # skip already computed values
                while p<q and nums[p]==nums[p+1]:
                    p=p+1
                p=p+1
                while p<q and nums[q]==nums[q-1]:
                    q=q-1
                q=q-1
            elif nums[p]+nums[q]>target:
                q=q-1
            elif nums[p]+nums[q]<target:
                p=p+1
    return res

if __name__=='__main__':
    nums=[-1,0,1,2,-1,-4]
    res=threeSum(nums)
    print(res)