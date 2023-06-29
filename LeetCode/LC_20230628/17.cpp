class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = -1;
        int n = nums.size();
        int min_distince = 1e9;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size(); j++){
                int s = nums[i] + nums[j];
                int p = upper_bound(nums.begin(), nums.end(), target - s) - nums.begin();
                int q = -1;
                //valid
                if(p>0){
                    q = max(p - 1, j+1);
                }
                //注意时序
                if(p==n){
                    p = -1;
                }
                else{
                    p = max(p, j+1);
                }
                auto check = [&](int p){
                    if(abs(target - s - nums[p])<min_distince){
                        min_distince = abs(target - s - nums[p]);
                        ret = s + nums[p];
                    }
                };
                // cout<<p<<","<<q<<"\n";
                if(p!=-1 && p<n){
                    check(p);
                }
                if(q!=-1 && q<n){
                    check(q);
                }
            }
        }
        return ret;
    }
};