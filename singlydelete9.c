#include<stdio.h>
#include<stdlib.h>//malloc() exit()
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert_last()
{
	struct node *s,*ptr;
	int k;
	printf("Enter new node value:");
	scanf("%d",&k);//17
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	ptr->next=NULL;
	if(head==NULL)//linkedlist not exits
	  head=ptr;
	else
	{
		s=head;
		while(s->next!=NULL)
		   s=s->next;
	   s->next=ptr;
	}
}
void display()
{
	struct node *s;
	s=head;
	while(s!=NULL)
	{
	  printf("\t%d",s->data);
	  s=s->next;	
	}
}
void delete_last()
{
    struct node *s, *temp;
    temp=head;
    if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else{
    while(temp->next!=NULL)
    {
        s=temp;
        temp=temp->next;
    }
    free(temp);
    s->next=NULL;
    }
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1 for insert last");
		printf("\n2 for display");
		printf("\n3 for delete");
		printf("\n0 for exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert_last();
			        break;
		    case 2:display();
		          break;
		    case 3:delete_last();
		          break;
		    case 0:exit(0);
		}
	}
}