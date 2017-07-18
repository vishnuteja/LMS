#include<stdio.h>
#include<string.h>

struct Book
{
    char bookId[20];
    char bookName[50];
    char authorName[50];
    char publisherName[20];
    char ISBN[10];
    int  edition;
    float cost;
    char department[5];
    char location[7];                           //department - Racno
    char status;                                //Available - Loaned - Requested - Hold
   
    char loanedDate[100];
    int dueDate;
    char loanedTo[100];

}B,TE;                                             //You are free to define sizes and types of variables.

//------------------------------FUNCTION PROTOTYPES------------------------------//

void update_book();
void add_book();
void delete_book();
char* unique_id(char []);
void display();
void search();

//-------------------------------------GLOBAL VARIABLES-------------------------------------//

int re=0;    
FILE *fp;                              //Variable to store the details of a book at a particular index of the array

//-------------------------------------MAIN-------------------------------------//

books()
{
  int opt;
  int i;

      
 do
  {
   system("cls");
   system("COLOR F1");
   printf("\n\t^-_-^-_-^-_-^-_-^-_-\n\t\tMENU\n\t^-_-^-_-^-_-^-_-^-_-\n");
   printf("\n\t1.ADD BOOK\n\n\t2.UPDATE BOOK\n\n\t3.DELETE BOOK\n\n\t4.DISPLAY\n\n\t5.EXIT\n");
   printf("\n\t\tEnter option");
   scanf("%d",&opt);
   system("cls");
   
   switch(opt)
   {
   case 1: add_book();
           break;
   case 2: //update_book();
           break;
   case 3: //delete_book();
           break;
   case 4: //display();
           break;
   case 5: 
           break;
   }
  }while(opt!=5);
  getch();
  
}

//---------------------------------FUNCTION TO ADD A BOOK-------------------------------//

void add_book()
{
     system("cls");
     
     char path[]="D:\\Project\\LMSdb\\Books\\";
     
                printf("\n\nEnter the Book details \n");
                
                printf("\n\tBook Name : ");
                    fflush(stdin);
                gets(B.bookName);
                    strupr(B.bookName);    
                
                printf("\n\tDepartment : ");
                   fflush(stdin);
                gets(B.department);
                strupr(B.department);
                   fflush(stdin);
               
                char r[]={'R',B.bookName[0],'.','b','i','n','\0'};
                
                 strcat(path,B.department);
                 strcat(path,"\\");
                 strcat(path,r);
                
                 fp=fopen(path,"rb+");
                
                  if(fp == NULL)
                    {
                       printf("error");
                       system("pause");
                       exit(0);
                    }
                
                fclose(fp);           

                printf("\n\tAuthor Name : ");
                    fflush(stdin);
                gets(B.authorName);
            
                
                printf("\n\tPublisher Name : ");
                    fflush(stdin);
                gets(B.publisherName);
                
                printf("\n\tISBN : ");
                    fflush(stdin);
                gets(B.ISBN);
           
                
                printf("\n\tEdition : ");
                    fflush(stdin);
                scanf("%d",&B.edition);
            
                
                printf("\n\tCost : ");
                   fflush(stdin);
                scanf("%f",&B.cost);
                
                fflush(stdin);
                
                B.status='A';
                
                unique_id(path);
 
                printf("\nUnique ID Generated for the Book is   %s   \n",B.bookId);

                
        getch();    
}

//---------------------------------GENERATE UNIQUE ID-------------------------------//

