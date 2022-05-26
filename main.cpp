#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include"Equipments.h"
#include"File.h"

using namespace std;

//Show Credits
 void ShowPreview()
{
	cout<<"\n\n\n\n\t\t\t************************************************************************\n";
	cout<<"\t\t\t\t\t\t\tGYM Managment";
	cout<<"\n\t\t\t***********************************************************************\n";
	cout<<"\n\n\nDeveloped by Hassan Mahmood";
	cout<<"\n\n\nPress Any Key to continue..";
	getch();
	
}
int choice;
	string username,password,un,pw;
	
bool IsLoggedIn()
{
	cout<<"Enter the username: ";
	cin>>username;
	
	cout<<"Enter the password: ";
	cin>>password;
	
	ifstream read("Login.txt" );
	getline(read, un);
	getline(read, pw);
	
	if(un==username && pw==password)
	{
		return true;
		

	}
	else
	{
		return false;
	}
	
}
		



void menu()
{
	cout<<"----------------------Select any on option:----------------- \n"<<endl;
	cout << "===================================================="<<endl;
	cout<<"1.Register\n2.login\n";
	cout << "===================================================="<<endl;
	cin>>choice;
	if(choice==1)
	{
	cout << "\n\n===================================================="<<endl;
	cout<<"select the username: ";
	cin>>username;
	cout << "===================================================="<<endl;
	cout<<"select the password: ";
	cin>>password;

	ofstream file;
	file.open("Login.txt");
	file<<username<<endl<<password;
	file.close();
	
	}
	
	else if(choice==2)
	{
		
		bool status=IsLoggedIn();
		if(!status)
		{
			cout<<"----false login----"<<endl;
			
		}
		
		else
		{
			cout<<"----Sucessfully login---"<<endl;
			cout<<endl;
		}
	}
	
}
void gym_menu(){
	int i=0;
while(i == 0){
	menu();
i++;
//-------------------------------------------------------------------------------------------------------
cout << "\n\n\n\n===================================================="<<endl;	
cout<<"Enter 0 to return to Login Menu"<<endl;
cout << "===================================================="<<endl;	
cout<<"Enter any other number to Open Gym Managment System "<<endl;
cout << "===================================================="<<endl;	
cin>>i;
} 

}
//Main Function
int main()
{
	gym_menu();
	ShowPreview();
	int opt;
	while(1)
	{
		system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t1.Add New Record"<<endl;
		cout<<"\t\t\t2.Display Trainer Record "<<endl;
		cout<<"\t\t\t3.Display Member Record "<<endl;
		cout<<"\t\t\t4.Display Schedules "<<endl;
		cout<<"\t\t\t5.Delete  Record "<<endl;
		cout<<"\t\t\t6.Equipments and Exercises"<<endl;
		cout<<"\t\t\t7.Exit "<<endl;
		cout<<"\t\t\tEnter your Option : ";
		cin>>opt;
		switch(opt)
		{
			case 1:
			{
				Add();
				cout<<"\nDisplay Main Menu"<<endl;
				getch();
				break;
			}
			case 2:
			{
				DisplayAllTrainer();
				cout<<"\nDisplay Main Menu"<<endl;
				getch();
				break;
			}
			case 3:
			{
				DisplayAllMember();
				cout<<"\nDisplay Main Menu"<<endl;
				getch();
				break;
			}
			case 4:
			{
				Schedule();
				cout<<"\nDisplay Main Menu"<<endl;
				getch();
				break;
			}
			case 5:
			{
				Delete();
				cout<<"\nDisplay Main Menu"<<endl;
				getch();
				break;
			}
			case 6:
			{
				Equipments();
				break;
			}
			case 7:
			{
				exit(0);
			}
			
			default:
			{
				cout<<"Wrong Choice....Press Key For View the Main Menu";
				getch();
				system("cls");
			}
		}
	}
}
 
//end of program
