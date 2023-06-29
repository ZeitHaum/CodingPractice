class Solution {
public:
    unordered_map<int,int> hash;
     //double find
    unordered_map<int,int> cnt;
    vector<int> nums_;
    vector<vector<int>> threeSum(vector<int>& nums) {
        //a number have more than 2 is useless(zero for 3).
        for(int i = 0;i<nums.size();i++){
            if(cnt.count(nums[i])==0){
                cnt[nums[i]] = 1;
                nums_.push_back(nums[i]);
            }
            else if(cnt[nums[i]]>=1 &&cnt[nums[i]]<=2){
                cnt[nums[i]]++;
                nums_.push_back(nums[i]);
            }
            else if(cnt[nums[i]]==3 && nums[i]==0){
                cnt[nums[i]]++;
                nums_.push_back(nums[i]);
            }
        }
        //build hash
        for(int i = 0;i<nums_.size();i++){
            hash[nums_[i]] = i;
        }
        set<tuple<int,int,int>> ret_set;
        for(int i = 0;i<nums_.size();i++){
            for(int j = i+1;j<nums_.size();j++){
                if(hash.count(-nums_[i] - nums_[j])!=0){
                    int k = hash[-nums_[i] - nums_[j]];
                    if(k>j){
                        vector<int> vec = {nums_[i], nums_[j], nums_[k]};
                        sort(vec.begin(), vec.end());
                        ret_set.insert({vec[0],vec[1],vec[2]});
                    }
                }
            }
        }

        vector<vector<int>> ret;
        for(tuple<int,int,int> x : ret_set){
            ret.push_back({get<0>(x), get<1>(x), get<2>(x)});
        }
        
        return ret;
    }
};