#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
long double items,added,total=0;
string food,decision,more,user,password;
char ch;
int choice,mealchosen,Amount,mycount=3;
ofstream outfile;

string meals[21]={"","plates of ugali  ","plates of beef   ","plates of matoke ",
         "plates of matumbo","mandazi          ",
         "cups of chai     ","plates of Rice   ","plates of Ndengu ",
         "plates of Pweza  ","cups of supu     ","plates of chips  ","pieces of Kuku   ",
         "cups of Uji      ","Plates of Mihogo ","Plates of Githeri","Plates of Waru   ",
         "Chapatis         ","plates of Beans  ","plates of Pilau  ","plates of pork   "};

int price[21]={0,20,80,50,80,5,20,50,20,200,50,50,600,30,20,50,30,20,30,60,90};
          string modprice[21]={"0  ","20 ","80 ","50 ","80 ","5  ","20 ","50 ","20 ",
          "200","50 ","50 ","200","30 ","20 ","50 ","30 ","20 ","30 ","60 ","90 "};

void receipt_creation(){outfile.open("receipt.txt");}


void ReceiptLayout(){
        outfile<<"#######################################################################\n\n";
        outfile<<"\tDAVID'S TRADITIONAL FOODS PARLOUR\n\n";
        outfile<<"QUANTITY    ITEM                  PRICE       DATE        TIME\n\n";}



void Systemlogin(){
      cout<<"please login (maximum of 3 attemps)"<<endl;
      start:
      cout<<"\n\nusername: ";
      cin>>user;
      cout<<"\npassword:  ";
      while(ch=getch()){
          if(ch==13){
             if(password.length()>8&&password=="davidmutune"&&user=="david"){
             system("CLS");
             cout<<"\n\t\t\t\tWEELCOME   "<<user<<"  GIVE YOUR BEST TODAY"<<endl;
             Sleep(2500);
             system("CLS");
             break;}
             else if(password.length()>8&&password!="davidmutune"&&user!="david"){
                  cout<<"\n\nwrong password";
                  cout<<" or username  "<<mycount-1<<" more attempt(s) left "<<endl;
                  password="";
                  if(mycount==1){system("CLS");cout<<"\n\nmaximum no of trials reached ";
                  cout<<"program has stopped"<<endl; exit(0);}
                  mycount-=1;
                  goto start;}
             else if(password.length()<8){
             cout<<"\n\nPassword must have at least 8 characters ";
             cout<<mycount-1<<" more attempt(s) left"<<endl;
             password="";
             if(mycount==1){system("CLS");cout<<"\n\nMAXIMUM NO OF TRIALS REACHED!!! ";
             cout<<"PROGRAM HAS STOPPED"<<endl; exit(0);}
             mycount-=1;
             goto start;}}
        if(ch==8){if(password.length()>0){cout<<"\b \b";
             password.erase(password.length()-1);}}

        else{cout<<"*";
             password+=ch;}}
}


void Welcomenote(){
       string welcomenote[10]={"\n\t\t\t\OUR CORE VALUES","INTEGRITY","SERVICE","HARDWORK",
            "CREATIVITY","PROFESSIONALISM","NETWORKING","TEAMWORK",
            "\n\n\n\n\n\n\n\nREMEMBER THAT THE CUSTOMER IS ALWAYS THE KING",
            "\nPURPOSE TO GIVE YOUR BEST TODAY"};
       for (int i=0;i<10;i++){
            if(i<9){cout<<welcomenote[i];
                    cout<<endl;
                    Sleep(1000);}
            if(i==9){cout<<welcomenote[9];
                   Sleep(3000);
                   system("CLS");}}
                    }
void DateAndTime(){
     char date[10];
	 char time[10];
 	_strdate(date);
	_strtime(time);
	outfile<<date<<"    "<<time;}

int ChoiceValidation(){mealchosen = -1;
    while(mealchosen<1){
    char c ;
    if( !( cin >> mealchosen ) || ( cin.get(c) && !isspace(c) ) ||mealchosen<1||mealchosen>10){
       cout<<"Your order must be a positive whole number";
       cout<<" within the choice range! re-make your order"<<endl;;
       cin.clear ();
       cin.ignore( 500, '\n' );
       mealchosen =-1 ;}
    else{return mealchosen;}}
                   }
