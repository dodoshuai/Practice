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
        	//��ת
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
    	//aa1ʼ�մ���ǰk�����е���һ���ڵ㣬�����������ýڵ㡣 
        ListNode *aa1=&aa;
        ListNode *bb1=NULL;
        ListNode *cur=head; 
        while(cur){
        	//��k���ڵ�Ŀ�ʼ 
        	ListNode* start=cur;
        	//�жϽڵ��Ƿ�����k�� 
        	int x=k;
        	while(x){
        		if(cur==NULL)
        		break;
        		cur=cur->next;
        		x--;
        	}
        	//x==0��ʾʣ��Ľڵ���ڵ���k 
        	if(x==0){     	
        		//bb1�洢��k+1���ڵ㣨��ֵ��ΪNULL�� 
        		bb1=cur;
        		//��ת
        		/*
        		ʹ��ջ������ջ����ջ��˳��Ϊ����˳�� 
				*/ 
        		stack<ListNode *> list_nz;
        		//��ջ 
        		while(start!=bb1){
        			list_nz.push(start);
        			start=start->next;
        		}
        		//��ջ 
        		while(!list_nz.empty()){
        			ListNode *qq=list_nz.top();
            	    list_nz.pop();
        			aa1->next=qq;
        			aa1=aa1->next;
        		}
        		aa1->next=bb1;		
			}else{
				//��ʣ��ڵ�С��kʱ������������ 
                aa1->next=start;
            }
        }
        return aa.next;
    } 
