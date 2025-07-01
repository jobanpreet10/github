class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        int possibility = 0;
        for(int i = 1; i < word.length(); i++){
            if(word[i-1] == word[i]){
                possibility++;
            }
        }
        return res+possibility;

    }
};
