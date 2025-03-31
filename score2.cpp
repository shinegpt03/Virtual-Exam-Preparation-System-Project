#ifndef SCORE2_H
#define SCORE2_H

#include "dashboard.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>  
#include "color.h"
#include "exam2.cpp"
using namespace std;
class Score 
{
	public:
    	void saveScore(string username, string subject, float score);
    	void viewUserScores(string username);
    	void viewAllScores();
    	void displayScoreChart(float score) 
		{
    		system("cls");
    		setColor(6);
    		cout << "=====================================\n";
    		cout << "    SCORE ANALYSIS                  \n";
    		cout << "=====================================\n";

    		cout << "\nScore: " << score << "%\n";
    		cout << "[";
    		for (int i = 0; i < (score / 2); i++) cout << "█";  
    		for (int i = score / 2; i < 50; i++) cout << " ";
    		cout << "]\n";

    		setColor(2);
    		if (score > 80) 
			{
				cout << "Excellent Performance!\n";
			}
			else if (score > 50) 
			{
				cout << "Good Job, Keep Improving!\n";
			}
    		else 
    		{
    			cout << "Needs More Practice. Try Again!\n";
			}
    		setColor(7);
		}
		void showScore(int finalScore) 
		{
    		system("cls");
    		setColor(3);
    		cout << "Calculating Score...\n";
    		setColor(6);
    		for (int i = 0; i <= finalScore; i += 5) 
			{
        		cout << "\rYour Score: " << i << "% ";
        		cout.flush();
        		Sleep(50);
    		}
    		setColor(2);
    		cout << "\nExam Completed! Final Score: " << finalScore << "%\n";
    		setColor(7);
    		Sleep(2000);
		}
};

void Score::saveScore(string username, string subject, float score) 
{
    ofstream file("scores.txt", ios::app);
    file << username << "|" << subject << "|" << score << endl;
    file.close();
    cout << "\nScore Saved Successfully!\n";
    Sleep(1000);
}

void Score::viewUserScores(string username) 
{
    system("cls");
    setColor(3);
    cout << "====================================\n";
    cout << "        YOUR PAST SCORES            \n";
    cout << "====================================\n";
	setColor(7);
    ifstream file("scores.txt");
    if (!file) 
	{
        cout << "No scores recorded yet.\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) 
	{
        stringstream ss(line);
        string user, subject, score;
        getline(ss, user, '|');
        getline(ss, subject, '|');
        getline(ss, score);
        if (user == username) 
		{
            cout << "Subject: " << subject << ", Score: " << score << "%\n";
            found = true;
        }
    }

    if (!found) cout << "No scores found for " << username << ".\n";
    file.close();
    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
	Sleep(1000);
}

void Score::viewAllScores() 
{
    system("cls");
    setColor(6);
    cout << "====================================\n";
    cout << "        ALL USER SCORES             \n";
    cout << "====================================\n";
    setColor(7);

    ifstream file("scores.txt");
    if (!file) 
	{
        cout << "No scores available.\n";
    	return;
	} 
    string line;
    while (getline(file, line)) 
	{
        stringstream ss(line);
        string user, subject, score;
        getline(ss, user, '|');
        getline(ss, subject, '|');
        getline(ss, score);
        cout << "User: " << user << " | Subject: " << subject << " | Score: " << score << "%\n";
    }

    file.close();
    cout << "\nPress any key to go back...";
    cin.ignore();
    cin.get();
    Sleep(1000);

}

#endif