class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        if(n==1) return 0;
        for(int it: nums){
            if(st.find(it)!=st.end()) return it;
            st.insert(it);
        }
        return 0;
    }
};