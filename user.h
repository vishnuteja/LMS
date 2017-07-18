//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>        VISHNU TEJA T        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<          IIIT- 73           <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>         MODULE # 5          >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    
                                    #include<stdio.h>
                                    #include<conio.h>
                                    #include<string.h>
                                    #include<stdlib.h>
                                    #include<dir.h>


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>        STRUCTURE DECLARATIONS      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

struct UserData
{

    char AccountNo[10];
    char FullName[30];
    int  RollNumber;
    char Address[30];
    char phoneNumber[15];
    char emailAddress[15];
    char gender;
    char dob[8];

} UD;

struct User
{

    char AccountNo[10];
    char username[15];
    char password[15];
    char Role[15];
    int no_of_books_taken;
    int no_of_items_taken;
    float total_amount_due;

} U;


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>       FUNCTION PROTOTYPES         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


                                    void    add_user();
                                    void    update_user();
                                    void    del_user();
                                    void    disp_userdetails();
                                    void    disp_user();


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       GLOBAL VARIABLES      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


                                    FILE *fp3;
                                    int records=0,records1=0;


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       MAIN FUNCTION        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

user()
{
    int option4;

    system("color 4f");
    
    do
    {
          system("cls");        
          printf("\n\n\t\t +-+-+-+---------------------------+-+-+-+\n");                                                                                   /* Display menu */ 
          printf("\t\t||-+-+-+-       User Accounts     -+-+-+-||\n");
          printf("\t\t +-+-+-+---------------------------+-+-+-+\n\n");
          printf("\t\t\t1. Add USER\n\n");
          printf("\t\t\t2. Update USER\n\n");
          printf("\t\t\t3. Delete USER\n\n");
          printf("\t\t\t4. Display USERS PERSONAL DETAILS \n\n");
          printf("\t\t\t5. Display USERS\n\n");
          printf("\t\t\t0. Exit\n\n");
          
          printf("\n\n\t\t\t\tEnter required option: ");
          
          scanf("%d",&option4);
          fflush(stdin);
          system("cls");              


              switch(option4)
              {
                    case 1:                      
                            add_user();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 2:                      
                            update_user();
                            fflush(stdin);
                            getch();              
                            system("cls");   
                            break;
                    case 3:                      
                            del_user();
                            fflush(stdin);
                            getch();
                            system("cls");   
                            break;
                    case 4:                      
                            disp_userdetails();
                            fflush(stdin);
                            getch();
                            system("cls");   
                            break; 
                    case 5:                      
                            disp_user();
                            fflush(stdin);
                            getch();
                            system("cls");   
                            break; 
                    
                    case 0: break;
                            
                   default: printf("Wrong option entered");
              }

          }while(option4 != 0);
      
      getch();
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>              ADD NEW USERS           >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


void add_user()                                   
{
 int i;
                   fp3=fopen("LMSdb\\library\\user_data.bin","r+b");                             //OPEN FILE
                      {
                        if(fp3==NULL)
                        {
                           fp3=fopen("LMSdb\\library\\user_data.bin","w+b");
                        }
                      }  
     
      fread(&records,sizeof(int),1,fp3);                                                         //READ HEADER PART
      records= records +1; 
      rewind(fp3);
      fwrite(&records, sizeof(int),1,fp3);
    
                 printf("\tEnter Personal Details ....... \n");
                 
                 fflush(stdin);
                 printf("\nFULL NAME : ");
                 gets(UD.FullName);
                 
                 fflush(stdin);
                 printf("\nRoll No : ");
                 scanf("%d",&UD.RollNumber);
                 
                 fflush(stdin);
                 printf("\nADDRESS : ");
                 gets(UD.Address);
                 
                 fflush(stdin);
                 printf("\nPHONE NUMBER: ");
                 gets(UD.phoneNumber);
                 
                 fflush(stdin);
                 printf("\nEmail Address : ");
                 gets(UD.emailAddress);
                 
                 fflush(stdin);
                 printf("\nGENDER : ");
                 scanf("%c",&UD.gender);
                 
                 fflush(stdin);
                 printf("\nDate of Birth (DD-MM-YY) : ");
                 gets(UD.dob);
                 fflush(stdin);
                 
                 UD.AccountNo[0]='\0';
                
                 char gen_user[]={'M','S','I','T','0','0',records+48,'\0'};                      // GENERATE USER ID
                 
                 strcpy(UD.AccountNo,gen_user);
                 
                  fseek(fp3,sizeof(int)+sizeof(UD)*(records-1),SEEK_SET);
                  fwrite(&UD,sizeof(UD),1,fp3);
                
                  fclose(fp3);
                
      fp3=fopen("LMSdb\\library\\users.bin","r+b");                                              //OPEN FILE
      {
        if(fp3==NULL)
        {
           fp3=fopen("LMSdb\\library\\users.bin","w+b");
        }
      }                                          
      
                            
      fread(&records1,sizeof(int),1,fp3);                                                        //READ HEADER PART
      records1= records1 +1;
      rewind(fp3);
      fwrite(&records1, sizeof(int),1,fp3);
         
                    
                strcpy(U.AccountNo,UD.AccountNo);
                
                printf("\n\tEnter Account Details ....... \n");
                
                fflush(stdin);               
                printf("\nEnter the USER NAME : ");
                gets(U.username);
                
                fflush(stdin);
                printf("\nEnter the PASS WORD : ");
                 
                 for(i=0;i<15;i++)
                   {
                      U.password[i]=getch();
                      if(U.password[i]==13)
                      {
                      U.password[i]='\0'; break; 
                      }
                      printf("*"); 
                   }
                
                fflush(stdin);
                printf("\nEnter the ROLE : ");
                gets(U.Role);
                fflush(stdin);
             
                    fseek(fp3,sizeof(int)+sizeof(U)*(records1-1),SEEK_SET);
                    fwrite(&U,sizeof(U),1,fp3);
               
               fclose(fp3);
                                  
getch();

}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>                 UPDATE USER           >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 
void update_user()
{
     char id[30],i;
     int  flag=0;
     system("cls");      
      
                                 fp3=fopen("LMSdb\\library\\user_data.bin","r+b");
                             
                                 if(fp3==NULL)
                                 {
                                   printf("\nERROR : Unable to Open File ... \n");
                                   getch();
                                   exit(1);
                                 }
     
     fread(&records,sizeof(int),1,fp3);
      
     printf("Enter the Account number :");
     fflush(stdin);
     gets(id);
     
     
     for(i=0; i<records; i++)
     {
        fread(&UD,sizeof(UD),1,fp3);
        
        if(!strcmp(id,UD.AccountNo))
        {    
            flag=1;
            
            printf("\tEnter Details to modify \n\n");
            printf("New Address: ");
            fflush(stdin);
            gets(UD.Address);
            
            printf("New Phone number :");
            fflush(stdin);
            gets(UD.phoneNumber);
            
            printf(" New Email Address: ");
            fflush(stdin);
            gets(UD.emailAddress); 

            fseek(fp3,sizeof(int)+sizeof(UD)*(i),SEEK_SET);
            fwrite(&UD,sizeof(UD),1,fp3); 
            break;
                
        }
     }
     
     if(flag==0)
       {
      printf("ERROR : User doesnt exist ... Invalid USER ID \n");
       }

    fclose(fp3);
    
    fp3=fopen("LMSdb\\library\\users.bin","r+b");
 
     fread(&records1,sizeof(int),1,fp3);
      
     
     for(i=0; i<records1; i++)
     {
        fread(&U,sizeof(U),1,fp3);
        
        if(!strcmp(id,UD.AccountNo))
        {    
            printf("New User Name: ");
            fflush(stdin);
            gets(U.username);
            
            printf("New Password :");
            fflush(stdin);
            gets(U.password);

            fseek(fp3,sizeof(int)+sizeof(U)*(i),SEEK_SET);
            
            fwrite(&U,sizeof(U),1,fp3); 
            
            break;        
        }
     }
    
    fclose(fp3);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>               DELETE USER           >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void del_user()
{
     FILE *fp4;
     
                                 fp3=fopen("LMSdb\\library\\user_data.bin","r+b");
                             
                                 if(fp3==NULL)
                                 {
                                   printf("\nERROR : Unable to Open File ... \n");
                                   getch();
                                   exit(1);
                                 }
                                 
                                 fp4=fopen("LMSdb\\library\\temp1.bin","w+b");
                                 
     int i;
     char ID[20];
     printf("Enter Account ID :");
     gets(ID);
          
     fread (&records,sizeof(int),1,fp3);  
     fwrite(&records,sizeof(int),1,fp4);
     
     for(i=0; fread(&UD,sizeof(UD),1,fp3) == 1 ; i++)
     {
                   if(!stricmp(ID,UD.AccountNo))
                   {
                             records = records - 1;
                             rewind(fp4);
                             fwrite(&records, sizeof(int), 1, fp4);
                             fseek(fp4,sizeof(int)+sizeof(UD)*(i),SEEK_SET);
                   }
                   
                    else
                    {
                       
                        fwrite(&UD,sizeof(UD),1,fp4);
                    }
     }
     
         fclose (fp3) ;
         fclose (fp4) ;
         remove("LMSdb\\library\\user_data.bin");
         rename("LMSdb\\library\\temp1.bin","LMSdb\\library\\user_data.bin");

         
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
         
           fp3=fopen("LMSdb\\library\\users.bin","r+b");
                             
                                 if(fp3==NULL)
                                 {
                                   printf("\nERROR : Unable to Open File ... \n");
                                   getch();
                                   exit(1);
                                 }
                                 
                                 fp4=fopen("LMSdb\\library\\temp2.bin","w+b");
     
     fread (&records1,sizeof(int),1,fp3);  
     fwrite(&records1,sizeof(int),1,fp4);
     
     for(i=0; fread(&U,sizeof(U),1,fp3) == 1 ; i++)
     {
                   if(!stricmp(ID,U.AccountNo))
                   {
                             records1 = records1 - 1;
                             rewind(fp4);
                             fwrite(&records1, sizeof(int), 1, fp4);
                             fseek(fp4,sizeof(int)+sizeof(U)*(i),SEEK_SET);
                   }
                   
                    else
                    {
                       
                        fwrite(&U,sizeof(U),1,fp4);
                    }
     }
     
         fclose (fp3) ;
         fclose (fp4) ;
         remove("LMSdb\\library\\users.bin");
         rename("LMSdb\\library\\temp2.bin","LMSdb\\library\\users.bin");
         
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>            DISPLAY USER DETAILS       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void disp_userdetails()
{
                   int i;
                                      fp3 = fopen("LMSdb\\library\\user_data.bin","rb+");
                                      
                                      if(fp3 == NULL)
                                      {
                                                  printf("Unable to open file\n");
                                      }
     
     
     fread(&records,sizeof(int),1,fp3);
     printf("No.of records = %d\n\n",records);
     
     
     printf("User Id \t Address \t DOB \t FULL NAME \t EMAIL \t GENDER \tPHONE NUMBER \t Roll No\n\n");
     printf("__________________________________________________________________________________\n\n");          
     
     for(i=0;i<records;i++)
     {
         fread(&UD,sizeof(UD),1,fp3);
         printf("\n%s\t\t",UD.AccountNo);
         printf("%s\t\t",UD.Address);
         printf("%s\t\t",UD.dob);
         printf("%s\t\t",UD.FullName);
         printf("%s\t\t",UD.emailAddress);
         printf("%c\t\t",UD.gender);
         printf("%s\t\t",UD.phoneNumber);
         printf("%d\t\n",UD.RollNumber);
     }

     fclose(fp3);
     getch();
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>            DISPLAY USER DETAILS       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void disp_user()
{
                int i;
     
     
                                    fp3 =fopen("LMSdb\\library\\users.bin","rb+");
                                      
                                      if(fp3 == NULL)
                                      {
                                        printf("Unable to open file\n");
                                      }    
     
     fread(&records1,sizeof(int),1,fp3);
     printf("No.of records = %d\n\n",records);
     
     printf("Account No \t Role\t USER NAME \t PASSWORD\n");
     printf("__________________________________________\n\n");     
    
     for(i=0 ; i<records1 ; i++)
     {
       
        fread(&U,sizeof(U),1,fp3);
        
        printf("%s\t\t%s\t\t%s\t%s\n",U.AccountNo,U.Role,U.username,U.password);
     
     }

     fclose(fp3);
}
