#include<iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*ListNode* swapPairs(ListNode* head) {
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
    */
    //迭代法
	//1-->3  2-->1 0-->2 last=0--->2  cur=1--->3  next=2--->4 
    ListNode* swapPairs(ListNode* head) {
    	ListNode pre;
    	ListNode *last;
    	last=&pre;
    	last->next=head;
    	ListNode* cur=head;
    	while(cur){
    		if(cur->next==NULL){
    			break;
    		}
    		ListNode *next=cur->next;
    		
			cur->next=next->next;
			next->next=cur;
			last->next=next;
			last=last->next->next;
			cur=cur->next; 
    	}
    	return pre.next;
    }
    
    ListNode* swapPairs(ListNode* head) {
    	//排除传值为空，防止pre的NULL解引用
        if(head==NULL)
    	return NULL;
    	ListNode *ret=head;
    	ListNode *pre=head->next;
    	ListNode *cur=head;
    	//排除不能交换的，第一个有值，第二个为空的情况下
    	if(pre==NULL){
    		return head;
    	}
    	//1-->2-->3
    	ret=pre->next;//ret====3
    	cur->next=ret;//cur====1
    	pre->next=cur;//pre====2
        //2-->1-->3
    	cur->next=swapPairs(ret);
        //2-->1--->(NULL||3||4)
    	return pre;
    	
    }
    
