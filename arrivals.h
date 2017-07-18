//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>        VISHNU TEJA T        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<          IIIT- 73           <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>         MODULE # 4          >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


                                #include<stdio.h>
                                #include<conio.h>
                                #include<string.h>
                                #include<stdlib.h>
                                #include<dir.h>


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>        STRUCTURE DECLARATIONS      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


                                struct Custody
                                {
                                    char temporaryId[20];
                                    char bookName[30];
                                    char author[30];
                                    char publisher[30];
                                    char ISBN[15];
                                    int edition;
                                    float cost;
                                    int no_of_time_voted;
                                }C;


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>       FUNCTION PROTOTYPES         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


                                    void    add_tempbook();
                                    void update_tempbook();
                                    void    del_tempbook();
                                    void    display_temp();
                                    void    endorsements();


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       GLOBAL VARIABLES      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


                                    FILE *fp2;
                                    int rec2=0;


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       MAIN FUNCTION        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


arrivals()
{
      int option3;

    system("color 4f");
    
    do
    {

          printf("\n\n\t\t +-+-+-+---------------------------+-+-+-+\n");                                                                                   /* Display menu */ 
          printf("\t\t||-+-+-+- NEW ARRIVALS MGMT SYSTEM-+-+-+-||\n");
          printf("\t\t +-+-+-+---------------------------+-+-+-+\n\n");
          printf("\t\t1. Add a temp book in library\n\n");
          printf("\t\t2. Update temp book details in library\n\n");
          printf("\t\t3. Delete a temp book\n\n");
          printf("\t\t4. Show the list of temp books in library\n\n");
          printf("\t\t0. Exit\n\n");
          printf("\n\n\t\t\t\tEnter requiured option: ");
          scanf("%d",&option3);
          fflush(stdin);
          system("cls");                
         
          fp2 =fopen("LMSdb\\custodybooks.bin","rb+");
          if(fp2 == NULL)
          {
                  fp2 =fopen("LMSdb\\custodybooks.bin","wb+");
                  fwrite(&rec2,sizeof(int),1,fp2);
                  if(fp2 == NULL)
                        printf("Unable to open file\n");
          }    
         

              switch(option3)
              {
                    case 1:                      
                            add_tempbook();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 2:                      
                            update_tempbook();
                            fflush(stdin);
                            getch();              
                            system("cls");   
                            break;
                    case 3:                      
                            del_tempbook();
                            fflush(stdin);
                            getch();
                            system("cls");   
                            break;
                    case 4:                      
                            display_temp();
                            fflush(stdin);
                            getch();
                            system("cls");   
                            break; 
                    
                    case 0: break;
                            
                   default: printf("Wrong option entered");
              }

          }while(option3 != 0);
      
      getch();
}   


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>            ADD NEW ARRIVALS          >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


void add_tempbook()                                   
{
        int i,flag1=0,flag2=0;
                
        rewind(fp2);                
        fread(&rec2, sizeof(int),1,fp2);
        rec2 = rec2 +1;       
        rewind(fp2);
        fwrite(&rec2, sizeof(int),1,fp2);                  
        
        fseek(fp2,sizeof(int)+sizeof(C)*(rec2-1),SEEK_SET);
        
                 fflush(stdin);
                 printf("Enter temp book name: ");
                 gets(C.bookName);
                 fflush(stdin);
                 printf("Enter author name: ");
                 gets(C.author);
                 fflush(stdin);
                 printf("Enter publisher name: ");
                 gets(C.publisher);
                 fflush(stdin);
                 printf("Enter ISBN code: ");
                 gets(C.ISBN);
                 printf("Enter Edition Number: ");
                 scanf("%d",&C.edition);
                 printf("Enter cost of the book: ");
                 scanf("%f",&C.cost);
                 fflush(stdin);
                 printf("Enter no. of times voted: ");
                 scanf("%d",&C.no_of_time_voted);
                 
                 C.temporaryId[0]='\0';
                
                 char rack[]={'R',C.bookName[0],' ',C.ISBN[6],C.ISBN[7],C.ISBN[8],'\0'};
                
                 strcat(C.temporaryId,rack);
                 
                 printf("Book stored in library with temporary ID: "); 
                 puts(C.temporaryId);
             
                 fwrite(&C,sizeof(C),1,fp2);    
                                          
                 printf("Temporary book added succesfully.........\n\n");
        getch();
       
       fclose(fp2);    
}
   
   
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>         UPDATE THE ARRIVAL DETAILS       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   


