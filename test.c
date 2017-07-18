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
   
   /*int loanedDate;
   int dueDate;
   char loanedTo[];*/

}B;                                             //You are free to define sizes and types of variables.

//------------------------------FUNCTION PROTOTYPES------------------------------//

void update_book();
void add_book();
void delete_book();
void unique_id();
void display();


//-------------------------------------GLOBAL VARIABLES-------------------------------------//

int records=0;    
FILE *fp;                              //Variable to store the details of a book at a particular index of the array

//-------------------------------------MAIN-------------------------------------//

main()
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
   case 5: exit(1);
           break;
   }
  }while(opt!=5);
  getch();
  
}

//---------------------------------FUNCTION TO ADD A BOOK-------------------------------//

void add_book()
{
     system("cls");
     char path[]="LMSdb\\Books\\";
     
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
                
                 fp=fopen(path,"a+b");
                
                  if(fp==NULL)
                    {
                       printf("error");
                       exit(0);
                       system("pause");
                    }
                
                fread(&records,sizeof(int),1,fp);
                records= records +1; 
                rewind(fp);
                fwrite(&records,sizeof(int),1,fp);
                fseek(fp,sizeof(int)+sizeof(B)*(records-1),SEEK_SET);
                            
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
                
                unique_id();
                printf("\nUnique ID Generated for the Book is   %s   \n",B.bookId);
                
                 fwrite(&B,sizeof(struct Book),1,fp);
                 fclose(fp);
                 
        getch();    
}

//---------------------------------GENERATE UNIQUE ID-------------------------------//

void unique_id()
{
     
    strcpy(B.bookId,B.department);
     
    char a[]={' ','R',B.bookName[0],' ',B.ISBN[6],B.ISBN[7],B.ISBN[8],'-','\0'};
    
    strcat(B.bookId,a);
     
    strncat(B.location,B.bookId,6);
    
     
    B.bookId[11] = (char)(B.edition+48);
    strcat(B.bookId," ");
    
    char s[]={'0','0',records+48,'\0'};
    
    strcat(B.bookId,s);

    if(s[2]=='9')
    {
            s[2]=0;
            s[1]=s[1]+1;
    }
    
    else
    {
            s[2]=s[2]+1;
    }

}

//---------------------------------UPDATE THE DETAILS OF THE BOOK-------------------------------//

/*void update_book()
{
char str[20];
int flag=0,i;
printf("\n\tEnter the Unique Id : ");
fflush(stdin);
gets(str);

  for(i=0;i<count;i++)
  {
    if(!strcmp(B[i].bookId,str))
    {
      printf("Enter the Publisher Name : ");
         gets(B[i].publisherName);
      printf("Enter Author Name : ");
         gets(B[i].authorName);
         fflush(stdin);
      printf("Enter Cost : ");
         scanf("%f",&B[i].cost);
         
         flag=1;
             break;
    }
  }
  
  if(flag==0)
    printf("\nID NOT FOUND\n"); 
    
    getch();
}

//---------------------------------DELETE THE RECORDS OF THE TABLE-------------------------------//

void delete_book()
{
char str[20];
int flag=0,i;
printf("\n\tEnter the Unique Id : ");
fflush(stdin);
gets(str);

  for(i=0;i<count;i++)
  {
    if(!strcmp(B[i].bookId,str))
    {
      B.authorName[0]='\0';
      B.bookId[0]='\0';
      B.bookName[0]='\0';
      B.cost=0;
      B.department[0]='\0';
      B.edition=0;
      B.ISBN[0]='\0';
      B.location[0]='\0';
      B.publisherName[0]='\0';
      B.status='\0';
         
         flag=1;
             break;
    }
  } 
  
  if(flag==0)
    printf("\n\n\tID doesnt Match\n"); 
    
    getch();
}*/
