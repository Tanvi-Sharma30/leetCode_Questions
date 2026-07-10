class Solution {
public:
    vector<int>nextSmallestElement(vector<int>& arr){
        int n = arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();

        if(st.empty()) nse[i]=n;
        else nse[i] = st.top();

        st.push(i);
        }
        return nse;
    }

    vector<int>previousSmallestElement(vector<int>& arr){
        int n = arr.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]) st.pop();

            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();

            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total =0;
        int mod = 1e9+7;
        vector<int>pse = previousSmallestElement(arr);
            vector<int> nse = nextSmallestElement(arr);
        for(int i=0;i<n;i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            total=(total+(right*left*1LL*arr[i]))%mod;
        }
        return total;
    }
};