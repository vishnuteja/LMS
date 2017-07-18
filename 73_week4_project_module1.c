#include<stdio.h>
#include<string.h>

struct Book
{
    char bookId[20];
    char bookName[50];
    char authorName[50];
    char publisherName[20];
    char ISBN[10];
    int edition;
    float cost;
    char department[5];
    char location[7];                           //department - Racno
    char status;                                //Available - Loaned - Requested - Hold
   
   /*int loanedDate;
   int dueDate;
   char loanedTo[];*/

}B[10];                                         //You are free to define sizes and types of variables.

//------------------------------FUNCTION PROTOTYPES------------------------------//

void update_book();
void add_book();
void delete_book();
void unique_id();
void display();


//-------------------------------------GLOBAL VARIABLES-------------------------------------//

int count=0;                                  //Variable to store the details of a book at a particular index of the array

//-------------------------------------MAIN-------------------------------------//

main()
{
  int opt;
  int i;
  
  for(i=0;i<10;i++)
  {
   B[i].status='A';                
  }
      
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
   case 2: update_book();
           break;
   case 3: delete_book();
           break;
   case 4: display();
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
         
        if(count<=10)
        {
                printf("\n\tBook Name : ");
                    fflush(stdin);
                gets(B[count].bookName);
                
                printf("\n\tAuthor Name : ");
                    fflush(stdin);
                gets(B[count].authorName);
            
                
                printf("\n\tPublisher Name : ");
                    fflush(stdin);
                gets(B[count].publisherName);
                
                
                printf("\n\tISBN : ");
                    fflush(stdin);
                gets(B[count].ISBN);
           
                
                printf("\n\tEdition : ");
                    fflush(stdin);
                scanf("%d",&B[count].edition);
            
                
                printf("\n\tCost : ");
                   fflush(stdin);
                scanf("%f",&B[count].cost);
             
                
                printf("\n\tDepartment : ");
                   fflush(stdin);
                gets(B[count].department);
                   fflush(stdin);
                
                unique_id();
                printf("\nUnique ID Generated for the Book is   %s   \n",B[count].bookId);
                
                count++;
        
        }
        
        else
            printf("\nNo slots available for a new book\n");
        
        getch();    
}

//---------------------------------GENERATE UNIQUE ID-------------------------------//

void unique_id()
{
     int i,flag=0;
     int a=0,b=0,c=0,total=0;
     strcpy(B[count].bookId,B[count].department);
     strcat(B[count].bookId," R");
     strncat(B[count].bookId,B[count].bookName,1);
     strcpy(B[count].location,B[count].bookId);
     
     for(i=6;i<=8;i++)
     {
      B[count].bookId[i]=B[count].ISBN[i];
     }
     
     strcat(B[count].bookId,"-");
     
     B[count].bookId[i+1]= (char)(B[count].edition+48);
     
     for(i=0;i<count;i++)
     {
       if(! strcmp(B[i].location,B[count].location) && ! strcmp(B[i].ISBN,B[count].ISBN))
       {
          a=(int)(B[i].bookId[13]-48);
          b=(int)(B[i].bookId[12]-48);
          c=(int)(B[i].bookId[11]-48);
          
          total = c*100+b*10+a;
          
            if(total < 9)
            {
           
              B[count].bookId[11]='0';
              B[count].bookId[12]='0';
              B[count].bookId[13]=(char)(total+1+48);
               flag=1;
            }
            
            else if(total < 99)
            {
              B[count].bookId[11]='0';
              B[count].bookId[12]=(char)((total/10)+48);
              B[count].bookId[13]=(char)((total%10)+1+48);
               flag=1;
            }
            
            else if(total < 999)
            {
              B[count].bookId[11]=(char)((total/100)+48);
              B[count].bookId[12]=(char)((total%100)/10+48);
              B[count].bookId[13]=(char)((total%100)+1+48);
               flag=1;
            }
          }
   }
   
     if(flag==0)
     {
         B[count].bookId[11]='0';
         B[count].bookId[12]='0';
         B[count].bookId[13]='1';                
     }
   
     B[count].bookId[14]='\0';
}

//---------------------------------UPDATE THE DETAILS OF THE BOOK-------------------------------//

void update_book()
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
       B[i].authorName[0]='\0';
       B[i].bookId[0]='\0';
       B[i].bookName[0]='\0';
       B[i].cost=0;
       B[i].department[0]='\0';
       B[i].edition=0;
       B[i].ISBN[0]='\0';
       B[i].location[0]='\0';
       B[i].publisherName[0]='\0';
       B[i].status='\0';
         
         flag=1;
             break;
    }
  } 
  
  if(flag==0)
    printf("\n\n\tID doesnt Match\n"); 
    
    getch();
}




//---------------------------------DISPLAY THE TABLE-------------------------------//

void display()
{
     int i=0;
     
  printf("Book ID\t\tBook Name\t\tAuthor\t\tPublisher\t\tISBN\t\tEdition\t\tCost\t\tDept\t\tStatus\t\tLocation\t\t\n");
  printf("-------\t\t---------\t\t------\t\t---------\t\t----\t\t-------\t\t----\t\t----\t\t------\t\t--------\t\t\n");
 
  for(i=0;i<count;i++)
  {
    printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%f\t\t%s\t\t%c\t\t%s\t\t\n",B[i].bookId,B[i].bookName,B[i].authorName,B[i].publisherName,B[i].ISBN,B[i].edition,B[i].cost,B[i].department,B[i].status,B[i].location);
  }
  
     getch();
}
