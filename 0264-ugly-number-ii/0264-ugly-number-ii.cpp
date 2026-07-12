class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<int>st;
        pq.push(1);
        st.insert(1);
        long long top=1;
        for(int i=0;i<n;i++){
            top = pq.top();
            pq.pop();
            long long x1 = 2*top;
            long long x2 = 3*top;
            long long x3 = 5*top;
            
            if(st.find(x1)==st.end()){
                pq.push(x1);
                st.insert(x1);
            }
            if(st.find(x2)==st.end()){
                pq.push(x2);
                st.insert(x2);
            }
            if(st.find(x3)==st.end()){
                pq.push(x3);
                st.insert(x3);
            }
        
        }
        return (int)top;
    }
};