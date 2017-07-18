#include<stdio.h>
#include<conio.h>
#include "71_M1.h"
#include "71_M3.h"
#include "71_M5.h"

typedef struct 
{
    int da_day;
    int da_mon;
    int da_year;
}date;

typedef struct
{
        int uniqueID;
        date timeOfRenew;
        char bookID[20];
        char accno[20];
}renew;


struct Transaction{
    int uniqueTransactionID;
    char typeOfTransaction; //books issuing to user or collecting returned
    date timeOfTransaction; //date month and year
    char bookID[20];
    char userId[10];
    int no_of_books;
    int no_of_items;
    int amounts_if_any; //Amounts charged here must reflect in the transaction slip.
}T;

date d;
renew r;
FILE *fpt,*fpu,*fpb,*fpm;
int records_no = 0;

void viewall();
void request();
/*void userloaned();
void trans();
void Issue();
void return_book();
*/
Func_Menu()
{
                  int choice,count=1;
                 do
                 {
                      /* Display menu */ 
                      printf("\t\t******** Library Management System *********\n\n");
                      printf("\t\t1.View books\n");
                      printf("\t\t2.Issue books\n");
                      printf("\t\t3.Transaction\n");
                      printf("\t\t4.Loaned Book\n");
                      printf("\t\t5.Return Book\n");
                      printf("\t\t6.Exit\n\n");           
                     
                      printf("\t\tEnter requiured option: ");
                      scanf("%d",&choice);
                      switch(choice)
                      {
                                   case 1:
                                        viewall();
                                        system("cls");
                                        break;
                                   /*case 2:
                                         Issue();
                                         system("cls");
                                         break;
                                   case 3:
                                        trans();
                                        system("cls");
                                        break;
                                   case 4:
                                        userloaned();
                                        system("cls");
                                        break;
                                   case 5:
                                        return_book();
                                        system("cls");
                                        break;*/
                                   case 6:
                                        break;
                                   default:
                                           printf("Wrong option entered...\n\n");
                                   
                      }
                 }while(choice != 6);      
}

void viewall()
{
     int i,j,cmp=1;
     char department[20],ch;
     char path[] = "LMSdb\\Books\\";
     fflush(stdin);
     printf("\nEnter Department:");
     gets(department);
     fflush(stdin);
     
     strcat(path,department);
     
     for(ch='A';ch <= 'Z';ch++)
     {
           char str[]={'R',ch,'.','b','i','n','\0'};
           strcat(path,str);
           fpt = fopen(path,"rb+");
     
           if(fpt == NULL)
                  printf("Cannot open");
     
           for(i=0;fread(&B,sizeof(B),1,fpt)==1;i++)
           {
                 printf("\nBook ID: %s\n",B.bookId);
                 printf("\nStatus: %c\n",B.status);
           }
     }
     fclose(fpt);
     

     printf("Do you want to request book:");
     scanf("%d",&i);
     if(i==1)
     request();
}
 
void request()
{
    char bid[20];
    char acc[20];
    int flag=0,i,cmp1=0,j,x,count=0;
    char booksIDs[100];
    
    printf("\nSelect the required option: \n");
    printf("1. Request Book \n"); 
    printf("2. Request Media \n");
    scanf("%d",&x);

    if(x==1)
    {
            system("cls");
            fflush(stdin);
            printf("Enter the book id for request: ");
            gets(T.bookID); 
            fflush(stdin);
            printf("\nEnter your Account  number"); fflush(stdin);
            gets(T.userId);   
            
            fpt=fopen("D:\\LMSdb\\library\\transcations.bin","rb+");
            if(fpt == NULL)
            {
                   fpt=fopen("D:\\LMSdb\\library\\transcations.bin","wb+");
                   fwrite(&records_no,sizeof(int),1,fpt);
                   if(fpt == NULL)
                          printf("Error in opening file\n\n");
            }
            
            rewind(fpt);
            fread(&records_no,sizeof(int),1,fpt);
            
            records_no = records_no+1;
            rewind(fpt);
            fwrite(&records_no,sizeof(int),1,fpt);
            
            
            fpu=fopen("D:\\LMSdb\\library\\user_details.bin","rb+");
                       
            if(fpu == NULL)
                   printf("Error in opening file\n\n");
            
            fread(&count,sizeof(int),1,fpu);
                        
            for(i=0;i<count;i++)
            {
                  fread(&U1,sizeof(U1),1,fpu); 
                  if(!stricmp(U1.username,T.userId))
                  {
                            U1.no_of_books_taken = U1.no_of_books_taken+1;
                            fseek(fpu,sizeof(int)+sizeof(U1)*(count-1),SEEK_SET);
                            fwrite(&U1,sizeof(U1),1,fpu);
                            T.no_of_books = U1.no_of_books_taken;
                            T.no_of_items = U1.no_of_items_taken;
                            T.amounts_if_any = U1.total_amount_due;
                            T.uniqueTransactionID = records_no;
                            T.typeOfTransaction = 'R';
                            fseek(fpt,sizeof(int)+sizeof(T)*(records_no-1),SEEK_SET);
                            fwrite(&T,sizeof(T),1,fpt);
                            break;
                  }
            }
            fclose(fpt);
            fclose(fpu);
            
    }
    else if(x==2)
    {
         system("cls");
            fflush(stdin);
            printf("Enter the Media Id for request: ");
            gets(T.bookID); 
            fflush(stdin);
            printf("\nEnter your Account  number"); fflush(stdin);
            gets(T.userId);   
            
            fpt=fopen("D:\\LMSdb\\library\\transcations.bin","rb+");
            if(fpt == NULL)
            {
                   fpt=fopen("D:\\LMSdb\\library\\transcations.bin","wb+");
                   fwrite(&records_no,sizeof(int),1,fpt);
                   if(fpt == NULL)
                          printf("Error in opening file\n\n");
            }
            
            rewind(fpt);
            fread(&records_no,sizeof(int),1,fpt);
            
            records_no = records_no+1;
            rewind(fpt);
            fwrite(&records_no,sizeof(int),1,fpt);
            
            
            fpu=fopen("D:\\LMSdb\\library\\user_details.bin","rb+");
                       
            if(fpu == NULL)
                   printf("Error in opening file\n\n");
            
            fread(&count,sizeof(int),1,fpu);
                        
            for(i=0;i<count;i++)
            {
                  fread(&U1,sizeof(U1),1,fpu); 
                  if(!stricmp(U1.username,T.userId))
                  {
                            U1.no_of_items_taken = U1.no_of_items_taken+1;
                            fseek(fpu,sizeof(int)+sizeof(U1)*(count-1),SEEK_SET);
                            fwrite(&U1,sizeof(U1),1,fpu);
                            T.no_of_books = U1.no_of_books_taken;
                            T.no_of_items = U1.no_of_items_taken;
                            T.amounts_if_any = U1.total_amount_due;
                            T.uniqueTransactionID = records_no;
                            T.typeOfTransaction = 'R';
                            fseek(fpt,sizeof(int)+sizeof(T)*(records_no-1),SEEK_SET);
                            fwrite(&T,sizeof(T),1,fpt);
                            break;
                  }
            }
            fclose(fpt);
            fclose(fpu);
    }
    else
       printf("Invalid Option\n\n");
       
}

           
    
     
