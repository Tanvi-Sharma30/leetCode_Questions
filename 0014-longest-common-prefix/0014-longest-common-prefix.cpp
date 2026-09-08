class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre= strs[0];
        if(pre.empty()) return"";
        for(int i=1;i<strs.size();i++){
            string word =strs[i];
            int k=0;
            while(k<word.size() && k<pre.size() && pre[k]==word[k]){
                k++;
            }
            pre = pre.substr(0,k);
        }
        return pre;
    }
};