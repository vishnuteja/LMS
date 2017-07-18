//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>        VISHNU TEJA T        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<          IIIT- 73           <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>         MODULE # 2-2          >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

                                    #include<stdio.h>
                                    #include<conio.h>
                                    #include<stdlib.h>
                                    #include<string.h>
                                    #include<dir.h>
                                    #include "bookheader.h"

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

                                    FILE *fp;
                                    int records=0;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>       MAIN FUNCTION        >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main()
{
    int option1;
    system("COLOR 4f");
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
        
         fp =fopen("LMSdb\\library\\departments.bin","rb+");
         
                if(fp==NULL)
                {
                  fp=fopen("D:\\Project\\LMSdb\\library\\departments.bin","wb+");  //create the Binary File if doesn't exist
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
                case 0: break; 
                
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
    int rec=0,i,flag1=0,flag2=0;
    char dept[5];
 
    
                for(i=0;fread(&records,sizeof(int),1,fp)==1;i++)
                     flag2=1;
                
                if(flag2==0)
                {
                  fwrite(&records,sizeof(int),1,fp);
                }
    
        rewind(fp);
        
        fread(&records,sizeof(int),1,fp);
         
        fflush(stdin);
        printf("Enter department name: ");
        gets(dept);
        fflush(stdin);
                
            for(i=0;i<records;i++)
                {
                      fread(&D,sizeof(D),1,fp);
                      if(!stricmp(dept,D.departmentName))
                      {
                              printf("Department name already exists");
                              flag1 = 1;
                              break;
                      }
                }
               
            if(flag1 == 0)
            {      
            
                    records = records +1;
                    rewind(fp);
                    fwrite(&records, sizeof(int),1,fp);
                            
                    strcpy(D.departmentName,dept);
                    D.deptId = records;
                    D.totalRacks = 26;
                                                        
                    fseek(fp,sizeof(int)+sizeof(D)*(records-1),SEEK_SET);    
                    fwrite(&D,sizeof(D),1,fp);    
                    
                    fseek(fp,sizeof(int)+sizeof(D)*(records-1),SEEK_SET);    
                    fread(&D,sizeof(D),1,fp);                                 
        
                    printf("\nDepartment Name     : %s\n",D.departmentName);
                    printf("Department ID       : %d\n",D.deptId);
                    printf("Racks in Department : %d\n",D.totalRacks);
                    
                    fclose(fp);                               
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
                            fwrite(&records,sizeof(int),1,fp);
                    		records++;
                            fclose(temp);   
                   
            	        }
          }

    fflush(stdin);
    getch();
    
    fclose(fp);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>        UPDATE THE EXISTING DEPARTMENT    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void update_dept()
{
     int DId;
     int i,flag =0;
    
     
     printf("Enter dept. Id");
     scanf("%d",&DId);
     
     fread(&records, sizeof(int),1,fp);  
     printf("No. of Records = %d",records);
     
     for(i=0; i<records; i++)
     {
           printf("In loop");
           fread(&D,sizeof(D),1,fp);
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
                    
                   fseek(fp,sizeof(int)+sizeof(D)*i,SEEK_SET);    
                   fwrite(&D,sizeof(D),1,fp);
                   flag =1; 
                   printf("\nSuccessfully Changed the Department\n from..  \n<< %s >>\n to \n<< %s >>\n",str,str1);               
                   break;
           }   
     }  
    if(flag ==0)
             printf("Invalid dept. Id");
             getch();
    fclose(fp);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>           DISPLAY FUNCTION            >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

                    void display()
                    {
                         int i;
                         
                         fread(&records,sizeof(int),1,fp);
                         
                         printf("No . of Records in the File is = %d\n",records);
                         
                         for(i=0;i<records; i++)
                         {
                                   fread(&D,sizeof(D),1,fp);
                             printf("\n%d\t%s\t%d\n",D.deptId,D.departmentName,D.totalRacks);
                         }
                         
                         fclose(fp);
                         
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
                                        
                                        rewind(fp);
                                        
                                        fread(&records,sizeof(int),1,fp);
                                        fwrite(&records,sizeof(int),1,ft);
                                        
                                        for(i=0;fread(&D,sizeof(D),1,fp)==1;i++)
                                        {
                                           
                                              if (Did==D.deptId)
                                              {
                                               records=records-1;
                                               rewind(ft);
                                               fwrite(&records,sizeof(int),1,ft);    
                                               fseek(ft,sizeof(int)+sizeof(D)*(i),SEEK_SET);
                                               strcat(r,D.departmentName); 
                                               system(r);
                                              }
                                              
                                              else
                                              {
                                                      
                                                fwrite (&D,sizeof(D),1,ft);
                                              }
                                        }
                                        
                                        fclose(fp);
                                        fclose(ft);
                                        remove("D:\\Project\\LMSdb\\library\\departments.bin");
                                        rename("D:\\Project\\LMSdb\\library\\temp.bin","D:\\Project\\LMSdb\\library\\departments.bin");
                                        getch();
                                  }
