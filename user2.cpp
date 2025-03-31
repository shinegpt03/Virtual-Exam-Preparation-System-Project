#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>  // For Sleep() {windows specific functionalities}
#include "dashboard.h"
#include "color.h"
using namespace std;
class User 
{
	protected:
		string username;
    	string password;

	public:
		void registerUser();
		bool loginUser(bool &isAdmin);
		string getUsername() { return username; }
};
void User :: registerUser() 
{
    system("cls");
    setColor(6);
    cout << "=================================\n";
    cout << "         USER REGISTRATION       \n";
    cout << "=================================\n";
    setColor(7);

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    setColor(2);
    cout << "\nRegistration Successful!\n";
    setColor(7);

    cout << "\nDo you want to login now? (Y/N): ";
    char choice;
    cin >> choice;
    
    if (choice == 'Y' || choice == 'y') 
	{
    	bool isAdmin=false;
        loginUser(isAdmin);  
    } 
	else 
	{
        mainMenu();  
    }
}

bool User :: loginUser(bool &isAdmin) 
{
    system("cls");
    setColor(6);
    cout << "=================================\n";
    cout << "           USER LOGIN            \n";
    cout << "=================================\n";
    setColor(7);

    string fileUser, filePass;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");
    bool found = false;
    while (file >> fileUser >> filePass) 
	{
        if (fileUser == username && filePass == password) 
		{
            found = true;
            break;
        }
    }
    file.close();

    if (found) 
	{
        setColor(2);
        cout << "\nLogin Successful! Redirecting...\n";
        setColor(7);
        Sleep(1000);
        
        isAdmin = (username == "admin");
        Dashboard dashboard;
        dashboard.displayDashboard(username, isAdmin);
		return true;

    } 
	else 
	{
        setColor(4);
        cout << "\nInvalid Credentials. Try Again!\n";
        setColor(7);
        Sleep(1000);
        mainMenu();
        return false; 
    }
}