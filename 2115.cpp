class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();

        unordered_set<string>st(begin(supplies),end(supplies));
        vector<string>result;
        vector<bool>cooked(n,false);

        int cnt = n;
        while(cnt--){

            for(int i = 0; i < n; i++){
                if(cooked[i]){
                    continue;
                }
                bool banPaega = true;
                for(int j = 0; j < ingredients[i].size(); j++){
                    if(!st.count(ingredients[i][j])){
                        banPaega = false;
                        break;
                    }
                }
                if(banPaega){
                    st.insert(recipes[i]);
                    result.push_back(recipes[i]);
                    cooked[i] = true;
                }
            }
        }
        return result;

    }
};
