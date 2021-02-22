#include <iostream>
#include <iomanip>
// This program calculates the judges scores for a talent show.
// Jason H. 5/28/2019
using namespace std;
// These are the prototypes for the functions.
void getJudgeData(double&);
void calcScore(double, double, double, double);
double findHighest(double, double, double, double);
double findLowest(double, double, double, double);

int main()
{
    double score = 0, score1, score2, score3, score4;

    // This for loop gets the 4 judges scores
    // and stores them into 4 variables.
    for(int i = 0; i < 4; i++){
        getJudgeData(score);
        if(i == 0)
            score1 = score;
        else if(i == 1)
            score2 = score;
        else if(i == 2)
            score3 = score;
        else if(i == 3)
            score4 = score;
    }

    calcScore(score1, score2, score3, score4);
    return 0;
}


void getJudgeData(double &score){// Reference parameter variable.
    // This function will get the data from the four judges.
    // If a number is out of the range, it will prompt the user to try again.
    cout << "what is the judges score?" << endl;
    cin >> score;
    while (score < 0 || score > 20){
        cout << "Invalid number, what is the judges score?" << endl;
        cin >> score;
    }

}

void calcScore(double score1, double score2, double score3, double score4)
{
    double high = 0, low = 0, highAndLow = 0, totalScore = 0;
    // The total score is calculated by having the sum of the
    // low and high scores subtracted from the sum of all four scores.
    // that difference is the divided by 2, and will then
    // print the average of the remaining two scores.
    high = findHighest(score1, score2, score3, score4);
    // highest will equal the highest score.
    low = findLowest(score1, score2, score3, score4);
    // lowest will equal the lowest score
    highAndLow = high + low;
    // This is the high and low scores added together.
    totalScore = score1 + score2 + score3 + score4;
    // This is the total of all four scores added together.
    double average = 0;
    average = (totalScore - highAndLow) / 2;
    cout << "The performer's score is ";
    cout << fixed << setprecision(1) << average << endl;
}


double findHighest(double score1, double score2, double score3, double score4)
{
    double highest = 0;
    // finds the highest by checking if each score greater than or
    // equal to the other scores, it then stores that score into
    // the variable called highest.
    if(score1 >= score2 && score1 >= score3 && score1 >= score4)
        highest = score1;
    else if(score2 >= score1 && score2 >= score3 && score2 >= score4)
        highest = score2;
    else if(score3 >= score1 && score3 >= score2 && score3 >= score4)
        highest = score3;
    else if(score4 >= score1 && score4 >= score3 && score4 >= score2)
        highest = score4;
    return highest;
}


double findLowest(double score1, double score2, double score3, double score4)
{
    double lowest = 0;
    // finds the lowest by checking if each score less than or
    // equal to the other scores, it then stores that score into
    // the variable called lowest.
    if(score1 <= score2 && score1 <= score3 && score1 <= score4)
        lowest = score1;
    else if(score2 <= score1 && score2 <= score3 && score2 <= score4)
        lowest = score2;
    else if(score3 <= score1 && score3 <= score2 && score3 <= score4)
        lowest = score3;
    else if(score4 <= score1 && score4 <= score3 && score4 <= score2)
        lowest = score4;
    return lowest;
}
/* Sample Run:
what is the judges score?
5
what is the judges score?
7.5
what is the judges score?
19
what is the judges score?
18.7
The performer's score is 13.1

Process returned 0 (0x0)   execution time : 12.638 s
Press any key to continue.*/
