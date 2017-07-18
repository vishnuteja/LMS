//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>        VISHNU TEJA T        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<          IIIT- 73           <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>         MODULE # 3          >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


                                    #include<stdio.h>
                                    #include<conio.h>
                                    #include<stdlib.h>
                                    #include<string.h>
                                    #include<dir.h>


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>        STRUCTURE DECLARATIONS      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


                                    struct Item
                                    {
                                        int itemId;
                                        char itemName[30];
                                        char itemType[20];                                              //Video - audio - DVD- Documentary
                                        float itemPrice;
                                        char creator[30];
                                        char publisher[30];
                                        char status;                                                    //Available - Loaned - Requested - Hold
                                        //loanDate;
                                        //dueDate;
                                        //loanedTo;
                                    }I; 


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>       FUNCTION PROTOTYPES         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void additems();
void updateitem();
void deleteitem();
void displayitem();

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       GLOBAL VARIABLES      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

FILE *fp1;
int record=0;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       MAIN FUNCTION        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

media_menu()
{
   
   int option2;
   
    
    do
    {
          
          system("color CF");
          system("cls");
          printf("\n\n\t\t +-+-+-+---------------------------+-+-+-+\n");                                                                                   /* Display menu */ 
          printf("\t\t||-+-+-+- MEDIA MANAGEMENT   MENU -+-+-+-||\n");
          printf("\t\t +-+-+-+---------------------------+-+-+-+\n\n");
          
          printf("\t\t1. Add an item in Media library\n\n");
          printf("\t\t2. Update an item in library\n\n");
          printf("\t\t3. Delete an item\n\n");
          printf("\t\t4. Show the list of items in media library\n\n");
          printf("\t\t0. Exit\n\n");
          printf("\n\n\t\t\t\t\tEnter requiured option: ");
          scanf("%d",&option2);
          fflush(stdin);
          system("cls");                
         
          fp1 =fopen("LMSdb\\Media\\media.bin","rb+");
         
          if(fp1 == NULL)
          {
                  fp1 =fopen("LMSdb\\Media\\media.bin","wb+");
                  fwrite(&record,sizeof(int),1,fp1);
                  if(fp1 == NULL)
                        printf("Unable to open file\n");
          }    
         
              switch(option2)
              {
                    case 1:                      
                            additems();
                            fflush(stdin);
                            getch();
                            system("cls");
                            break;
                    case 2:                      
                            updateitem();
                            fflush(stdin);
                            getch();              
                            system("cls");   
                            break;
                    case 3:                      
                            deleteitem();
                            fflush(stdin);
                            getch();
                            system("cls");   
                            break;
                    case 4:                      
                            displayitem();
                            fflush(stdin);
                            getch();
                            system("cls");   
                            break; 
                    case 0:                                                                  //exit from menu
                            break;
                    default:
                            printf("Wrong option entered");
              }
                   
          }while(option2 != 0);     
      
      getch();
}   

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>             ADD ITEMS                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


