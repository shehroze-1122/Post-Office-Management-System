#include <iostream>
#include <Windows.h>
#include "Header.h"

int main()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
label:
	int choice;
	SetConsoleTextAttribute(console, 11); // set color for the next print
	cout << "\n\n\n\t\t\t-------------------- < POST OFFICE MANAGEMENT SYSTEM > --------------------\n\n\n";
	Postal_Services *user=new Postal_Services;
	user->Login(); //for logging in the user 

	while (1) //WHILE loop will be executed till the user enters zero  
	{
		SetConsoleTextAttribute(console, 11); // set color for the next print
		cout << "                  <<  ----------------------- ~ SERVICES OFFERED ~ ----------------------- >>\n\n\n" << endl;
		cout << "\n1. Registered post\n\n2. Parcel Booking\n\n3. Money Transfer\n\n4. Speed Post\n\n5. E-Card Booking\n\n6. Delete Account\n\n7. Log Out\n\n8. User Activity\n\n9. Contact Us\n\n0. Exit Program";
		//now using switch case Statements
	label1:
		cout << endl << endl;
		SetConsoleTextAttribute(console, 15); // set color for the next print
		while (cout << "\nEnter an OPTION number: " && !(cin >> choice)) //This is for restricting the user to only numbers 
		{
			cout << "\n Enter number only" << endl; //displayin' the message in case the user entered other a number
			cin.clear(); //clearing all the stream
			cin.ignore();
			SetConsoleTextAttribute(console, 12); // set color for the next print
		}
		cin.ignore(); //clearing the buffer stream
		switch (choice) //switch case statements
		{
		case 0: //if choice is 0
			break;
		case 1://if choice is 1
			user->Registered_post();
			break;
		case 2://if choice is 2
			user->Parcel_Booking();
			break;
		case 3://if choice is 3
			user->Money_Transfer();
			break;
		case 4://if choice is 4
			user->Speed_Post();
			break;
		case 5://if choice is5
			user->ECard_Booking();
			break;
		case 6://if choice is 6
			user->DeleteAccount();
			goto label;
		case 7://if choice is 7
			SetConsoleTextAttribute(console, 12); // set color for the next print
			cout << "\n\n\t\t\t LOGGING OUT";
			for (int i = 0; i < 5; ++i)
			{
				Sleep(1000);//sleep function which sleeps for 1 second in each iteration
				cout << ". ";
			}
			SetConsoleTextAttribute(console, 11); // set color for the next print
			cout << "\n\n SUCCESSFULLY LOGGED OUT . . . \n\n" << endl;
			system("pause");
			system("cls");
			goto label;
		case 8://if choice is 8
			user->User_Activity();
			break;
		case 9: //if choice is 10
			user->Contact_us();
			break;
		default://if choice is any other number
			SetConsoleTextAttribute(console, 12); // set color for the next print
			cout << "Enter an appropriate option. " << endl; //because the option entered is wrong
			goto label1;  //goto the statement where it would ask again the user about choice 
		}
		if (choice == 0)
		{
			SetConsoleTextAttribute(console, 12); // set color for the next print
			cout << "EXITING THE PROGRAM......" << endl;
			break; //breaking out of the while loop to terminate the program successfully.
		}
	}
	return 0;
}