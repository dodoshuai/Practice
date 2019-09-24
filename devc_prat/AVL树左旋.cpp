void RotateL(Node* parent)
{
	Node* subR=parent->right;
	NOde* subRL=subR->left;
	parent->right=subRL;
	if(subR->left!=NULL)
	subRL->_parent=parent;
	subR->left=_parent;	
	Node * ppNode=parent->_parent;
	parent->parent=subR;
	if(parent==root)
	{
		_root=subR;
		_root->_parent=nullptr;
	}else{
		if(ppNode->left=parent){
			ppNode->_left=suR
		}else{
			ppNode->_right=subR;
		}
		subR->_parent=ppNode;
	}
	


} 
