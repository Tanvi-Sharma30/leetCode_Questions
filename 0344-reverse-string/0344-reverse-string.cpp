class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int right=n-1;
        int left=0;
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};