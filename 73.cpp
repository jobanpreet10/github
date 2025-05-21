class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>>q;
        for(int row=0; row < matrix.size();row++){
            for(int col = 0; col < matrix[0].size(); col++){
                if(matrix[row][col] == 0 ){
                q.push({row,col});
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for(int i = 0 ; i < matrix[0].size(); i++){
                matrix[row][i] = 0;
            }
            for(int i = 0 ; i < matrix.size(); i++){
                matrix[i][col] = 0;
            }
        }
    }
};
