
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/serialize-and-deserialize-a-binary-tree

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    void solve1(Node* root, vector<int>& arr){
        if(root == NULL){
            arr.push_back(-1);
            return ;
        }
        arr.push_back(root -> data);
        solve1(root -> left, arr);
        solve1(root -> right, arr);
    }
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> arr;
        solve1(root, arr);
        return arr;
    }
    // Function to deserialize a list and construct the tree.
    int idx = 0;
    Node* solve2(vector<int>& arr){
        if(arr[idx] == -1){
            idx++;
            return NULL;
        }
        Node* newNode = new Node(arr[idx]);
        idx++;
        newNode -> left = solve2(arr);
        newNode -> right = solve2(arr);\
        return newNode;
    }
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        return solve2(arr);
    }
};
