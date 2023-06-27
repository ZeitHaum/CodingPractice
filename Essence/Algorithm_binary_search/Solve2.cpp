class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = 1;
        int ans = 1;
        for(int i = 1;i<n;i++){
            int maxlen = 0;
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]) maxlen = max(maxlen,dp[j]);
            }
            dp[i] = maxlen+1;
            ans = max(dp[i],ans);
        }
        return ans;
    }
};