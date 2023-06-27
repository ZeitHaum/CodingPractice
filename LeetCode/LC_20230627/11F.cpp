class Solution {
public:
    int n;
    vector<int>premax;
    vector<int>sufmax;

    int ceil(int n,int x){
        return (n + x -1)/x;
    }

    void init_max(vector<int>& vec){
        premax.resize(n);
        sufmax.resize(n);
        for(int i = 0;i<vec.size();i++){
            if(i==0){
                premax[i] = vec[i];
            }
            else{
                premax[i] = max(premax[i-1], vec[i]);
            }
        }
        for(int i = n-1;i>=0;i--){
            if(i==n-1){
                sufmax[i] = vec[i];
            }
            else{
                sufmax[i] = max(sufmax[i+1],vec[i]);
            }
        }
    }


    int maxArea(vector<int>& height) {
        n = height.size();
        init_max(height);
        int l = 0;
        int r = *max_element(height.begin(), height.end()) * (height.size()) + 1;// max_l + 1
        while(r - l >1){
            int mid = l + (r - l)/2;
            auto check = [&](){
                for(int i = 0;i<height.size();i++){
                    //特例
                    if(height[i]==0){
                        continue;
                    }
                    int bias = ceil(mid, height[i]);
                    if(i+bias<height.size() && sufmax[i+bias]>=height[i]){
                        return 1;
                    }
                    if(i-bias>=0 && premax[i-bias]>=height[i]){
                        return 1;
                    }
                }
                return 2;
            };
            if(check()==1){
                l = mid;
            }
            else{
                r = mid;
            }
        }  
        return l;
    }
};