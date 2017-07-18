#include<stdio.h>

#include "user.h"
#include "arrivals.h"
#include "booksheader.h"
#include "mediaheader.h"
#include "depts.h"

main()
{
  char username[15],password[15];
  
  int i,flag=0,rec,option1,option2;
  
  FILE *ptr;
  
  ptr =fopen("LMSdb\\library\\users.bin","rb+");
                  
    if(ptr == NULL)
        exit(1);
        
    system("cls");
    system("color E");
    
          printf("\n\n\t\t +-+-+-+---------------------------+-+-+-+\n");                                                                                   /* Display menu */ 
          printf("\t\t||-+-+-+- INSPIRING MINDS LIBRARY -+-+-+-||\n");
          printf("\t\t +-+-+-+---------------------------+-+-+-+\n\n");
          
          printf("\t\t\tEnter the Login Details . . \n\n");
       
       
       fflush(stdin);
    printf("\n\n\t\tUsername      :  ");
       gets(username);
       
       fflush(stdin);
    printf("\t\tPassword      :  ");

          for(i=0;i<15;i++)
           {
                      password[i]=getch();
                      if(password[i]==13)
                      {
                      password[i]='\0'; break; 
                      }
                      printf("*"); 
           }
           
           password[i]='\0';

  fread(&rec,sizeof(int),1,ptr);
  
  for(i=0 ; i<rec ; i++)
  {

   fread(&U,sizeof(U),1,ptr);
   
   if( !(strcmp(U.username,username)) && !(strcmp(U.password,password)))
     {

        printf("\n\t USER authenticated\n");  
        
        if(! strcmp(U.Role,"admin"))
          flag = 1;
        
        else if(! strcmp(U.Role,"student"))
          flag = 2;
        
        break;
     }
  }
  
  fclose(ptr);
   
if(flag == 1)
 {
           do
           {
            system("cls");
            system("color C");
            printf("\t\t\t\tWelcome, %s \n\n",U.username);
                                
                                 /* Display menu for admin*/ 
            printf("\t\t||-+-+-+-    ADMINISTRATOR MENU   -+-+-+-||\n");
            printf("\t\t +-+-+-+---------------------------+-+-+-+\n\n");
            printf("\t1. Department Menu \n");
            printf("\n\t2. Book Menu \n");
            printf("\n\t3. New Arrivals Menu \n");
            printf("\n\t4. Media Menu \n");
            printf("\n\t5. User Menu \n");
            printf("\n\t6. Library Function Menu \n");
            printf("\n\t7. LOG OFF \n");
            printf("\n\t\t0.Exit\n");
            
            printf("\n\t\t\tEnter Option --> ");
            scanf("%d",&option1);
            
                switch(option1)
                  {
                       case 1 :  depart();
                                 break;
                       
                       case 2 :  books();
                                 break;
                                 
                       case 3 :  arrivals();
                                 break;
                       
                       case 4 :  media_menu();
                                 break;
                       
                       case 5 :  user();
                                 break;
                       
                       case 6 :  
                       
                       case 7 :  printf("Bye, %s .. Have a Nice Day",username);
                                 
                                 system("pause");
                                 
                                 main();
                                 
                                 break;
                       
                       case 0 :  break;
                       
                       default : printf("\n\tInvalid Option\n");
                                 break; 
                   }
            
           }while(option1!=0);
}  
  
 else if(flag == 2)
 {
       do
       {
            system("cls");
            printf("\t\tWelcome, %s\n\n",U.username);
            printf("\n\n");
                             /* Display menu for normal user*/
            printf("\t\t        ||-+-+-+-    MENU  -+-+-+-||\n");
            printf("\t\t +-+-+-+---------------------------+-+-+-+\n\n");
            
            printf("\t1. Search for a book\n");
            printf("\t2. Books loaned by You \n");
            printf("\t3. Renew a book \n");
            printf("\t4. Endorse a temporary Book \n");
            printf("\t5. Log Off \n");
            printf("\t\t0.Exit\n");
            
            printf("\nEnter Option\n");
            scanf("%d",&option2);

                 switch(option2)
                  {
                       case 1 :  search();
                                 break;
                                 
                       case 2 :  
                            
                       case 3 :  
                            
                       case 4 :  endorsements();
                                 break;
                                 
                       case 5 :  printf("Bye, %s .. Have a Nice Day",username);
                                 
                                 system("pause");
                                 
                                 main();
                                 
                                 break;
                            
                       case 0 :  break;
                       
                       default : printf("\n\tInvalid Option\n");
                                 break;
                  }
            
       }while(option2!=0);
 }
  
 else
 {
    printf("\n Invalid User \n");
    system("pause");
    system("cls");
    main();
 }
 
getch();
}
