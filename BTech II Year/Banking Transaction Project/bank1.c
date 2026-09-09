#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct bank
{
  char acno[16], name[30], fname[30], ad[100];
  int bal;
  struct bank *next;
} *head = NULL, *temp, *newnode;
int main()
{
  FILE *fp;
  int i, flag = 1, a;
  char s[16];
  //Creation of Bankdata.txt file throgh linkedlist
  /*
    printf("Give Bank data\n");
    while (flag != 0)
    {
      newnode = (struct bank *)malloc(sizeof(struct bank));
      if (head == NULL)
      {
        head = newnode;
        temp = newnode;
      }
      else
      {
        temp->next = newnode;
        temp = newnode;
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

      printf("Enter Address : ");
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
      fprintf(fp, "%s|%s|%s|%s|%d\n", temp->acno, temp->name, temp->fname, temp->ad, temp->bal);

      temp = temp->next;
    }
    fclose(fp);
    */
//Reading of bankdata.txt file to access existing data
  fp = fopen("bankdata.txt", "r");
  //Taking data into linkedlist for operations
  while (1)
  {
    newnode = (struct bank *)malloc(sizeof(struct bank));
    if (head == NULL)
    {
      head = newnode;
      temp = newnode;
    }
    else
    {
      temp->next = newnode;
    }
    if (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%d\n", newnode->acno, newnode->name, newnode->fname, newnode->ad, &newnode->bal) == EOF)
    {
      free(newnode);
      break;
    }
    temp = newnode;
  }
  temp->next = NULL;
  fclose(fp);
  
  i = 1;
  int m;
  printf("WELCOME TO FIROZABAD BANK\n\n\n\n");
  while (i != 0)
  {
    flag = 0;
    printf("Enter\n 1.Make a account\n 2.Delete an account\n 3.Check balance\n 4.Deposite money\n 5.Withdraw money\n 6.see all data");

    scanf("%d", &a);

    switch (a)
    {
//Editing linkedlist as per operations
    case 1:        //Creating a new account
      newnode = (struct bank *)malloc(sizeof(struct bank));
      if(newnode==NULL)
      {
        printf("Not more memory available");
        break;
      }
      temp->next = newnode;
      temp = newnode;
      getchar();
      printf("OPENING NEW ACCOUNT\n");
      printf("Enter Account Number: ");
      fgets(temp->acno, 15, stdin);
      temp->acno[strcspn(temp->acno, "\n")] = '\0';

      printf("enter name");
      fgets(temp->name, 30, stdin);
      temp->name[strcspn(temp->name, "\n")] = '\0';

      printf("enter father name");
      fgets(temp->fname, 30, stdin);
      temp->fname[strcspn(temp->fname, "\n")] = '\0';

      printf("enter adress");
      fgets(temp->ad, 100, stdin);
      temp->ad[strcspn(temp->ad, "\n")] = '\0';

      printf("enter balance");
      scanf("%d", &temp->bal);
      temp->next = NULL;
      break;

    case 2:   //Deleting of account
      printf("Enter account number");
      scanf("%s", s);
      temp = head;
      while (temp != NULL)
      {
        if (strcmp(s, temp->acno) == 0)
        {
          head = temp->next;
          temp = temp->next;
          flag = 1;
          break;
        }
        else if (temp->next != NULL && strcmp(s, temp->next->acno) == 0)
        {
          temp->next = temp->next->next;
          flag = 1;
          break;
        }
        temp = temp->next;
      }
      if (flag != 1)
        printf("Your account not found\n");
      break;

    case 3:            //Checking balance
      printf("Enter account number");
      scanf("%s", s);
      temp = head;
      while (temp != NULL)
      {
        if (strcmp(s, temp->acno) == 0)
        {
          printf("your current balance is %d Rs\n", temp->bal);
          flag = 1;
          break;
        }
        temp = temp->next;
      }
      if (flag != 1)
        printf("Your account not found\n");
      break;

    case 4:        //Depositing money
      printf("Enter account number");
      scanf("%s", s);
      printf("Enter amount of money you want to deposite");
      scanf("%d", &m);
      temp = head;
      while (temp != NULL)
      {
        if (strcmp(s, temp->acno) == 0)
        {
          temp->bal = (temp->bal) + m;
          flag = 1;
          break;
        }
        temp = temp->next;
      }
      if (flag != 1)
        printf("Your account not found\n");
      break;

    case 5:       //Withdraw money
      printf("Enter account number");
      scanf("%s", s);
      printf("Enter amount of money you want to withdraw");
      scanf("%d", &m);
      temp = head;
      while (temp != NULL)
      {
        if (strcmp(s, temp->acno) == 0)
        {
          if (((temp->bal) - m) < 0)
          {
            printf("No such balance available\n");
            flag = 1;
            break;
          }
          else
          {
            temp->bal = (temp->bal) - m;
            break;
          }
        }
      }
      if (flag != 1)
        printf("Your account not found\n");
      break;

    case 6:    //Seeing all data
      temp = head;
      while (temp != NULL)
      {
        printf("%s %s %s %s %d\n", temp->acno, temp->name, temp->fname, temp->ad, temp->bal);
        temp = temp->next;
      }
      break;

    default:
      i = 0;
      printf("\n");
    }
    temp = head;
    //Updating of data file on each operation
    fp = fopen("bankdata.txt", "w");
    while (temp != NULL)
    {

      fprintf(fp, "%s|%s|%s|%s|%d\n", temp->acno, temp->name, temp->fname, temp->ad, temp->bal);

      temp = temp->next;
    }
    fclose(fp);
  }
}
