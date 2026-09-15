class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        long long maxi = LLONG_MIN;
        long long secMaxi = LLONG_MIN;
        long long thiMaxi = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            if(nums[i]==maxi || nums[i]==secMaxi || nums[i]==thiMaxi) continue;
            if (nums[i] > maxi) {
                thiMaxi = secMaxi;
                secMaxi = maxi;
                maxi = nums[i];
            }
            else if (nums[i] > secMaxi){
                thiMaxi = secMaxi;
                secMaxi = nums[i];}
            else if (nums[i] > thiMaxi){
                thiMaxi = nums[i];}
        }
        if (thiMaxi == LLONG_MIN)
            return maxi;

        return thiMaxi;
    }
};