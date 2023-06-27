class Solution {
public:
    int n;
    struct Segment_Tree{   
        int n;
        const int N_INF = -1e9; 
        vector<int> data;
        Segment_Tree(vector<int>& vec){
            data.resize(vec.size()*4 + 1);
            n = vec.size();
            build(1, n, 1, vec);
        }

        void build(int l,int r, int p, vector<int>& vec){
            if(l>r){
                return;
            }
            if(l==r){
                data[p] = vec[l-1];
                return;
            }
            int mid = l + (r-l)/2;
            build(l, mid, p*2,vec);
            build(mid+1, r, p*2+1,vec);
            data[p] = max(data[p*2], data[p*2+1]);
        }

        int query(int l,int r,int L,int R, int p){
            if(l>r || l>R || r<L){
                return N_INF;
            }
            if(l==r){
                return data[p];
            }
            int mid = l + (r - l )/2;
            return max(query(l,mid,L,R,p*2),query(mid+1,r,L,R,p*2+1));
        }
    };

    int ceil(int n,int x){
        return (n + x -1)/x;
    }


    int maxArea(vector<int>& height) {
        n = height.size();
        Segment_Tree seg(height);
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
                    if(i+bias<height.size() && seg.query(1,n,i+bias+1, n, 1)>=height[i]){
                        return 1;
                    }
                    if(i-bias>=0 && seg.query(1,n, 1, i-bias+1, 1)>=height[i]){
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