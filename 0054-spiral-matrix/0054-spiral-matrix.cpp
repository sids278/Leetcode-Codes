class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int>result;
        int m=matrix.size();
    int n=matrix[0].size();        
   int top=0;
    int down=m-1;
    int left=0;
    int right=n-1;
    
    int direction=0;
    
    while(top<=down && left<=right){
        
        if(direction==0){
         
            for(int i=left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            
            top+=1;
             
        }
           else if(direction==1){
            
                  for(int i=top;i<=down;i++){
                result.push_back(matrix[i][right]);
            }
               right-=1;
        }
         else if(direction==2){
                for(int i=right;i>=left;i--){
                result.push_back(matrix[down][i]);
            }
            
             down-=1;
             
        }
        else if(direction==3){
               for(int i=down;i>=top;i--){
                result.push_back(matrix[i][left]);
            }
            
            left+=1;
        }
        
       direction=(direction+1)%4;
    }
    return result;
    }
};