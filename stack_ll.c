#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display();  
struct node   
{  
int val;  
struct node *next;  
};  
struct node *top;  
  
void push()  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
        printf("Enter the value");  
        scanf("%d",&val);  
        if(top==NULL)  //empty
        {         
            ptr->val = val;  
            ptr->next = NULL;  //new node becomes the first element of the stack
            top=ptr;  
        }   
        else   
        {  
            ptr->val = val;  
            ptr->next = top;  
            top=ptr;  
               
        }  
        printf("Item pushed");  
          
    }
  
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (top == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = top->val;  
        ptr = top;  
        top = top->next;  
        free(ptr);  
        printf("Item popped");  
          
    }  
}  
void display()  
{  
    int i;  
    struct node *ptr;  
    ptr=top;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
}
int main ()  
{  
    int ch;     
    printf("\nStack operations using linked list\n");   
    while(1)  
    {  
        printf("\n\nChoose one from the below options:\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&ch);  
        switch(ch)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                exit(0);  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
    };  
}  
}    