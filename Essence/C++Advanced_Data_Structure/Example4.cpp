class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int i = 0;
        for(;i<k;i++) pq.push(nums[i]);
        for(;i<n;i++){
            pq.push(nums[i]);
            pq.pop();
        }
        return pq.top();
    }
};