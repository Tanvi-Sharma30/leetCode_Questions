class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        for(char x :s){
            mp[x]++;
        }
        for(int i=0;i<n;i++){
            char cur = s[i];
            if(mp.find(cur)!=mp.end() && mp[cur]==1) return i;
        }
        return -1;
    }
};