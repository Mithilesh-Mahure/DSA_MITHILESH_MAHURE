class Solution {
    int t[47];
public:
    int climbStairs(int n) {
        t[n];
        if(n==1||n==0){
            return 1;
        }
        t[0]=1;
        t[1]=1;
        for(int i=2;i<=n;i++){
            t[i]=t[i-1]+t[i-2];
        }
        return t[n];
    }
};