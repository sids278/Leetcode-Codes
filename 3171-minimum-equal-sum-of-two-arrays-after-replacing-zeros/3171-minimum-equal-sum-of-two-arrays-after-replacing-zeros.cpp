class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
       long sum1=0;
       int one1=0;
       int one2=0;
       long sum2=0;
       for(auto x:nums1){
        sum1+=x;
        if(x==0)one1++;
        }
       for(auto x:nums2){
        sum2+=x;
        if(x==0)one2++;
       }
       
       if(sum2>sum1){
        if(one1==0 && one2!=0)return -1;
        if(one2>one1)return sum2+one2;
       }
       if(sum1>=sum2){
        if(one2==0 && one1!=0)return -1;
        if(one1>one2)return sum1+one1;
       }
       cout<<sum1<<" "<<one1<<endl;
       cout<<sum2<<" "<<one2<<endl;
       long maxS= max(sum1+one1,sum2+one2);
       if(one1==0){
        if(maxS>sum1)return -1;
        
       }
       if(one2==0){
        if(maxS>sum2)return -1;
        
       }
       cout<<"diff 1 "<<(maxS-sum1)<<" "<<one1<<endl;
       cout<<"diff 2 "<<(maxS-sum2)<<" "<<one2<<endl;

       if(maxS-sum1>=one1 && maxS-sum2>=one2){
          return maxS;
       }
    //    long minS=max(sum1+one1,sum2+one2);
    //    int x=(sum1-sum2)/(one2-one1);
    //    if(x<0||x==0)return -1;
    //    long maxS=sum1+x*one1;
    //    long l=minS;
    //    long r=maxS;
    //    long mid;
    //    long ans=INT_MAX;
       
    //    while(l<=r){
    //     mid=(l+r)/2;
    //     if(mid>sum1 && (mid-sum1)/one1>0 && mid>sum2 && (mid-sum2)/one2>0){
    //        ans=mid;
    //        r=mid-1;
    //     }
    //     else{
    //         l=mid+1;
    //     }
    //    }
     return -1;

    }
};