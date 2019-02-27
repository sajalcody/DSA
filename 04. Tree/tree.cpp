pair<int,bool> height(TreeNode* r){
        if(!r)return make_pair(0,true);
        if(!r->left && !r->right) return make_pair(1,true);
        pair<int,bool> a =height(r->left),b=height(r->right);
        return make_pair(1+max(a.first,b.first),a.second&&b.second&&(abs(a.first-b.first)<2));
    }

int Solution::isBalanced(TreeNode* A) {
    return height(A).second;
}
