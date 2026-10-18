class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int ones=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ones+=1;
            else if(i+1==n || s[i+1]=='1'){
                ans+=ones;
            }
        }
        return ans;
    }
};