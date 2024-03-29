#pragma once
#include<iostream>
#include<Windows.h>
#include <string>
#include <vector>
using namespace std;

class Postal_Services
{
private: //private ACCESS SPECIFIER


	bool login_check = false; //login checking variable
	string userfile_creator; //for creating the user file naming username
	string username; //username variable
	string password; //for user password
	string number; //for user number
	string email; //for email of user
	string postal_code; //postal code of user 
	string Sender_Name; //SENDER name 
	string Sender_Address; //sender address
	double Sender_PinCode; //pincode of sender
	string Sender_City; //city of sender
	string Sender_State; //SEnder's state
	double Weight; //weight of the parcel
	double Cost; //cost of the booking
	//now creating the variables for reciever credentials
	string Reciever_Name;
	string Reciever_Address;
	string Reciever_PinCode;
	string Reciever_City;
	string Reciever_State;
	string Amount;
	string Code; //CODE OF ECARD BOOKING
	int Credentials_line_number;
public:
	//public access specifier 
	//FUNCTION PROTOTYPES for the services being provided to the user
	virtual void Login();
	void Registered_post();
	void Parcel_Booking();
	void Money_Transfer();
	void Speed_Post();
	void ECard_Booking();
	void DeleteAccount();
	void DailyPostalBookingReport();
	void User_Activity();
	void Contact_us();
};
//for the services offered in the menu ,functions will be created inside the class
class admin_login :private Postal_Services
{
public:
	virtual void Login();
};