//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1,string s2, int n, int m)
    {
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(s1[i]==s2[j]) {
                    if(i==0||j==0) {
                        dp[i][j]=1;
                    }else {
                        dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans=max(dp[i][j],ans);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends