vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;//二维数组
        queue<TreeNode*> nums;//循环队列
        nums.push(root);//将根节点加入队列
        if(root==NULL)//将root为空排除
            return res;
        while(!nums.empty()){//当队列不为空，进入循环
            vector<int> num;//num数组
            queue<TreeNode*> nextnodes;//保存下一层队列
            while(!nums.empty()){//当队列不为空，进入循环
                TreeNode* tre = nums.front() ;//将队列头赋值
                num.push_back(tre->val) ;//将其加入数组
                nums.pop() ;  
               if(tre->left) nextnodes.push(tre->left);//当左子树不为空则 递归左子树 
                if(tre->right)nextnodes.push(tre->right);//当右子树不为空则 递归右子树 
            }
            nums=nextnodes;
            res.push_back(num);
        }
        return res;
    }
