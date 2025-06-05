class Solution {
public:
    vector<int>parent;
     
    int find(int a){
        if(parent[a] != a){
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    void union_set(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa ==  pb) return;

        if(pa > pb){
            parent[pa] =  pb;
        }
        else{
            parent[pb] = pa;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);

        for(int i = 0;i < 26; i++) parent[i] = i;

        for(int i = 0;i < s1.length(); i++){
            union_set(s1[i]-'a',s2[i] - 'a' );
        } 
        string result = "";
        for (char ch : baseStr) {
            result += (char)(find(ch - 'a') + 'a');
        }

        return result;

    }
};
