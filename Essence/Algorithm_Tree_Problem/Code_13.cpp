class NumArray {
public:
    vector<int>s;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        s.resize(n*4+1);
        nums.insert(nums.begin(),0);
        auto build = [&](auto self,int l,int r,int p)->void{
            if(l==r){
                s[p] = nums[l];
                return;
            }
            int mid = (l+r)/2;
            self(self,l,mid,p*2);
            self(self,mid+1,r,p*2+1);
            s[p] = s[p*2] + s[p*2+1];  
        };
        build(build,1,n,1);
    }
    
    void update(int index, int val) {
        index = index + 1;
        auto up = [&](auto self,int l,int r,int p)->void{
            if(l<=index && r>=index){
                if(l==r){
                    s[p] = val;
                    return;
                }
                int mid = (l+r)/2;
                self(self,l,mid,p*2);
                self(self,mid+1,r,p*2+1);
                s[p] = s[p*2] + s[p*2+1];
                return;
            }
            else{
                return;
            }
        };
        up(up,1,n,1);
    }
    
    int sumRange(int left, int right) {
        left = left + 1;
        right = right + 1;
        auto query = [&](auto self, int l,int r,int p)->int{
            if(left<=l && right>= r){
                return s[p];
            }
            else if(l>right || r<left){
                return 0;
            }
            else{
                int mid = (l+r)/2;
                return self(self,l,mid,p*2)+self(self,mid+1,r,p*2+1);
            }
        };
        return query(query,1,n,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */