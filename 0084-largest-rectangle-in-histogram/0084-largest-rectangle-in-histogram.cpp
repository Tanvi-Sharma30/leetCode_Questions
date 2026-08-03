class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int area = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                int top = st.top();
                st.pop();

                int height = heights[top];
                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                area = max(area, height * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();

            int height = heights[top];
            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            area = max(area, height * (nse - pse - 1));
        }
        return area;
    }
};