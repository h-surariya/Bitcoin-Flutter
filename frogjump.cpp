class Solution {
public:
    bool helper(set<int>& st, map<pair<int, int>, int>& vis, int n, int k, int t){
        if(vis.find({n, k})!=vis.end())return false; 
        vis[{n, k}] = 1; 
        if(n==t)return true; 
        if(st.find(n+k)==st.end())return false; 
        else{
            cout<< n<<endl;
            bool l = helper(st, vis, n+k, k-1, t); 
            bool m = helper(st, vis, n+k, k, t); 
            bool r = helper(st, vis, n+k, k+1, t); 
            if(l||r||m)return true; 
        }
        return false; 
    }
    bool canCross(vector<int>& stones) {
        set<int>st(stones.begin(), stones.end()); 
        map<pair<int, int>, int> vis; 
        return helper(st, vis, 0, 1, stones[stones.size()-1]);  
    }
};

// buy sell stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = INT_MAX; 
        int ans =0; 
        for(int i = 0; i< prices.size(); i++){
            ans = max(ans, prices[i]-l); 
            l = min(l, prices[i]); 
        }
        return ans; 
    }
};

// buy sell stock 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        int m = 10000; 
        int ans = 0; 
        for(int i =0; i< n; i++){
            if(prices[i]>m){
                ans = ans + prices[i]-m; 
                m = prices[i]; 
            }
            else{
                m = prices[i]; 
            }
        }
        return ans; 
    }
};

//  buy sell stock 3
class Solution {
public:
    int helper(int n, int buy, int k, vector<int> &prices, vector<vector<vector<int>>>& dp){
        if(n==prices.size())return 0; 
        if(k==0)return 0; 
        if(dp[n][k][buy]!=-1)return dp[n][k][buy]; 
        if(buy){
            return dp[n][k][buy] = max(-prices[n]+helper(n+1, 0, k, prices, dp), helper(n+1, 1, k, prices, dp)); 
        }
        else{
            return dp[n][k][buy] = max(prices[n]+helper(n+1, 1, k-1, prices, dp), helper(n+1, 0, k, prices, dp)); 
        }
    }
    int maxProfit(vector<int>& prices) {
        int m = prices.size(); 
        vector<vector<int>> next(3, vector<int>(2, 0)); 
        vector<vector<int>> curr(3, vector<int>(2, 0)); 
        for(int i = m-1; i>=0; i--){
            for(int k = 2; k>=1; k--){
                for(int buy = 0; buy<2; buy++){
                    if(buy){
                       curr[k][buy] = max(-prices[i]+next[k][0], next[k][1]) ; 
                    }
                    else{
                        curr[k][buy] = max(prices[i]+next[k-1][1], next[k][0]); 
                    }
                }
            }
            next = curr; 
        }
        return next[2][1];
    }
};

// longest palindromic subsequence
    bool helper(string ans){
        int i = 0; 
        int j = ans.size()-1; 
        while(i<j){
            if(ans[i]!=ans[j])return false; 
            i++; j--; 
        }
        return true; 
    }
    string longestPalindrome(string s) {
        string t = s; 
        reverse(t.begin(), t.end()); 
        cout<<s<<endl; 
        cout<<t<<endl; 
        int n = s.size(); 
        vector<vector<int>> dp(n+1, vector<int>(n+1)); 
        for(int i = 0; i<= n;i++){
            for(int j = 0; j<= n; j++){
                if(i==0||j==0){
                    dp[i][j] = 0; 
                }
                else if(s[i-1]==t[j-1])dp[i][j] = dp[i-1][j-1]+1; 
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
 
            }
           
        }
        
        string ans; 
        string ans2; 
        int i = n, j = n; 
        while(i>0&&j>0){
            if(dp[i][j]==0)break; 
            if(dp[i-1][j-1]+1==dp[i][j]){
                ans.push_back(s[j-1]);
                ans2.push_back(t[j-1]); 
                i--; j--; 
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--; 
            }
            else{
                j--; 
            }
        }
        if(helper(ans))return ans; 
        return ans2; 
    }
// Reverse Integer
    int reverse(int a) {
        long long  ans = 0;
        long long x =  a; 
        bool y = true; 
        if(x<0) y = false, x = -1*x; 
        while (x) {
            long long temp = ans * 10 + x % 10;
            if(temp>INT_MAX)return 0; 
            ans = temp;
            x /= 10;
        }
        if(y)
        return ans;
        else return -1*ans; 
    }
