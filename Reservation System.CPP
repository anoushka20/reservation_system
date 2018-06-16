	    /********** RAILWAY RESERVATION SYSTEM **********/



#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;


static double pnr=1265;
static int stno=20;



float catfare=0.0,fare=0.0;
float tfare=0.0;
char found='n';
char prompt;

class reservation
 {
  public:

  int tno;
  int i;
  char tname[100], bp[100], dst[100];
  int psngrs;
  char pname[100][80] ;
  int stno,cls;
  int dj,mj,yj;
  char gen;
  int cat;
  long double phn, urpnr;
  int addr,ad;
  int age;
  void reserve();
  void mr();
  void view();
  float pdetails();
  void cancel();
  void enquiry();
  void ddetails();
  void dispdetails();
  void can();
  double getpnr()
   {
    return pnr;
   }
 };


reservation sys;


void menu();
void reserve();
void can();
void cdetails();
void mr();




class cancel1 :public reservation
 {
  public:

  int dj1,mj1,yj1;
  double pnr1;


  void can();

  double cdetails()
   {
    cout<<"\nEnter the PNR no.\n" ;
    cin>>pnr1;
    return pnr1;
   }
 };

cancel1 tyt;
void menu();






void cancel1::can()
 {
  cancel1 tyt;
  reservation sys;

  fstream f1;
  fstream f2;

  f1.open("rail.txt",ios::in|ios::out|ios::binary);
  f2.open("tempo.txt",ios::in|ios::out|ios::binary);
  cout<<"\nEnter the PNR No. for the booking that is to be cancelled\n";
  cin>>pnr1;

  while(!f1.eof())
   {
    f1.read((char *) & sys, sizeof(sys));
    if (pnr1==sys.getpnr())
     {
      found='y';
      cout<<"Are you sure you want to cancel?\n";
      cout<<"Press y- for Yes\nPress n- for No\n";
      cin>>prompt;
      if(prompt=='n')
      f2.write((char *) & sys, sizeof(sys));
     }
    else
     {
       f2.write((char *) & sys, sizeof(sys));
     }
   }
   if(found=='n')
    cout<<"\nRecord of this reservation not found!!\n";
  f1.close();
  f2.close();
  remove("rail.txt");
  rename("tempo.txt","rail.txt");
  cout<<"Cancellation done!";
  cout<<"Charges payable after cancellation=";
  float pay=(0.5*tfare);
  cout<<pay;
  f2.open("tempo.txt",ios::in|ios::out|ios::binary);
 }



void cancel()
 {
  fstream f;
  int cho;
  correct:
  do
   {
   // clrscr();
    cout<<setw(50)<<"CANCELLATION MENU";
    cout<<endl<<endl;
    cout<<"1.Cancel\n2.Return to main menu\n";
    cin>>cho;
    cout<<endl;
    switch(cho)
     {
      case 1:
      tyt.can();
      menu();
      break;
      case 2:
      menu();
      break;
      default:
       {
	//clrscr();
	cout<<"\n\n\a\aWHOAA!! You entered wrong choice!\n\n\a\a"    ;
	cout<<"Try entering a valid number from the menu\n";
	goto correct;
       }
     }
   } while (cho==1 || cho==2);
  getch();
 }




void reservation::view()
 {
  //clrscr();

  pnr++;
  cout<<"Train No. & Name:\t";
  cout<<tno;cout<<"\t";
  puts(tname);
  cout<<"\nFrom:\t ";
  puts(bp);
  cout<<"\nBoarding:\t ";
  puts(dst);
  cout<<"\nReservation Upto:\t ";
  puts(dst);
  cout<<"\n\nDate of Journey";
  if (mj==1)
  cout<<dj<<"-"<<"Jan-"<<yj<<endl;
  if(mj==2)
  cout<<dj<<"-"<<"Feb-"<<yj<<endl;
  if(mj==3)
  cout<<dj<<"-"<<"Mar-"<<yj<<endl;
  if(mj==4)
  cout<<dj<<"-"<<"Apr-"<<yj<<endl;
  if(mj==5)
  cout<<dj<<"-"<<"May-"<<yj<<endl;
  if(mj==6)
  cout<<dj<<"-"<<"Jun-"<<yj<<endl;
  if(mj==7)
  cout<<dj<<"-"<<"Jul-"<<yj<<endl;
  if(mj==8)
  cout<<dj<<"-"<<"Aug-"<<yj<<endl;
  if(mj==9)
  cout<<dj<<"-"<<"Sep-"<<yj<<endl;
  if(mj==10)
  cout<<dj<<"-"<<"Oct-"<<yj<<endl;
  if(mj==11)
  cout<<dj<<"-"<<"Nov-"<<yj<<endl;
  if(mj==12)
  cout<<dj<<"-"<<"Dec-"<<yj<<endl;
  cout<<"\nFARE DETAILS:\n";
  cout<<"\nTotal Fare:\t" ;
  cout<<tfare<<endl;
  cout<<endl;
  cout<<"PNR No. : \t ";
  cout<<pnr;
  cout<<endl<<endl;
  cout<<"PASSENGER DETAILS:\n";
  if(psngrs==1)
   {
    cout<<"\nName of passenger:\n";
    for(i=0;i<psngrs;i++)
    cout<<pname[i];
   }
  else if(psngrs>1)
   {
    cout<<"Names of passengers:\n";
    for(i=0;i<psngrs;i++)
     {
      cout<<pname[i] ;
      cout<<endl;
     }
   }
  cout<<"Seat No.: \t"<<stno;
  stno++;
 }




