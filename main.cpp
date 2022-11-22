#include<iostream>
#include<fstream>
#include<strstream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<cstring>
#include<iomanip>
#include <conio.h>
#include<cstdlib>
#include <stdlib.h>
#include<time.h>

//globalvariables
double data[100];
int counter = 0;
int op = 0;
int userlvl = 0;
char exitFlag, op2;
std::string process;
int scost[5];



//admininfo
char name[50], cntctNmbr[50], email[50], rLoginUsrnm[50], rLoginPsswrd[50];
std::string nameOfHotel = "Stargazers Hotel", adminUsrnm = "Admin", adminPsswrd = "12345";



class HOTEL {
private:
	int room_no;
	std::string firstname;
	std::string lastname;
	
	char address[50];
	char phone[15];
	long days;
	long cost;
	long totalcost;
	long tax;
	char rtype[30];
	long pay;
	int  receipt;

	void breakfast(int);        
	void lunch(int);            
	void dinner(int);           
	char loginUsername[100];
	char loginPassword[100];
	int randomNum;


public:
	void startUp();
	void registration();
	void adminLogin();
	void clientLogin();
	void clientMenu();
	void topFaP();
	void price();
	void ext();
	void adminMenu();	 	  
	void add();		
	void add2();			
	void display(); 		  
	void rooms();			 
	void edit();			  
	int check(int);		  
	void modify();		  
	void delete_rec();              
	void restaurant();	          
	void modify_name(int);         
	void modify_address(int);       
	void modify_phone(int);        
	void modify_days(int);          
};

//****************************************CLOSE AND STARTUP**************************************************

void HOTEL::startUp() {
	while (exitFlag != '1')
	{
		system("cls");
		std::cout << "\n\t\t\t+_ _ _ + _ _ _ + Stargazers Hotel + _ _ _ + _ _ _+" << std::endl;
		std::cout << "\t\t\t|                                                |" << std::endl;
		std::cout << "\t\t\t+                                                +" << std::endl;
		std::cout << "\t\t\t|                Welcome User!                   |" << std::endl;
		std::cout << "\t\t\t+                                                +" << std::endl;
		std::cout << "\t\t\t|                Login as:                       |" << std::endl;
		std::cout << "\t\t\t+                [1]Login as an Admin            +" << std::endl;
		std::cout << "\t\t\t|                [2]Enter as a Client            |" << std::endl;
		std::cout << "\t\t\t+                [x]Exit                         +" << std::endl;
		std::cout << "\t\t\t|                                                |" << std::endl;
		std::cout << "\t\t\t+ _ _ _ + _ _ _ + _ _ _ + _ _ _ + _ _ _ + _ _ _ +" << std::endl;
		std::cout << "\n\t\t\t\t\tChoose an option: ";
		std::cin >> op2;

		switch (op2)
		{
		case '1': adminLogin();
			break;
		case '2': clientLogin();
			break;
		case 'X':
		case 'x': ext();
			break;
		default: std::cout << "\n\t\t\t\t\tInvalid input!\n" << std::endl;
			_getch();
		}
	}
	
};

void HOTEL::ext() {
	system("cls");
	std::cout << "\n\t\t\t+ _ _ + _ _ _ + Stargazers  Hotel + _ _ _ + _ _ +" << std::endl;
	std::cout << "\t\t\t|\t   Thank you for your visit user!\t|" << std::endl;
	std::cout << "\t\t\t+ _ _ _ + _ _ _ + _ _ _ + _ _ _ + _ _ _ + _ _ _ +" << std::endl;
	exit(0);
};

void HOTEL::price() {
	system("cls");
	int rtype = 0, r = 0;
	long pos, flag = 0;

	std::ifstream fin("Prices.txt", std::ios::in | std::ios::binary);
	fin >> data[1];
	fin >> data[2];
	fin >> data[3];

		std::cout << "\n\t\t\t +-----------------------+-----------+";
		std::cout << "\n\t\t\t |  Room Types Available |   Price   |";
		std::cout << "\n\t\t\t +-----------------------+-----------+";
		std::cout << "\n\t\t\t   [1]Deluxe            |   " << data[1];
		std::cout << "\n\t\t\t   [2]Executive         |   " << data[2];
		std::cout << "\n\t\t\t   [3]Presidential      |   " << data[3];
		std::cout << "\n\t\t\t +-----------------------+-----------+";
		
		std::cout << "\n\t\t\t   [0]Back                            ";
		std::cout << "\n\t\t\t   [x]Exit                		    ";
		std::cout << "\n\t\t\t +-----------------------+-----------+";

	fin.close();

	
	std::cout << "\n\t\t\tEnter type of room to edit: ";
	std::cin >> op2;

	std::fstream fout("Prices.txt", std::ios::in | std::ios::out | std::ios::binary);
	std::cout << "\n\t\t\tEnter new price: ";

	switch (op2)
		{
		case '1':
			std::cin >> data[1];
			break;
		case '2':
			
			std::cin >> data[2];
			break;
		case '3': std::cin >> data[3];
			break;
		case 'X':
		case 'x': ext();
			break;
		default: std::cout << "\n\t\t\t\t\tInvalid input!\n" << std::endl;
			_getch();
		}

	fout << data[1] << std::endl;
	fout << data[2] << std::endl;
	fout << data[3] << std::endl;
	
	std::cout << "\n\t\t\tEdit Successful";
	fout.close();

	getchar();
	getchar();
	
}




