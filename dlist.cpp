//double linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
void insrert_last()
{
	int k;
	struct node *ptr,*s;
	printf("Enter new node value");
	scanf("%d",&k);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	ptr->next=NULL;
	if(head==NULL)
	{
		ptr->prev=NULL;
		head=ptr;
	}
	else{
		s=head;
		while(s->next!=NULL)
		 s=s->next
	   s->next=ptr;
	   ptr->prev=s;
	}
}
void insert_first()
{
	int k;
	struct node *ptr;
	printf("Enter the data to be inserted");
	scanf("%d",&k);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	ptr->prev=NULL;
	ptr->next=head;
	if(head!=NULL)
	head->prev=ptr;
	head=ptr;
}
void insert_before_node_value()
{
    int k,b,f;
	struct node *ptr,*s,*w;	
	printf("\nEnter new node value");
	scanf("%d",&k);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	printf("Enter node value before which we want to insert");
	scanf("%d",&b);
	if(head->data==b)
	{
		ptr->next=head;
		ptr->prev=NULL;
		head->prev=ptr;
		head=ptr;
	}
	else{
		s=head->next;
		f=0;
		while(s->data!=b)
		{
			s=s->next;
			if(s==NULL)
			{
				f=1;break;
			}
		}
		if(f==1)
		{
			printf("\nNode value does not exists");
			free(ptr);
		}
		else{
		   w=s->prev;
		   w->next=ptr;
		   ptr->prev=w;
		   ptr->next=s;
		   s->prev=ptr;	
		}
	}
}
void insert_pos()
{
	int k,f,i,p;
	struct node *ptr,*s,*t;
	printf("Enter new node value");
	scanf("%d",&k);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	printf("Enter position to insesert");
	scanf("%d",&p);
	if(p==1)
	{
		ptr->prev=NULL;
		ptr->next=head;
		head->prev=ptr;
		head=ptr;
	}
	else{
		s=head;
		f=0;
		for(i=1;i<=p-2;i++)
		{
			s=s->next;
			if(s==NULL)
			{
				f=1;break;
			}
		}
		if(f==1)
		{
			printf("Position does not exists");
			free(ptr);
		}
		else{
		   t=s->next;
		   s->next=ptr;
		   ptr->prev=s;
		   ptr->next=t;
		   if(t!=NULL)
		    t->prev=ptr;	
		}
	}
}
void del_pos()
{
	int p,f,i;
	struct node *s,*t;
	printf("Enter position to delete");
	scanf("%d",&p);
	if(p==1)
	{
		s=head;
		head=head->next;
		head->prev=NULL;
		free(s);
	}
	else{
		s=head;
		f=0;
		for(i=1;i<=p-2;i++)
		{
			s=s->next;
			if(s==NULL)
			{
				f=1;break;
			}
		}
		if(f==1)
		  printf("Position does not exists");
		else
		{
			t=s->next;
			s->next=t->next;
			if(t->next!=NULL)
			 t->next->prev=s;
			free(t);
		}
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




