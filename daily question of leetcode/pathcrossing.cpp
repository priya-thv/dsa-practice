class Solution {
public:
    bool isPathCrossing(string path) {
       set<pair<int, int>> t;
        int x=0,y=0;
        t.insert({x,y});
        for(auto d:path){
            if(d=='N'){
                x++;
            }else if(d=='S'){
                x--;
            }else if(d=='E'){
                y++;
            }else if(d=='W'){
                y--;
            }
            if(!t.insert({x,y}).second){
            return true;
        }
        }
        

        return false;
    }
};
