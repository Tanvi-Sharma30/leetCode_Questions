class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if(n!=goal.length()) return false;
        for(int i=0;i<n;i++){
            string ans = s.substr(i) + s.substr(0,i);
            if(ans==goal) return true;
        }
        return false;
    }
};