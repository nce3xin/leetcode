def two_sum(nums,target):
    val_idx={}
    for i in range(len(nums)):
        val_idx[nums[i]]=i
    for i in range(len(nums)):
        x=target-nums[i]
        if x in val_idx and val_idx[x]!=i:
            return [i,val_idx[x]]