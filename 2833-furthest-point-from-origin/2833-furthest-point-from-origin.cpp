class Solution {
public:
    int moveMaker(char x){
        if(x=='L')return -1;
        return 1;

    }
    int furthestDistanceFromOrigin(string moves) {
        int dist=0;
        int movL=moves.size();
        int unknow=0;
        for(int i=0;i<movL;i++){
            char x=moves[i];
            if(x=='L'||x=='R')dist+=moveMaker(x);
            else unknow++;
        }
        if(dist>=0)return dist+=unknow;
        return (unknow-dist);
    }
};