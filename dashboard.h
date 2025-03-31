#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include "exam2.cpp"
#include "question2.cpp"
#include "score2.cpp"
#include "color.h"
using namespace std;
class Dashboard 
{
	public:
    	void displayDashboard(string username, bool isAdmin) 
		{
        	system("cls");
        	setColor(6);
        	cout << "=================================\n";
        	cout << "       DASHBOARD - " << username << " \n";
        	cout << "=================================\n";
        	setColor(7);
        	if (isAdmin) 
			{
            	adminDashboard();
        	} 
			else 
			{
            	userDashboard(username);
        	}
    	}

		void userDashboard(string username);
		void adminDashboard();
};
void Dashboard :: userDashboard(string username)
{
    		system("cls");
    		setColor(3);
    		cout << "=================================\n";
    		cout << "    Welcome, " << username << "! \n";
    		cout << "=================================\n";
    		setColor(7);

			Score s;
    		Exam exam;
    		cout << "1. Start Exam\n";
    		cout << "2. View Past Scores\n";
    		cout << "3. Logout\n";
    		cout << "Enter your choice: ";
    		int choice;
    		cin >> choice;
    
   			switch (choice) 
			{
        		case 1: 
            	{
				
					transitionEffect("Starting Exam...");
            		float score=exam.takeExam(username);
           			s.saveScore(username, exam.getSubject(), score);
            		s.showScore(score);
            		s.displayScoreChart(score);
            		cout << "\nPress any key to go back to Dashboard...";
            		cin.ignore(); 
            		cin.get();  
            		userDashboard(username);
            		break;
    			}
        		case 2: 
					s.viewUserScores(username);
		   			cout << "\nPress any key to go back to Dashboard...";
            		cin.ignore();
            		cin.get();  
            		userDashboard(username);
					break;
				
        		case 3: 
					mainMenu(); 
					return;
        		
				default:
            		cout << "Invalid choice! Try again.\n";
            	Sleep(1000);
            	userDashboard(username);  
    		}
}
void Dashboard :: adminDashboard()
{
    		system("cls");
    		setColor(6);
    		cout << "=================================\n";
    		cout << "      ADMIN CONTROL PANEL        \n";
    		cout << "=================================\n";
    		setColor(7);
			Question q;
    		Score s;
    		cout << "1. Add Question\n";
    		cout << "2. View Questions\n";
    		cout << "3. Delete Question\n";
    		cout << "4. View All User Scores\n";
    		cout << "5. Logout\n";
    		cout << "Enter your choice: ";
    		int choice;
    		cin >> choice;

    		switch (choice) 
			{
        		case 1: 
					q.addQuestion();
					cin.ignore();
    				cin.get(); 
					break;
        		case 2: 
					q.viewQuestions();
					cin.ignore();
    				cin.get(); 
					break;
        		case 3: 
					q.deleteQuestion(); 
					cin.ignore();
    				cin.get();
					break;
        		case 4: 
					s.viewAllScores();
    				cin.ignore();
    				cin.get();
					break;
        		case 5: 
					mainMenu(); 
					return;
        		default: 
            		cout << "Invalid choice! Try again.\n";
            	Sleep(1000);
            	adminDashboard();
    		}
}

#endif
