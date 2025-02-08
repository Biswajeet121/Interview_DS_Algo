
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/boundary-traversal-of-binary-tree

class Solution {
  public:
    void solveLeft(Node* root, vector<int>& ans){
        if(root == NULL || root -> left == NULL && root -> right == NULL){
            return ;
        }
        ans.push_back(root -> data);
        if(root -> left == NULL){
            solveLeft(root -> right, ans);
        }
        solveLeft(root -> left, ans);
    }
    
    void solveLeaf(Node* root, vector<int>& ans){
        if(root == NULL)    return;
        if(root -> left == NULL && root -> right == NULL)
            ans.push_back(root -> data);
        solveLeaf(root -> left, ans);
        solveLeaf(root -> right, ans);
    }
    
    void solveRight(Node* root, vector<int>& ans){
        if(root == NULL || root -> left == NULL && root -> right == NULL){
            return ;
        }
        if(root -> right == NULL){
            solveRight(root -> left, ans);
        }
        solveRight(root -> right, ans);
        ans.push_back(root -> data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        ans.push_back(root -> data);
        if(root -> left == NULL && root -> right == NULL)
            return ans;
        //left
        solveLeft(root -> left, ans);
        //leaf
        solveLeaf(root, ans);
        //right
        solveRight(root -> right, ans);
        return ans;
    }
};
