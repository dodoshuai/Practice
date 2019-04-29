/*
	时间：2019/4/22
	删除链表的倒数第N个结点 
*/
ListNode *removeNthFromEnd(ListNode* head,int n){
	ListNode *cur=head;
	while(n--)
		cur=cur->next;	//  find  n
	if(!cur)
		return head->next;//when n   is   NULL     so    (ex:n=2;   1,2,3    find 2)
	ListNode *last=head;
	while(cur->next!=NULL){// go  head  when  head is NULL
		last=last->next;
		cur=cur->next;
	}
	last->next=last->next->next;
	return head;
} 
