class Solution {
public:
    //N-->1
    //E-->2
    //S-->3
    //W-->4
    map<pair<int,int>,int>mp;
    int operation(int direction,int op){
        
        if(direction==4){
            if(op==-1)return 1;
            if(op==-2)return 3;
        }
        if(op==-1)return direction+1;
        return direction+3>4?(direction+3)%4:direction+3;
    }
    pair<int,int> increment(int x,int y,int direction,int op){
        if(direction==1){
            for(int i=1;i<=op;i++){
                if(mp.find({x,y+i})!=mp.end())return {x,y+i-1};
            }
            return {x,y+op};
        }
        if(direction==2){
            for(int i=1;i<=op;i++){
                if(mp.find({x+i,y})!=mp.end())return {x+i-1,y};
            }
            return {x+op,y};
        }
        if(direction==3){
            for(int i=1;i<=op;i++){
                if(mp.find({x,y-i})!=mp.end())return {x,y-i+1};
            }
            return {x,y-op};
        }
        for(int i=1;i<=op;i++){
                if(mp.find({x-i,y})!=mp.end())return {x-i+1,y};
        }
        cout<<"came here";
        return {x-op,y};;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direction=1;
        int x=0;int y=0;
        mp.clear();
        for(auto x:obstacles){
            mp[{x[0],x[1]}]=1;
        }
        int dis=0;
        for(auto c:commands){
            if(c==-1||c==-2){
                direction=operation(direction,c);
            }
            else{
                auto X=increment(x,y,direction,c);
                x=X.first;
                y=X.second;
            }
            cout<<direction<<" "<<x<<" "<<y<<endl;
            dis=max(dis,x*x+y*y);
        }
        
        return dis;
    }
};