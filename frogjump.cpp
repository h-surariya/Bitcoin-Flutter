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
