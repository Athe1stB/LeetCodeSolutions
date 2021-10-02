class Solution {
public:
    int numDistinct(string a, string b) {
        int n1=b.size();
        int n2=a.size();
        long long dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++)dp[i][j]=0;
        }
        for(int i=1;i<=n2;i++){
            if(b[0]==a[i-1])dp[1][i]=dp[1][i-1]+1;
            else dp[1][i]=dp[1][i-1];
        }
        for(int i=2;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(b[i-1]==a[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[n1][n2];
    }
};
