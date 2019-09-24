#include<iostream>
using namespace std;
template<class K,int M=3>
class BTreeNode{
	public:
		BTreeNode():_pParent(NULL),_size(0)
		{
			for(size_t i=0;i<=M;++i){
				_pSub[i]=NULL;
			}
		}
	pair<PNode,int> Find(const K& key){
		PNode pCur=_pRoot;
		PNode pParent=NULL;
		size_t=0;
		while(pCur){
			i=0;
			while(i<pCur->_size){
				if(key==pCur->_keys[i])
					return pair<PNode,int>(pCur,i);
				else if(key<pCur->_keys[i])
					break;
				else
					i++;
			}
			pParent=pCur;
			pCur=pCur->_pSub[i];
		}
		return pair<PNode,int>(pParent,-1);
	}
	void _InsertKey(PNode pCur,const k& key,PNode pSub){
		int end =pCur->size-1;
		while(end>=0){
			if(key<pCur->_keys[end]){
				pCur->_keys[end+1]=pCur->_keys[end];
				pCur->_pSub[end+2]=pCur->_pSub[end+1];
				end--;
			}
			else break;
		}
		pCur->_pSub[end+2]=pSub;
		if(pSub){
			pSub->_pParent=pCur;
			pCur->_size++;
		}
	}
	void Insert(const K& key){
		//跟节点为空 
		if(NULL==_pRoot){
			_pRoot=new Node();
			_pRoot->_keys[0]=key;
			_pRoot->_size=1;
			return true;
		}
		//查找指定key值的节点 
		pair<PNode,int>ret=Find(key);
		if(-1!=ret.second)
		return false;
		K k=key;
		PNode temp=NULL;
		PNode pCur=ret.first;
		while(true){
			_InsertKey(pCur,k,temp);
			//当前节点未达到分裂 
			if(pCur->size<M){
				return true;
			}
			temp=new Node;
			int mid=(M>>1);
			for(size_t i=mid+1;i<pCur->_size;++i){
				temp->_keys[temp->size]=pCur->_keys[i];
				temp->_pSub[temp->_size++]=pCur->_pSub[i];
				if(pCur->_pSub[i]){
					pCur->_pSub[i]->_pParent=temp;
				}
				
			}
			temp->_pSub[temp->_size]=pCur->_pSub[pCur->_size];
			if(pCur->_pSub[pCur->_size]){
				pCur->_pSub[pCur->_size]->_pParent=temp;
			}
			pCur->_size-=(temp->_size+1);
			if(pCur==_pRoot){
				_pRoot=new Node;
				_pRoot->_keys[0]=pCur->_keys[mid];
				_pRoot->_pSub[0]=pCur;
				_pRoot->_pSub[1]=temp;
				_pRoot->_size=1;
				pCur->_pParent=temp->_pParent=_pRoot;
				return true;
			}
			else{
				k=pCur->_keys[mid];
				pCur=pCur->_pParent;
			}
		}
		return true;
		
	}
		
	private:
		k _keys[M];
		BTreeNode<K,M>* _pSub[M+1];
		BTreeNode<K,M>* _pParent;
		size_t _size;
}; 
