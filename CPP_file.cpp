#include<iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <map>
#include "Header.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
//member function for Logging in to the account or to create a new account
void Postal_Services::Login()
{
	//setting a label to jump back when needed
label:
	SetConsoleTextAttribute(console, 15); // set color for the next print
	cout << "\n\n         1.Login " << endl;
	cout << "         2.Create Account" << endl;
	cout << "         3.Admin Login" << endl;
	//asking a user to choose between logging in(if the user already has a account) or to create a account
	int ch1;
	SetConsoleTextAttribute(console, 15); // set color for the next print
	while (cout << "\nEnter an OPTION number: " && !(cin >> ch1)) //This is for restricting the user to only numbers 
	{
		SetConsoleTextAttribute(console, 12); // set color for the next print
		cout << "\n\n\nEnter number only... " << endl;
		cin.clear(); //clearing all the stream
		cin.ignore(); //getting ready for the next input 
		SetConsoleTextAttribute(console, 15); // set color for the next print
	}
	cin.ignore();//built in function to clear the input buffer
	system("cls");
	//if the user wants to log in
	if (ch1 == 1)
	{
		//setting up label1
	label1:
		//creating an object of ifstream and naming it as Create_User
		ifstream Create_User;
		//opening a file which contains all the account details of customers in input mode
		Create_User.open("Login_File.txt", ios::in);
		//checking if the file is really open to continue with
		if (Create_User.is_open())
		{
			//creating two string variables 
			string uname;//for username
			string pwd;//for password
					   //creating a boolean variable for login and assigning it to false
			bool log = false;
			SetConsoleTextAttribute(console, 13); // set color for the next print
			cout << "\n\n\t\t                               << LOGIN FORM >> " << endl << endl;
			//taking the username from the user
			cout << "Enter Username: ";
			cin >> uname;
			//taking the corressponding password from the user 
			cout << "\nEnter Password: ";
			cin >> pwd;
			SetConsoleTextAttribute(console, 12); // set color for the next print
			cout << "\nMatching Credentials";
			//for loop to show the system is matching the user's credentials to the accounts created in the file
			for (int i = 0; i < 5; ++i)
			{
				Sleep(1000);//sleep function which sleeps for 1 second in each iteration
				cout << ". ";
			}
			SetConsoleTextAttribute(console, 13); // set color for the next print
			//clearing the screen
			system("cls");
			//new line
			cout << "\n";
			// a int variable counter set to 0
			int counter = 0;
			// a while loop which runs as long as end of file is not met
			//eof() is a built in function in the fstream library which returms 1 when it meets the end of file
			while (!Create_User.eof())
			{
				//incrementing the variable counter to look for the line in the login file which matches the credentials of the user 
				++counter;
				// a string variable credentials
				string credentials;
				//two variables of the double type which will check if the credentials are found in the file or not
				double x, y;
				// using a getline function to read a line of file in each iteration 
				getline(Create_User, credentials);
				//find function returns string::npos if the string is not found in the line 
				x = credentials.find(uname, 0);//matching the username the user entered to the usernames in the file
				y = credentials.find(pwd, 0);//matching the password the user entered to the password in the file
											 // if the username is found in the line and also the password is found in the line of file the they wont return string::npos
											 // so proceding if the credentials match
				if (x != string::npos && y != string::npos)
				{
					// a string which is used to create a text file for each user
					username = uname;
					userfile_creator = uname + ".txt";
					//displaying the message
					SetConsoleTextAttribute(console, 11); // set color for the next print
					cout << "\n\n\nSuccessfully logged in !!!\n\n\n";
					//closing the file
					Create_User.close();
					//setting the line number from the file which matched the credentials to keep track of it
					Credentials_line_number = counter;
					// a login check boolean variable set to true
					login_check = true;
					system("pause");
					system("cls");
					//breaking from the loop
					break;

				}
			}
		}
		else
		{
			SetConsoleTextAttribute(console, 12); // set color for the next print
			cout << "\n\nThere is no existing account for this program.\n\nPlease Create a Account first . . .\n\n ";
			goto label2;
		}
		//checking if the login_check is false which will be true if the user was successfully logged in
		if (login_check == false)
		{
			SetConsoleTextAttribute(console, 12); // set color for the next print
			//telling the user that he has entered a wrong username or password or the account does not exist
			cout << "\n\n\nIncorrect Username or Password :(\n";
			//setting a label3
		label3:
			SetConsoleTextAttribute(console, 11); // set color for the next print
			//int variable to check for the user choice
			int ch2;
			//giving user a choice to either try again or create a user first
			cout << "\n1. Try Again\n";
			cout << "\n2. Create Account\n";
			//taking choice
			cin >> ch2;
			cin.ignore();
			//if users wants to try again
			if (ch2 == 1)
			{
				//clearing the screen
				system("cls");
				//jumping to label1
				goto label1;
			}
			//if the user wants to create a new account
			else if (ch2 == 2)
			{
				//clearing the screen
				system("cls");
				//jumping to label2
				goto label2;
			}
			//if the user enters something else
			else
			{
				SetConsoleTextAttribute(console, 12); // set color for the next print
				//displaying error
				cout << "Incorrect entry . . . Please enter a valid choice\n";
				//jumping to label3
				goto label3;
			}
		}

	}
	//if the user wants to create a new account
	else if (ch1 == 2)
	{
		//setting up label2
	label2:
	SetConsoleTextAttribute(console, 13); // set color for the next print
		cout << "\n\n\t\t                           << CREATE A NEW ACCOUNT >> \n" << endl;
		//taking username from the user
	label6:
		cout << "Enter Username (username should be a combination of some letters, followed by digits) : ";
		cin >> username;
		cin.ignore();
		// a int variable counter set to 0
		int counter = 0;
		// a while loop which runs as long as end of file is not met
		//opening a file which contains all the account details of customers in input mode
		//creating an object of ifstream and naming it as Create_User
		ifstream User;
		User.open("Login_File.txt", ios::in);
		//eof() is a built in function in the fstream library which returms 1 when it meets the end of file
		if (User.is_open())
		{
			while (!(User.eof()))
			{
				// a string variable credentials
				string credential;
				//two variables of the double type which will check if the credentials are found in the file or not
				double a;
				// using a getline function to read a line of file in each iteration 
				getline(User, credential);
				//find function returns string::npos if the string is not found in the line 
				a = credential.find(username, 0);//matching the username the user entered to the usernames in the file
				if (a != string::npos) //if the username is already existing then prompting the message that USERNAME already exists
				{
					SetConsoleTextAttribute(console, 12); // set color for the next print
					cerr << "         EXCEPTION CAUGHT: Username Already exists!" << endl;
					User.close();
					SetConsoleTextAttribute(console, 13); // set color for the next print
					goto label6;
				}
			}
		}
		//taking password from the user
		cout << "\nEnter Password: ";
		cin >> password;
		//taking Phone Number from the user
		cout << "\nEnter Phone Number: ";
		cin >> number;
		//taking Email Address from the user
		cout << "\nEnter Email: ";
		cin >> email;
		//taking Postal Code from the user
		cout << "\nEnter Postal Code: ";
		cin >> postal_code;
		//creating a object of ofstream class
		ofstream Create_User1;
		//opening a file named Login_File in append mode so that it does not overwrite
		Create_User1.open("Login_File.txt", ios::app);
		//writing all the info that user entered in the file 
		Create_User1 << "Username: " << username << "  " << "Password: " << password << "  " << "Phone Number: " << number << "  " << "Email: " << email << "  " << "Postal Code: " << postal_code << "\n";
		//closing the file
		Create_User1.close();
		//displaying the message
		SetConsoleTextAttribute(console, 11); // set color for the next print
		cout << "\n\n\n                                 << Successfully Created your account !!! >>\n" << endl;
		//pausing the screen so that it continues when user enters any key
		system("pause");
		//clearing the screen
		system("cls");
		//jumping back to label1
		goto label1;

	}
	else if (ch1 == 3)
	{
	    admin_login *user=new admin_login;
		user->Login();
		goto label;
    }
	//if users enters a invalid choice
	else
	{
	    SetConsoleTextAttribute(console, 12); // set color for the next print
		//displaying the error
		cout << "\n\n\nIncorrect entry . . . Please enter a valid choice\n";
		//jumping to label
		goto label;
	}
}

