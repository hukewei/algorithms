class BinarySearchTree {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root ==nullptr){
            return new TreeNode(val);
        }
        if(val<root->val){
            if(root->left == nullptr){
                root->left = new TreeNode(val);
            } else {
                insertIntoBST(root->left, val);
            }
        } else {
            if(root->right == nullptr){
                root->right = new TreeNode(val);
            } else {
                insertIntoBST(root->right, val);
            }
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        //case 0: root doesn't exist
        if(root == nullptr){
            return root;
        }
        
        if(key< root->val){
            root->left = deleteNode(root->left, key);
        } else if (key> root->val){
            root->right = deleteNode(root->right, key);
        } else {
            //current node to be deleted
            //case 1: No child
            if(root->left == nullptr && root->right == nullptr){
                return nullptr;
            }
            
            //case 2: 1 Child
            if(root->left == nullptr) {
                return root->right;
            }
            if(root->right == nullptr) {
                return root->left;
            }
            
            //case 3: 2 childs
            TreeNode* successor = root->right;
            while(successor->left !=nullptr){
                successor = successor->left;
            }
            root->val = successor->val;
            root->right = deleteNode(root->right, root->val );
        }
        return root;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = root;
        while(true){
            if(res == nullptr || res->val == val){
                break;
            }
            if(val < res->val){
                res = res->left;
            } else {
                res = res->right;
            }
        }
        return res;
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
private:
    bool isValidBST(TreeNode* node, TreeNode* min,TreeNode* max){
        if(node == nullptr){
            return true;
        }
        if( (min!=nullptr && node->val <=min->val) || (max!=nullptr && node->val >=max->val) ){
            return false;
        }
       
        return isValidBST(node->left, min, node) && isValidBST( node->right, node, max);
    }
};