class Solution {
public:
    vector<int>previousSmallestElement(vector<int>& nums,int n){
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<nums[st.top()]) st.pop();
                if(st.empty()) pse[i]=-1;
                else pse[i] = st.top();
                st.push(i);
        }
        return pse;
    }
    vector<int>nextSmallestElement(vector<int>& nums,int n){
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<=nums[st.top()]) st.pop();
            if(st.empty()) nse[i]=n;
            else nse[i] = st.top();

            st.push(i);
        }
        return nse;
    }
    vector<int>previousLargestElement(vector<int>& nums,int n){
        vector<int>ple(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]>nums[st.top()]) st.pop();
                if(st.empty()) ple[i]=-1;
                else ple[i] = st.top();
                st.push(i);
        }
        return ple;
    }
    vector<int>nextLargestElement(vector<int>& nums,int n){
        vector<int>nle(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>=nums[st.top()]) st.pop();
            if(st.empty()) nle[i]=n;
            else nle[i] = st.top();

            st.push(i);
        }
        return nle;
    }

    long long sumOfSubarrayMaxi(vector<int>& nums){
        int n = nums.size();
        vector<int> ple = previousLargestElement(nums,n);
        vector<int> nle = nextLargestElement(nums,n);
        long long total = 0;
        for(int i=0;i<n;i++){
            long long left = i-ple[i];
            long long right = nle[i]-i;
            total+= right*left*nums[i]*1LL;
        }
        return total;
    }
    long long sumOfSubarrayMini(vector<int>& nums){
        int n = nums.size();
        vector<int> pse = previousSmallestElement(nums,n);
        vector<int> nse = nextSmallestElement(nums,n);
        long long total=0;
        for(int i=0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i]-i;

            total += right*left*nums[i]*1LL;
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumOfSubarrayMaxi(nums) - sumOfSubarrayMini(nums);
    }
};