void Postal_Services::Speed_Post()
{    //SPEED POST BOOKING
	system("cls");
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cin.ignore(); //clearing the buffer
	cout << "\t\t\t                              << Sender INFORMATION >>  \n\n" << endl; //SENDER INFORMATION 
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "Enter Name: ";  //asking the name of SENDER
	getline(cin, Sender_Name);
	cin.ignore();
	cout << "Enter Address: "; //asking the address of SENDER
	getline(cin, Sender_Address);
	cin.ignore();
	cout << "Enter Pin Code: ";//asking the pincode 
	cin >> Sender_PinCode;
	cin.ignore();
	cout << "\nEnter City Name: "; //asking the city of SENDER
	getline(cin, Sender_City);
	cin.ignore();
	cout << "Enter State: "; //asking the state of SENDER
	getline(cin, Sender_State);
	cin.ignore();

	cout << "NOTE: The weight should not exceed 30kg\nEnter Weight (in Kg): "; //asking the weight of parcel
	cin >> Weight;
label:
	if (Weight > 0 && Weight <= 1) //upt0 1kg
		Cost = 100;
	else if (Weight > 1 && Weight <= 3) //upto 3kg
		Cost = 175;
	else if (Weight > 3 && Weight <= 5) //upto 5kg
		Cost = 250;
	else if (Weight > 5 && Weight <= 10)  //upto 10kg
		Cost = 375;
	else if (Weight > 10 && Weight <= 15)//upto 15kg
		Cost = 500;
	else if (Weight > 15 && Weight <= 20)//upto 20kg
		Cost = 625;
	else if (Weight > 20 && Weight <= 25) //upto 25kg
		Cost = 750;
	else if (Weight > 25 && Weight <= 30) //upto 30kg
		Cost = 875;
	else
		goto label; //if the weight exceeds 30kg
	cin.ignore();
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "\t\t\t                              << Reciever INFORMATION >>  \n\n" << endl; //now reciever information
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "Enter Name: "; //asking the name of reciever
	getline(cin, Reciever_Name);
	cin.ignore();
	cout << "Enter Address: "; //asking the address of reciever
	getline(cin, Reciever_Address);
	cin.ignore();
	cout << "Enter Pin Code: "; //asking the pincode of reciever
	cin >> Reciever_PinCode;
	cin.ignore();
	cout << "\nEnter City Name: ";  //asking the city of reciever
	getline(cin, Reciever_City);
	cin.ignore();
	cout << "Enter State: "; //asking the state of reciever
	getline(cin, Reciever_State);
	cin.ignore();
	ofstream User_file; //for saving into file 
	User_file.open(userfile_creator, ios::app); //opening the file of user
	User_file << "\t\t\t** Speed Post BOOKING *" << endl << endl; //writing in the file 

	User_file << "SENDER INFORMATION:" << endl;
	//writing all the details of sender information in the file using the USER_file pointer 
	User_file << "Name: " << Sender_Name << " Address: " << Sender_Address << " City: " << Sender_City << endl;
	User_file << "State: " << Sender_State << " Pin Code: " << Sender_PinCode << " Weight of Box: " << Weight << endl;
	cout << "\n\n" << endl;
	User_file << " RECIEVER INFORMATION: " << endl;
	//writing all the details of reciever information in the file using the USER_file pointer 
	User_file << "Name: " << Reciever_Name << " Address: " << Reciever_Address << " City: " << Reciever_City << endl;
	User_file << "State: " << Reciever_State << " Pin Code: " << Reciever_PinCode << endl;
	User_file << "COST: " << Cost + 150 << " Rs. " << endl;
	User_file << "\n\n " << endl;
	User_file.close(); //closing the user file after writing
	ofstream Booking; //for opening the BOOKING LIST file so that we can keep the records of the new orders
	Booking.open("Booking List.txt", ios::app); //opening the file in the append mode
	Booking << "***** By a User: " << username << endl; //
	Booking << " **** SPEED POST BOOKING *****" << endl;
	Booking << "SENDER INFORMATION:" << endl; //sender information being written in the booking lists
	//writing all the details of sender information in the file using the Booking pointer 
	Booking << "Name: " << Sender_Name << " Address: " << Sender_Address << " City: " << Sender_City << endl;
	Booking << "State: " << Sender_State << " Pin Code: " << Sender_PinCode << " Weight of Box: " << Weight << endl;
	Booking << " RECIEVER INFORMATION: " << endl; //Reciever information being written in the booking lists
	//writing all the details of reciever information in the file using the Booking pointer 
	Booking << "Name: " << Reciever_Name << " Address: " << Reciever_Address << " City: " << Reciever_City << endl;
	Booking << "State: " << Reciever_State << " Pin Code: " << Reciever_PinCode << endl;
	Booking << "COST: " << Cost + 150 << " Rs." << endl; //150 is because it's speed post BOOKING
	Booking << "\n\n " << endl;
	Booking.close(); //closing the Booking list file after writing
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "Checking Details ";
	for (int i = 0; i < 3; ++i)
	{
		Sleep(1000);//sleep function which sleeps for 1 second in each iteration
		cout << ". ";
	}
	SetConsoleTextAttribute(console, 11); // set color for the next print

	cout << "\n\n\n\t\t\t                     << Order SUCCEESSFULLY placed !!! >>\n" << endl;
	system("pause");
	system("cls");

}
void Postal_Services::Registered_post()
{
	system("cls");
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cin.ignore(); //clearing the buffer
	cout << "\t\t\t                              << Sender INFORMATION >>  \n\n" << endl; //SENDER INFORMATION 
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "Enter Name: ";  //asking the name of SENDER
	getline(cin, Sender_Name);
	cin.ignore();
	cout << "Enter Address: "; //asking the address of SENDER
	getline(cin, Sender_Address);
	cin.ignore();
	cout << "Enter Pin Code: ";//asking the pincode 
	cin >> Sender_PinCode;
	cin.ignore();
	cout << "\nEnter City Name: "; //asking the city of SENDER
	getline(cin, Sender_City);
	cin.ignore();
	cout << "Enter State: "; //asking the state of SENDER
	getline(cin, Sender_State);
	cin.ignore();
label:
	cout << "NOTE: The weight should not exceed 30kg\nEnter Weight (in Kg): "; //asking the weight of parcel
	cin >> Weight;
	if (Weight > 0 && Weight <= 1) //upt0 1kg
		Cost = 100;
	else if (Weight > 1 && Weight <= 3) //upto 3kg
		Cost = 175;
	else if (Weight > 3 && Weight <= 5) //upto 5kg
		Cost = 250;
	else if (Weight > 5 && Weight <= 10)  //upto 10kg
		Cost = 375;
	else if (Weight > 10 && Weight <= 15)//upto 15kg
		Cost = 500;
	else if (Weight > 15 && Weight <= 20)//upto 20kg
		Cost = 625;
	else if (Weight > 20 && Weight <= 25) //upto 25kg
		Cost = 750;
	else if (Weight > 25 && Weight <= 30) //upto 30kg
		Cost = 875;
	else
		goto label;
	cin.ignore();
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "\t\t\t                             << Reciever INFORMATION >>  \n\n" << endl; //now reciever information
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "Enter Name: "; //asking the name of reciever
	getline(cin, Reciever_Name);
	cin.ignore();
	cout << "Enter Address: "; //asking the address of reciever
	getline(cin, Reciever_Address);
	cin.ignore();
	cout << "Enter Pin Code: "; //asking the pincode of reciever
	cin >> Reciever_PinCode;
	cin.ignore();
	cout << "\nEnter City Name: ";  //asking the city of reciever
	getline(cin, Reciever_City);
	cin.ignore();
	cout << "Enter State: "; //asking the state of reciever
	getline(cin, Reciever_State);
	cin.ignore();
	ofstream User_file; //for saving into file 
	User_file.open(userfile_creator, ios::app); //opening the file of user
	User_file << "\t\t\t** Registered Post BOOKING *" << endl << endl; //writing in the file 

	User_file << "SENDER INFORMATION:" << endl;
	//writing all the details of sender information in the file using the USER_file pointer 
	User_file << "Name: " << Sender_Name << " Address: " << Sender_Address << " City: " << Sender_City << endl;
	User_file << "State: " << Sender_State << " Pin Code: " << Sender_PinCode << " Weight of Box: " << Weight << endl;

	cout << "\n\n" << endl;
	User_file << " RECIEVER INFORMATION: " << endl;
	//writing all the details of reciever information in the file using the USER_file pointer 
	User_file << "Name: " << Reciever_Name << " Address: " << Reciever_Address << " City: " << Reciever_City << endl;
	User_file << "State: " << Reciever_State << " Pin Code: " << Reciever_PinCode << endl;
	User_file << "COST: " << Cost + 75 << " Rs." << endl; //75 rupees is for delivery charges
	User_file << "\n\n " << endl;
	User_file.close(); //closing the user file after writing
	ofstream Booking; //for opening the BOOKING LIST file so that we can keep the records of the new orders
	Booking.open("Booking List.txt", ios::app); //opening the file in the append mode
	Booking << "***** By a User: " << username << endl; //
	Booking << " **** Registered POST BOOKING *****" << endl;
	Booking << "SENDER INFORMATION:" << endl; //sender information being written in the booking lists
											  //writing all the details of sender information in the file using the Booking pointer 
	Booking << "Name: " << Sender_Name << " Address: " << Sender_Address << " City: " << Sender_City << endl;
	Booking << "State: " << Sender_State << " Pin Code: " << Sender_PinCode << " Weight of Box: " << Weight << endl;
	Booking << " RECIEVER INFORMATION: " << endl; //Reciever information being written in the booking lists
												  //writing all the details of reciever information in the file using the Booking pointer 
	Booking << "Name: " << Reciever_Name << " Address: " << Reciever_Address << " City: " << Reciever_City << endl;
	Booking << "State: " << Reciever_State << " Pin Code: " << Reciever_PinCode << endl;
	Booking << "COST: " << Cost + 75 << " Rs." << endl; //75 rupees is for delivery charges
	Booking << "\n\n " << endl;
	Booking.close(); //closing the Booking list file after writing
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "Checking Details ";
	for (int i = 0; i < 3; ++i)
	{
		Sleep(1000);//sleep function which sleeps for 1 second in each iteration
		cout << ". ";
	}
	SetConsoleTextAttribute(console, 11); // set color for the next print

	cout << "\n\n\n\t\t\t                     << Order SUCCEESSFULLY placed !!! >>\n" << endl;
	system("pause");
	system("cls");
}
void Postal_Services::Parcel_Booking()
{
	system("cls");
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cin.ignore(); //clearing the buffer
	cout << "\t\t\t                              << Sender INFORMATION >>  \n\n" << endl; //SENDER INFORMATION 
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "Enter Name: ";  //asking the name of SENDER
	getline(cin, Sender_Name);
	cin.ignore();
	cout << "Enter Address: "; //asking the address of SENDER
	getline(cin, Sender_Address);
	cin.ignore();
	cout << "Enter Pin Code: ";//asking the pincode 
	cin >> Sender_PinCode;
	cin.ignore();
	cout << "\nEnter City Name: "; //asking the city of SENDER
	getline(cin, Sender_City);
	cin.ignore();
	cout << "Enter State: "; //asking the state of SENDER
	getline(cin, Sender_State);
	cin.ignore();
label:
	cout << "NOTE: The weight should not exceed 30kg\nEnter Weight (in Kg): "; //asking the weight of parcel
	cin >> Weight;
	if (Weight > 0 && Weight <= 1) //upt0 1kg
		Cost = 100;
	else if (Weight > 1 && Weight <= 3) //upto 3kg
		Cost = 175;
	else if (Weight > 3 && Weight <= 5) //upto 5kg
		Cost = 250;
	else if (Weight > 5 && Weight <= 10)  //upto 10kg
		Cost = 375;
	else if (Weight > 10 && Weight <= 15)//upto 15kg
		Cost = 500;
	else if (Weight > 15 && Weight <= 20)//upto 20kg
		Cost = 625;
	else if (Weight > 20 && Weight <= 25) //upto 25kg
		Cost = 750;
	else if (Weight > 25 && Weight <= 30) //upto 30kg
		Cost = 875;
	else
		goto label;
	cin.ignore();
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "\t\t\t                             << Reciever INFORMATION >>  \n\n" << endl; //now reciever information
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "Enter Name: "; //asking the name of reciever
	getline(cin, Reciever_Name);
	cin.ignore();
	cout << "Enter Address: "; //asking the address of reciever
	getline(cin, Reciever_Address);
	cin.ignore();
	cout << "Enter Pin Code: "; //asking the pincode of reciever
	cin >> Reciever_PinCode;
	cin.ignore();
	cout << "\nEnter City Name: ";  //asking the city of reciever
	getline(cin, Reciever_City);
	cin.ignore();
	cout << "Enter State: "; //asking the state of reciever
	getline(cin, Reciever_State);
	cin.ignore();
	ofstream User_file; //for saving into file 
	User_file.open(userfile_creator, ios::app); //opening the file of user
	User_file << "\t\t\t** Parcel BOOKING *" << endl << endl; //writing in the file 

	User_file << "SENDER INFORMATION:" << endl;
	//writing all the details of sender information in the file using the USER_file pointer 
	User_file << "Name: " << Sender_Name << " Address: " << Sender_Address << " City: " << Sender_City << endl;
	User_file << "State: " << Sender_State << " Pin Code: " << Sender_PinCode << " Weight of Box: " << Weight << endl;
	cout << "\n\n" << endl;
	User_file << " RECIEVER INFORMATION: " << endl;
	//writing all the details of reciever information in the file using the USER_file pointer 
	User_file << "Name: " << Reciever_Name << " Address: " << Reciever_Address << " City: " << Reciever_City << endl;
	User_file << "State: " << Reciever_State << " Pin Code: " << Reciever_PinCode << endl;
	User_file << "COST: " << Cost + 75 << " Rs." << endl; //75 rupees is for delivery charges
	User_file << "\n\n " << endl;
	User_file.close(); //closing the user file after writing
	ofstream Booking; //for opening the BOOKING LIST file so that we can keep the records of the new orders
	Booking.open("Booking List.txt", ios::app); //opening the file in the append mode
	Booking << "***** By a User: " << username << endl; //
	Booking << " **** Parcel BOOKING *****" << endl;
	Booking << "SENDER INFORMATION:" << endl; //sender information being written in the booking lists
											  //writing all the details of sender information in the file using the Booking pointer 
	Booking << "Name: " << Sender_Name << " Address: " << Sender_Address << " City: " << Sender_City << endl;
	Booking << "State: " << Sender_State << " Pin Code: " << Sender_PinCode << " Weight of Box: " << Weight << endl;
	Booking << " RECIEVER INFORMATION: " << endl; //Reciever information being written in the booking lists
												  //writing all the details of reciever information in the file using the Booking pointer 
	Booking << "Name: " << Reciever_Name << " Address: " << Reciever_Address << " City: " << Reciever_City << endl;
	Booking << "State: " << Reciever_State << " Pin Code: " << Reciever_PinCode << endl;
	Booking << "COST: " << Cost + 75 << " Rs." << endl; //75 rupees is for delivery charges
	Booking << "\n\n " << endl;
	Booking.close(); //closing the Booking list file after writing
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "Checking Details ";
	for (int i = 0; i < 3; ++i)
	{
		Sleep(1000);//sleep function which sleeps for 1 second in each iteration
		cout << ". ";
	}
	SetConsoleTextAttribute(console, 11); // set color for the next print
	cout << "\n\n\n\t\t\t                     << Order SUCCEESSFULLY placed !!! >>\n" << endl;
	system("pause");
	system("cls");
}
void Postal_Services::Money_Transfer()
{
	system("cls");
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "\t\t\t                              << Sender INFORMATION >>  \n\n" << endl; //SENDER INFORMATION 
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "Enter Name: ";//asking the name of SENDER
	getline(cin, Sender_Name);
	cin.ignore();
	cout << "Enter Address: ";//asking the address of SENDER
	getline(cin, Sender_Address);
	cin.ignore();
	cout << "Enter Pin Code: ";
	cin >> Sender_PinCode;//asking the pincode of SENDER
	cin.ignore();
	cout << "\nEnter City Name: ";
	getline(cin, Sender_City);//asking the city of SENDER
	cin.ignore();
	cout << "Enter State: ";
	getline(cin, Sender_State);//asking the state of SENDER
	cin.ignore();
	cout << "Enter Amount(in Rs.): "; //asking the amount being transferred
	cin >> Amount;
	cin.ignore();
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "\t\t\t                             << Reciever INFORMATION >>  \n\n" << endl; //now reciever information
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "Enter Name: ";
	getline(cin, Reciever_Name); //asking the name of reciever
	cin.ignore();
	cout << "Enter Address: ";
	getline(cin, Reciever_Address);
	cin.ignore(); //asking the name of reciever
	cout << "Enter Pin Code: ";
	cin >> Reciever_PinCode;//asking the pincode of reciever
	cin.ignore();
	cout << "\nEnter City Name: ";
	getline(cin, Reciever_City); //asking the city of reciever
	cin.ignore();
	cout << "Enter State: ";
	getline(cin, Reciever_State); //asking the state of reciever
	cin.ignore();
	ofstream User_file;
	User_file.open(userfile_creator, ios::app);
	User_file << "\t\t\t** MONEY TRANSFER *" << endl << endl;
	//writing all the details of sender information in the file using the USER_file pointer 
	User_file << "SENDER INFORMATION:" << endl;
	User_file << "Name: " << Sender_Name << " Address: " << Sender_Address << " City: " << Sender_City << endl;
	User_file << "State: " << Sender_State << " Pin Code: " << Sender_PinCode << " Amount: " << Amount << " Rs. " << endl;
	cout << "\n\n" << endl;
	//writing all the details of reciever information in the file using the USER_file pointer 
	User_file << " RECIEVER INFORMATION: " << endl;
	User_file << "Name: " << Reciever_Name << " Address: " << Reciever_Address << " City: " << Reciever_City << endl;
	User_file << "State: " << Reciever_State << " Pin Code: " << Reciever_PinCode << endl;
	User_file << "\n\n " << endl;
	User_file.close();//closing the user file after writing
	ofstream Booking; //for opening the BOOKING LIST file so that we can keep the records of the new orders
	Booking.open("Booking List.txt", ios::app); //opening the file in the append mode
	Booking << "***** By a User: " << username << endl; //
	Booking << " **** Money Transfer BOOKING *****" << endl;
	Booking << "SENDER INFORMATION:" << endl; //sender information being written in the booking lists
											  //writing all the details of sender information in the file using the Booking pointer 
	Booking << "Name: " << Sender_Name << " Address: " << Sender_Address << " City: " << Sender_City << endl;
	Booking << "State: " << Sender_State << " Pin Code: " << Sender_PinCode << " Amount: " << Amount << " Rs. " << endl;

	Booking << " RECIEVER INFORMATION: " << endl; //Reciever information being written in the booking lists
												  //writing all the details of reciever information in the file using the Booking pointer 
	Booking << "Name: " << Reciever_Name << " Address: " << Reciever_Address << " City: " << Reciever_City << endl;
	Booking << "State: " << Reciever_State << " Pin Code: " << Reciever_PinCode << endl;
	Booking << "\n\n " << endl;
	Booking.close(); //closing the Booking list file after writing
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "Checking Details ";
	for (int i = 0; i < 3; ++i)
	{
		Sleep(1000);//sleep function which sleeps for 1 second in each iteration
		cout << ". ";
	}
	SetConsoleTextAttribute(console, 11); // set color for the next print
	cout << "\n\n\n\t\t\t                     << Money SUCCEESSFULLY Transferred !!! >>\n" << endl;
	system("pause");
	system("cls");
}

