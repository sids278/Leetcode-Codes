class Solution {
public:
    
    
    // A--> AAA(3)  AAA(4)-->AAA(5)-->AAAAAA()
    
    int minSteps(int n) {
        if(n==1)return 0;
        int minOps=1e9;
        for(int i=2;i<n/2;i++){
            if(n%i==0){
                minOps=min(minOps,(n/i)+minSteps(i));
            }
        }
        
        return minOps==1e9?n:minOps;
    }
};