//*******************************ADMIN LOGIN******************************************


void HOTEL::adminLogin() {
	system("cls");
	std::cout << "\n\t\t\t+ _ _ _ + _ _ _+ Stargazers  Hotel +_ _ _ + _ _ _ +" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t+            Enter your Admin Credentials         +" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t+ _ _ _ + _ _ _ + _ _ _  + _ _ _ +  _ _ _ + _ _ _ +" << std::endl;
	std::cout << "\n\t\t\t\t\tUsername: ";
	std::cin >> loginUsername;
	std::cout << "\t\t\t\t\tPassword: ";
	std::cin >> loginPassword;
	if (loginUsername == adminUsrnm && loginPassword == adminPsswrd)
	{

		std::cout << "\n\n\t\t\tLogin Successful! Press any key to continue.";
		getchar();
		_getch();
		adminMenu();
	}
	else
	{
		std::cout << "\n\n\t\t\t   Wrong Username or Password! " << std::endl;
		std::cout << "\n\t\t\t     Press [y] or [Y[ to re-enter your admin credentials" << std::endl;
		std::cout << "\t\t\t     Press [0] to go back to login screen" << std::endl;
		std::cout << "\t\t\t     Press [x] to exit the program" << std::endl;
		std::cout << "\n\t\t\t   Choose an option: ";
		std::cin >> op2;

		switch (op2)
		{
		case 'y':
			system("cls");
			adminLogin();
			break;
		case '0':
			system("cls");
			startUp();
			break;
		case 'X':
		case 'x': ext();
			break;
		default: std::cout << "\n\t\t\t\t\tInvalid input!\n" << std::endl;
			_getch();
		}
	}
};



//**************************************-CLIENT LOGIN AND REGISTRATION************************************
void HOTEL::clientLogin() {
	int count{ 0 };
	std::string userId, password, id, pass;

	system("cls");
	/*
	std::cout << "\n_ _ _ _ _ _ _" << nameOfHotel << "_ _ _ _ _ _ _" << std::endl;
	std::cout << "\tEnter User credentials\n";
	std::cout << "\t[1]Continue" << std::endl;
	std::cout << "\t[0]Back" << std::endl;
	std::cout << "\tChoose an option: ";

	*/
	std::cout << "\n\t\t\t+ _ _ _ + _ _ _+ Stargazers  Hotel +_ _ _ + _ _ _ +" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t|                   Client Menu                   |" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t|                 [1]Login                        |" << std::endl;
	std::cout << "\t\t\t|                 [2]Register                     |" << std::endl;
	std::cout << "\t\t\t|                 [0]Go Back                      |" << std::endl;
	std::cout << "\t\t\t|                 [x]Exit                         |" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t+ _ _ _ + _ _ _ + _ _ _  + _ _ _ +  _ _ _ + _ _ _ +" << std::endl;

	std::cout << "\n\t\t\t\t\tChoose an option: ";
	std::cin >> op2;

	if (op2 == '1')
	{
		std::cout << "\t\t\t\t\tUsername: ";
		std::cin >> userId;
		std::cout << "\t\t\t\t\tPassword: ";
		std::cin >> password;
		std::ifstream input("Clientrecords.txt");
		while (input >> id >> pass) {
			if (id == userId && pass == password) {
				count = 1;
				system("cls");
			}
		}
		input.close();

		if (count == 1) {
			std::cout << "\n\t\t\t+ _ _ _ + _ _ _+ Stargazers  Hotel +_ _ _ + _ _ _ +" << std::endl;
			std::cout << "\t\t\t                                                   " << std::endl;
			std::cout << "\t\t\t             Welcome  " << userId << std::endl;
			std::cout << "\t\t\t             Your LOGIN is successful          \n";
			std::cout << "\t\t\t                                                   ";
			std::cout << "\n\t\t\t+ _ _ _ + _ _ _ + _ _ _  + _ _ _ +  _ _ _ + _ _ _ +" << std::endl;
			_getch();
			clientMenu();
			_getch();
		}
		else {
			std::cout << "\n Login Failed \n Please check your username and password";
			clientLogin();
		}

	}
	if (op2 == '2') {
		registration();
	}
	if (op2 == '0') {
		startUp();
	}
	if (op2 == 'x' || op2 == 'X') {
		ext();
	}
	else {
		std::cout << "Invalid input!";
		std::cout << "Press Enter to Retry!";
		_getch();
		clientLogin();

	}
};

