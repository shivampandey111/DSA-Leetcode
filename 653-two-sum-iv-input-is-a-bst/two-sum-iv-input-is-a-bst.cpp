class Solution {
public:
    // vector<int> temp;
    // void func(TreeNode* root){
    //     if(root==NULL) return;
    //     if(root->left!=NULL){
    //         func(root->left);
    //     }
    //     temp.push_back(root->val);
    //     if(root->right!=NULL){
    //         func(root->right);
    //     }
    // }
    stack<TreeNode*> asc; 
    stack<TreeNode*> desc;
    TreeNode* getSmall(){
        if(asc.empty()) return NULL;
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* rC = small->right;
        while(rC){
            asc.push(rC);
            rC = rC->left;
        }
        return small;
    }
    TreeNode* getBig(){
        if(desc.empty()) return NULL;
        TreeNode* big = desc.top();
        desc.pop();
        TreeNode* lc = big->left;
        while(lc){
            desc.push(lc);
            lc = lc->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        TreeNode* t = root;
        while(t){
            asc.push(t);
            t = t->left;
        }
        t = root;
        while(t){
            desc.push(t);
            t = t->right;
        }
        TreeNode* i = getSmall();
        TreeNode* j = getBig();
        while(i && j && i!=j && i->val<=j->val){
            int sum = i->val + j->val;
            if(sum==k) return true;
            if(sum>k){
                j = getBig();
            }
            else{
                i = getSmall();
            }
        }
        return false;
        // if(root==NULL) return false;
        // func(root);
        // int i = 0;
        // int j = temp.size()-1;
        // while(i<j){
        //     int sum = temp[i] + temp[j];
        //     if(sum==k) return true;
        //     if(sum<k) i++;
        //     if(sum>k) j--;
        // }
        // return false;
    }
};