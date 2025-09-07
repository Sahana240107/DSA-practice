/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        res.push_back(root->data);
        vector<int> left=preorder(root->left);
        res.insert(res.end(),left.begin(),left.end());
        vector<int> right=preorder(root->right);
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
};