vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;//��ά����
        queue<TreeNode*> nums;//ѭ������
        nums.push(root);//�����ڵ�������
        if(root==NULL)//��rootΪ���ų�
            return res;
        while(!nums.empty()){//�����в�Ϊ�գ�����ѭ��
            vector<int> num;//num����
            queue<TreeNode*> nextnodes;//������һ�����
            while(!nums.empty()){//�����в�Ϊ�գ�����ѭ��
                TreeNode* tre = nums.front() ;//������ͷ��ֵ
                num.push_back(tre->val) ;//�����������
                nums.pop() ;  
               if(tre->left) nextnodes.push(tre->left);//����������Ϊ���� �ݹ������� 
                if(tre->right)nextnodes.push(tre->right);//����������Ϊ���� �ݹ������� 
            }
            nums=nextnodes;
            res.push_back(num);
        }
        return res;
    }
