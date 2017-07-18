#include<stdio.h>
#include<conio.h>
#include "booksheader.h"
#include "user.h"

struct date
{
        
    int da_day;
    int da_mon;
    int da_year;

}d;


struct renew
{
        
        int uniqueID;
        struct date timeOfRenew;
        char bookID[20];
        char accno[20];

}r;


struct Transaction
{
       
    int uniqueTransactionID;
    char typeOfTransaction;     //books issuing to user or collecting returned
    struct date d;     //date month and year
    char bookID[20];
    char userId[10];
    int no_of_books;
    int no_of_items;
    int amounts_if_any;         //Amounts charged here must reflect in the transaction slip.

}T;


FILE *fpt,*fpu,*fpb,*fpm;
int records_no = 0;

void viewall();
void Issue();
void trans();
void fine();

/*void userloaned();
void return_book();
*/

main()
{
               int choice,count=1;
        
                 do
                 {
                      /* Display menu */ 
                      printf("\t\tTRANSACTIONS\n\n");

                      printf("1.View books\n\n");
                      printf("2.Issue books\n\n");
                      printf("3.Transaction\n\n");
                      printf("4.Loaned Book\n\n");
                      printf("5.Return Book\n\n");
                      printf("\t6. Calculoate Fine amount\n");
                      printf("7.Exit\n\n");           
                     
                      printf("\t\t\tEnter option: ");
                      scanf("%d",&choice);
                      
                      switch(choice)
                      {
                            case 1:  viewall();
                                     system("cls");
                                     break;
                            case 2:  Issue();
                                     system("cls");
                                     break;
                           case 3:
                                    trans();
                                    system("cls");
                                    break;
                            /*case 4:
                                userloaned();
                                system("cls");
                                break;
                            case 5:
                                return_book();
                                system("cls");
                                break;*/
                                case 6 : fine();
                                         break;
                                   case 7:
                                        break;
                                   default:
                                           printf("Wrong option entered...\n\n");
                                   
                      }
                 }while(choice != 6);      
}

void viewall()
{
     int i,j,cmp=1,length;
     char department[20],ch;char pathbackup[200];
    
     fflush(stdin);
     printf("\nEnter Department:");
     gets(department);
     fflush(stdin);
      
      printf("\n\tBook ID        Status        BOOKD ID\n");
      printf("\n\t-------        ------        --------\n");

     for(ch='A' ; ch <= 'Z' ; ch++)
      {
           char path[] = "D:\\Project\\LMSdb\\Books\\";
           
           strcpy(pathbackup,path);
           strcat(pathbackup,"\0");
           
           strcat(path,department);
           strcat(path,"\\");
           length=strlen(path);
           path[length]='\0';
           char str[]={'R',ch,'.','b','i','n','\0'};
           strcat(path,str);
           fpt = fopen(path,"rb+");
     
           if(fpt == NULL)
                  printf("Cannot open");
     
           fread(&records_no,sizeof(int),1,fpt);
           
           
           
                 for(i=0;fread(&B,sizeof(B),1,fpt)==1;i++)
                  {
                     printf("\n\t%s        %c        %s\n",B.location,B.status,B.bookId);
                     printf("\nLoaned To : %s\n",B.loanedTo);
                     /*printf("\nAuthor Name: %s\n",B.authorName);
                     printf("\nTITLE: %s\n",B.bookName);
                     printf("\ncost: %f\n",B.cost);
                     printf("\nDept: %s\n",B.department);
                     printf("\nedition: %d\n",B.edition);
                     printf("\nISBN: %s\n",B.ISBN);
                     printf("\nPublisher: %s\n",B.publisherName);*/   
                  }
       
       strcpy(path,pathbackup);
     
     }
     printf("\n");
     fclose(fpt);
     
     getch();
     
}
 
