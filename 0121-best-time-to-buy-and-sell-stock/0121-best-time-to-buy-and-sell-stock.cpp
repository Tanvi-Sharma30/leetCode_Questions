class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int miniPrice=prices[0];
        int maxProfit = 0;
        for(int i=0;i<n;i++){
            int cost = prices[i]-miniPrice;
            maxProfit = max(maxProfit, cost);
            miniPrice = min(miniPrice,prices[i]);
        }
        return maxProfit;
    }
};