void PrintLots(list L, list P)
{
	list tmp1 = L;
	list tmp2 = P->next;
	static int last = 0;
	while(tmp2)
	{
		int i;
		i = tmp2->data - last;
		last = tmp2->data;
		while(i--)
		{
			tmp1 = tmp1->next;
		}
		printf("%d ",tmp1->data);
	tmp2 = tmp2->next;
	}
}
