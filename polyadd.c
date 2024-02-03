//polynomial addtition
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef,power;
	struct node *next;
};
void display(struct node *head)
{
	while(head!=NULL)
	{
		printf("(%dx^%d)",head->coef,head->power);
		head=head->next;
	}
}
void addpoly(struct node *head1,struct node *head2)
{
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->power>head2->power)
		{
			printf("(%dx^%d)",head1->coef,head1->power);
			head1=head1->next;
		}
		else if(head2->power>head1->power)
		{
			printf("(%dx^%d)",head2->coef,head2->power);
			head2=head2->next;
		}
		else
		{
			printf("(%dx^%d)",head1->coef+head2->coef,head1->power);
			head1=head1->next;
			head2=head2->next;
		}
	}
	while(head1!=NULL)
	{
		printf("(%dx^%d)",head1->coef,head1->power);
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		printf("(%dx^%d)",head2->coef,head2->power);
		head2=head2->next;
	}
}


int main()
{
	struct node *head1=NULL,*head2=NULL,*ptr,*temp;
	int ch,i,c,p,n;
	while(1)
	{
		printf("\n1 for create first polynomial");
		printf("\n2 for create second polynomial");
		printf("\n3 for display first poly");
		printf("\n4 for display second poly");
		printf("\n5 for addition");
		printf("\n6 for exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter no of terms");
			        scanf("%d",&n);
			        for(i=1;i<=n;i++)
			        {
			        	printf("Enter coef and pow:");
			        	scanf("%d%d",&c,&p);
			        	ptr=(struct node*)malloc(sizeof(struct node));
			        	ptr->coef=c;
			        	ptr->power=p;
			        	ptr->next=NULL;
			        	if(head1==NULL)
			        	 {
			        	 	head1=ptr;
			        	 	temp=head1;
						 }
						 temp->next=ptr;
						 temp=temp->next;
					}
					break;
		case 2:
			 printf("\nEnter no of terms");
			        scanf("%d",&n);
			        for(i=1;i<=n;i++)
			        {
			        	printf("Enter coef and pow:");
			        	scanf("%d%d",&c,&p);
			        	ptr=(struct node*)malloc(sizeof(struct node));
			        	ptr->coef=c;
			        	ptr->power=p;
			        	ptr->next=NULL;
			        	if(head2==NULL)
			        	 {
			        	 	head2=ptr;
			        	 	temp=head2;
						 }
						 temp->next=ptr;
						 temp=temp->next;
					}
					break;
		 case 3:
		 	    display(head1);
		 	    break;
		case 4:display(head2);
		       break;
		case 5:addpoly(head1,head2);
		       break;
		case 6:exit(0);
			       
		}
	}
}









