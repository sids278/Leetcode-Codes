class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        //numexchange-- empty to one full numexcahnge++
        //drink any number of fullbottles

        /*
        now we see --> 13 bottles and 6 exchange rate
        6 peeli--> ans==6
        6--> 1 full
        8 __> 7 peeli
        13--> 6
        7+1__>8
        7+6+2=15
        ex2: 10 and 3
        3 peeli
        7+1==8
        4 peeli
        4+1==5
        5 peeli
        5->5=1
        1
        */
        int iN=numBottles;//intial bottles(iN)
        int eR=numExchange;//exchange Rate(eR)
        int ans=0;
        while(iN>0){
            if(iN>=eR){
                ans+=eR;
                iN-=eR;//drank eR jitni bottles
                iN+=1;//gave back one full bottle
            }else{
                ans+=iN;
                iN=0;
            }
            eR+=1;
        }
        return ans;
    }
};