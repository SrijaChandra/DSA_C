//Linked List
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
void insert_first()
{
	int k;
	struct node *ptr;
	printf("Enter new node value:");
	scanf("%d",&k);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	ptr->next=head;
	head=ptr;	
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
void insert_after_value()
{
	int k,a,f=0;
	struct node *ptr,*s;
	printf("Enter new node value:");
	scanf("%d",&k);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	printf("Enter node value after which we want to insert");
	scanf("%d",&a);
	s=head;
	while(s->data!=a)
	{
		s=s->next;
		if(s==NULL)
		{
			f=1;break;
		}
	}
	if(f==1)
	{
		printf("\n node value does not exists in the list");
		free(ptr);
	}
	else{
		ptr->next=s->next;
		s->next=ptr;
	}
}
void insert_before_node_value()
{
	int k,b,f=0;
	struct node *ptr,*s,*w;
	printf("Enter new node value");
	scanf("%d",&k);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	printf("Enter node value befor which we want to insert");
	scanf("%d",&b);
	if(head->data==b)
	{
		ptr->next=head;
		head=ptr;
	}
	else{
		s=head->next;
		w=head;
		while(s->data!=b)
		{
			s=s->next;
			w=w->next;
			if(s==NULL)
			{
				f=1;break;
			}
		}
		if(f==1)
		{
			printf("no not present in list");
			free(ptr);
		}
		else{
			w->next=ptr;
			ptr->next=s;
		}
	}
}
void del_pos()
{
	int p,f=0,i;
	struct node *s,*t;
	printf("Enter pos to delete");
	scanf("%d",&p);
	s=head;
	if(p==1)
	{
		head=head->next;
		free(s);
	}
	else{
		for(i=1;i<=p-2;i++)
		{
			s=s->next;
			if(s==NULL)
			{
				f=1;break;
			}
		}
		if(f==1)
		 printf("position not found");
		else{
			t=s->next;
			s->next=t->next;
			free(t);
		}
	}
}
void insert_position()
{
	int k,f=0,p,i;
	struct node *ptr,*s;
	printf("Enter new node value:");
	scanf("%d",&k);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	printf("Enter position to insert");
	scanf("%d",&p);
	if(p==1)
	{
		ptr->next=head;
		head=ptr;
	}
	else{
		s=head;
		for(i=1;i<=p-2;i++)
		{
			s=s->next;
			if(s==NULL)
			{f=1;break;}
			
		}
		if(f==1)
		{
			printf("Position does not exists");
			free(ptr);
		}
		else{
			ptr->next=s->next;
			s->next=ptr;
		}
	}
}
void rdisplay(struct node *s)
{
	if(s!=NULL)
	{
		rdisplay(s->next);
		printf("\t%d",s->data);
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1 for insert last");
		printf("\n2 for insert first");
		printf("\n3 for display");
		printf("\n4 for insert after node value");
		printf("\n5 for insert before a node value");
		printf("\n6 insert at any position");
		printf("\n7 Enter postion to delete ");
		printf("\n8 for reverse display");
		printf("\n0 for exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert_last();
			        break;
			case 2:insert_first();
			    break;
		    case 3:display();
		          break;
		    case 4:insert_after_value();break;
		    case 5:insert_before_node_value();
		           break;
		    case 6:insert_position();
		            break;
		    case 7:del_pos();break;
		    case 8:rdisplay(head);break;
		    case 0:exit(0);
		}
	}
}


