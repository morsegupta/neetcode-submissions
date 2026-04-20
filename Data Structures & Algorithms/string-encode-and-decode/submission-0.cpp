class Solution {
public:

    string encode(vector<string>& strs) {
        string x = "";
        for(auto& momos: strs){
            x += to_string(momos.size()) + "#" + momos;
        }
        return x;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i<s.size()){
            int len = 0;
            while(s[i] != '#'){
                len = len*10 + (s[i]-'0');
                i++;
            }
            i++;
            res.push_back(s.substr(i, len));
            i+=len;
        }
        
        return res;
    }
};
