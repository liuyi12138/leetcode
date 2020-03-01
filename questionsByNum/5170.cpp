class Solution {
public:
    bool validateBinaryTreeNode(vector<int>& leftChild, vector<int>& rightChild, vector<bool>& used, int depth){
        if(depth >= leftChild.size())
            return true;
        if(depth == -1)
            return true;
        if(leftChild[depth] == -1 && rightChild[depth] == -1)
            return true;
        else if(leftChild[depth] == -1){
            if(used[rightChild[depth]])
                return false;
        }
        else if(rightChild[depth] == -1){
            if(used[leftChild[depth]])
                return false;
        }
        else if(used[leftChild[depth]] || used[rightChild[depth]])
            return false;
        if(leftChild[depth] != -1){
            used[leftChild[depth]] = true;
        }
        if(rightChild[depth] != -1){
            used[rightChild[depth]] = true;
        }
        return validateBinaryTreeNode(leftChild,rightChild,used,leftChild[depth]) & validateBinaryTreeNode(leftChild,rightChild,used,rightChild[depth]);
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> used(n,false);
        used[0] = true;
        if(leftChild[0] != -1){
            used[leftChild[0]] = true;
        }
        if(rightChild[0] != -1){
            used[rightChild[0]] = true;
        }
        if(validateBinaryTreeNode(leftChild,rightChild,used,leftChild[0]) & validateBinaryTreeNode(leftChild,rightChild,used,rightChild[0])){
            for(int i = 0; i < n; ++i){
                if(used[i] == false){
                    return false;
                }   
            }
            return true;
        }
        return false;
    }
};



class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(leftChild[i] == -1)
                count++;
            if(rightChild[i] == -1)
                count++;          
        }
        return (count == (n+1));
    }
};