float reservation :: pdetails()
 {
  static int k=1;

  cout<<"\nEnter the name of passenger "<<k;
  gets(pname[i]);
  cout<<"\nEnter the gender\n";
  cout<<"Enter M- for Male and F- for female\n";
  cin>>gen;
  cout<<"Enter age\n";
  cin>>age;
  cout<<"Does the passenger belong to any of these concession categories?";
  invalid:
  cout<<"\n1.Military Personnel\n2.Senior citizen\n3.children velow 5 years\n";
  cout<<"4.None\n";
  cin>>cat;

  if(cat==3  && age>=5)
   {
    cout<<"Invalid choice!!\n";
    goto invalid;
   }

  else if(age>=70 && cat!=2)
   {
    cout<<"Invalid choice!!\n";
    cout<<"This is a senior citizen.\n" ;
    goto invalid;
   }
  else if(age<=5 && cat!=3)
   {
    cout<<"Invalid choice!!\n";
    cout<<"This is a child.\n";
    goto invalid;
   }
  else if(cat==1 && age<18 )
   {
    cout<<"Invalid choice!!\n";
    goto invalid;
   }
  else if(cat==1)
   catfare=0.25;
  else if(cat==2)
   catfare=0.35;
  else if(cat==3)
   catfare=0;
  else catfare=1;

  cout<<"choose from the following options:\n";
  cout<<"1.For AC 1\n2.For AC 2\n3.For Sleeper Class\n";
  cin>>cls;
  if(cls==1)
   fare=1100*catfare;
  else if(cls==2)
   fare=850*catfare;
  else if(cls==3)
   fare=500*catfare;
  k++;
  cout<<"\nFare for this passenger= "<<fare;
  cout<<endl;

  return fare;
}




void reservation::mr()
 {
  int i=1;

  reservation sys;
 // clrscr();
  cout<<"Enter the following details:";
  cout<<"\nTrain No. \n";
  cin>>tno;
  cout<<"\nTrain Name \n";
  gets(tname);
  cout<<"\nBoarding point: \n";
  gets(bp);
  cout<<"\nDestination: \n";
  gets(dst);
  check:
  cout<<"\nDate of journey(DD/MM/YY)\n";
  cin>>dj>>mj>>yj;
  if((mj==2 && dj>29 ) || mj>12 || dj>31 || dj==0 || mj ==0)
   {
    cout<<"Invalid date!!";
    goto check;
   }
   
  cout<<"\nNo. of passengers: \n" ;
  cin>>psngrs;
  for( i;i<=psngrs;i++)
   {
    sys.pdetails();
    tfare=tfare+fare;
    cout<<"TOTAL FARE = "<<tfare;
   }
}




void reserve()
 {
  reservation sys;
  int ch;
  char c;
  char let ;
  fstream f;
  correct:

  do
   {
   // clrscr();
    cout<<setw(50)<<"RESERVATION MENU" ;
    cout<<endl;
    cout<<"1.Make reservations\n2.View the reservations done\n";
    cout<<"3.Return to main menu\n";
    cout<<"\nEnter your choice\n";
    cin>>ch;

    switch(ch)
     {
       case 1:
       f.open("rail.txt",ios::out|ios::in|ios::binary);
       do
	{
	 sys.mr();
	 f.write((char*) & sys, sizeof (sys));
	 cout<<"\nDo you want to make more reservations?\nPress y- for Yes\nPress n- for No\n";
	 cin>>let;
	 //clrscr();
	}while(let=='y');

       cout<<"\nReservations Done!!\n" ;
       f.close();
       break;
       case 2:
       f.open("rail.txt",ios::in|ios::out|ios::app|ios::binary);
       f.seekg(0);
       while(f.read((char *) & sys, sizeof(sys)))
	{
	 sys.view();
	}
       f.close();
       break;

       case 3:
      // clrscr();
       menu();
       break;
       default:
	{
	// clrscr();
	 cout<<"\n\n\a\aWHOAA!! You entered wrong choice!\n\n\a\a"    ;
	 cout<<"Try entering a valid number from the menu\n";
	 goto correct;
	}
     }
   } while(c=='y');
 }



void menu()
 {
  int ch;
  correct:
  do
   {
    cout<<"\n\n"<<setw(42)<<"MAIN MENU";
    cout<<endl;
    cout<<"\n1.Reservation\n2.Cancellation of Reservation\n";
    cout<<"3.Exit\n";
    cout<<endl;
    cout<<"Enter your choice:";
    cin>>ch;
    cout<<endl;

    switch(ch)
     {
      case 1:
      reserve();
      break;
      case 2:
      cancel();
      break;
      case 3:
      exit(0);
      default:
       {
//	clrscr();
	cout<<"\n\n\a\aWHOAA!! You entered wrong choice!\n\n\a\a"    ;
	cout<<"Try entering a valid number from the menu\n";
	goto correct;

       }
     }
   }while(ch<=4);
 }



  int main()
 {
//  clrscr();
  int ch;
  cout<<setw(50)<<"__________________________";
  cout<<"\n\n"<<setw(51)<<"RAILWAY RESERVATION SYSTEM\n";
  cout<<setw(50)<<"__________________________";
  cout<<endl<<endl<<setw(45)<<"WELCOME GUEST!!";
  cout<<endl<<endl;
  menu();
 return 0;
 // getch();
 }
