//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>        VISHNU TEJA T        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<          IIIT- 73           <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>         MODULE # 2-1          >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

                                    #include<stdio.h>
                                    #include<conio.h>
                                    #include<stdlib.h>
                                    #include<string.h>
                                    #include<dir.h>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>       FUNCTION PROTOTYPES         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

                                    void root_dir();
                                    void create_dept();
                                    void update_dept();
                                    void del_dept();
                                    void display();

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>        STRUCTURE DECLARATIONS      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

                                    struct Racks
                                    {
                                        int no_of_books_available;
                                        int no_of_sections; //the bins or draws
                                        int totalCapacity;
                                        char assignedAlphabet;
                                    }R;      
                                    
                                    
                                    struct Department
                                    {
                                        int deptId;
                                        char departmentName[20];
                                        int totalRacks;
                                       // struct Racks allRacks;
                                    }D;  

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       GLOBAL VARIABLES      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

                                    FILE *fptr;
                                    int recs=0;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       MAIN FUNCTION        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

depart()
{
    int option1;
    system("cls");
    system("COLOR B");
    printf("\n\t\t +-+-+-+- HOME PAGE -+-+-+-+\n");
    system("COLOR 4f");
    printf("\n\t 1.Create root directories \n\t\tNote : Use only if you run first time\n");
    printf("\n\t 2.Append data\n");
    printf("\n\t\tEnter required option : ");
    scanf("%d",&option1);
    if(option1 == 1)
            root_dir();
    
    else if(option1 == 2)
    {
       do
       {
        system("cls"); 
        printf("\n\n\t\t +-+-+-+---------------------------+-+-+-+\n");                                                                                   /* Display menu */ 
        printf("\t\t||-+-+-+- DEPT MANAGEMENT SYSTEM  -+-+-+-||\n");
        printf("\t\t +-+-+-+---------------------------+-+-+-+\n\n");
        printf("\t1. Create a Department\n");
        printf("\t2. Update a Department\n");
        printf("\t3. Delete a Department\n");
        printf("\t4. View all Departments\n");
        printf("\t0. Exit\n");
        scanf("%d",&option1);
        
         fptr =fopen("LMSdb\\library\\departments.bin","rb+");
         
                if(fptr==NULL)
                {
                  fptr=fopen("D:\\Project\\LMSdb\\library\\departments.bin","wb+");  //create the Binary File if doesn't exist
                }
        
        switch(option1)
        {
                case 1: create_dept();
                        break;
                case 2: update_dept();
                        break;
                case 3: del_dept();
                        break; 
                case 4: display();
                        break;
                case 0: 
                        break; 
                default: 
                         printf("Wrong option entered");
                
        }
       } while(option1!=0);
        }
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>           CREATE DEPARTMENTS         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void create_dept()
{
    char str[] = "D:\\Project\\LMSdb\\Books\\";
    int recs=0,i,flag1=0,flag2=0;
    char dept[5];
 
    
                for(i=0;fread(&recs,sizeof(int),1,fptr)==1;i++)
                     flag2=1;
                
                if(flag2==0)
                {
                  fwrite(&recs,sizeof(int),1,fptr);
                }
    
        rewind(fptr);
        
        fread(&recs,sizeof(int),1,fptr);
         
        fflush(stdin);
        printf("Enter department name: ");
        gets(dept);
        fflush(stdin);
                
            for(i=0;i<recs;i++)
                {
                      fread(&D,sizeof(D),1,fptr);
                      
                      if(!stricmp(dept,D.departmentName))
                      {
                              printf("Department name already exists");
                              flag1 = 1;
                              break;
                      }
                }
               
            if(flag1 == 0)
            {      
            
                    recs = recs +1;
                    rewind(fptr);
                    fwrite(&recs, sizeof(int),1,fptr);
                            
                    strcpy(D.departmentName,dept);
                    D.deptId = recs;
                    D.totalRacks = 26;
                                                        
                    fseek(fptr,sizeof(int)+sizeof(D)*(recs-1),SEEK_SET);    
                    fwrite(&D,sizeof(D),1,fptr);    
                    
                    fseek(fptr,sizeof(int)+sizeof(D)*(recs-1),SEEK_SET);    
                    fread(&D,sizeof(D),1,fptr);                                 
        
                    printf("\nDepartment Name   : %s\n",D.departmentName);
                    printf("Department ID       : %d\n",D.deptId);
                    printf("Racks in Department : %d\n",D.totalRacks);
                   
                    fclose(fptr);                               
                    strcat(str,dept);
              
              
                    mkdir(str);
                    
        
                        FILE *temp;
                        
                        for (i=0; i<26; i++)
                    	{
                            char str[] = "D:\\Project\\LMSdb\\Books\\";
                            
                            strcat(str,D.departmentName);
                            strcat(str,"\\");
                            char rack_bin[]={'R',65+i,'.','b','i','n','\0'};
                            
                            strcat(str,rack_bin);
                            
                            temp=fopen(str, "wb");            //creating rack binary files
                            //fwrite(&recs,sizeof(int),1,fptr);
                    		//recs++;
                            fclose(temp);   
                   
            	        }
          }

    fflush(stdin);
    getch();
    
    fclose(fptr);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>        UPDATE THE EXISTING DEPARTMENT    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void update_dept()
{
     int DId;
     int i,flag =0;
    
     
     printf("Enter dept. Id");
     scanf("%d",&DId);
     
     fread(&recs, sizeof(int),1,fptr);  
     printf("No. of recs = %d",recs);
     
     for(i=0; i<recs; i++)
     {
           printf("In loop");
           fread(&D,sizeof(D),1,fptr);
           if(DId == D.deptId)
           {
                    char str[]="D:\\Project\\LMSdb\\Books\\";
                    char str1[]="D:\\Project\\LMSdb\\Books\\";
                    
                   fflush(stdin);
                   strcat(str,D.departmentName);
                   printf("Enter department name to modify: ");
                   gets(D.departmentName);   
                  
                   strcat(str1,D.departmentName);
                   
                   rename(str,str1);
                    
                   fseek(fptr,sizeof(int)+sizeof(D)*i,SEEK_SET);    
                   fwrite(&D,sizeof(D),1,fptr);
                   flag =1; 
                   printf("\nSuccessfully Changed the Department\n from..  \n<< %s >>\n to \n<< %s >>\n",str,str1);               
                   break;
           }   
     }  
    if(flag ==0)
             printf("Invalid dept. Id");
             getch();
    fclose(fptr);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>           DISPLAY FUNCTION            >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

                    void display()
                    {
                         int i;
                         
                         fread(&recs,sizeof(int),1,fptr);
                         
                         printf("No . of recs in the File is = %d\n",recs);
                         
                         for(i=0;i<recs; i++)
                         {
                                   fread(&D,sizeof(D),1,fptr);
                             printf("\n%d\t%s\t%d\n",D.deptId,D.departmentName,D.totalRacks);
                         }
                         
                         fclose(fptr);
                         
                    getch();
                    
                    }

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>       CREATE ROOT DIRECTORIES        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

                    void root_dir()            
                    {
                        
                        mkdir("D:\\Project\\LMSdb");
                        mkdir("D:\\Project\\LMSdb\\Books");
                        mkdir("D:\\Project\\LMSdb\\Magazines");
                        mkdir("D:\\Project\\LMSdb\\Media");
                        mkdir("D:\\Project\\LMSdb\\library");
                    }

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>           DELETE  DIRECTORIES        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

                    void del_dept()            
                    {
                      
                                  FILE *ft;
                                  int Did,i;
                                  fflush(stdin);
                                  fflush(stdout);
                                  char r[100]="rmdir /s D:\\Project\\LMSdb\\Books\\";
                      
                                  ft=fopen("D:\\Project\\LMSdb\\library\\temp.bin","wb+");
                                  
                                        printf("\nEnter Department ID : \n");
                                        fflush(stdin);
                                        scanf("%d",&Did);
                                        
                                        rewind(fptr);
                                        
                                        fread(&recs,sizeof(int),1,fptr);
                                        fwrite(&recs,sizeof(int),1,ft);
                                        
                                        for(i=0;fread(&D,sizeof(D),1,fptr)==1;i++)
                                        {
                                           
                                              if (Did==D.deptId)
                                              {
                                               recs=recs-1;
                                               rewind(ft);
                                               fwrite(&recs,sizeof(int),1,ft);    
                                               fseek(ft,sizeof(int)+sizeof(D)*(i),SEEK_SET);
                                               strcat(r,D.departmentName); 
                                               system(r);
                                              }
                                              
                                              else
                                              {
                                                      
                                                fwrite (&D,sizeof(D),1,ft);
                                              }
                                        }
                                        
                                        fclose(fptr);
                                        fclose(ft);
                                        remove("D:\\Project\\LMSdb\\library\\departments.bin");
                                        rename("D:\\Project\\LMSdb\\library\\temp.bin","D:\\Project\\LMSdb\\library\\departments.bin");
                                        getch();
                                  }
