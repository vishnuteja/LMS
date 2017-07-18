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

void add_item();
void update_item();
void delete_item();
void display_item();

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       GLOBAL VARIABLES      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

FILE *fp1;
int rec1=0;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       MAIN FUNCTION        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main()
{
   
   int option2;
   system("color 4f");
    
    do
    {
          printf("\n\n\t\t +-+-+-+---------------------------+-+-+-+\n");                                                                                   /* Display menu */ 
          printf("\t\t||-+-+-+- MEDIA MANAGEMENT SYSTEM -+-+-+-||\n");
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
                  fwrite(&rec1,sizeof(int),1,fp1);
                  if(fp1 == NULL)
                        printf("Unable to open file\n");
          }    
         
              switch(option2)
              {
                    case 1:                      
                            add_item();
                            fflush(stdin);
                            getch();
                            system("cls");
                            break;
                    case 2:                      
                            update_item();
                            fflush(stdin);
                            getch();              
                            system("cls");   
                            break;
                    case 3:                      
                            delete_item();
                            fflush(stdin);
                            getch();
                            system("cls");   
                            break;
                    case 4:                      
                            display_item();
                            fflush(stdin);
                            getch();
                            system("cls");   
                            break; 
                    case 0:                                                                  //exit from menu
                            exit(1);
                    default:
                            printf("Wrong option entered");
              }
                   
          }while(option2 != 0);     
      
      getch();
}   

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>             ADD ITEMS                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


void add_item()                                                                               //Function to add an item
{
        int i,deptid,flag1=0,flag2=0;

                    rewind(fp1);                
                    fread(&rec1, sizeof(int),1,fp1);
                    rec1 = rec1 +1;       
                    rewind(fp1);
                    
                    fwrite(&rec1, sizeof(int),1,fp1);                  
                    
                    fseek(fp1,sizeof(int)+sizeof(I)*(rec1-1),SEEK_SET);
                    
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
                    
                    I.itemId = rec1;       
            
                    fwrite(&I,sizeof(I),1,fp1);    
                                                      
                    printf("Media Item added succesfully.........\n\n");
                    getch();
                    
      fclose(fp1);    

}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>          UPDATE THE BOOK DETAILS         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void update_item()
{
     int Iid;
     
     int i,flag =0;
    
     printf("Enter dept. Id");
     scanf("%d",&Iid);
     
     fread(&rec1, sizeof(int),1,fp1);  
     printf("No. of Records = %d",rec1);
     
     for(i=0; i<rec1; i++)
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

void delete_item()
{
     
                                     FILE *ft,*fp2;
                                      
                                        int id,i;
                                  
                                        ft=fopen("LMSdb\\Media\\temp.bin","wb");
                                  
                                        printf("\nEnter ID : \n");
                                        scanf("%d",&id);
                                        
                                        fread(&rec1,sizeof(int),1,fp1);
                                        
                                        printf("I am position 1 \n");
                                       
                                        fwrite(&rec1,sizeof(int),1,ft);
                                        
                                        
                                        for(i=0;fread(&I,sizeof(I),1,fp1)==1;i++)
                                        {
                                            
                                            
                                              if (id == I.itemId)
                                              {
                                                rec1=rec1-1;
                                                rewind(ft);
                                                fwrite(&rec1,sizeof(int),1,ft);
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

void display_item()
{
     int i;
    /* fclose(fp1);
     FILE *fp2;
     fp2=fopen("LMSdb\\Media\\media.bin","rb");*/
     fread(&rec1,sizeof(int),1,fp1);
     printf("No.of Records = %d \n",rec1);
     
     printf("Item ID\tItem Name\tType\tPrice\tPublisher\tstatus\tCreator\n");
     printf("-------\t---------\t----\t-----\t---------\t------\t-------\n");
     
     for(i=0;fread(&I,sizeof(I),1,fp1)==1;i++)
     {  
        
        printf("%d\t%s\t\t%s\t%3.2f\t\t%s\t%c\t%s\n",I.itemId,I.itemName,I.itemType,I.itemPrice,I.publisher,I.status,I.creator); 
     }
     //fclose(fp2);
     fclose(fp1);
}
