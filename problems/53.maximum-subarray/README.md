## 题意
求连续最大子序列和。例子：
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
## 思路
动态规划，找状态转移方程。
`dp[i] - 表示到当前位置 i 的最大子序列和`
状态转移方程为： `dp[i] = max(dp[i - 1] + nums[i], nums[i])`
解释：如果dp[i-1]>0，则dp[i]=dp[i-1]+nums[i]；否则，dp[i]=nums[i]。
初始化：`dp[0] = nums[0]`

从状态转移方程中，我们只关注前一个状态的值，所以不需要开一个数组记录位置所有子序列和，只需要两个变量，

`currMaxSum - 累计最大和到当前位置i`

`maxSum - 全局最大子序列和`:
* `curMaxSum = max(curMaxSum + nums[i], nums[i])`
* `maxSum = max(curMaxSum, maxSum)`
## 复杂度
* 时间复杂度：O(n)。
* 空间复杂度：O(1)。