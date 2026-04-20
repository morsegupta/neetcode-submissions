class Solution {
public:
    bool checkValidString(string s) {
        int maxopen = 0;
        int minopen = 0;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                maxopen++;
                minopen++;
            }
            else if(s[i] == ')'){
                maxopen--;
                minopen--;
            }
            else{
                maxopen++;
                minopen--;
            }
            if(maxopen<0) return false;
            if(minopen<0) minopen = 0;
        }
        return minopen == 0;
    }
};