void HOTEL::registration() {
	system("cls");
	std::string ruserId, rpassword, rid, pass;
	/*
	 std::cout << "\n_ _ _ _ _ _ _" << nameOfHotel << "_ _ _ _ _ _ _" << std::endl;
	std::cout << "\tEnter User credentials\n";
	std::cout << "\t[1]Continue" << std::endl;
	std::cout << "\t[0]Back" << std::endl;
	std::cout << "\tChoose an option: ";
	std::cin >> op;
	*/

	std::cout << "\n\t\t\t+ _ _ _ + _ _ _+ Stargazers  Hotel +_ _ _ + _ _ _ +" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t|           Register for Stargazers Hotel         |" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t|              [1]Enter User Credentials          |" << std::endl;
	std::cout << "\t\t\t|              [0]Go Back                         |" << std::endl;
	std::cout << "\t\t\t|              [x]Exit                            |" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t+ _ _ _ + _ _ _ + _ _ _  + _ _ _ +  _ _ _ + _ _ _ +" << std::endl;

	std::cout << "\n\t\t\t\t\tChoose an option: ";
	std::cin >> op2;

	if (op2 == '1')
	{
		std::cout << "\t\t\t\tEnter Username: ";
		std::cin >> ruserId;
		std::cout << "\t\t\t\tEnter Password: ";
		std::cin >> rpassword;
		std::ofstream f1("Clientrecords.txt", std::ios::app);
		f1 << ruserId << ' ' << rpassword << std::endl;

		system("cls");
	
		std::cout << "\n\t\t\t+ _ _ _ + _ _ _+ Stargazers  Hotel +_ _ _ + _ _ _ +" << std::endl;
		std::cout << "\t\t\t                                                   " << std::endl;
		std::cout << "\t\t\t             Welcome  " << ruserId << std::endl;
		std::cout << "\t\t\t             Your Registration is successful          \n";
		std::cout << "\t\t\t                                                   ";
		std::cout << "\n\t\t\t+ _ _ _ + _ _ _ + _ _ _  + _ _ _ +  _ _ _ + _ _ _ +" << std::endl;
		_getch();
		clientMenu();
	}

	if (op2 == '0'){
		startUp();
	}
	if (op2 == 'x' || op2 == 'X') {
		ext();
	}

	else {
		std::cout << "\tWrong input enter Y to continue!: ";
		std::cin >> process;
		if (process == "Y" or process == "y") {
			registration();
		}
	}
};

//*****************************************CLIENT MENU********************************************
void HOTEL::clientMenu() {
	system("cls");

	std::cout << "\n\t\t\t+ _ _ _ + _ _ _+ Stargazers  Hotel +_ _ _ + _ _ _ +" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t|                   Booking Menu                  |" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t|        [1]View Rooms & Service Offered          |" << std::endl;
	std::cout << "\t\t\t|                 [2]Book Now                     |" << std::endl;
	std::cout << "\t\t\t|                 [0]Go Back                      |" << std::endl;
	std::cout << "\t\t\t|                 [x]Exit                         |" << std::endl;
	std::cout << "\t\t\t|                                                 |" << std::endl;
	std::cout << "\t\t\t+ _ _ _ + _ _ _ + _ _ _  + _ _ _ +  _ _ _ + _ _ _ +" << std::endl;

	std::cout << "\t\t\t\tChoose an option: ";
	std::cin >> op2;
	switch (op2)
	{
	case '1': topFaP();
		break;
	case '2': add2();
		break;
	case '0': clientLogin();
		break;
	case 'X':
	case 'x': ext();
		break;
	default:
		std::cout << "\n\t\t\tWrong input enter Y to continue!: ";
		std::cin >> process;
		if (process == "Y" or process == "y") {
			clientLogin();
		}
	}
}

void HOTEL::topFaP() {
	system("cls");

	std::ifstream fin("Prices.txt", std::ios::in | std::ios::binary);
	fin >> data[1];
	fin >> data[2];
	fin >> data[3];

	std::cout << "\n\t\t\t +---------------+------Stargazers Hotel+-------+-------------------+" << std::endl;
	std::cout << "\t\t\t +-----------------------+----------------------+-------------------+" << std::endl;
	std::cout << "\t\t\t | Type of Room  |      Description             |  Cost per day     |" << std::endl;
	std::cout << "\t\t\t +-----------------------+----------------------+-------------------+" << std::endl;
	std::cout << "\t\t\t |  Deluxe       |  M Bed + TV                  |      P" << data[1] << "        |" << std::endl;
	std::cout << "\t\t\t |  Executive    |  L Bed + TV + Breakfast      |      P" << data[2] << "        |" << std::endl;
	std::cout << "\t\t\t |  Presidential |  2 L Bed + TV + Breakfast    |      P" << data[3] << "        |" << std::endl;
	std::cout << "\t\t\t +-----------------------+----------------------+-------------------+" << std::endl;

	fin.close();

	/* 
	std::ifstream input;
	input.open("topFaP.txt", std::ios::in);
	if (input.is_open()) {
		std::string line;
		while (getline(input, line)) {
			std::cout << "\t" << line << std::endl;
		}
		input.close();
	}
	*/
	

	_getch();
	_getch();
	clientMenu();
};



//********************************ADMIN MENUS*************************************************

