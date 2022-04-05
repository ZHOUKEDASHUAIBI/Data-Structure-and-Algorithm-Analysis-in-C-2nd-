/* include header L */
void PrintList(list L)
{
	position tmp = L->next;
	while(tmp)
	{
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
