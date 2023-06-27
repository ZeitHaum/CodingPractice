class Solution {
public:
    struct point{
        int x;
        int y;
        point(int x,int y):x(x),y(y) {}
        point(): x(-1),y(-1){}
        bool operator==(const point& p)const{
            return this->x==p.x && this->y==p.y;
        }
        bool operator<(const point&p )const{
            if(this->x == p.x) return this->y<p.y;
            else return this->x<p.x;
        }
        point(const point& p): x(p.x),y(p.y){}
        void swap(point& p){
            int temp_x = p.x;
            int temp_y = p.y;
            p.x = this->x;
            p.y = this->y;
            this->x = temp_x;
            this->y = temp_y;
        }
        friend ostream& operator<<(ostream& out,const point& p){
            return out<<p.x<<" "<<p.y<<" ";
        }
    };

    struct DSU_size{
        map<point,point>e;
        DSU_size(vector<vector<char>>& grid){
            for(int i = 0;i<grid.size();i++){
                for(int j = 0;j<grid[0].size();j++){
                    if(grid[i][j]=='1'){
                        point p{i,j};
                        point* l = new point();
                        e[p] = *l;
                    }
                }
            }
        }
        point find(point& p){return e[p].x<0?p:e[p] = find(e[p]);}
        bool check_same(point& p1,point& p2){return find(p1)==find(p2);}
        bool size(point& p){return -find(p).x;}
        int unite(int x1,int y1,int x2,int y2){
            point p1{x1,y1};
            point p2{x2,y2};
            p1 = find(p1), p2 = find(p2);
            if(p1==p2) return 0;
            if(e[p1].x<e[p2].x) p1.swap(p2);
            e[p2].x += e[p1].x;
            e[p1] = p2;
            return -1;
        }   

    };

    int numIslands(vector<vector<char>>& grid) {
        DSU_size dsu(grid);
        int n = grid.size();
        int m = grid[0].size();
        int land_cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                land_cnt+= grid[i][j]=='1'?1:0;
            }
        }
        if(grid.size()==0) return 0;
        int merge_cnt = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]!='1') continue;
                if(i>0 && grid[i-1][j]=='1') merge_cnt+=dsu.unite(i,j,i-1,j);
                if(j>0 && grid[i][j-1]=='1') merge_cnt+=dsu.unite(i,j,i,j-1);
            }
        }
        // for(auto iter = dsu.e.begin();iter!=dsu.e.end();iter++){
        //     cout<<iter->first<<iter->second<<endl;
        // }
        return land_cnt+merge_cnt;
    }
};