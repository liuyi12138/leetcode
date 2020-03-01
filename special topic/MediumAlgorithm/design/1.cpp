//自己写的是序列化用队列，反序列化用栈，坑太多了，不想写了
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
 
    // Encodes a tree to a single string. 层次遍历
    string serialize(TreeNode* root) {
        string ans;
        if (root == NULL)
            return "[]";
        ans = "[";
        queue<TreeNode*> que;
        que.push(root);
 
        char str[100];
 
        while (!que.empty())
        {
            TreeNode* top = que.front();
            que.pop();
 
            if (top != NULL)
            {
                que.push(top->left);
                que.push(top->right);
 
                sprintf(str, "%d", top->val);
                ans += str;
            }
            else{
                ans += "null";
            }
 
            ans += ",";
        }
 
        int end = ans.length() - 1;
        while ( !( ans[end] >= '0' && ans[end] <= '9') )
            end--;
 
        string rs = ans.substr(0, end + 1);
        rs += "]";
 
        return rs;
    }
 
    // Decodes your encoded data to tree. // 解析一个层次遍历
    TreeNode* deserialize(string data) {
 
        int len = data.size();
 
        if (len <= 2)
            return NULL;
 
        int numsCount = 0;
        vector<TreeNode*> nums;
 
        string word = "";
        for (int i = 1; i <= len - 2; i++){
            if (data[i] == ',')
            {
                TreeNode* tmp = NULL;
                if (word == "null")
                {
 
                }
                else{
                    int num = atoi(word.c_str());
                    tmp = new TreeNode(num);
                }
                nums.push_back(tmp);
                word = "";
            } else{
                //if (data[i] >= '0' && data[i] <= '9')
                    word += data[i];
            }
        }
        if (word != "" && word != "null")
        {
            int num = atoi(word.c_str());
            TreeNode* tmp = new TreeNode(num);
            nums.push_back(tmp);
        }
 
        int cnt = nums.size();
 
        int q = 0; // 遍历的节点,每个节点一个一个遍历（包括了NULL 节点）
        int p = 1; // 当前遍历结点 的 左孩子节点， p+1就是右孩子节点
        while (p < cnt)
        {
            if (nums[q] == NULL){
                q++;
            }
            else{
                if (p < cnt)
                    nums[q]->left = nums[p];
                if (p + 1 < cnt)
                    nums[q]->right = nums[p + 1];
                p += 2;
                q++;
            }
        }
 
        return nums[0];
    }
};
 
 
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));