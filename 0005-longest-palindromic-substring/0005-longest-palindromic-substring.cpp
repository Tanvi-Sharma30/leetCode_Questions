class Solution {
public:
    int isPalindrom(int left, int right, string s){
        while(left>=0 && right<s.size() && s[left]==s[right]){
                left--;
                right++;
            }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(s.empty()) return "";
        int start = 0; int end=0;
        for(int i=0;i<n;i++){
            int odd = isPalindrom(i,i,s);
            int even = isPalindrom(i,i+1,s);
            int len = max(odd,even);

            if(len > end-start+1){
            start = i-(len-1)/2;
            end = i+len/2;
            } 
        }
        
        return s.substr(start,end-start+1);
    }
};