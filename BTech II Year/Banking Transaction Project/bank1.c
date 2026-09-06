#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct bank
{
  char acno[16], name[30], fname[30], ad[100];
  int bal;
  struct bank *next;
} *head=NULL, *temp, *newnode;
int main()
{
  FILE *fp;
  int i, flag=1, a;
  char s[16];
  
/*
  printf("Give Bank data\n");
  while (flag != 0)
  {
  newnode= (struct bank *)malloc(sizeof(struct bank));
    if (head==NULL){
      head=newnode;
      temp=newnode;
      }
    else
    {
     temp->next=newnode;
      temp=newnode;
    }

    printf("Enter Account Number: ");
    fgets(newnode->acno, 15, stdin);
    newnode->acno[strcspn(newnode->acno, "\n")] = '\0';

    printf("Enter Name: ");
    fgets(newnode->name, 30, stdin);
    newnode->name[strcspn(newnode->name, "\n")] = '\0';

    printf("Enter Father's Name: ");
    fgets(newnode->fname, 30, stdin);
    newnode->fname[strcspn(newnode->fname, "\n")] = '\0';

    printf("Enter Address: ");
    fgets(newnode->ad, 100, stdin);
   newnode->ad[strcspn(newnode->ad, "\n")] = '\0';
    
    printf("Enter Balance: ");
    scanf(" %d", &newnode->bal);
  

    printf("Enter 1 if you want to add more and 0 for no more: ");
    scanf("%d", &flag);
    getchar();
  }

  newnode->next = NULL;
  temp = head;
  fp = fopen("bankdata.txt", "w");

  while (temp != NULL)
  {
    printf("%s %s %s %s %d\n", temp->acno, temp->name, temp->fname, temp->ad, temp->bal);
    fprintf(fp, "%s,%s,%s,%s,%d\n", temp->acno, temp->name, temp->fname, temp->ad, temp->bal);

    temp =temp->next;
  }
  fclose(fp);
  */
i=1;
  printf("WELCOME TO FIROZABAD BANK\n\n\n\n");
  printf("Enter\n 1.Make a account\n 2.Delete an account\n 3.Check balance\n 4.Deposite money\n 5.Withdraw money\n 6.see all data");
  scanf("%d",&a);
  fp=fopen("bankdata.txt","r");
  
  
  newnode= (struct bank *)malloc(sizeof(struct bank));
    if (head==NULL){
      head=newnode;
      temp=newnode;
      }
    else
    {
     temp->next=newnode;
      temp=newnode;
    }
    fscanf(fp,"%s,%s,%s,%s,%d\n",newnode->acno,newnode->name,newnode->fname,newnode->ad,&newnode->bal);
        printf("%s %s %s %s %d\n",temp->acno,temp->name,temp->fname,temp->ad,temp->bal);
        return 0;
 
    
   /*  
  printf("\n linkedlist created successfully\n");
  temp=head;
  while(temp!=NULL)
  {
    printf("%s %s %s %s %d\n",temp->acno,temp->name,temp->fname,temp->ad,temp->bal);
    temp=temp->next;
  }

  
  switch(a)
  {


  case 1:
    //clrscr();
    printf("OPENING NEW ACCOUNT");
    printf("Enter Account Number: ");
    fgets(first->acno,15,stdin);
    first->acno[strcspn(first->acno,"\n")]='\0';
    printf("enter name");
   fgets(first->name,30,stdin);
   first->name[strcspn(first->name,"\n")]='\0';

   printf("enter father name");
   fgets(first->fname,30,stdin);
   first->fname[strcspn(first->fname,"\n")]='\0';

   printf("enter adress");
   fgets(first->ad,100,stdin);
   first->ad[strcspn(first->ad,"\n")]='\0';

   printf("enter balance");
   scanf("%d",&first->bal);
   third->next=first;
   first->next=NULL;
   break;
  default:
    printf("sorry");

  }





  first=head;
  while(first!=NULL)
  {
    printf("%s %s %s %s %d\n",first->acno,first->name,first->fname,first->ad,first->bal);
    first=first->next;
  }
  */
  getchar();
  return 0;
}
