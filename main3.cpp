#include "user2.cpp"
#include "score2.cpp"
#include "dashboard.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "color.h"
#include "exam2.cpp"
using namespace std;
void transitionEffect(string message) 
{
    system("cls");
    setColor(6);
    cout << "\n===============================\n";
    cout << message << "\n";
    cout << "===============================\n";
    Sleep(1000);
    setColor(7);
}
void loadingBar() 
{
    system("cls");
    setColor(3);
    cout << "=========================================\n";
    cout << "   Initializing Exam Preparation System...    \n";
    cout << "=========================================\n";
    setColor(6);

    int barWidth = 30;
    cout << "╔";
    for (int i = 0; i < barWidth; i++) cout << "═";
    cout << "╗\n║";
    for (int i = 0; i < barWidth; i++) cout << " ";
    cout << "║ 0%";  
    cout.flush();
    
    cout << "\r║";  

    for (int i = 0; i <= barWidth; i++) 
	{
        cout << "#";  
        cout.flush();
        Sleep(70);

        cout << "\r║";
        for (int j = 0; j <= i; j++) cout << "#";
        for (int j = i; j < barWidth; j++) cout << " ";
        cout << "║ " << (i * 100) / barWidth << "%";
    }

    cout << "\n╚";
    for (int i = 0; i < barWidth; i++) cout << "═";
    cout << "╝\n";
    
    setColor(2);
    cout << "System Ready!\n\n";
    setColor(7);
    Sleep(2000);
}

void examTimer(int seconds) 
{
    for (int i = seconds; i >= 0; i--) 
	{
        system("cls");
        setColor(4);
        cout << "=====================================\n";
        cout << "   Time Remaining: " << i << " seconds \n";
        cout << "=====================================\n";
        Sleep(1000);
    }
    setColor(7);
}


void mainMenu() 
{
    system("cls");
    setColor(2);
    cout << "╔═════════════════════════════════╗\n";
    cout << "║   EXAM PREPARATION SYSTEM       ║\n";
    cout << "╠═════════════════════════════════╣\n";
    setColor(6);
    cout << "║ 1. Register                     ║\n";
    cout << "║ 2. Login                        ║\n";
    cout << "║ 3. Exit                         ║\n";
    setColor(2);
    cout << "╚═════════════════════════════════╝\n";
    setColor(7);
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    User user;
    bool isAdmin=false;
   	string username;

    if (choice == 1) 
	{
		user.registerUser();
	}
    else if (choice == 2) 
	{
		if (user.loginUser(isAdmin)) 
		{
			username=user.getUsername();
			Dashboard dashboard;
            if (isAdmin) 
			{
                transitionEffect("Redirecting to Admin Panel...");
                cout << "\nAdmin Access Granted!\n";
                Sleep(1000);
                dashboard.adminDashboard(); 
            } 
			else 
			{
            	transitionEffect("Redirecting to User Dashboard...");
                dashboard.userDashboard(username); 
            }
        }
    } 
	else 
	{
        exit(0);
    }
}
int main() {
	system("chcp 65001 > nul");
    loadingBar();
    mainMenu();
    return 0;
}