void HOTEL::adminMenu()
{
	int choice{ 0 };
	while (choice != 6)
	{
		system("cls");
	
		std::cout << "\n\t\t\t+ _ _ _ + _ _ _+ Stargazers  Hotel +_ _ _ + _ _ _ +" << std::endl;
		std::cout << "\t\t\t|                                                 |" << std::endl;
		std::cout << "\t\t\t+                   Admin Menu                    +" << std::endl;
		std::cout << "\t\t\t|                                                 |" << std::endl;
		std::cout << "\t\t\t+                [1]Book a Room                   +" << std::endl;
		std::cout << "\t\t\t|                [2]View Customer Info            |" << std::endl;
		std::cout << "\t\t\t+                [3]View Rooms Alloted            +" << std::endl;
		std::cout << "\t\t\t|                [4]Edit Customer Details         |" << std::endl;
		std::cout << "\t\t\t+                [5]Edit Costs                    +" << std::endl;
		std::cout << "\t\t\t|                [0]Go Back                       |" << std::endl;
		std::cout << "\t\t\t+                [x]Exit                          +" << std::endl;
		std::cout << "\t\t\t|                                                 |" << std::endl;
		std::cout << "\t\t\t+ _ _ _ + _ _ _ + _ _ _  + _ _ _ +  _ _ _ + _ _ _ +" << std::endl;



		std::cout << "\n\t\t\tEnter Your Choice: ";
		std::cin >> op2;
		switch (op2)
		{
		case '1': add();
			break;
		case '2': display();
			break;
		case '3': rooms();
			break;
		case '4': edit();
			break;
		case '5': price();
			break;
		case 'X':
		case 'x': ext();
			break;
		case '0': adminLogin();
		default:
		{
			std::cout << "\n\n\t\t\tWrong choice.";
			std::cout << "\n\t\t\tPress any key to continue.";
			getchar();
		}
		}
	}
}



int HOTEL::check(int r)
{
	int flag = 0;
	std::ifstream fin("Record.dat", std::ios::in | std::ios::binary);
	while (fin.read((char*)this, sizeof(HOTEL)))
	{
		if (room_no == r)
		{
			flag = 1;
			break;
		}
		else
		{
			if (r > 100)
			{
				flag = 2;
				break;
			}
		}
	}
	fin.close();
	return(flag);
}


