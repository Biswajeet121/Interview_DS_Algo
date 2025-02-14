
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/fixed-two-nodes-of-a-bst

class Solution {
  public:
  vector<pair<int , Node*>> ino;
  
  // Inorder traversal to store nodes in ino
  void func(Node* root){
      if(root == NULL) return;
      
      if(root->left){
          func(root->left);
      }
      ino.push_back({root->data , root});
      
      if(root->right){
          func(root->right);
      }
  }
  
  // Function to fix the swapped nodes in the BST
  void correctBST(Node* root) {
      func(root);
      
      vector<pair<int , Node*>> so;
      so = ino;
      sort(so.begin(), so.end());
      
      Node* no = NULL;
      for(int i = 0; i < ino.size(); i++){
          if(ino[i].first != so[i].first && no == NULL){
              no = ino[i].second;
          }
          else if(ino[i].first != so[i].first){
             swap(no->data , ino[i].second->data);
          }
      }
  }   
};
