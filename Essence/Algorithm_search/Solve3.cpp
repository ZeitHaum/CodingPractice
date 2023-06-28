class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxas = 0;
        while(l<=r){
            maxas = max(maxas, (r - l) * min(height[l],height[r]));
            if(height[r] > height[l]){
                l++;
            }
            else{
                r --;
            }
        }
        return maxas;
    }
};