class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int l = 0;
        int r = n;
        while(r-l>1){
            int mid = l + (r - l)/2;
            auto check = [&](){
                int cnt = 0;
                for(int i = 0;i<n+1;i++){
                    if(nums[i]<=mid) cnt++;
                }
                if(cnt<=mid) return 1;
                else return 2;
            };
            if(check()==1) l = mid;
            else r = mid;
        }
        return r;
    }
};