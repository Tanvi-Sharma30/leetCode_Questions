class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int n= s.length();
        unordered_map<char,int>mp;
        for(char c: s){
            mp[c]++;
        }
        unordered_map<int,string>grp;
        for(auto it:mp){
            char ch = it.first;
            int freq = it.second;
            grp[freq]+=ch;
        }
        string ans="";
        int maxSize=0;
        int bestFreq=0;
        for(auto it:grp){
            int freq = it.first;
            string ch = it.second;
            if(ch.size()>maxSize || (ch.size()==maxSize && freq>bestFreq)) {
                ans = ch;
                maxSize = ch.size();
                bestFreq=freq;
            }
        }
        return ans;
    }
};