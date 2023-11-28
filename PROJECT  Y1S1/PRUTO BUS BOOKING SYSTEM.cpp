#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
char ch[20][130]={"Dep Time=8am.\t\tMombasa/8pm.Nairobi Express","Dep Time=7am.\t\tKisumu/7am.Nairobi Express","Dep Time=6am.\t\tEldoret/6am.Nairobi Express","Dep Time=5am.Namanga/5am.Nairobi Express","Dep Time=9am.Lodwar/9am.Nairobi Express",
                  "Dep Time=10am.Wajir/10am.Nairobi Express","Dep Time=11am.Mandera/11am.Nairobi Express","Dep Time=12pm.Nakuru/12pm.Nairobi Express","Dep Time=7.50am.Bomet/7.50am.Nairobi Express","Dep Time=10.30am.Garissa/10.30am.Nairobi Express"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno;
void bus();//for list of bus
void name_number(int booking,char numstr[100]);
void booking();//for booking the tickets
float Amount;
int read_number(int trno);//for reading the number from the file
void read_name(int trno);//for reading the name from the file
void status();//for printing the status by user input
void status_1(int trno);//for printing the status while booking ticket
void cancel();
void login();
int main()
{
	login();
    int num,i;
    do{
    system("cls");
    printf("\n\n\n");
   printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<< WELCOME TO BUS RESERVATION SYSTEM >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
    printf("\t\t\t\t\t[1]>>>> View Bus List <<<<\n");
    printf("\n");
    printf("\t\t\t\t\t[2]>>>> Book Tickets <<<<\n");
    printf("\n");
    printf("\t\t\t\t\t[3]>>>> Cancel Booking <<<<\n");
    printf("\n");
    printf("\t\t\t\t\t[4]>>>> Bus Status Board <<<<\n");
    printf("\n");
    printf("\t\t\t\t\t[5]>>>> Exit <<<<\n\n");
    printf("**********************************************************************************************=\n\n");
    printf("\t\t\tEnter Your Choice: ");
    scanf("%d",&num);

    switch(num)
    {
    case 1:
        bus();//for list of bus
        break;
    case 2:
        booking();//for booking the tickets
        break;
    case 3:
        cancel();
        break;
    case 4:
        status();
        break;
    }
getch();
    }while(num != 5);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t^^^^^^^^THANK YOU FOR USING OUR BUS RESERVATION SYSTEM^^^^^^^^\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t********BROUGHT TO YOU BY PRUTO TRANSPORT ORGANIZATION********");
    getch();
    return 0;
}


void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BUS RESERVATION SYSTEM >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
    printf("\t\t\t\t\t[1]  >>>>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  >>>>  %s\n",ch[1]);
    printf("\n"); 
	printf("\t\t\t\t\t[3]  >>>>  %s\n",ch[2]);
    printf("\n"); 
	printf("\t\t\t\t\t[4]  >>>>  %s\n",ch[3]);
    printf("\n"); 
	printf("\t\t\t\t\t[5]  >>>>  %s\n",ch[4]);
	printf("\n");
    printf("\t\t\t\t\t[6]  >>>>  %s\n",ch[5]);
	printf("\n");
	printf("\t\t\t\t\t[7]  >>>>  %s\n",ch[6]);
	printf("\n");
	printf("\t\t\t\t\t[8]  >>>>  %s\n",ch[7]);
	printf("\n");
	printf("\t\t\t\t\t[9]  >>>>  %s\n",ch[8]);
	printf("\n");
	printf("\t\t\t\t\t[10]  >>>>  %s\n",ch[9]);
	printf("\n");
}

void booking()
{

    int i=0;
    char numstr[100];
system("cls");
printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BUS RESERVATION SYSTEM >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");//for entering train number
bus();//for seeing BUS LIST
printf("Enter the Bus number:>>");
scanf("%d",&trno);
system("cls");
printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BUS RESERVATION SYSTEM >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");//for selecting coach
printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
status_1(trno);
 FILE *f1, *fopen();//for reading the seats from the user.
 char str1[80]="32",str2[4],str3[4];
 int seat1,seat2,booking=0;


seat1=atoi(str1);//covert the string into number
if(seat1 <= 0)
{
 printf("WE ARE SORRY, THERE IS NO EMPTY SEAT IN THIS BUS!! ");
}else
{
printf("\n\n\n\t\t\t\tAvailable Seats:>>>%d\n",seat1);
printf("\n\t\t\t\tNumber of Tickets:>>>");
scanf("%d",&booking);
printf("\n");

seat1=seat1-booking;
itoa(trno,numstr,10);
name_number(booking,numstr);
printf("\n\t\t\t\tYour Total booking =%d",booking);
Amount=1400*booking;
printf("\n\t\t\t\tThe Total booking amount is KSH.%.2f\n",Amount);
itoa(seat1, str1, 10);
//for reading the seats from the user.

}
}



void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");//for open the file to write the name in the file
   b = fopen(tempstr2,"a");//for open the file for writing the number in the file
for(i=0; i<booking; i++)//for entering the person name and seat number in the file
{
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ENTER THE DETAIL FOR A TICKET NO %d>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n",i+1);
      printf("\t\t\t\tEnter the seat number:>>>");
      scanf("%d",&number);
      printf("\t\t\t\tEnter the name of person:>>>");
      scanf("%s",name[number-1]);
    printf("\n***********************************************************************************************\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int trno)//for putting the numeric value in the array
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the name in it
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int trno)//for putting the numeric value in the array
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
system("cls");
printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BUS RESERVATION SYSTEM >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
    int i,trno,index=0,j;
    printf("Enter the number of bus:>>>");
    scanf("%d",&trno);
    j=read_number(trno);
    read_name(trno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no>>>%d>>>>%s                                                 \n",trno,ch[trno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ",
	                       "Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ",
						   "Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ",
						   "Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ",
						   "Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void status_1(int trno)
{
    printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
    system("cls");
printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BUS RESERVATION SYSTEM >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
    int i,index=0,j;
    j=read_number(trno);
    read_name(trno);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ",
	                       "Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ",
						   "Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ",
						   "Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ",
						   "Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}


void cancel()
{
 int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 printf("Enter the bus number:>>>");
 scanf("%d",&trno);
 itoa(trno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(trno);
 read_name(trno);
 status_1(trno);
 printf("Enter the seat number:>>>");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\t >>YOUR KSH. 1400 HAS BEEN RETURNED<<\t\t\t\n");
    printf("======================================================================================================\n");
}
    void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	system("color 0b");
	 printf("\n     >>>>>>>>BROUGHT TO YOU BY PRUTO TRANSPORT COMPANY<<<<<<<<\n\n");
	 
    printf("\n  >>>>>>>>>>>>>>>>>>>>>>>>>>>>  LOGIN FORM  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<  ");
    printf(" \n                       ENTER USERNAME: ");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD: ");
	while(i<10)

	 {
        pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"Kiprutoh")==0 && strcmp(pword,"Abed/21")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM, LOGIN IS SUCCESSFUL");
	Beep(3500,100);
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n\n\n \tWE ARE SORRY, LOGIN IS UNSUCESSFUL!!!\n\n");
		Beep(750,1000);
		a++;
		
		getch();//holds the screen
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
getch();
		
}