void Issue()
{
    char bid[20];
    char acc[20];
    int  flag=0,i,cmp1=0,j,x,count=0,count1=0;
    char booksIDs[50];
    

    system("cls");
    
    printf("\nSelectoption: \n");
    printf("\t\t1. Request Book \n"); 
    printf("\t\t2. Request Media \n");
    scanf("%d",&x);
    
    char path[] = "D:\\Project\\LMSdb\\Books\\";
    
    if(x==1)
    {
            system("cls");
           
            fflush(stdin);
            printf("\nEnter the book id for request : ");
            gets(T.bookID);
           
            fflush(stdin);
            printf("\nEnter your Account Number   :");
            gets(T.userId);
            
            strncat(path,T.bookID,3);
            strcat(path,"\\");
            char a[]={T.bookID[4],T.bookID[5],'.','b','i','n','\0'};
            strcat(path,a);
            printf("%s\n",path);
            
            fpt=fopen("D:\\Project\\LMSdb\\library\\transactions.bin","rb+");
                 
                    if(fpt == NULL)
                    {
                           fpt=fopen("D:\\Project\\LMSdb\\library\\transactions.bin","wb+");
                           fwrite(&records_no,sizeof(int),1,fpt);
                           
                           if(fpt == NULL)
                                  printf("Error in opening file\n\n");
                    }
            
            rewind(fpt);
            fread(&records_no,sizeof(int),1,fpt);
            
            records_no = records_no+1;
            rewind(fpt);
            fwrite(&records_no,sizeof(int),1,fpt);
            
            //printf("Records No = %d",records_no);
            //system("pause");
            
            fpu=fopen("D:\\Project\\LMSdb\\library\\user_data.bin","rb+");
            fpb=fopen(path,"rb+");
            
              if(fpu == NULL || fpb == NULL)
                 {
                   printf("Error in opening file\n\n");
                   exit(1);
                 }
            
            fread(&count,sizeof(int),1,fpu);
            fread(&count1,sizeof(int),1,fpb);
                        
            for(i=0;i<count1;i++)
            {
                  fread(&B,sizeof(B),1,fpb); 
                  
                  printf("\n%s\n",B.bookId);
                  
                  for(j=0;j<count;j++)
                  {
                      fread(&U,sizeof(U),1,fpu);
                      
                      if(!stricmp(U.AccountNo,T.userId))
                      {
                                                        
                        strcpy(B.loanedTo,T.userId);
                        B.status='L';
                        fseek(fpb,sizeof(int)+sizeof(B)*(count1-1),SEEK_SET);
                        fwrite(&B,sizeof(B),1,fpb);
                        
                        T.no_of_books=1;
                        T.no_of_items=0;
                        T.amounts_if_any=0;
                        
                        T.uniqueTransactionID = records_no;
                        T.typeOfTransaction = 'I';
                        
                        printf("\n Enter the Date : ");
                        scanf("%d",&T.d.da_day);
                        
                        printf("\n Enter the Date : ");
                        scanf("%d",&T.d.da_mon);
                        
                        printf("\n Enter the Date : ");
                        scanf("%d",&T.d.da_year);
              
                        fseek(fpt,sizeof(int)+sizeof(T)*(records_no-1),SEEK_SET);
                        fwrite(&T,sizeof(T),1,fpt);
                  
                        break;
                        getch();
                        
                      }
                  }
            }
            
            fclose(fpt);
            fclose(fpu);
            fclose(fpb);
            
    }
    
    else if(x==2)
    {
         printf("-- Code under Development\n");
    }
    
    else
       printf("Invalid Option\n\n");
       
       getch();
       
}

void trans()
{  
           int i;
           
           fpt=fopen("D:\\Project\\LMSdb\\library\\transactions.bin","rb+");
                 
                    if(fpt == NULL)
                    {
                        printf("\n\nError in opening file\n\n");
                        main();
                    }
            
            rewind(fpt);
            
            fread(&records_no,sizeof(int),1,fpt);
            
            for(i=0 ; fread(&T,sizeof(T),1,fpt)==1 ; i++)
            {                      
              printf("\n%d\t",T.uniqueTransactionID);
              printf("%c\t",T.typeOfTransaction);
              printf("%d\t",T.no_of_items);
              printf("%d\t",T.no_of_books);
              printf("%s\t",T.bookID);
              printf("\t%s",T.userId);
              
              printf("   %d-%d-%d",T.d.da_day,T.d.da_mon,T.d.da_year);
            }
            
            getch();
            fclose(fpt);
}

void fine()
{
             struct Transaction dummy;
             int t,days,fine_amount,i;
             fpt=fopen("D:\\Project\\LMSdb\\library\\transactions.bin","rb+");
                 
                    if(fpt == NULL)
                    {
                        printf("\n\nError in opening file\n\n");
                        main();
                    }
            
            rewind(fpt);
            
            printf("\nEnter the Transaction ID");
            scanf("%d",&t);
                        
            fread(&records_no,sizeof(int),1,fpt);
            
             for(i=0 ; fread(&T,sizeof(T),1,fpt)==1; i++)
            {                 
               if(t==T.uniqueTransactionID)
               { 
                                 
                        printf("\n Enter the Date Today : ");
                        scanf("%d",&dummy.d.da_day);
                        
                        printf("\n Enter the Date Today : ");
                        scanf("%d",&dummy.d.da_mon);
                        
                        printf("\n Enter the Date Today : ");
                        scanf("%d",&dummy.d.da_year);
                        
                       days = (dummy.d.da_year-T.d.da_year)*365+(dummy.d.da_mon-T.d.da_mon)*30+(dummy.d.da_day-T.d.da_day)*1;
                       
                       if(days<10)
                       {
                          fine_amount=100+(days-1)*5;
                          printf("Fine Amount = Rs. %d /-",fine_amount); 
                           
                       }
                       else
                          printf("Your Library Account has given Pink Slip\n");
                       break;
               }
              
            }
           
getch();
}