int ItemsValidation(){
    start:
    cin>>items;
         if(cin.fail()){
         cin.clear();
         cin.ignore();
        cout <<"Invalid Choice, Please select a valid quantity of "<<meals[choice]<<":  ";
        goto start;}
        else{return items;}
                     }
void menudisplay(){
       ifstream menu3;
     char foods[255];
     menu3.open("menu3.txt");
     if(!menu3){cout<<"Hotel menu does not exist! create menu"<<endl;Sleep(6000);exit(0);}else{
     while(!menu3.eof()){
            menu3.getline(foods, 255);
            cout<<foods<<endl;}}
                 }

void receiptGen(){
     cout<<"What  would you like to have from our menu?"<<endl;
    do{
    int mealchosen=ChoiceValidation();
    choice=(mealchosen*2-1);
    cout<<"\nEnter the number of "<<meals[choice]<<" that you need:  ";
    ItemsValidation();
    outfile<<"   "<<items<<"        "<<meals[choice]<<"     "<<"ksh"<<modprice[choice];
    outfile<<"     ";
    DateAndTime();
    outfile<<endl;
    total=total + items*price[choice];
    choice=choice+1;
    cout<<"Enter the number of "<<meals[choice]<<" that you need:  ";
    ItemsValidation();
    outfile<<"   "<<items<<"        "<<meals[choice]<<"     "<<"ksh"<<modprice[choice];
    outfile<<"     ";
    DateAndTime();
    outfile<<endl;
    total=total + items*price[choice];

    cout<<"\nwould you like to take any other combination? yes, no"<<endl;
    cin>>more;
    for(int i=0;i<4;i++){
    more[i]=toupper(more[i]);}
    if(more=="YES"){cout<<"\nWhat else do you need?"<<endl;}
    }while(more=="YES");
           }

void CustomerBalance(){
    system("CLS");
    cout<<"Your total bill is Ksh"<<"  "<<total<<endl;
    cout<<"Enter the amount that you want to pay to receive your change"<<endl;
    cin>>Amount;
    do{if(Amount>=total){
    cout<<"CHANGE"<<"  " <<"="<<"  "<<"Ksh"<<" "<<Amount-total<<endl;}
    else{cout<<"There is a deficit of ksh"<<"  "<<total-Amount<<" on your"<<" "<<"Ksh"<<total<<" "<<"bill"<<endl;
        cout<<"Please enter the amount that you want to add onto the Ksh"<<" "<<Amount<<endl;
        cin>>added;
        Amount=Amount+added;
        if(Amount>=total){
        cout<<"CHANGE"<<"  " <<"="<<"  "<<"Ksh"<<" "<<Amount-total<<endl;}                                  }
        }while(Amount<total);
                     }
void receipt_close(){outfile.close();}

void BaseDetails(){
     outfile<<"\n\nTOTAL BILL  :\t\t\t  "<<"Ksh"<<total<<endl;
     outfile<<"\nAMOUNT PAID :\t\t\t  "<<"Ksh"<<Amount<<endl;
     outfile<<"\nCHANGE GIVEN:\t\t\t  "<<"Ksh"<<Amount-total<<endl;
     outfile<<"\n\n#######################################################################";
     receipt_close();}

void Receiptview(){
     cout<<"VIEW RECEIPT? yes,no"<<endl;
     cin>>decision;
     for(int i=0;i<3;i++){
     decision[i]=toupper(decision[i]);}
     if(decision=="YES"){
        system("CLS");
        ifstream file;
        char details[255];
        file.open("receipt.txt");
        while(!file.eof()){
        file.getline(details, 250);
        cout<<details<<"\n\n";}
        receipt_close();}
               }
int  main(){
    Welcomenote();
    Systemlogin();
    do{
    receipt_creation();
    ReceiptLayout();

    menudisplay();
    receiptGen();
    CustomerBalance();
    BaseDetails();
    Receiptview();
    cout<<"Receipt was successfully generated and saved"<<endl;
    cout<<"\nSatisfied? or CANCEL my meals order and START afresh? YES-CANCEL. NO-SATISFIED"<<endl;
    cin>>decision;
    for(int i=0;i<3;i++){
    decision[i]=toupper(decision[i]);}
    if(decision=="YES"){
    system("CLS");}
   }while(decision=="YES");
   return 0;
   }







