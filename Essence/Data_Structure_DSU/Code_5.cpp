
class Solution {
public:
    struct point{
        int x;
        int y;
        point(int x,int y):x(x),y(y){}
        point():x(-1),y(-1){}
        bool operator==(const point& p)const{
            return this->x==p.x && this->y == p.y;
        }
        bool operator<(const point& p)const{
            if(this->x==p.x) return this->y<p.y;
            else return this->x<p.x;
        }
        point(const point& p):x(p.x),y(p.y){}
        friend ostream& operator<<(ostream& out, const Solution::point& p){
            return out<<p.x<<" "<<p.y<<" ";
        } 
    };

    struct DSU_size{
        int element_cnt;
        map<point,point> e;
        DSU_size(vector<vector<int>>grid){
            element_cnt =  0;
            for(int i =0;i<grid.size();i++){
                for(int j = 0;j<grid[0].size();j++){
                    if(grid[i][j]==1){
                        point*l = new point();
                        point p = point(i,j);
                        e[p] = *l;
                        element_cnt++;
                    }
                }
            }
        }
        point find(const point& p){return e[p].x<0?p:e[p] = find(e[p]);}
        int size(const point& p){return -e[find(p)].x;}
        int unite(int x1,int y1,int x2,int y2){
            point x{x1,y1};
            point y{x2,y2};
            x = find(x),y = find(y);
            if(x==y) return 0;
            if(e[x].x<e[y].x) swap<point>(x,y);
            e[y].x += e[x].x;
            e[x] = y;
            return -1;
        }
    };


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        DSU_size dsu(grid);
        int max_size = 0;
        if(grid.size()==0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(i>0 && grid[i-1][j] ==1) {
                        dsu.unite(i,j,i-1,j);
                    }
                    if(j>0 && grid[i][j-1]==1){
                        dsu.unite(i,j,i,j-1);
                    }
                    point p{i,j};
                    max_size = max(max_size,dsu.size(p));    
                }
            }
        }
        // for(auto iter = dsu.e.begin();iter!=dsu.e.end();iter++){
        //     cout<<iter->first<<" "<<iter->second<<endl;
        // }
        return max_size;
    }
};
