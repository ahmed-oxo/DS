#include<stdio.h>
#include<stdlib.h>
void insert();
void display();
void search();
void del();

struct node
{
	int data;
	struct node*next;
};
struct node *n,*head=NULL,*temp=NULL,*p=NULL;
void main()
{
	int ch;
	while(1)
	{
		printf("1.insert,2.display,3.search,4.del,5.exit\n");
		printf("enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();
			break;
			case 2: display();
			break;
			case 3: search();
			break;
			case 4: del();
			break;
			case 5: exit(1);
		}
		}
	}
	void insert()
	{
		int c,t;
		n=(struct node *)malloc(sizeof(struct node));
		printf("enter data: ");
		scanf("%d",&n->data);
		if(head==NULL)
		{
			head=n;
			n->next=NULL;
		}
		else
		{
			printf("1.begin,2.ending,3.after somenode,4.before somenode\n");
			printf("enter your choice ");
		    scanf("%d",&c);
		    switch(c)
		{
			case 1:n->next=head;
			       head=n;
			    break;
			case 2:n->next=NULL;
			       temp=head;
			       while(temp->next!=NULL)
			{
			       temp=temp->next;
			}
			       temp->next=n;
		           break;
			case 3:printf("after some node ");
			       scanf("%d",&t);
			       temp=head;
			       while(temp->data==t)
			{
				   temp=temp->next;
			}
			       n->next=temp->next;
			       temp->next=n;
			case 4:printf("before some node ");
			       scanf("%d",&t);
			       temp=head;
			       p=NULL;
			       while(temp->data!=t)
			{
				   p=temp;
				   temp=temp->next;
			}
			       n->next=temp;
			       p->next=n;
			       break;
			}
		}
	}
void display()
{
	if(head==NULL)
	{
		printf("no element found\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void del()
{
	int c,t;
	if(head==NULL)
	{
		printf("linked list is empty\n");
	}
	else
	{
		printf("1.begin,2.ending,3.particular node\n");
		printf("enter your choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: temp=head;
			head=head->next;
			free(temp);
			break;
			case 2: p=NULL;
			temp=head;
			while(temp->next!=NULL);
			{
				p=temp;
				temp=temp->next;
			}
			p->next=NULL;
			free(temp);
			break;
			case 3: printf("enter node to delete");
			scanf("%d",&t);
			p=NULL;
			temp=head;
			while(temp->data!=t)
			{
				p=temp;
				temp=temp->next;
			}
			p->next=temp->next;
			free(temp);
			break;
		}
	}
}
void search()
{
	int t,c=0;
	if(head==NULL)
	{
		printf("no linked list to perform search\n");
	}
	else
	{
		printf("enter data to search: ");
		scanf("%d",&t);
		temp=head;
		while(temp!=NULL)
		{
			if(temp->data==t)
			{
			
			
				c=1;
				break;
			}
			else
				printf("enter data to search: ");
				scanf("%d",&t);
				temp=head;
				while(temp!=NULL)
				{
					if(temp->data==t)
					{
						c=1;
						break;
					}
					else
					
						temp=temp->next;
					
					}
					if(c==1)
					printf("data found\n");
					else
					printf("data not found\n");
				}
			}
		}
	

