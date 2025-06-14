class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string max_s = "";
        string min_s = "";

        char ele = ' ';
        for(char ch: s){
            if(ch != '9'){
                ele = ch;
                break;
            }
        }

        for(char ch : s){
            if(ch == ele) max_s += '9';
            else max_s += ch;
        }

        for(int i = 0; i < s.length(); i++){
            if(s[0] == s[i]) min_s += '0';
            else min_s += s[i];
        }

        return stoi(max_s) - stoi(min_s);


    }
};
