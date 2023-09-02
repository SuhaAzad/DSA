#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL, *tail=NULL;
void create();
void view();
void insert();
void deletion();

int main()
{
	int ch;
	while(1)
	{
		printf("\n1 to create, 2 to view, 3 to insert, 4 to delete: ");
		scanf("%d",&ch);
		if(ch==1)
			create();
		else if(ch==2)
			view();
		else if(ch==3)
			insert();
		else if(ch==4)
			deletion();

	}
}
void create()
{
	struct node *temp;
	int n,i;
	printf("No of nodes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&temp->data);
		temp->prev=NULL; temp->next=NULL;

		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			temp->prev=tail;
			tail=temp;

		}

	}

}
void view()
{
	struct node *trav;
	trav=head;
	while(trav!=NULL)
	{
		printf("%d\t",trav->data);
		trav=trav->next;
	}
}

void insert()
{
	int control, item;
	printf("1 to insert before node, 2 to insert after node: ");
	scanf("%d",&control);
	struct node *temp, *trav;
	trav=head;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node to insert: ");
	scanf("%d",&temp->data);
	if(control==1)
	{
		printf("Enter node before which you want to insert: ");
		scanf("%d",&item);
		if(head->data==item)
		{
			temp->next=head;
			head->prev=temp;
			head=temp;
		}
		else
		{
			while(trav->data!=item)
				trav=trav->next;

			temp->next=trav;
			temp->prev=trav->prev;
			trav->prev->next=temp;
			trav->prev=temp;

		}

	}
	else if(control==2)
	{
		printf("Enter node after which you want to insert data: ");
		scanf("%d",&item);
		while(trav->data!=item)
			trav=trav->next;

		if(trav==tail)
		{
			temp->next=NULL;
			trav->next=temp;
			temp->prev=trav;
			tail=temp;

		}
		else
		{
			temp->next=trav->next;
			trav->next->prev=temp;
			temp->prev=trav;
			trav->next=temp;

		}

	}
}

void deletion()
{
	int control;
	printf("1 for deleting first instance of node or 2 to delete all instances of a node: ");
	scanf("%d",&control);

	struct node *trav, *temp;
	trav=head;
	int item;
	printf("enter the item to be deleted: ");
	scanf("%d",&item);
	if(control==1)
	{
		if(head->data==item)
		{
			temp=head;
			head->next->prev=NULL;
			head=head->next;
			free(temp);
		}
		else
		{
			while(trav->data!=item)
				trav=trav->next;

			if(trav==tail)
			{
				temp=tail;
				tail=tail->prev;
				tail->next=NULL;
				free(temp);
			}
			else
			{
				temp=trav;
				trav->prev->next=trav->next;
				trav->next->prev=trav->prev;
				free(temp);
			}


		}
	}
	else if(control==2)
	{
		while(trav->next!=NULL)
		{
			if(trav->next==tail)
			{
				temp=trav->next;
				tail=tail->prev;
				tail->next=NULL;
				free (temp);
			}
			else if(trav->next->data==item)
			{
				temp=trav->next;
				trav->next=temp->next;
				temp->next->prev=trav;
				free(temp);

			}
			else
				trav=trav->next;
		}
		if(head->data==item)
		{
			temp=head;
			head=head->next;
			head->prev=NULL;
			free(temp);
		}
	}
}
