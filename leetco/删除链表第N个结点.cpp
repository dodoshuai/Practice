/*
	ʱ�䣺2019/4/22
	ɾ������ĵ�����N����� 
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