void HOTEL::display()
{
	system("cls");
	std::ifstream fin("Record.dat", std::ios::in | std::ios::binary);
	int r, flag{ 0 };
	std::cout << "\n Enter Room Number: ";
	std::cin >> r;
	while (fin.read((char*)this, sizeof(HOTEL)))
	{
		if (room_no == r)
		{
			system("cls");
			std::cout << "\n Customer Details";
			std::cout << "\n ----------------";
			std::cout << "\n\n Room Number: " << room_no;
			std::cout << "\n First Name: " << firstname;
			std::cout << "\n Last Name: " << lastname;
			std::cout << "\n Address: " << address;
			std::cout << "\n Phone Number: " << phone;
			std::cout << "\n Staying for " << days << " days.";
			std::cout << "\n Room Type: " << rtype;
			std::cout << "\n Total cost of stay: " << cost;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		std::cout << "\n Room is Vacant.";
	std::cout << "\n\n Press any key to continue.";
	getchar();
	getchar();
	fin.close();

}


void HOTEL::rooms()
{
	system("cls");


	const char separator = ' ';
	const int NoWidth = 8;
	const int GuestWidth = 17;
	const int Guest2Width = 17;
	const int AddressWidth = 15;
	const int RoomWidth = 13;
	const int ContactNoWidth = 13;
	const int DaysWidth = 19;
	const int ReceiptWidth = 12;
	const int CostWidth = 19;
	std::ifstream fin("Record.dat", std::ios::in | std::ios::binary);
	
	std::cout << "\n\t\t\t\t\t\t\t    LIST OF ROOMS ALLOTED";
	std::cout << "\n\t\t\t\t\t\t\t   -----------------------";
	std::cout << "\n\n +---------+------------------+------------------+----------------+--------------+--------------+--------------------+-------------+--------------------+";
	std::cout << "\n | Room No.|    First Name    |     Last Name    |     Address    |   Room Type  |  Contact No. | No. of Days Stayed | Receipt No. |      Amount Due    |";
	std::cout << "\n +---------+------------------+------------------+----------------+--------------+--------------+--------------------+-------------+--------------------+";
	while (fin.read((char*)this, sizeof(HOTEL)))
	{
		tax = cost * .1;
		totalcost = cost + tax;
		std::cout << "\n |" << std::setw(NoWidth) << std::setfill(separator) << room_no << " |";
		std::cout << std::setw(GuestWidth) << std::setfill(separator) << firstname << " |";
		std::cout << std::setw(Guest2Width) << std::setfill(separator) << lastname << " |";
		std::cout << std::setw(AddressWidth) << std::setfill(separator) << address << " |";
		std::cout << std::setw(RoomWidth) << std::setfill(separator) << rtype << " |";
		std::cout << std::setw(ContactNoWidth) << std::setfill(separator) << phone << " |";
		std::cout << std::setw(DaysWidth) << std::setfill(separator) << days << " |";
		std::cout << std::setw(ReceiptWidth) << std::setfill(separator) << receipt << " |";
		std::cout << std::setw(CostWidth) << std::setfill(separator) << totalcost << " |";
	}
	std::cout << "\n +---------+------------------+------------------+----------------+--------------+--------------+--------------------+-------------+--------------------+";
	std::cout << "\n Press any key to continue.";
	getchar();
	getchar();
	fin.close();
}

void HOTEL::edit()
{
	system("cls");
	int choice;
	std::cout << "\n EDIT MENU";
	std::cout << "\n ---------";
	std::cout << "\n\n 1. Modify Customer Information.";
	std::cout << "\n 2. Customer Check Out.";
	std::cout << "\n Enter your choice: ";
	std::cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:	modify();
		break;
	case 2:	delete_rec();
		break;
	default: std::cout << "\n Wrong Choice.";
		break;
	}
	std::cout << "\n Press any key to continue.";
	getchar();
	getchar();
}



void HOTEL::modify()
{
	system("cls");
	int ch, r;
	
	std::cout << "\n MODIFY MENU";
	std::cout << "\n -----------";
	std::cout << "\n\n\n 1. Modify Name";
	std::cout << "\n 2. Modify Address";
	std::cout << "\n 3. Modify Phone Number";
	std::cout << "\n 4. Modify Number of Days of Stay";
	std::cout << "\n Enter Your Choice: ";
	std::cin >> ch;
	system("cls");
	
	const char separator = ' ';
	const int NoWidth = 8;
	const int GuestWidth = 17;
	const int Guest2Width = 17;
	const int AddressWidth = 15;
	const int RoomWidth = 13;
	const int ContactNoWidth = 13;
	const int DaysWidth = 19;
	const int ReceiptWidth = 12;
	const int CostWidth = 19;
	std::ifstream fin("Record.dat", std::ios::in | std::ios::binary);


	std::cout << "\n\t\t\t\t\t\t\t    LIST OF ROOMS ALLOTED";
	std::cout << "\n\t\t\t\t\t\t\t   -----------------------";
	std::cout << "\n\n +---------+------------------+------------------+----------------+--------------+--------------+--------------------+-------------+--------------------+";
	std::cout << "\n | Room No.|    First Name    |     Last Name    |     Address    |   Room Type  |  Contact No. | No. of Days Stayed | Receipt No. |    Amount Due      |";
	std::cout << "\n +---------+------------------+------------------+----------------+--------------+--------------+--------------------+-------------+--------------------+";
	while (fin.read((char*)this, sizeof(HOTEL)))
	{
		tax = cost * .1;
		totalcost = cost + tax;
		std::cout << "\n |" << std::setw(NoWidth) << std::setfill(separator) << room_no << " |";
		std::cout << std::setw(GuestWidth) << std::setfill(separator) << firstname << " |";
		std::cout << std::setw(Guest2Width) << std::setfill(separator) << lastname << " |";
		std::cout << std::setw(AddressWidth) << std::setfill(separator) << address << " |";
		std::cout << std::setw(RoomWidth) << std::setfill(separator) << rtype << " |";
		std::cout << std::setw(ContactNoWidth) << std::setfill(separator) << phone << " |";
		std::cout << std::setw(DaysWidth) << std::setfill(separator) << days << " |";
		std::cout << std::setw(ReceiptWidth) << std::setfill(separator) << receipt << " |";
		std::cout << std::setw(CostWidth) << std::setfill(separator) << totalcost << " |";
	}
	std::cout << "\n +---------+------------------+------------------+----------------+--------------+--------------+--------------------+-------------+--------------------+";

	std::cout << "\n Enter Room Number: ";
	std::cin >> r;
	switch (ch)
	{
	case 1: modify_name(r);
		break;
	case 2: modify_address(r);
		break;
	case 3: modify_phone(r);
		break;
	case 4: modify_days(r);
		break;
	default: std::cout << "\n Wrong Choice";
		getchar();
		getchar();
		break;
	}
}

void HOTEL::modify_name(int r)
{
	
	long pos, flag = 0;
	std::fstream file("Record.dat", std::ios::in | std::ios::out | std::ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char*)this, sizeof(HOTEL));
		if (room_no == r)
		{
			std::cout << "\n Enter new first Name: ";
			std::cin >> firstname;
			std::cout << "\n Enter new last Name: ";
			std::cin >> lastname;
			file.seekg(pos);
			file.write((char*)this, sizeof(HOTEL));
			std::cout << "\n Customer Name has been modified.";
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		std::cout << "\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::modify_address(int r)
{
	long pos, flag = 0;
	std::fstream file("Record.dat", std::ios::in | std::ios::out | std::ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char*)this, sizeof(HOTEL));
		if (room_no == r)
		{
			std::cout << "\n Enter New Address: ";
			std::cin >> address;
			file.seekg(pos);
			file.write((char*)this, sizeof(HOTEL));
			std::cout << "\n Customer Address has been modified.";
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		std::cout << "\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::modify_phone(int r)
{
	long pos, flag = 0;
	std::fstream file("Record.dat", std::ios::in | std::ios::out | std::ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char*)this, sizeof(HOTEL));
		if (room_no == r)
		{
			std::cout << "\n Enter New Phone Number: ";
			std::cin >> phone;
			file.seekg(pos);
			file.write((char*)this, sizeof(HOTEL));
			std::cout << "\n Customer Phone Number has been modified.";
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		std::cout << "\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::modify_days(int r)
{
	long pos, flag = 0;

	std::ifstream fin("Prices.txt", std::ios::in | std::ios::binary);
	fin >> data[1];
	fin >> data[2];
	fin >> data[3];


	std::fstream file("Record.dat", std::ios::in | std::ios::out | std::ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char*)this, sizeof(HOTEL));
		if (room_no == r)
		{
			std::cout << " Enter New Number of Days of Stay: ";
			std::cin >> days;
			if (room_no >= 1 && room_no <= 50)
			{
				strcpy_s(rtype, "Deluxe");
				cost = days * data[1];
			}
			else
			{
				if (room_no >= 51 && room_no <= 80)
				{
					strcpy_s(rtype, "Executive");
					cost = days * data[2];
				}
				else
				{
					if (room_no >= 81 && room_no <= 100)
					{
						strcpy_s(rtype, "Presidential");
						cost = days * data[3];
					}
				}
			}
			file.seekg(pos);
			file.write((char*)this, sizeof(HOTEL));
			std::cout << "\n Customer information is modified.";
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		std::cout << "\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	fin.close();
	file.close();
}

void HOTEL::delete_rec()
{
	int r, flag = 0;
	char ch;
	std::cout << "\n Enter Room Number: ";
	std::cin >> r;
	std::ifstream fin("Record.dat", std::ios::in | std::ios::binary);
	std::ofstream fout("temp.txt", std::ios::out | std::ios::binary);
	while (fin.read((char*)this, sizeof(HOTEL)))
	{
		if (room_no == r)
		{
			std::cout << "\n First Name: " << firstname;
			std::cout << "\n Last Name: " << lastname;
			std::cout << "\n Address: " << address;
			std::cout << "\n Phone Number: " << phone;
			std::cout << "\n Room Type: " << rtype;
			std::cout << "\n Your total bill is: P " << cost;
			std::cout << "\n\n Do you want to check out this customer(y/n): ";
			std::cin >> ch;
			if (ch == 'n')
				fout.write((char*)this, sizeof(HOTEL));
			else
				std::cout << "\n Customer Checked Out.";
			flag = 1;
		}
		else
			fout.write((char*)this, sizeof(HOTEL));
	}
	fin.close();
	fout.close();
	if (flag == 0)
		std::cout << "\n Sorry, Room is Vacant.";
	else
	{
		remove("Record.dat");
		rename("temp.txt", "Record.dat");
	}
	getchar();
	getchar();
}

void HOTEL::add()
{
	
	system("cls");
	int r = 0, flag, r2 = 0;

	


	std::ofstream fout("Record.dat", std::ios::app | std::ios::binary);
	std::ifstream fin("Prices.txt", std::ios::in | std::ios::binary);
	fin >> data[1];
	fin >> data[2];
	fin >> data[3];


	std::cout << "\n\t\t\t +-----------------------+----------------------+";
	std::cout << "\n\t\t\t | Rooms  |   Room Type  | Current Cost per day |";
	std::cout << "\n\t\t\t +-----------------------+----------------------+";
	std::cout << "\n\t\t\t |   1-50 |    Deluxe    |        P" << data[1] << "         |";
	std::cout << "\n\t\t\t |  51-80 |   Executive  |        P" << data[2] << "         |";
	std::cout << "\n\t\t\t | 81-100 | Presidential |        P" << data[3] << "         |";
	std::cout << "\n\t\t\t +-----------------------+----------------------+";
	std::cout << "\n\n ENTER CUSTOMER DETAILS";
	std::cout << "\n ----------------------";
	std::cout << "\n\nRoom Number: ";
	std::cin >> r;
	flag = check(r);

	if (flag == 1) {
		std::cout << "\n Room is already booked.\n";
		_getch();
	}
	else
	{
		if (flag == 2)
			std::cout << "\n Room does not exist.\n";
		else
		{
			r2 = rand() % (1000000 - 1 + 1) + 1;
			flag = check(r2);
			if (flag == 1) {
				for (int i = 0; flag != 0; i++) {
					r2 = rand() % (1000000 - 1 + 1) + 1;
					if (i == 1000000) {
						std::cout << "Record is full!, Please Delete Some Records!";
						add2();
					}
				}
			}

			room_no = r;
			receipt = r2;

			std::cout << "Firstname: ";
			std::cin >> firstname;
			std::cout << "Lastname: ";
			std::cin >> lastname;
			std::cout << "Address: ";
			std::cin >> address;
			std::cout << "Phone Number: ";
			std::cin >> phone;
			std::cout << "Number of Days of Stay: ";
			std::cin >> days;

			


			if (room_no >= 1 && room_no <= 50)
			{
				strcpy_s(rtype, "Deluxe");
				cost = days * data[1];
			}
			else
			{
				if (room_no >= 51 && room_no <= 80)
				{
					strcpy_s(rtype, "Executive");
					cost = days * data[2];
				}
				else
				{
					if (room_no >= 81 && room_no <= 100)
					{
						strcpy_s(rtype, "Presidential");
						cost = days * data[3];
					}
				}
			}
			tax = cost * 0.1;
			totalcost = cost + tax;

			fout.write((char*)this, sizeof(HOTEL));
			std::cout << "\n Room has been booked.";
			std::cout << "\n Receipt No.:" << receipt;
			std::cout << "\n Booking Price: " << cost;
			std::cout << "\n Value Added Tax: " << tax;
			std::cout << "\n Total Cost: " << totalcost;

			
		}
		fin.close();
		fout.close();
		
	}
	std::cout << "\n Press any key to continue.";
	_getch();
	adminMenu();
}

void HOTEL::add2()
{
	system("cls");
	int r=0, r2=0, flag = 0, t=0;
	
	std::ifstream fin("Prices.txt", std::ios::in | std::ios::binary);
	fin >> data[1];
	fin >> data[2];
	fin >> data[3];

	std::ofstream fout("Record.dat", std::ios::app | std::ios::binary);

	std::cout << "\n\t\t\t +-----------------------+-----------------+";
	std::cout << "\n\t\t\t |  Room Types Available |   Cost per day  |";
	std::cout << "\n\t\t\t +-----------------------+-----------------+";
	std::cout << "\n\t\t\t |  [1]Deluxe            |     P" << data[1] << "       |";
	std::cout << "\n\t\t\t |  [2]Executive         |     P" << data[2] << "       |";
	std::cout << "\n\t\t\t |  [3]Presidential      |     P" << data[3] << "       |";
	std::cout << "\n\t\t\t +-----------------------+-----------------+";
	std::cout << "\n\n\t\t\t SELECT THE TYPE OF ROOM YOU WANT TO BOOK: ";
	std::cin >> t;

	if (t == 1) {
		srand(time(NULL));
		 r = rand() % (50 - 1 + 1) + 1;
		 flag = check(r);
		 if (flag == 1) {
			 for (int i = 0; flag != 0; i++) {
				 r = rand() % (50 - 1 + 1) + 1;
				 if (i == 50) {
					 std::cout << "All rooms are booked, try another type of room!";
					 add2();
				 }
			 }
		 }
		 
		 r2 = rand() % (1000000 - 1 + 1) + 1;
		 flag = check(r2);
		 if (flag == 1) {
			 for (int i = 0; flag != 0; i++) {
				 r2 = rand() % (1000000 - 1 + 1) + 1;
				 if (i == 1000000) {
					 std::cout << "Record is full!, Please Delete Some Records!";
					 add2();
				 }
			 }
		 }


		 room_no = r;
		 receipt = r2;

		 std::cout << "\t\t\t\t Firstname: ";
		 std::cin >> firstname;
		 std::cout << "\t\t\t\t Lastname: ";
		 std::cin >> lastname;
		 std::cout << "\t\t\t\t Address: ";
		 std::cin >> address;
		 std::cout << "\t\t\t\t Phone Number: ";
		 std::cin >> phone;
		 std::cout << "\t\t\t\t Number of Days of Stay: ";
		 std::cin >> days; 

		 strcpy_s(rtype, "Deluxe");
		 cost = days * data[1];
	}

	if (t == 2) {
		srand(time(NULL));
		r = rand() % (80 - 51 + 1) + 51;
		flag = check(r);
		if (flag == 1) {
			for (int i = 0; flag != 0; i++) {
				r = rand() % (80 - 51 + 1) + 51;
				if (i == 50) {
					std::cout << "All rooms are booked, try another type of room!";
					add2();
				}
			}
		}
		r2 = rand() % (1000000 - 1 + 1) + 1;
		flag = check(r2);
		if (flag == 1) {
			for (int i = 0; flag != 0; i++) {
				r2 = rand() % (1000000 - 1 + 1) + 1;
				if (i == 1000000) {
					std::cout << "Record is full!, Please Delete Some Records!";
					add2();
				}
			}
		}

		room_no = r;
		receipt = r2;
		std::cout << "\t\t\t\t Firstname: ";
		std::cin >> firstname;
		std::cout << "\t\t\t\t Lastname: ";
		std::cin >> lastname;
		std::cout << "\t\t\t\t  Address: ";
		std::cin >> address;
		std::cout << "\t\t\t\t  Phone Number: ";
		std::cin >> phone;
		std::cout << "\t\t\t\t  Number of Days Stay: ";
		std::cin >> days;
		strcpy_s(rtype, "Executive");
		cost = days * data[2];

	}

	if (t == 3) {
		r = rand() % (100 - 81 + 1) + 81;
		flag = check(r);
		if (flag == 1) {
			for (int i = 0; flag != 0; i++) {
				r = rand() % (100 - 81 + 1) + 81;
				if (i == 50) {
					std::cout << "\t\t\t\t  All rooms are booked, try another type of room!";
					add2();
				}
			}
		}
		r2 = rand() % (1000000 - 1 + 1) + 1;
		flag = check(r2);
		if (flag == 1) {
			for (int i = 0; flag != 0; i++) {
				r2 = rand() % (1000000 - 1 + 1) + 1;
				if (i == 1000000) {
					std::cout << "Record is full!, Please Delete Some Records!";
					add2();
				}
			}
		}

		room_no = r;
		receipt = r2;
		std::cout << "\t\t\t\t Firstname: ";
		std::cin >> firstname;
		std::cout << "\t\t\t\t Lastname: ";
		std::cin >> lastname;
		std::cout << "\t\t\t\t Address: ";
		std::cin >> address;
		std::cout << "\t\t\t\t Phone Number: ";
		std::cin >> phone;
		std::cout << "\t\t\t\t Number of Days Stay: ";
		std::cin >> days;

		strcpy_s(rtype, "Presidential");
		cost = days * data[3];

		
	}

	//std::cin >> r;
	//flag = check(r);

	//if (flag == 1) {
	//	std::cout << "\n Sorry, Room is already booked.\n";
	//	_getch();
	//}
	//else
	//{
	//	if (flag == 2)
	//		std::cout << "\n Sorry, Room does not exist.\n";
	//	else
	//	{
	//		room_no = r;
	//		std::cout << " Name: ";
	//		std::cin >> name;
	//		std::cout << " Address: ";
	//		std::cin >> address;
	//		std::cout << " Phone Number: ";
	//		std::cin >> phone;
	//		std::cout << " Number of Days Stay: ";
	//		std::cin >> days;
	//		if (room_no >= 1 && room_no <= 50)
	//		{
	//			strcpy_s(rtype, "Deluxe");
	//			cost = days * 10000;
	//		}
	//		else
	//		{
	//			if (room_no >= 51 && room_no <= 80)
	//			{
	//				strcpy_s(rtype, "Executive");
	//				cost = days * 12500;
	//			}
	//			else
	//			{
	//				if (room_no >= 81 && room_no <= 100)
	//				{
	//					strcpy_s(rtype, "Presidential");
	//					cost = days * 15000;
	//				}
	//			}
	//		}
	//		fout.write((char*)this, sizeof(HOTEL));
	//		std::cout << "\n Room has been booked.";
	//	}
	//	fout.close();
	//}
	fout.write((char*)this, sizeof(HOTEL));
	fout.close();
	fin.close();
	
	
	system("cls");
	tax = cost * 0.1;
	totalcost = cost + tax;


	std::cout << "\n\n\n\t\t\t +-----------------------+----------------------+";
	std::cout << "\n\t\t\t |              Room has been booked            |";
	std::cout << "\n\t\t\t +-----------------------+----------------------+";
	std::cout << "\n\t\t\t    Guest Name: " << firstname << " "<< lastname << "";
	std::cout << "\n\t\t\t    Room number: " << r << "                     ";
    std::cout << "\n\t\t\t    Your booking cost: " << cost <<"             ";
	std::cout << "\n\t\t\t    Value added tax: " << tax << "               ";
	std::cout << "\n\t\t\t                                                 ";
	std::cout << "\n\t\t\t    Total cost: " << totalcost << "              ";
	std::cout << "\n\t\t\t                                                 ";
	std::cout << "\n\t\t\t                                                 ";
	std::cout << "\n\t\t\t               Receipt number: " << r2 << "      ";
	std::cout << "\n\t\t\t                  Enjoy your stay!               ";
	std::cout << "\n\t\t\t +-----------------------+----------------------+";
	

	std::cout << "\n\n\t\t\t\t Press any key to continue.";
	_getch();
	clientMenu();
}


/*
void HOTEL::restaurant()
{
	system("cls");
	int r, ch, num;
	cout << "\n RESTAURANT MENU:";
	cout << "\n --------------- ";
	cout << "\n\n 1. Order Breakfast\n 2. Order Lunch\n 3. Order Dinner";
	cout << "\n\n Enter your choice: ";
	cin >> ch;
	system("cls");
	cout << " Enter Room Number: ";
	cin >> r;
	switch (ch)
	{
	case 1: breakfast(r);
		break;

	case 2: lunch(r);
		break;

	case 3: dinner(r);
		break;
	}
	cout << "\n\n Press any key to continue.";
	getchar();
	getchar();
	return;
}

void HOTEL::breakfast(int r)
{
	int num, flag = 0;
	long pos;
	cout << " Enter number of people: ";
	cin >> num;
	fstream file("Record.txt", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char*)this, sizeof(HOTEL));
		if (room_no == r)
		{
			pay = 500 * num;
			cost = cost + pay;
			file.seekg(pos);
			file.write((char*)this, sizeof(HOTEL));
			cout << "\n Amount added to the bill: Rs. " << pay;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}


void HOTEL::lunch(int r)
{
	int num, flag = 0;
	long pos;
	cout << " Enter number of people: ";
	cin >> num;
	fstream file("Record.txt", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char*)this, sizeof(HOTEL));
		if (room_no == r)
		{
			pay = 1000 * num;
			cost = cost + pay;
			file.seekg(pos);
			file.write((char*)this, sizeof(HOTEL));
			cout << "\n Amount added to the bill: Rs. " << pay;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}


void HOTEL::dinner(int r)
{
	int num, flag = 0;
	long pos;
	cout << " Enter number of people: ";
	cin >> num;
	fstream file("Record.txt", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char*)this, sizeof(HOTEL));
		if (room_no == r)
		{
			pay = 1200 * num;
			cost = cost + pay;
			file.seekg(pos);
			file.write((char*)this, sizeof(HOTEL));
			cout << "\n Amount added to the bill: Rs. " << pay;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}

*/

int main()
{
	HOTEL h;
	system("cls");
	h.startUp();
	return 0;
}