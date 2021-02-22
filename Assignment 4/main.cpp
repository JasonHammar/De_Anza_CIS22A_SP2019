#include <iostream>

using namespace std;

int main()
{
    float minutes, totalCostA, totalCostB, minutesA, minutesB, savings;
    // These variables represent the minutes, total costs for package a and b,
    // minutes for a and b, and the saving.
    const char PACKAGE_A = '1', PACKAGE_B = '2', PACKAGE_C = '3', QUIT = '4';
    // package numbers.
    char package;
    const int MIN_A = 450, MIN_B = 900;
    // Constant minutes for packages a and b.
    const float COST_A = 39.99, COST_B = 59.99, COST_C = 69.99;

    const float ADD_MIN_FOR_A = 0.45, ADD_MIN_FOR_B = 0.40;
    cout << "Please select a subscription package." << endl;
    cout << "Select 1 for package A, 2 for package B, ";
    cout << "3 for package C, or 4 to quit." << endl;
    cin >> package;

    switch(package){

        case PACKAGE_A: cout << "How many minutes were used?";
        // If the user chooses package 1.
        cin >> minutes;
        if(minutes <= MIN_A)
            cout << "Your total amount due is " << COST_A << endl;
    // if minutes is less than minimum minutes. cost is base cost.
        else{
            minutesA = minutes;
            minutesA -= MIN_A;
            minutesA *= ADD_MIN_FOR_A;
            totalCostA = COST_A + minutesA;
            cout << "Your total amount due is " << totalCostA << endl;
            // This calculates the total cost for package a.
        }
        if(minutes <= MIN_B){
            savings = totalCostA - COST_B;
            if(savings <= 0)
                cout << "No Savings with package B! \n";
            else
                cout << "Your savings for Package B are " << savings << endl;
        }// Calculates savings with packages a and b.
        else{
            minutesB = minutes;
            minutesB -= MIN_B;
            minutesB *= ADD_MIN_FOR_B;
            totalCostB = COST_B + minutesB;
            savings = totalCostA - totalCostB;
            if(savings <= 0)
                cout << "No Savings!";
            else
                cout << "Your savings for Package B are " << savings << endl;
        }// calculates savings with packages a and b.
        savings = totalCostA - COST_C;
        if(savings > 0)
            cout << "Your savings with Package C are " << savings << endl;
        else
            cout << "No Savings with Package C!";

// calculates savings with packages a and c.
       break;
       case PACKAGE_B: cout << "How many minutes were used?";
        cin >> minutes;
           if(minutes <= MIN_B)

            cout << "Your total amount due is " << COST_B << endl;
        else{
            minutesB = minutes;
            minutesB -= MIN_B;
            minutesB *= ADD_MIN_FOR_B;
            totalCostB = COST_B + minutesB;
            cout << "Your total amount due is " << totalCostB << endl;
        }// calculates total cost with package b.
        if(minutes <= MIN_B){
            if(minutes <= MIN_B)
                savings = COST_B - COST_A;
            else
                savings = totalCostB - COST_A;
            if(savings <= 0)
                cout << "No Savings with package A! \n";
            else
                cout << "Your savings for Package A are " << savings << endl;
        }// calculates savings with packages b and a.
        else{
            minutesA = minutes;
            minutesA -= MIN_A;
            minutesA *= ADD_MIN_FOR_A;
            totalCostA = COST_A + minutesA;
            savings = totalCostB - totalCostA;
            if(savings <= 0)
                cout << "No Savings with package A! \n";
            else
                cout << "Your savings for Package A are " << savings << endl;
        }
        savings = totalCostB - COST_C;
        if(savings > 0)
            cout << "Your savings with Package C are " << savings << endl;
        else
            cout << "No Savings with Package C! \n";
// calculates savings with packages b and c.
        break;

       case PACKAGE_C:
       cout << "How many minutes were used?";
       cin >> minutes;
       cout << "Your total amount due is " << COST_C << endl;
       // package c total cost.
       if(minutes <= MIN_B){
         savings = COST_C - COST_B;
         if(savings <= 0)
             cout << "No Savings with package B! \n";
         else
             cout << "Your savings for Package B are " << savings << endl;
        }
        else{
            minutesB = minutes;
            minutesB -= MIN_B;
            minutesB *= ADD_MIN_FOR_B;
            totalCostB = COST_B + minutesB;
            savings = COST_C - totalCostB;
            if(savings <= 0)
                cout << "No Savings with package B! \n";
            else
                cout << "Your savings for Package B are " << savings << endl;
        }// calculates savings with packages c and b.
        if(minutes <= MIN_A){
            if(minutes <= MIN_B)
                savings = COST_C - COST_A;
            if(savings <= 0)
                cout << "No Savings with package A! \n";
            else
                cout << "Your savings for Package A are " << savings << endl;
        }
        else{
            minutesA = minutes;
            minutesA -= MIN_A;
            minutesA *= ADD_MIN_FOR_A;
            totalCostA = COST_A + static_cast<float>(minutesA);
            savings = COST_C - totalCostA;
            if(savings <= 0)
                cout << "No Savings with package A! \n";
            else
                cout << "Your savings for Package A are " << savings << endl;
        }// calculates savings with packages c and a.
       break;
       case QUIT: cout << "Thank you and Goodbye!";
       // If the user enters 4, the program stops.
       break;
       default:
       cout << "Invalid entry, please run the program again and ";
       cout << "type 1 to 4 for a package choice";
       // If you enter an invalid number, you have to run the program again.
    }

    return 0;
}
/* Sample Run:
 Please select a subscription package.
 Select 1 for package A, 2 for package B, 3 for package C, or 4 to quit.
 2
 How many minutes were used?980
 Your total amount due is 91.99
 No Savings with package A!
 Your savings with Package C are 22
*/
