#include<stdio.h>
ListNode* swapPairs(ListNode* head) {
        ListNode aa;
        ListNode bb;
        ListNode *aa1=&aa;
        ListNode *bb1=&bb;
        ListNode *cur=head; 
        while(cur){
        	aa1->next=cur;
        	aa1=aa1->next;
        	bb1->next=cur->next;
        	bb1=bb1->next;
        	if(bb1&&bb1->next){
        		cur=bb1->next;
        	}
        }
        
        
        
        
    } 
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode aa;
        ListNode bb;
        ListNode *aa1=&aa;
        ListNode *bb1=&bb;
        ListNode *cur=head; 
        while(cur){
        	
        	ListNode* start=cur;
        	int x=k-1;
        	while(x){
        		if(cur==NULL)
        		break;
        		cur=cur->next;
        		x--;
        	}
        	if(x==0){
        	
        	bb1=cur->next;
        	//逆转
        	stack<ListNode *> list_nz;
        	while(start!=bb1){
        		list_nz.push(start);
        		start=start->next;
        	}
        	while(!list_nz.empty()){
        		ListNode *qq=list_nz.top();
        		list_nz.pop();
        		aa1->next=qq;
        		aa1=aa1->next;
        	}
        	aa1->next=bb1;
			
		
			cur=cur->next; 
			}
        }
        return aa.next;
    } 
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode aa(0);
    //    ListNode bb(0);
    	//aa1始终代表当前k个序列的上一个节点，用于连接逆置节点。 
        ListNode *aa1=&aa;
        ListNode *bb1=NULL;
        ListNode *cur=head; 
        while(cur){
        	//存k个节点的开始 
        	ListNode* start=cur;
        	//判断节点是否满足k个 
        	int x=k;
        	while(x){
        		if(cur==NULL)
        		break;
        		cur=cur->next;
        		x--;
        	}
        	//x==0表示剩余的节点大于等于k 
        	if(x==0){     	
        		//bb1存储第k+1个节点（有值或为NULL） 
        		bb1=cur;
        		//逆转
        		/*
        		使用栈，先入栈，出栈的顺序即为逆置顺序 
				*/ 
        		stack<ListNode *> list_nz;
        		//入栈 
        		while(start!=bb1){
        			list_nz.push(start);
        			start=start->next;
        		}
        		//出栈 
        		while(!list_nz.empty()){
        			ListNode *qq=list_nz.top();
            	    list_nz.pop();
        			aa1->next=qq;
        			aa1=aa1->next;
        		}
        		aa1->next=bb1;		
			}else{
				//当剩余节点小于k时，不进行逆置 
                aa1->next=start;
            }
        }
        return aa.next;
    } 