void Postal_Services::ECard_Booking()
{
	system("cls");
	cin.ignore();
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "\t\t\t                              << Sender INFORMATION >>  \n\n" << endl; //SENDER INFORMATION 
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "Enter Name: "; //asking the name of SENDER
	getline(cin, Sender_Name);
	cin.ignore();
	cout << "Enter Address: "; //asking the address of SENDER
	getline(cin, Sender_Address);
	cin.ignore();
	cout << "Enter Pin Code: "; //asking the pincode of SENDER
	cin >> Sender_PinCode;
	cin.ignore();
	cout << "\nEnter City Name: "; //asking the city of SENDER
	getline(cin, Sender_City);
	cin.ignore();
	cout << "Enter State: "; //asking the state of SENDER
	getline(cin, Sender_State);
	cin.ignore();
	cout << "Enter Code of CARD: "; //asking the CODE OF CARD
	cin >> Code;
	cin.ignore();
	SetConsoleTextAttribute(console, 11); // set color for the next print
	cout << "\n\nAuthenticating Details";
	for (int i = 0; i < 5; ++i)
	{
		Sleep(1000);//sleep function which sleeps for 1 second in each iteration
		cout << ". ";
	}
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "\n\t\t\t                              << Reciever INFORMATION >>  \n\n" << endl; //now reciever information
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "Enter Name: "; //asking the name of reciever
	getline(cin, Reciever_Name);
	cin.ignore();
	cout << "Enter Address: "; //asking the address of reciever
	getline(cin, Reciever_Address);
	cin.ignore();
	cout << "Enter Pin Code: "; //asking the pincode of reciever
	cin >> Reciever_PinCode;
	cin.ignore();
	cout << "\nEnter City Name: "; //asking the city of reciever
	getline(cin, Reciever_City);
	cin.ignore();
	cout << "Enter State: "; //asking the state of reciever
	getline(cin, Reciever_State);
	cin.ignore();
	int cost = 300;
	ofstream User_file;
	User_file.open(userfile_creator, ios::app);
	User_file << "\t\t\t** E-CARD BOOKING *" << endl << endl;
	//writing all the details of sender information in the file using the USER_file pointer
	User_file << "SENDER INFORMATION:" << endl;
	User_file << "Name: " << Sender_Name << " Address: " << Sender_Address << " City: " << Sender_City << endl;
	User_file << "State: " << Sender_State << " Pin Code: " << Sender_PinCode << " CODE of CARD: " << Code << endl;
	cout << "\n\n" << endl;
	//writing all the details of reciever information in the file using the USER_file pointer
	User_file << " RECIEVER INFORMATION: " << endl;
	User_file << "Name: " << Reciever_Name << " Address: " << Reciever_Address << " City: " << Reciever_City << endl;
	User_file << "State: " << Reciever_State << " Pin Code: " << Reciever_PinCode << endl;
	User_file << "Cost: " << cost;
	User_file << "\n\n " << endl;
	User_file.close(); //closing the user file after writing
	ofstream Booking; //for opening the BOOKING LIST file so that we can keep the records of the new orders
	Booking.open("Booking List.txt", ios::app); //opening the file in the append mode
	Booking << "***** By a User: " << username << endl; //
	Booking << " **** E-Card BOOKING *****" << endl;
	Booking << "SENDER INFORMATION:" << endl; //sender information being written in the booking lists
											  //writing all the details of sender information in the file using the Booking pointer 
	Booking << "Name: " << Sender_Name << " Address: " << Sender_Address << " City: " << Sender_City << endl;
	Booking << "State: " << Sender_State << " Pin Code: " << Sender_PinCode << " CODE of CARD: " << Code << endl;
	Booking << " RECIEVER INFORMATION: " << endl; //Reciever information being written in the booking lists
												  //writing all the details of reciever information in the file using the Booking pointer 
	Booking << "Name: " << Reciever_Name << " Address: " << Reciever_Address << " City: " << Reciever_City << endl;
	Booking << "State: " << Reciever_State << " Pin Code: " << Reciever_PinCode << endl;
	Booking << "Cost: " << cost;
	Booking << "\n\n " << endl;
	Booking.close(); //closing the Booking list file after writing
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "Checking Details ";
	for (int i = 0; i < 3; ++i)
	{
		Sleep(1000);//sleep function which sleeps for 1 second in each iteration
		cout << ". ";
	}
	SetConsoleTextAttribute(console, 11); // set color for the next print
	cout << "\n\n\n\t\t\t                     << Order SUCCEESSFULLY placed !!! >>\n" << endl;
	system("pause");
	system("cls");
}
void Postal_Services::DailyPostalBookingReport()
{
	system("cls");
	SetConsoleTextAttribute(console, 11); // set color for the next print
	ifstream Booking; //for displaying the order placed by the user
	string list; //for getting the words from the file
	Booking.open("Booking List.txt", ios::in); //opening the file in input mode to see the contents of the file
	if (Booking.is_open())
	{
		while (!Booking.eof()) // a while loop which runs as long as end of file is not met
				//eof() is a built in function in the fstream library which returms 1 when it meets the end of file
		{
			getline(Booking, list); //getting the words and storing it in the list variable
			cout << list << endl; //now displaying all the orders 
			cout << endl;
		}
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\tThere are no records to show . . . \n\n\n";
	}
	system("pause");
	system("cls");
}

