/* a. Queue in Array */
#include<stdio.h>
#include<stdlib.h>

struct QueueRecord
{
	int capacity;
	int* front;
	int* rear;
	int size;
	int* Array;	
};

typedef struct QueueRecord* queue;

queue CreateQueue(int maxsize);
void MakeEmpty(queue Q);
int IsEmpty(queue Q);
int IsFull(queue Q);
void Enqueue(int x, queue Q);
void Dequeue(queue Q);
int* succ(int* index, queue Q);
void PrintQueue(queue Q);

int main()
{	
	/* Test Case */
	queue Q;
	Q = CreateQueue(5);
	printf("%d\n",IsEmpty(Q));
	Enqueue(2,Q);
	Enqueue(1,Q);
	Enqueue(5,Q);
	Enqueue(4,Q);
	Enqueue(9,Q);
	printf("%d\n",IsFull(Q));
	PrintQueue(Q);
	printf("\n");
	Dequeue(Q);
	Dequeue(Q);
	PrintQueue(Q);
	Enqueue(3,Q);
	PrintQueue(Q);
	printf("%d\n",IsFull(Q));
	return 0;
}

queue CreateQueue(int maxsize)
{
	queue Q = (queue)malloc(sizeof(struct QueueRecord));
	Q->Array = (int*)malloc(sizeof(int) * maxsize);
	Q->front = (int*)malloc(sizeof(int));
	Q->rear = (int*)malloc(sizeof(int));
	Q->capacity = maxsize;
	MakeEmpty(Q);
	return Q;
}

void MakeEmpty(queue Q)
{
	Q->size = 0;
	*(Q->front) = -1;
	*(Q->rear) = -1;
}

int IsEmpty(queue Q)
{
	return *(Q->front) == *(Q->rear);
}

int IsFull(queue Q)
{
	return (*(Q->rear) + 1) % (Q->capacity) == *(Q->front) || Q->size == Q->capacity;
}

int* succ(int* index, queue Q)
{
	if(++(*index) == Q->capacity)
		*index = 0;	
	return index;
}

void Enqueue(int x, queue Q)
{
	if(IsFull(Q))
		printf("Queue is full");
	else
	{
		Q->size++;
		Q->rear = succ(Q->rear, Q);
		Q->Array[*(Q->rear)] = x;
	}
}

void Dequeue(queue Q)
{	
	if(IsEmpty(Q))
		printf("Queue is empty");
	else
	{
		Q->size--;
		Q->front = succ(Q->front, Q);
		Q->Array[*(Q->front)] = NULL;
	}
}

void PrintQueue(queue Q)
{
	int i = *(Q->front) + 1;
	if(i == 0)
	{
		while(i <= *(Q->rear))
		{
			printf("%d ",Q->Array[i]);
			i++;
		}
	}
	else
	{	
		while(i != *(Q->rear))
		{
			printf("%d ",Q->Array[i]);
			i = (i+1) % (Q->capacity);
		}
		printf("%d\n",Q->Array[i]);
	}
}


/* b. Queue in Linkedlist */
#include<stdio.h> 
#include<stdlib.h>

struct Node
{
	int Element;
	struct Node* next;
};

struct QNode
{
	struct Node* front;
	struct Node* rear;	
};

typedef QNode* queue;
typedef Node* node;

queue CreateQueue();
void MakeEmpty(queue Q);
int IsEmpty(queue Q);
void Enqueue(int x, queue Q);
void Dequeue(queue Q);
void PrintQueue(queue Q);

int main()
{	
	/* Test Case */
	queue Q;
	Q = CreateQueue();
	//printf("%d",IsEmpty(Q));
	Dequeue(Q);
	Enqueue(2,Q);
	Enqueue(1,Q);
	Enqueue(5,Q);
	Enqueue(9,Q);
	Enqueue(3,Q);
	PrintQueue(Q);
	
	Dequeue(Q);
	PrintQueue(Q);
	Dequeue(Q);
	PrintQueue(Q);
	Dequeue(Q);
	PrintQueue(Q);
	Dequeue(Q);
	PrintQueue(Q);
	Dequeue(Q);
	PrintQueue(Q);
	printf("%d",IsEmpty(Q));
	return 0;
}

void MakeEmpty(queue Q)
{
	Q->front = (node)malloc(sizeof(struct Node));
	Q->rear = (node)malloc(sizeof(struct Node));
	Q->front = NULL;
	Q->rear = NULL;
}

queue CreateQueue()
{
	queue Q;
	Q = (queue)malloc(sizeof(struct QNode));
	MakeEmpty(Q);
	return Q;
}

int IsEmpty(queue Q)
{
	return Q->front == NULL;
}

void Enqueue(int x, queue Q)
{
	node tmp;
	tmp = (node)malloc(sizeof(struct Node));
	tmp->Element = x;
	if(IsEmpty(Q))
	{
		Q->front = tmp;
		tmp->next = Q->rear;
		Q->rear = tmp;
	}
	else
	{
		tmp->next = Q->rear->next;
		Q->rear->next = tmp;
		Q->rear = Q->rear->next; 
	} 
}

void Dequeue(queue Q)
{
	if(IsEmpty(Q))
	{
		printf("Queue is Empty\n");
	}
	else
	{
		node temp;
		temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
	}
}

void PrintQueue(queue Q)
{
	node tmp;
	tmp = Q->front;
	if(IsEmpty(Q))
		printf("[Empty]\n");
	else
	{
		while(tmp != Q->rear)
		{
			printf("%d ",tmp->Element);
			tmp = tmp->next;	
		} 
		printf("%d\n",tmp->Element);
	}
}