void update_tempbook()
{
     int i,flag=0;
     char ID[20];
     printf("Enter temporary Id:");
     gets(ID);
     
     fread(&rec2, sizeof(int),1,fp2);  
     
     for(i=0; i<rec2; i++)
     {
           fread(&C,sizeof(C),1,fp2);
           if(!stricmp(ID,C.temporaryId))
           {
                   fflush(stdin);
                   
                   printf("Enter temp book name: ");
                   gets(C.bookName);
                   fflush(stdin);
                   printf("Enter author name: ");
                   gets(C.author);
                   fflush(stdin);
                   printf("Enter publisher name: ");
                   gets(C.publisher);
                   fflush(stdin);
                   printf("Enter ISBN code: ");
                   gets(C.ISBN);
                   printf("Enter Edition Number: ");
                   scanf("%d",&C.edition);
                   printf("Enter cost of the book: ");
                   scanf("%f",&C.cost);
                   fflush(stdin);
                   printf("Enter no. of times voted: ");
                   scanf("%d",&C.no_of_time_voted);
                   C.temporaryId[0]='\0';
                  
                   char rack[]={'R',C.bookName[0],' ',C.ISBN[6],C.ISBN[7],C.ISBN[8],'\0'};
                  
                   strcat(C.temporaryId,rack); 
                   
                   fseek(fp2,sizeof(int)+sizeof(C)*i,SEEK_SET);    
                   fwrite(&C,sizeof(C),1,fp2);
                   printf("Successfully updated......\n\n");
                   getch();                   
                   flag =1;                
                   break;
           }   
     }
    
     if(flag ==0)
             printf("Invalid Temp. book Id");
    fclose(fp2);
                 
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>                    DELETE ARRIVALS            >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


void del_tempbook()
{
     FILE *ft2;
     int i;
     char ID1[20];
     printf("Enter temporary Id:");
     gets(ID1);
     
     ft2 = fopen ( "LMSdb\\TEMP.bin", "wb+" ) ;
         
     fread(&rec2, sizeof(int),1,fp2);  
     fwrite(&rec2, sizeof(int), 1, ft2);
     
     for(i=0;fread(&C, sizeof(C), 1, fp2 ) == 1; i++)
     {
           if(!stricmp(ID1,C.temporaryId))
           {
                     rec2 = rec2-1;
                     rewind(ft2);
                     fwrite(&rec2, sizeof(int), 1, ft2);
                      fseek(ft2,sizeof(int)+sizeof(C)*(i),SEEK_SET);
           }
                else
                {
                   
                    fwrite(&C,sizeof(C),1,ft2);
                }
     }
     
         fclose (fp2) ;
         fclose (ft2) ;
         remove("LMSdb\\custodybooks.bin");
         rename("LMSdb\\TEMP.bin","LMSdb\\custodybooks.bin");
         printf("Deleted\n");
         getch();      
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>             DISPLAY ARRIVALS          >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


void display_temp()
{
     int i;
     
     fread(&rec2,sizeof(int),1,fp2);
     
     printf("Temp Id \t Book Name \t author \t Publisher \t ISBN \t edition Cost \tNo. of times voted\n");
     printf("------- \t --------- \t ------- \t ---------\t ---- \t ------- ---- \t------------------\n");
          
     for(i=0;i<rec2;i++)
     {
             fread(&C,sizeof(C),1,fp2);
             printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t%d\t%.2f\t%d\n",C.temporaryId,C.bookName,C.author,C.publisher,C.ISBN,C.edition,C.cost,C.no_of_time_voted);
     }
     fclose(fp2);
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>             ENDORSEMENTS              >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


void endorsements()
{
  FILE *end;
  char ID[20];
  int count,i;
  end=fopen("LMSdb\\custodybooks.bin","r+b");

  if(end==NULL)
    printf("Unable to Open File \n");
  
  else
  {
      
    printf("\nEnter the ID\n");
    fflush(stdin);
    gets(ID);
    fflush(stdin);
    rewind(end);
    fread(&count,sizeof(int),1,end);
    
    for(i=0;fread(&C,sizeof(C),1,end)==1;i++)
    {
      if(!strcmp(ID,C.temporaryId))
      {
        C.no_of_time_voted=C.no_of_time_voted+1;
        fseek(end,sizeof(int)+sizeof(C)*(i),SEEK_SET);
        fwrite(&C,sizeof(C),1,end);
        break;
      }
    }
  }

fclose(end);

}
