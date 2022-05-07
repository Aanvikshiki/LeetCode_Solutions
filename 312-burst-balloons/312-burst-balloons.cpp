class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> A(n+2);
        A[0]=A[n+1]=1;
        for(int i=1;i<=n;i++)
            A[i] = nums[i-1];
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=1;i<=n;i++){
           for(int j = 1; j<=n-i+1;j++){
               int r = j+i-1;
               for(int k = j; k<= r;k++){
                   dp[j][r] = max(dp[j][r],A[j-1]*A[k]*A[r+1]+dp[j][k-1]+dp[k+1][r]);
               }
           } 
        }
        return dp[1][n];
    }
};