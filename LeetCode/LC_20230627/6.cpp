class Solution {
public:
    int numRows;
    int state = 0;//{0:down, 1:rise}
    int flag = 0;// finished count
    pair<int,int> next(const pair<int,int>& p){
        //特例 numRows = 1
        if(this->numRows==1){
            return {p.first, p.second+1};
        }
        pair<int,int> ret;
        if(state==0){
            ret = {p.first+1, p.second};
        }
        else{
            ret = {p.first-1, p.second+1};
        }
        flag++;
        if(flag == this->numRows){
            state = 1 - state;
            flag = 1;
        }
        return ret;
    }

    string convert(string s, int numRows) {
        this->numRows = numRows;
        auto ceil = [&](int n,int x){
            return (n+x-1)/x;
        };
        const int numColumns = s.size(); //忽略常数
        vector<vector<char>> map(numRows+1, vector<char>(numColumns+1,char(0)));
        //initialization
        pair<int,int> last = {1,1};
        flag = 1;
        map[last.first][last.second] = s[0];
        for(int i = 1;i<s.size();i++){
            last = next(last);
            // cout<<last.first<<","<<last.second<<"\n";
            map[last.first][last.second] = s[i];
        }
        string ret = "";
        for(int i = 1;i<=numRows;i++){
            for(int j  = 1;j<=numColumns;j++){
                if(map[i][j]!=char(0)){
                    ret.push_back(char(map[i][j]));
                }
            }
        }
        return ret;
    }
};