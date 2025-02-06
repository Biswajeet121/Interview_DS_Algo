
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/construct-tree-1
    
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &idx, int preS,
        int preE, int size, unordered_map<int, int>& mp){
        
        if(idx >= size || preS > preE)
            return NULL;
        
        int val = preorder[idx++];
        Node* root = new Node(val);
        int pos = mp[val];
        
        root -> left = solve(inorder, preorder, idx, preS, pos-1, size, mp);
        root -> right = solve(inorder, preorder, idx, pos+1, preE, size, mp);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = inorder.size(), preIdx = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return solve(inorder, preorder, preIdx, 0, n-1, n, mp);
    }
};
