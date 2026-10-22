class Solution {
public:
    vector<int> suffix(vector<int>& prices){
        int n = prices.size();
        vector<int>suf(n);
        suf[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],prices[i]);
        }
        return suf;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans=0;
        vector<int>suf = suffix(prices);
        for(int i=0;i<n;i++){
            int temp = abs(suf[i]-prices[i]);
            ans =max(ans,temp);
        }
        return ans;
    }
};