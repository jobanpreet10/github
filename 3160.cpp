class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>ballToColor;
        unordered_map<int,int>Color;
        vector<int>ans;
        for(auto query : queries){
            int ball = query[0];
            int color = query[1];

            if(ballToColor.find(ball) != ballToColor.end()){
                int oldColor =  ballToColor[ball];
                Color[oldColor]--;

                if(Color[oldColor] == 0){
                    Color.erase(oldColor);
                }
            }
            ballToColor[ball] = color;
            Color[color]++;
            ans.push_back(Color.size());
        }
        
        return ans;
    }
};
