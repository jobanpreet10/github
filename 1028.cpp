/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int n;
    TreeNode* solve(string traversal , int &i , int depth){
        if(i >= n){
            return NULL;
        }
        int j = i;
        while (j < n && traversal[j] == '-') {
            j++;
        }
        
        int dash = j - i;
        if(dash != depth){
            return NULL;
        }
        
        i += dash;
        int num = 0;

        while( i < n && isdigit(traversal[i])){
            num = num* 10 +(traversal[i] - '0');
            i++;
        }

        TreeNode* node = new TreeNode(num);

        node->left = solve(traversal ,i , depth +1);
        node->right = solve(traversal ,i , depth +1);

        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n =  traversal.length();
        int i = 0;
        int depth = 0;

        return solve(traversal, i , depth);
    }
};
