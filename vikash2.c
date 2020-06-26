#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct stu_info
{
	char fnam[MAX];
	char lnam[MAX];
	long long int no;
};

int main()
{
	struct stu_info per[30];
	int i,ch,n,j,t,mid,l=0,r=2,direct=0;
	char fname[20],lname[20],op,temp[20];
	
	strcpy(per[0].fnam, "vikash");
	strcpy(per[0].lnam, "singh");
	per[0].no = 8876041514;
			
	strcpy(per[1].fnam, "saurav");
	strcpy(per[1].lnam, "gupta");
	per[1].no = 7412365890;
	
	strcpy(per[2].fnam, "Debo");
	strcpy(per[2].lnam, "purk");
	per[2].no = 6598748123;
	

	
	do
	{
		system("cls");
		
		printf("\nNAME :\t\t\t\tVIKASH SINGH\n\n");
		printf("REGISTER NO :\t\t\t1847263\n\n");
		//printf("\n\n\n******************************TELEPHONE DIRECTORY******************************\n\n");
		printf("Select anyone of the option\n\n");
		printf("1.Enter the name and check using linear search if it is present \n");
		printf("2.Enter the name and check using binary search if it is present \n");
		printf("3.Exit\n\n");

		printf("\nSELECT ANYONE OF THE OPTION (1-3):");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
			{
				
				system("cls");
				printf("\n\nEnter the First Name you want to search : ");
				scanf("%s",&fname);
				
				printf("\n\nEnter the Last Name you want to search : ");
				scanf("%s",&lname);
				
				printf("\n\n");
				for(i=0;i<2;i++)
				{
					if((strcmp(fname,per[i].fnam) == 0  && (strcmp(lname,per[i].lnam)) == 0))
					{
						printf("\n\nSEARCH IS SUCCESSFUL");
						printf("\n\nFisrt Name : %s",per[i].fnam);
						printf("\n\nLast Name : %s",per[i].lnam);
						printf("\n\nTelephone Number : %llu",per[i].no);
						break;
					}
					else if(i==2)
					{
 						printf("\n\nNOT FOUND! Name is not present in the list.");
					}
					
				}
				break;
			}
			case 2: //binary search algorithm belongs to the O(log n)
			{
				for (i = 0; i < 2 ; i++)
				{
					for (j = i + 1; j < 2; j++)
					{
						if ((strcmp(per[i].fnam, per[j].fnam)) > 0)
                		{
                    		strcpy(temp, per[i].fnam);
                    		strcpy(per[i].fnam, per[j].fnam);
                    		strcpy(per[j].fnam, temp);
                    		
                    		strcpy(temp, per[i].lnam);
                    		strcpy(per[i].lnam, per[j].lnam);
                    		strcpy(per[j].lnam, temp);
                    		
                    		t = per[i].no;
                    		per[i].no = per[j].no;
                    		per[j].no = t;
						}
            		}
        		}
        		
        		system("cls");
				printf("\n\nEnter the First Name which you want to search : ");
				scanf("%s",&fname);
				
				printf("\n\nEnter the Last Name which you want to search : ");
				scanf("%s",&lname);
				
				if(l<=r)
				{
 					mid=(l+r)/2;
 					for(i=0;i<2;i++)
 					{
 						if ((strcmp(fname,per[i].fnam) == 0) && (strcmp(lname,per[i].lnam) == 0))
 						{
 							printf("\n\nSEARCH IS SUCCESSFUL");
							printf("\n\nFisrt Name : %s",per[i].fnam);
							printf("\n\nLast Name : %s",per[i].lnam);
							printf("\n\nTelephone Number : %d",per[i].no);
							direct = 1;
							break;
						}	
 						else if((strcmp(fname,per[i].fnam) > 0) && (strcmp(lname,per[i].lnam) > 0))
 						{
 							l=mid+1;
 							r=r;
 						}
 						else if((strcmp(fname,per[i].fnam) < 0) && (strcmp(lname,per[i].lnam) < 0))
 						{
 							l=l;
 							r=mid-1;
 						}
 					}	
 				}	
 				if(r == 0)
				{			
					printf("\n\nNOT FOUND! Name is not present in the list.");
				}
			break;
			}
			case 3:
			{
				exit(0);
			}
			default:
			{
				printf("\n\nInvalid Input");
				break;
			}
			
		}
		printf("\n\nDo you want to search for another number in the directory? (y/n)");
		scanf(" %c",&op);
	}while(op=='y' || op=='Y');
	
	return 0;
}    

