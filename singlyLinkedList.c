#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;

void insertAtBeg();   
void insertAtEnd();  
void insertAtLoc();  
void deleteFromBeg();  
void deleteFromEnd();  
void deleteFromLoc();  
void search();  
void display();

void main()
{
    int ch = 0;  
    while(ch != 9)   
    {    
        printf("\n\n 1.Insert Element at Begining \n 2.Insert Element at End \n 3.Insert Element at Desired Location \n 4.Delete Element from Beginning \n 5.Delete Element from Last \n 6.Delete Element at desired Location \n 7.Search an Element \n 8.Display the Linked List \n 9.Exit \n ");  
        printf("\n Enter your choice? \n");         
        scanf("\n%d",&ch);
        
        switch(ch)  
        {  
            case 1:  
            insertAtBeg();      
            break;  
            case 2:  
            insertAtEnd();         
            break;  
            case 3:  
            insertAtLoc();       
            break;  
            case 4:  
            deleteFromBeg();       
            break;  
            case 5:  
            deleteFromEnd();        
            break;  
            case 6:  
            deleteFromLoc();          
            break;  
            case 7:  
            search();         
            break;  
            case 8:  
            display();        
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Ivalid choice");  
        }  
    }  
}

void insertAtBeg()  
{  
    struct node *ptr;  
    int item;  
    ptr = (struct node *)malloc(sizeof(struct node *));  
    printf("\nEnter value\n");    
    scanf("%d",&item);    
    ptr->data = item;  
    ptr->next = head;  
    head = ptr;  
    printf("\nNode inserted");
}

void insertAtEnd()  
{  
    struct node *ptr, *temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    printf("\nEnter value?\n");  
    scanf("%d",&item);  
    ptr->data = item;  
    if(head == NULL)  
    {  
        ptr->next = NULL;  
        head = ptr;  
        printf("\nNode inserted");  
    }  
    else  
    {  
        temp = head;  
        while (temp->next != NULL)  
        {  
            temp = temp->next;  
        }  
        temp->next = ptr;  
        ptr->next = NULL;  
        printf("\nNode inserted");  
          
    }  
}

void insertAtLoc()  
{  
    int i, loc, item;   
    struct node *ptr, *temp;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    printf("\nEnter value");  
    scanf("%d",&item);  
    ptr->data = item;  
    printf("\nEnter the location after which you want to insert ");  
    scanf("\n%d",&loc);  
    temp=head;  
    for(i=0;i<loc;i++)  
    {  
        temp = temp->next;  
        if(temp == NULL)  
        {  
            printf("\nInsertion not possible\n");  
            return;  
        }   
    }  
    ptr->next = temp->next;   
    temp->next = ptr;   
    printf("\nNode inserted"); 
} 

void deleteFromBeg()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nDeletion at beginning successful\n");  
    }  
}  
void deleteFromEnd()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nSingle node deleted\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nLast node deleted\n");  
    }     
}  
void deleteFromLoc()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location: \n");  
    scanf("%d",&loc);  
    ptr = head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1->next = ptr->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}

void search()  
{  
    struct node *ptr;  
    int item, i=0, flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nList Empty\n");  
    }  
    else  
    {   
        printf("\nEnter the Element you want to search:\n");   
        scanf("%d", &item);  
        while (ptr != NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("Element present at location %d ",i+1);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr->next;  
        }  
        if(flag==1)  
        {  
            printf("Element not present\n");  
        }  
    }     
          
}  
  
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("List is Empty");  
    }  
    else  
    {  
        while (ptr!=NULL)  
        {  
            printf("%d ", ptr->data);  
            ptr = ptr->next;  
        }  
    }  
}     
             
