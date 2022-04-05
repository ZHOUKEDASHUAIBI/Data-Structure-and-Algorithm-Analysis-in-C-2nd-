/*
	a.singly Linkedlist.
	assume that we will exchange nodes ptr1 and ptr2
	pre is the previous node of ptr1
*/
void Exchange(pre, ptr1)
{
	pre->next = ptr1->next;
	ptr1->next = pre->next->next;
	pre->next->next = ptr1;	
} 

/*
	b. doubly Linkedlist.
	assume that we will exchange nodes ptr1 and ptr2.
*/
void Exchange(ptr1, ptr2)
{
	ptr1->next = ptr2->next;
	ptr1->prev->next = ptr2;
	ptr2->next = ptr1;
	ptr1->next->prev = ptr1;
	ptr2->prev = ptr1->prev;
	ptr1->prev = ptr2;
}
