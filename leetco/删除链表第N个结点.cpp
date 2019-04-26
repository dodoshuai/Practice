/*
	时间：2019/4/22
	删除链表的倒数第N个结点 
*/
ListNode *removeNthFromEnd(ListNode* head,int n){
	ListNode *cur=head;
	while(n--)
		cur=cur->next;	
	if(!cur)
		return head->next;
	ListNode *last=head;
	while(cur->next!=NULL){
		last=last->next;
		cur=cur->next;
	}
	last->next=last->next->next;
	return head;
} 
