#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>  // For timer
#include "score2.cpp"
#include "dashboard.h"
#include "question2.cpp"
using namespace std;
class Exam 
{
	private:
    	string subject;
    	int totalQuestions;
    	int correctAnswers;
	public:
    	Exam() 
		{
        	totalQuestions = 0;
        	correctAnswers = 0;
    	}
    	string getSubject() 
		{
    		return subject;
		}

    	float takeExam(string userName);
};
float Exam::takeExam(string userName) 
{
	cout << "Subjects available are: Data Structures and Algorithms, Networks, Operating System, RDBMS, Aptitude" << endl;
    cout << "Enter Subject: ";
    cin.ignore();
    getline(cin, subject);

    ifstream file("questions.txt");
    if (!file) 
	{
        cout << "No questions available!\n";
        return 0.0;
    }

    string line, question, optionA, optionB, optionC, optionD, correctAnswer, userAnswer;
    bool subjectFound = false;
    totalQuestions = 0;
    correctAnswers = 0;
    while (getline(file, line)) 
	{
        if (line == "Subject: " + subject) 
		{
            subjectFound = true;
            continue; 
        }

        if (subjectFound && line.find("Subject: ") == 0) 
		{
            break;  
        }

        if (subjectFound && !line.empty()) 
		{
            question = line;  
            if (!getline(file, optionA) || optionA.empty()) { continue; }
            if (!getline(file, optionB) || optionB.empty()) { continue; }
            if (!getline(file, optionC) || optionC.empty()) { continue; }
            if (!getline(file, optionD) || optionD.empty()) { continue; }
            if (!getline(file, correctAnswer) || correctAnswer.empty()) { continue; }

            cout << "\n " << question << "\n";
            cout << optionA << "\n" << optionB << "\n" << optionC << "\n" << optionD << "\n";
            cout << "Enter your answer (A/B/C/D): ";
            cin >> userAnswer;

            if (userAnswer == correctAnswer) 
			{
                correctAnswers++;
                cout << "Correct!\n";
            } 
			else 
			{
                cout << "Incorrect! The correct answer is: " << correctAnswer << "\n";
            }
            Sleep(1000);
            totalQuestions++;
        }
    }
    file.close();
    if (!subjectFound) 
	{
        cout << "No questions found for this subject!\n";
        return 0.0;
    }

    float sc;
	if(totalQuestions > 0)
	{
		sc=correctAnswers * 100.0 / totalQuestions;
	}
	else
	{
		sc=0;
	}

    Sleep(2000);

    return sc;
}

#endif
