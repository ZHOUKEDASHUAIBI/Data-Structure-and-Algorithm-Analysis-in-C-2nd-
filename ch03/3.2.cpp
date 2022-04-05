/* 
   Running Time O(L+P)
   We use a variable i to record position. So that we can avoid doing loop everytime.
   Condition : The LinkedList should have a head.
*/

void PrintLots(list L, list P)
{
	list tmp1 = L;
	list tmp2 = P->next;
	int i = 1;
	while(tmp2)
	{
		while(i <= tmp2->data)
		{
			tmp1 = tmp1->next;
			i++;
		}
		printf("%d ",tmp1->data);
		tmp2 = tmp2->next;
	}
}
