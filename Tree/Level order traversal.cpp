
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/level-order-traversal

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<int> arr;
            while(n--){
                Node* front = q.front();
                q.pop();
                arr.push_back(front -> data);
                if(front -> left)   q.push(front -> left);
                if(front -> right)  q.push(front -> right);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};
