#include <iostream>
// CIS 22a Spring Assignment 7, 6/6/19
// This program will check the scores for an exam and determine
// if the student passed or failed.
using namespace std;
// function prototypes
void input(char[], int);
void checkAnswers(char[], char[], int &, int &, int);
int main()
{
    char answers[20] = {'A', 'B', 'A', 'C', 'D', 'A', 'C', 'C', 'B', 'B',
    'D', 'A', 'B', 'C', 'B', 'D', 'C', 'D', 'D', 'B'};

    char guesses[20];
    int questions = 20, incorrect = 0, correct = 0;

    input(guesses, questions);
    checkAnswers(answers, guesses, correct, incorrect, questions);
    // Displays correct answers and incorrect answers,
    // then states whether or not the student has passed
    cout << "Correct Answers: " << correct << endl;
    cout << "Incorrect Answers: " << incorrect << endl;
    if(correct >= 15)
        cout << "The student passed the exam!" << endl;
    else
        cout << "The student failed the exam!" << endl;
    return 0;
}

void input(char answers[], int questions){
    // This function stores all of the students answers into the guesses array
    cout << "Please enter A, B ,C, D or a, b, c, d. ";
    cout << "Press enter after each entry. " << endl;
    for (int i = 0; i < questions; i++){
        // there's 20 questions, so loops 20 times.
        cout << "Question " << i + 1 << ": ";
        cin >> answers[i];
    // If an answer is not A B C D or a b c d,
    // then the user must re enter that entry.
        if(answers[i] != 'A' && answers[i] != 'a' && answers[i] != 'B'
        && answers[i] != 'b' && answers[i] != 'C' && answers[i] != 'c'
        && answers[i] != 'D' && answers[i] != 'd'){
            cout << "Invalid entry, please enter a lower or uppercase letter";
            cout << " that's A, B, C, or D or a, b, c, or d" << endl;
            while(cin >> answers[i]){
                if(answers[i] != 'A' && answers[i] != 'a' && answers[i] != 'B'
                && answers[i] != 'b' && answers[i] != 'C' && answers[i] != 'c'
                && answers[i] != 'D' && answers[i] != 'd'){
                    cout << "Invalid entry, please enter a lower or";
                    cout << " uppercase letter that's A, B, C, or D" << endl;

            }else
                break;

        }
    }
}
}
void checkAnswers(char answers[], char guesses[], int &correct,
                  int &incorrect, int questions){
    // This program will check the answers
    // and add up how many are correct and incorrect.
    cout << "Questions that were answered incorrectly: " << endl;
    for(int i = 0; i < questions; i++){
        // If the answers are correct, they are added into the correct
        // variable, if the are incorrect, it will tell
        // the user which answers are incorrect.
        if(answers[i] == guesses[i] || answers[i] + 32 == guesses[i]){
            correct++;
        }else{
            incorrect++;
            cout << i + 1 << endl;
        }
    }
}

/* Sample Run:
Please enter A, B ,C, D or a, b, c, d. Press enter after each entry.
Question 1: a
Question 2: s
Invalid entry, please enter a lower or uppercase letter that's A, B, C, or D or a, b, c, or d
d
Question 3: a
Question 4: c
Question 5: c
Question 6: d
Question 7: f
Invalid entry, please enter a lower or uppercase letter that's A, B, C, or D or a, b, c, or d
d
Question 8: c
Question 9: d
Question 10: c
Question 11: a
Question 12: d
Question 13: b
Question 14: d
Question 15: c
Question 16: d
Question 17: c
Question 18: d
Question 19: a
Question 20: b
Questions that were answered incorrectly:
2
5
6
7
9
10
11
12
14
15
19
Correct Answers: 9
Incorrect Answers: 11
The student failed the exam!

Process returned 0 (0x0)   execution time : 15.283 s
Press any key to continue.*/