void additems()                                                                               //Function to add an item
{
        int i,deptid,flag1=0,flag2=0;

                    rewind(fp1);                
                    fread(&record, sizeof(int),1,fp1);
                    record = record +1;       
                    rewind(fp1);
                    
                    fwrite(&record, sizeof(int),1,fp1);                  
                    
                    fseek(fp1,sizeof(int)+sizeof(I)*(record-1),SEEK_SET);
                    
                    printf("Enter Item Name: ");
                           fflush(stdin);
                    gets(I.itemName);
             

                    
                    printf("Enter creator: ");
                           fflush(stdin);
                    gets(I.creator);
                 
                    
                    printf("Enter publisher: ");
                           fflush(stdin);
                    gets(I.publisher);
                    
                    
                    printf("Enter cost of media: ");
                    scanf("%f",&I.itemPrice);
                    
                    printf("Enter type <Video - audio - DVD- Documentary>: ");   
                            fflush(stdin);
                    gets(I.itemType);                                 
                 
                    I.status = 'A';
                    
                    I.itemId = record;       
            
                    fwrite(&I,sizeof(I),1,fp1);    
                                                      
                    printf("Media Item added succesfully.........\n\n");
                    getch();
                    
      fclose(fp1);    
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>          UPDATE THE BOOK DETAILS         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void updateitem()
{
     int Iid;
     
     int i,flag =0;
    
     printf("Enter dept. Id");
     scanf("%d",&Iid);
     
     fread(&record, sizeof(int),1,fp1);  
     printf("No. of Records = %d",record);
     
     for(i=0; i<record; i++)
     {

           fread(&I,sizeof(I),1,fp1);
         
           if(Iid == I.itemId)
           {
                    flag=1;
                    printf("Enter Item Name: ");
                    fflush(stdin);
                    gets(I.itemName);
                    
                    printf("Enter creator: ");
                           fflush(stdin);
                    gets(I.creator);
                 
                    
                    printf("Enter publisher: ");
                           fflush(stdin);
                    gets(I.publisher);
                    
                    
                    printf("Enter cost of media: ");
                    scanf("%f",&I.itemPrice);
                    
                    printf("Enter type <Video - audio - DVD- Documentary>: ");   
                            fflush(stdin);
                    gets(I.itemType);                                 
                 
                    fseek(fp1,sizeof(int)+sizeof(I)*(i),SEEK_SET);
                    
                    fwrite(&I,sizeof(I),1,fp1);    
                                                      
                    printf("Media Item added succesfully.........\n\n");
                    break;
                    getch();
                    
           }   
           
     }  
      fclose(fp1);
    if(flag ==0)
             printf("Invalid dept. Id");
             getch();
   
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>                    DELETE BOOKS            >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void deleteitem()
{
     
                                     FILE *ft,*fp2;
                                      
                                        int id,i;
                                  
                                        ft=fopen("LMSdb\\Media\\temp.bin","wb");
                                  
                                        printf("\nEnter ID : \n");
                                        scanf("%d",&id);
                                        
                                        fread(&record,sizeof(int),1,fp1);
                                        
                                        printf("I am position 1 \n");
                                       
                                        fwrite(&record,sizeof(int),1,ft);
                                        
                                        
                                        for(i=0;fread(&I,sizeof(I),1,fp1)==1;i++)
                                        {
                                            
                                            
                                              if (id == I.itemId)
                                              {
                                                record=record-1;
                                                rewind(ft);
                                                fwrite(&record,sizeof(int),1,ft);
                                                fseek(ft,sizeof(int)+sizeof(I)*(i),SEEK_SET);
                                              }
                                               
                                              else
                                              {
                                                fwrite(&I,sizeof(I),1,ft);
                                              }

                                        }
                                       
                                        fclose(fp1);
                                        fclose(ft);
                                     
                                        
                                        remove("LMSdb\\Media\\media.bin");
                                        rename("LMSdb\\Media\\temp.bin","LMSdb\\Media\\media.bin");
                                        
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>           DISPLAY FUNCTION            >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void displayitem()
{
     int i;
     fclose(fp1);
     FILE *fp2;
     fp2=fopen("LMSdb\\Media\\media.bin","rb");
     fread(&record,sizeof(int),1,fp1);
     printf("No.of Records = %d \n",record);
     
     printf("Item ID\tItem Name\tType\tPrice\tPublisher\tstatus\tCreator\n");
     printf("-------\t---------\t----\t-----\t---------\t------\t-------\n");
     
     for(i=0;fread(&I,sizeof(I),1,fp1)==1;i++)
     {  
        
        printf("%d\t%s\t\t%s\t%3.2f\t\t%s\t%c\t%s\n",I.itemId,I.itemName,I.itemType,I.itemPrice,I.publisher,I.status,I.creator); 
     }
     //fclose(fp2);
     fclose(fp1);
}
