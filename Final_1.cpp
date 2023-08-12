#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct customer{
	int cid,amt;
	char name[30],phno[11],date[11];
};
struct menulist{
	int id;
	char iname[100];
	int price;
}menu[]={{1,"Masala Dosa",65},{2,"Mixed Veg.",100},{3,"Mutton kebab",350},{4,"Chicken Briyani",200},{5,"Mutton Briyani",350},{6,"Cold Coffe",130},{7,"Manchurian",399},{8,"Tandori Chicken",249},{9,"Soft Drinks",59},{10,"Ice Cream",80}};
void menu1()
{
	printf("\n\t.................WELCOME..................\n");
	printf("\n Enter your choice according to given menu : \n");
	
	char *menu[]={"Book a Table","Check Table Availibility","Collection of the Day","Total Customer of the Day","Highest Bill of the day","Customer Details","Food Menu","Exit"};
	int i;
	for(i=0;i<8;i++)
	{
		printf("\n %d = %s",(i+1)%8,menu[i]);
	}
}
void space_management(int n)
{
	for(int i=1;i<=n;i++)
	{
		printf(" ");
	}
}
void Menu_List()
{
	int i,j=0;
	printf("\n------------MENU--------------\n");
	for(i=0;i<10;i++)
	{
		printf("\n%d=%s",i+1,menu[i].iname);
		space_management(20-strlen(menu[i].iname));
		printf("Rs.%d",menu[i].price);	
	}
	printf("\n");
	printf("\n**************x***************\n");
}
void timetable()
{
	int i,j=0;
	printf("\n------------TIME TABLE----------\n");
	for(i=11;i<=22;i++)
	{
		printf("%d=%d:00-%d:00\t",j+1,i,i+1);
		j++;
		if(j%2==0)
		printf("\n");
	}
}
int main()
{
	int ch,ch1,plate,cid=101,ans,slot,i,index=0,total=0,bill=0,max=0,r;
	customer c1,a[100];
	static int table[7];
	printf("\n******************GREEN CHILLI RESTAURENT*********************\n");
	while(1)
	{
		menu1();
		printf("\n >>>> ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: printf("\n !!Thanks for visiting !!");
					exit(0); 
					break;
			case 1: bill=0;
					fflush(stdin);
					printf("Name :");
					gets(c1.name);
					printf("\nPhone No:");
					scanf("%s",c1.phno);
					printf("\nDate :");
					scanf("%s",c1.date);
					Menu_List();
					printf("\n Enter your choice:");
					scanf("%d",&ch1);
					printf("\n Plate :");
					scanf("%d",&plate);
					bill+=plate*menu[ch1-1].price;
					do{
						printf("\nWant to order more dish ??\npress(0..No,1..Yes) : ");
						scanf("%d",&ans);
						if(ans==0)
						break;
						printf("\n Enter your choice:");
					scanf("%d",&ch1);
					printf("\n Plate :");
					scanf("%d",&plate);
					bill+=plate*menu[ch1-1].price;
					}while(1);
					timetable();
					printf("\n Enter Slot :");
					scanf("%d",&slot);
					table[slot-1]++;
					printf("\n --------THANK YOU------------\n");
					printf("\n\tSuccessful!!");
					printf("\n\tCustomer ID : %d",cid);
					printf("\n\tTable :%d",table[slot-1]);
					printf("\n -----------------------------\n");	
					c1.cid=cid;
					c1.amt=bill;
					//cid++;
					a[index++]=c1;
					total+=bill;
					if(max<bill)
					{
						max=bill;
						r=cid;
					}
					cid++;
					break;
			case 2: timetable();
					printf("\n----------------------");
					printf("\n Enter Slot :");
					scanf("%d",&slot);
					for(i=1;i<=7;i++)
					{
						printf("\n Table Number -%d",i);
						printf("\tStatus :");
						if(i<=table[slot-1])
						{
							printf("Booked");
						}	
						else
						printf("Empty");
					}
					break;
			case 3:
				printf("\n Collection of the day : %d",total);
				break;
			case 4:
				printf("\n Total number of customer = %d",index);
			    break;	
			case 5:
				printf("\n Highest bill of the day = %d",max);
				printf("\n Customer ID : %d",r);
				break;		
			case 6:
				for(i=0;i<index;i++)
				{
					printf("\n Customer ID : %d ",a[i].cid);
					printf("\n Name : %s",a[i].name);
					printf("\n Phone Number :%s ",a[i].phno);
					printf("\n Date : %s",a[i].date);
					printf("\n Customer Bill : %d",a[i].amt);
					printf("\n\n");
				}
				break;
			case 7:
				Menu_List();
				break;	
			default:
				printf("\n INVALID INPUT ");
					
		}
	}
}
