class Solution {
public:
    int maxDepth(string s) {
        int maxi= 0;
        int depth=0;
        for(char ch : s){
            if(ch=='('){
                depth++;
            } else {
                if(ch==')') depth--;
            };

            maxi=max(maxi,depth);
        }
        return maxi;
    }
};