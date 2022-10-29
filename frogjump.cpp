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
