#ifndef QUESTION_H
#define QUESTION_H

#include "dashboard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>  // For Sleep()
#include "color.h"
using namespace std;

class Dashboard;

class Question 
{
    public:
        void addQuestion();
        void viewQuestions();
        void deleteQuestion();
};


void Question::addQuestion() 
{
    system("cls");
    cout << "==============================\n";
    cout << "       ADD NEW QUESTION       \n";
    cout << "==============================\n";

    string subject, question, option1, option2, option3, option4, correctAnswer;
    cout << "Enter Subject: ";
    cin.ignore();
    getline(cin, subject);
    cout << "Enter Question: ";
    getline(cin, question);
    cout << "Enter Option A: ";
    getline(cin, option1);
    cout << "Enter Option B: ";
    getline(cin, option2);
    cout << "Enter Option C: ";
    getline(cin, option3);
    cout << "Enter Option D: ";
    getline(cin, option4);
    cout << "Enter Correct Answer (A/B/C/D): ";
    cin >> correctAnswer;

    ofstream file("questions.txt", ios::app);
    file << "Subject: " << subject << "\n";
    file << question << "\n";
    file << "A) " << option1 << "\n";
    file << "B) " << option2 << "\n";
    file << "C) " << option3 << "\n";
    file << "D) " << option4 << "\n";
    file << correctAnswer << "\n\n";
    file.close();

    cout << "\nQuestion Added Successfully!\n";
    Sleep(1000);
}

void Question::viewQuestions() 
{
    system("cls");
    cout << "==============================\n";
    cout << "       VIEW QUESTIONS         \n";
    cout << "==============================\n";

    ifstream file("questions.txt");
    if (!file) 
	{
        cout << "No questions found.\n";
        return;
    }

    string line;
    bool isSubject = false;
    int questionNo = 0;

    while (getline(file, line)) 
	{
        if (line.rfind("Subject:", 0) == 0) 
		{
            cout << "\n" << line << "\n";  
            isSubject = true;
        } 
		else if (!line.empty() && !isSubject) 
		{
            cout << ++questionNo << ") " << line << "\n"; 
            isSubject = true;  
        } 
		else 
		{
            cout << line << "\n";  
        }
    }

    file.close();
    
    cout << "\nPress any key to return to the menu...";
    
    Sleep(1000);
    cin.ignore();
    cin.get();
}

void Question::deleteQuestion() 
{
    system("cls");
    cout << "==============================\n";
    cout << "       DELETE QUESTION        \n";
    cout << "==============================\n";

    ifstream file("questions.txt");
    if (!file) 
    {
        cout << "No questions available to delete.\n";
        return;
    }

    ofstream tempFile("temp.txt");
    string line, subject;
    int questionNo = 0, deleteIndex;
    bool isSubject = false, skip = false, subjectDeleted = false;

    cout << "Available Questions:\n";
    while (getline(file, line)) 
    {
        if (line.rfind("Subject:", 0) == 0) 
        {
            subject = line;
            cout << "\n" << line << "\n";
            isSubject = true;
        } 
        else if (!line.empty() && isSubject) 
        {
            questionNo++;
            cout << questionNo << ") " << line << "\n";
            isSubject = false;
        } 
        else 
        {
            cout << line << "\n";
        }
    }

    if (questionNo == 0) 
    {
        cout << "No questions found.\n";
        return;
    }

    cout << "\nEnter question number to delete: ";
    cin >> deleteIndex;

    file.clear();
    file.seekg(0);
    questionNo = 0;
    bool lastLineWasBlank = false;

    while (getline(file, line)) 
    {
        if (line.rfind("Subject:", 0) == 0) 
        {
            subject = line;
            skip = false;
            subjectDeleted = false;
        } 
        else if (!line.empty()) 
        {
            questionNo++;
            if (questionNo == deleteIndex) 
            {
                skip = true;
                subjectDeleted = true;
                continue;
            }
        }

        if (!skip) 
        {
            tempFile << line << "\n";
        } 
        else 
        {
            for (int i = 0; i < 5 && getline(file, line); i++);
            skip = false;
        }
    }

    file.close();
    tempFile.close();
    remove("questions.txt");
    rename("temp.txt", "questions.txt");

    cout << "\nQuestion and Subject Deleted Successfully!\n";
    Sleep(1000);
    cin.ignore();
    cin.get();
}

#endif