char* unique_id(char x[])
{
    int count=0,i,a,b,c,total,flag=0,flag2=0;
    
    FILE *ptr;
    
    strcpy(B.bookId,B.department);
     
    char A[]={' ','R',B.bookName[0],' ',B.ISBN[6],B.ISBN[7],B.ISBN[8],'-','\0'};
    
    strcat(B.bookId,A);
        
    B.bookId[11] = (char)(B.edition+48);
    
    strcat(B.bookId," ");
    
    ptr=fopen(x,"rb+");
     
                for(i=0;fread(&count,sizeof(int),1,fp)==1;i++)
                      flag2=1;
                
                if(flag2==0)
                {
                  fwrite(&count,sizeof(int),1,fp);
                }
                
                rewind(ptr);    
                
                fread(&count,sizeof(int),1,ptr);
                
                count=count+1; 
                
                rewind(ptr);
                
                fwrite(&count,sizeof(int),1,ptr);
                
    printf("Count of Records = %d",count);
    
    for(i=0;i<count;i++)
     {
      
      fread(&TE,sizeof(TE),1,ptr);
       
       if(!strcmp(B.ISBN,TE.ISBN))
       {
          a=(int)(TE.bookId[12]-48);
          b=(int)(TE.bookId[13]-48);
          c=(int)(TE.bookId[14]-48);
          
          total = a*100+b*10+c;
          
            if(total < 9)
            {
              B.bookId[12]='0';
              B.bookId[13]='0';
              B.bookId[14]=(char)(total+1+48);
               flag=1;
            }
            
            else if(total < 99)
            {
              B.bookId[12]='0';
              B.bookId[13]=(char)((total/10)+48);
              B.bookId[14]=(char)((total%10)+1+48);
               flag=1;
            }
            
            else if(total < 999)
            {
              B.bookId[12]=(char)((total/100)+48);
              B.bookId[13]=(char)((total%100)/10+48);
              B.bookId[14]=(char)((total%100)+1+48);
               flag=1;
            }
          }
   }
   
     if(flag==0)
     {
         B.bookId[12]='0';
         B.bookId[13]='0';
         B.bookId[14]='1';                
     }
   
     B.bookId[15]='\0';
     
     strncpy(B.location,B.bookId,6);
     
     fseek(ptr,-sizeof(B),SEEK_CUR);
     fwrite(&B,sizeof(B),1,ptr);
     
     fclose(ptr);
     
}

//--------------------------------- SEARCH FOR A BOOK -------------------------------//

void search()
{
    FILE *fp;
    char path[100];
    char b_name[20];
    char dept[3];
    int i,recd=0;
   
    printf("\t\tSEARCHING A BOOK\n");
    printf("\nEnter the depatrtment\n");
    fflush(stdin);
    gets(dept);
   
    printf("\nEnter The Book Name:\n");
    fflush(stdin);
    gets(b_name);
    strupr(b_name);
   
   
    
    strcpy(path,"D:\\Project\\LMSdb\\Books\\");
    char a[]={'R',b_name[0],'.','b','i','n','\0'};
   
    strcat(path,dept);
    strcat(path,"\\");
    strcat(path,a);
   
    fp=fopen(path,"r+b");
    if(fp==NULL)
    {
        printf("error\n");
        system("pause");
        exit(0);
    }
    
    fread(&recd,sizeof(int),1,fp);
   
    for(i=0;fread(&B,sizeof(B),1,fp);i++)
    {
        if(strcmp(B.bookName,b_name)==0)
        {
             printf("\nBook Id         :%s",B.bookId);
             printf("\nBook Name       :%s",B.bookName);
             printf("\ndepartment      :%s",B.department);
             printf("\nAuthor Name     :%s",B.authorName);
             printf("\nPublisher Name  :%s",B.publisherName);
             printf("\nCost            :%f",B.cost);
             printf("\nEdition         :%d",B.edition);
             printf("\nISBN            :%s",B.ISBN);
        }
    }
    fclose(fp);
getch();
}

//--------------------------------- UPDATE BOOK -------------------------------//

/*void update_book()
{
     int i,flag =0,temp=0;
     char ID[15];
     char path[]="LMSdb\\Books\\";
     printf("Enter book Id:");
     gets(ID);
     strncat(path,ID,3);
     strcat(path,"\\");
     
     char ch[] = {ID[4],ID[5],'.','b','i','n','\0'};
     strcat(path,ch);
     
     f=fopen(path,"rb+");
                
     if(f==NULL)
     {
           printf("error in opening file");
           system("pause");
     }
     
     else
     {
          fread(&R,sizeof(int),1,f);
                
          for(i=0;i<R;i++)
          {
                     fread(&B,sizeof(B),1,f);
                     if(!stricmp(B.bookId,ID))
                     {
                                printf("Enter book name: ");
                                gets(B.bookName);
                                fflush(stdin);
                                printf("Enter author name: ");
                                gets(B.authorName);
                                fflush(stdin);
                                printf("Enter publisher name: ");
                                gets(B.publisherName);
                                printf("Enter ISBN code: ");
                                gets(B.ISBN);
                                printf("Enter Edition Number: ");
                                scanf("%d",&B.edition);
                                printf("Enter cost of the book: ");
                                scanf("%f",&B.cost);
                                fflush(stdin);
                                printf("Enter Department: ");
                                gets(B.department);
                                //unique_id(path);
                                fseek(f,sizeof(int)+sizeof(B)*i,SEEK_SET);
                                fwrite(&B,sizeof(B),1,f);
                                
                                printf("Updated\n\n");
                                flag = 1;
                                break;
                     }           
     } 
     if(flag == 0)
             printf("Invalid book ID\n\n");
  }*/
