class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            if(freq.find(nums[i])!=freq.end() && freq[nums[i]]>=n/2) return nums[i]; 
            else freq[nums[i]]++;
        }
        return 0;
    }
};