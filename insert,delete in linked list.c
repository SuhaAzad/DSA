int item;
	trav=head;

	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node to insert: ");
	scanf("%d",&(temp->data));
	temp->next=NULL;

	if(control==1)
	{
		printf("Enter the node after which you want to insert: ");
		scanf("%d",&item);

		while(trav->data!=item)
			trav=trav->next;

		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter node to insert: ");
		scanf("%d",&(temp->data));
		temp->next=NULL;

		if(trav==tail)// data item to stored after tail
		{
@@ -113,29 +113,17 @@ void Insert()
		scanf("%d",&item);
		if(item==head->data)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			printf("Enter node to insert: ");
			scanf("%d",&(temp->data));
			temp->next=head;

			head=temp;
		}
		 else{
		 	while(trav->next->data!=item)	
				trav=trav->next;

			temp=(struct node*)malloc(sizeof(struct node));
			printf("Enter node to insert: ");
			scanf("%d",&(temp->data));
			temp->next=NULL;



			temp->next=trav->next;
			trav->next=temp;

		 }


	}
}
