#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<process.h>
/ / Structure is created for the node
struct node
{
struct node *prev;
int info;
struct node *next;
}*start;
typedef struct node *NODE;
/ / fucntion to create a doubly linked list
void create_list(int num)
{
NODE q,tmp;
/ / a new node is created
tmp=(NODE)malloc(sizeof(struct node));
tmp->info=num;/ / assigning the data to the new node
tmp->next=NULL;
if(start==NULL)
{
tmp->prev=NULL;
start->prev=tmp;
start=tmp;
}
else
{
q=start;
while(q->next!=NULL)
q=q->next;
q->next=tmp;
tmp->prev=q;
}
}/ *End of create_list()*/
/ / Function to add new node at the beginning
void addatbeg(int num)
{
NODE tmp;
/ / a new node is created for inserting the data
tmp=(NODE)malloc(sizeof(struct node));
tmp->prev=NULL;
tmp->info=num;
tmp->next=start;
start->prev=tmp;
start=tmp;
}/ *End of addatbeg()*/
/ / This fucntion will insert a node in any specific position
void addafter(int num,int pos)
{
NODE tmp,q;
int i;
q=start;
/ / Finding the position to be inserted
for(i=0;i<pos-1;i++)
{
q=q->next;
if(q==NULL)
{
printf (“\ nThere are less than %d elements\ n”,pos);
return;
}
}
/ / a new node is created
tmp=(NODE)malloc(sizeof(struct node) );
tmp->info=num;
q->next->prev=tmp;
tmp->next=q->next;
tmp->prev=q;
q->next=tmp;
}/ *End of addafter() */
/ / Function to delete a node
void del(int num)
{
NODE tmp,q;
if(start->info==num)
{
tmp=start;
start=start->next; / *first element deleted*/
start->prev = NULL;
free(tmp);/ / Freeing the deleted node
return;
}
q=start;
while(q->next->next!=NULL)
{
if(q->next->info==num) / *Element deleted in between*/
{
tmp=q->next;
q->next=tmp->next;
tmp->next->prev=q;
free(tmp);
return;
}
q=q->next;
}
if (q->next->info==num) / *last element deleted*/
{ tmp=q->next;
free(tmp);
q->next=NULL;
return;
}
printf(“\ nElement %d not found\ n”,num);
}/ *End of del()*/
/ / Displaying all data(s) in the node
void display()
{
NODE q;
if(start==NULL)
{
printf(“\ nList is empty\ n”);
return;
}
q=start;
printf(“\ nList is :\ n”);
while(q!=NULL)
{
printf(“%d ”, q->info);
q=q->next;
}
printf(“\ n”);
}/ *End of display() */
void main()
{
int choice,n,m,po,i;
start=NULL;
while(1)
{
/ / Menu options for the doubly linked list operation
clrscr();
printf(“\ n1.Create List\ n”);
printf(“2.Add at begining\ n”);
printf(“3.Add after\ n”);
printf(“4.Delete\ n”);
printf(“5.Display\ n”);
printf(“6.exit\ n”);
printf(“\ nEnter your choice:”);
scanf(“%d”,&choice);
/ / switch instruction is called to execute
/ / correspoding function
switch(choice)
{
case 1:
printf(“\ nHow many nodes you want:”);
scanf(“%d”,&n);
for(i=0;i<n;i++)
{
printf(“\ nEnter the element:”);
scanf(“%d”,&m);
/ / create linked list function is called
create_list(m);
}
break;
case 2:
printf(“\ nEnter the element:”);
scanf(“%d”,&m);
addatbeg(m);
break;
case 3:
printf(“\ nEnter the element:”);
scanf(“%d”,&m);
printf(“\ nEnter the position after which this element is inserted:”);
scanf(“%d”,&po);
addafter(m,po);
break;
case 4:
printf(“\ nEnter the element for deletion:”);
scanf(“%d”,&m);
/ / Delete a node fucntion is called
del(m);
break;
case 5:
display();
getch();
break;
case 6:
exit(0);
default:
printf(“\ nWrong choice\ n”);
getch();
}/ *End of switch*/
}/ *End of while*/
}/ *End of main()*/