void Postal_Services::DeleteAccount()
{
	system("cls");
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "Deleting your account ";
	//showing progress
	for (int i = 0; i < 5; ++i)
	{
		Sleep(1000);//function to sleep for 1 second
		cout << ". ";
	}
	//creating a object of ofstream class named temp_file
	//it is a temporary file created to omit the currently opened account and write all others to this file 
	ofstream temp_file;
	//opening new_file in output mode so as to overwrite each time
	temp_file.open("new_file.txt", ios::out);
	//a string variable line
	string line;
	//setting up line counter
	int line_counter = 0;
	//creating a object of ifstream class named Delete_cd to read the data from login file
	ifstream Delete_cd;
	//opening login file in input mode
	Delete_cd.open("Login_File.txt", ios::in);
	//opening the file created against the user in the out and trunc mode so as to empty all the records from it
	ofstream clear_data(userfile_creator, ios::out | ios::trunc);
	//closing the file
	clear_data.close();
	//while loop which runs until the end of file is met
	while (!(Delete_cd.eof()))
	{
		//incrementing line counter
		++line_counter;
		//using getline to read from the login file
		getline(Delete_cd, line);
		//checking if the line counter is not equal to the line where the current user's credentials are
		//we will skip that credentials line to write in temp file
		if (Credentials_line_number != line_counter)
		{
			//writing to temporary file
			temp_file << line << endl;
		}
	}
	//closing both the files
	Delete_cd.close();
	temp_file.close();
	//creating a object of ofstream class named updated_cd
	ofstream updated_cd;
	//opening file in output mode so as to overwrite
	updated_cd.open("Login_File.txt", ios::out);
	//creating a object of ifstream class named temp_file1
	ifstream temp_file1;
	//opening new_file in input mode so as to read from it
	temp_file1.open("new_file.txt", ios::in);
	//while loop which runs until the end of file is met
	while (!(temp_file1.eof()))
	{
		//using getline to read from the temporary file which does not create the deleted credentials
		getline(temp_file1, line);
		//writing the line into login file so that it gets updated
		updated_cd << line << endl;
	}
	//closing files
	updated_cd.close();
	temp_file1.close();
	//displaying messages
	SetConsoleTextAttribute(console, 11); // set color for the next print
	cout << "\n\nSuccessfully Deleted your account !!!" << endl;
	cout << "\n\nPress any key to continue . . . ";
	//getting a character from the user to continue
	getchar();
	//clearing screen
	system("cls");
}
void Postal_Services::User_Activity()
{
	system("cls");
	SetConsoleTextAttribute(console, 11); // set color for the next print
	ifstream User_file; //for displaying the order placed by the user
	string orders; //for getting the words from the file 
	User_file.open(userfile_creator, ios::in); //ios::in is used for showing contents of the file on the CONSOLE 
	if (User_file.is_open())
	{
		while (!User_file.eof())// a while loop which runs as long as end of file is not met
				//eof() is a built in function in the fstream library which returms 1 when it meets the end of file
		{
			getline(User_file, orders); //getting the words and storing it in ORDERS
			cout << orders << endl; // displayin' the orders now :)
		}
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\tThere are no records to show . . . \n\n\n";
	}
	system("pause");
	system("cls");
}
void Postal_Services::Contact_us()
{
	SetConsoleTextAttribute(console, 11); // set color for the next print
	system("cls");
	cout << "\n\n\t\t\t\t           << Emails >>\n\n\t\t\t           stalat.bee19seecs@seecs.edu.pk\n\t\t\t           amateen.bee19seecs@seecs.edu.pk\n\t\t\t           asial.bee19seecs@seecs.edu.pk\n" << endl;
	cout << "\t\t\t                   <<Phone >>\n\n\t\t\t\t          0349-2501150\n\t\t\t\t          0306-5598796\n\t\t\t\t          0349-9743368\n\n\n";
	system("pause");
	system("cls");
}
void admin_login::Login()
{
	labela:
	string auname,apwd;
	SetConsoleTextAttribute(console, 13); // set color for the next print
	cout << "\nEnter Username: ";
	cin >> auname;
	cout << "\n\nEnter Password: ";
	cin >> apwd;
	SetConsoleTextAttribute(console, 12); // set color for the next print
	cout << "\nMatching Credentials";
	//for loop to show the system is matching the user's credentials to the accounts created in the file
	for (int i = 0; i < 5; ++i)
	{
		Sleep(1000);//sleep function which sleeps for 1 second in each iteration
		cout << ". ";
	}
	cout << "\n\n\n";
	if ((auname == "shehroze11" && apwd == "she1122") || (auname == "mateen12" && apwd == "mat1122") || (auname == "ahsan13" && apwd == "ahs1122"))
	{
		SetConsoleTextAttribute(console, 11); // set color for the next print
		cout << "Successfully Logged in to Admin Account . . .\n\n\n";
		system("pause");
		system("cls");
		Postal_Services admin;
	labelc:
		SetConsoleTextAttribute(console, 11); // set color for the next print
		cout << "\n\n\n          1.Daily Postal Booking Report\n\n";
		cout << "          2.Users Account Details\n\n";
		cout << "          3.Log out\n";
		int ch3;
		cin >> ch3;
		if (ch3 == 1)
		{
			admin.DailyPostalBookingReport();
			system("pause");
			system("cls");
			goto labelc;

		}
		else if (ch3 == 2)
		{
			//creating an object of ifstream and naming it as Create_User
			ifstream Create_User;
			//opening a file which contains all the account details of customers in input mode
			Create_User.open("Login_File.txt", ios::in);
			//checking if the file is really open to continue with
			string line;
			int count = 0;
			SetConsoleTextAttribute(console, 11); // set color for the next print
			if (Create_User.is_open())
			{
			
				while (!(Create_User.eof()))
				{
					getline(Create_User, line);
					cout << line<<"\n\n";
					if (line != "")
					{
						++count;
					}
				}
			SetConsoleTextAttribute(console, 12); // set color for the next print
			cout << "\n\n                     << There are total " << count << " Accounts Created >>\n\n";
			SetConsoleTextAttribute(console, 11); // set color for the next print
			system("pause");
			system("cls");
			}
			else
			{
				SetConsoleTextAttribute(console, 12); // set color for the next print
				cout << "\n\n                << There is no data to show . . . No Accounts Created >>\n\n";
			}
			SetConsoleTextAttribute(console, 11); // set color for the next print
			system("pause");
			system("cls");
			goto labelc;

		}
		else if (ch3 == 3)
		{
			system("pause");
			system("cls");
		}
		else
		{
			SetConsoleTextAttribute(console, 12); // set color for the next print
			//displaying error
			cout << "\n\n                     << Incorrect entry . . . Please enter a valid choice >>\n";
			SetConsoleTextAttribute(console, 11); // set color for the next print
			system("pause");
			system("cls");
			//jumping to label3
			goto labelc;
		}

	}
	else
	{
		SetConsoleTextAttribute(console, 12); // set color for the next print
		cout << "                Incorrect Username or Password :(\n\n" << endl;
	labelb:
		SetConsoleTextAttribute(console, 11); // set color for the next print
		//int variable to check for the user choice
		int ch3;
		//giving user a choice to either try again or create a user first
		cout << "\n1. Try Again\n";
		cout << "\n2. Main Menu\n";
		//taking choice
		cin >> ch3;
		cin.ignore();
		//if users wants to try again
		if (ch3 == 1)
		{
			//clearing the screen
			system("cls");
			//jumping to label1
			goto labela;
		}
		//if the user wants to go to the main menu
		else if (ch3 == 2)
		{
			system("cls");
		}
		//if the user enters something else
		else
		{
			SetConsoleTextAttribute(console, 12); // set color for the next print
			//displaying error
			cout << "Incorrect entry . . . Please enter a valid choice\n";
			//jumping to label3
			goto labela;
		}
		
	}
}