#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void addbook(char*,int);
void deletebook(char*);
void searchbook();
void issuebook();
void returnbook();
void display();
int db[20][20];
int main()
{
	int x,n;
	char m[20];
	do
	{
	printf("1:ADD BOOK\n2:DELETE BOOK\n3:SEARCH BOOK\n4:ISSUE BOOK\n5:RETURN BOOK\n6:DISPLAY BOOKS\n7:EXIT\n");
	printf("****************************************************************************************\n");
	printf("Enter Your Choice: ");
	scanf("%d",&x);
	switch(x)
	{
		case 1:printf("Enter Name of book to be added: ");
	           scanf("%s",m);
	           printf("Enter Book Number: ");
	           scanf("%d",&n);
		       addbook(m,n);
		       break;
		case 2:printf("Enter Name of Book To Be Deleted: ");
	           scanf("%s",m);
		       deletebook(m);
		       break;
		case 3:searchbook();
		       break;
		case 4:issuebook();
		       break;
		case 5:returnbook();
		       break;
		case 6:display();
		       break;
		case 7:break;
		default:printf("Invalid Input");
		        break;
	}
	}while(x!=7);
}

struct node
{
	int number;
	char name[20];
	struct node *next,*prev;
};
struct node *start=NULL,*temp,*p,*q,*book;

void addbook(char b[20],int n)
{
	temp=(struct node *)malloc(sizeof(struct node));	
	temp->number=n;
	strcpy(temp->name,b);
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		p=start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;
	}
}
	
	
void deletebook(char* nav)
{
	char n[20];
	temp=(struct node *)malloc(sizeof(struct node));	
	strcpy(temp->name,nav);
	p=q=start;
    while(p!=NULL)
	{
		if(p->name==temp->name)
		{
			if(p==start)          //for first book
			{
				start=start->next;
				start->prev==NULL;
				printf("%s is Deleted Successfully\n",temp->name);
				free(p);
				break;			
			}
			else
			{
                q->next=p->next;
                p->next->prev=q;
                printf("%s is Deleted Successfully\n",temp->name);
                free(p);
				break;	
			}
		}
        else
        {
	        q=p;
			p=p->next;
		}
    }
    if(p==NULL)
    printf("%s is not found",temp->name);
}
		
void searchbook()
{
	temp=(struct node *)malloc(sizeof(struct node));
	int c=0;
	printf("Enter Name Of the book: ");
    scanf("%s",temp->name);
	while(p->name!=temp->name)
	{
		c++;
		p=p->next;
	}
	printf("Book Found At Position %d",c);
}

void issuebook()
{
	char b[20];
	int db[20][20],n;
	printf("Enter The Book you want to Borrow: ");
	scanf("%s",b);
	printf("Enter Book Number: ");
	scanf("%d",&n);
	printf("Enter Date(DD/MM/YYYY): ");
    for(int i=0;i<8;i++)
	scanf("%d",&db[n][i]);
	deletebook(b);
}

void returnbook()
{
	char b[20];
	int n,dr[20][20];
	printf("Enter The Name of Book: ");
	scanf("%s",b);
	printf("Enter Book Number: ");
	scanf("%d",&n);
	printf("Enter Date(DD/MM/YYYY): ");
    for(int i=0;i<8;i++)
	scanf("%d",&dr[n][i]);
	addbook(b,n);
	for(int i=0;i<8;i++)
	printf("%d",db[n][i]);
}

void display()
{
	p=start;
	while(p!=NULL)
	{
		printf("BOOK NAME: %s",p->name);
		printf("BOOK NO.: %d",p->number);
		p=p->next;
	}
}
