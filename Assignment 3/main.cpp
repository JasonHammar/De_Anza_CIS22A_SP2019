#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // This constant is used to convert from pounds to kilograms.
    const float WEIGHT_CONVERSION = 2.2046;
    // this constant is used in the calculation to get calories per minute.
    const float CAL_PER_MIN_NUM = 0.0175;
    int pounds;
    float kilograms;
    int mets;
    int minutes;
    float caloriesPerMinute;
    float totalCalories;
    cout << "Welcome to the calorie calculator." << endl;
    cout << "Enter your weight in pounds" << endl;
    cin >> pounds;
    cout << "Enter the number of METS for the activity." << endl;
    cin >> mets;
    cout << "Enter the number of minutes spent exercising." << endl;
    cin >> minutes;
    // This statement below converts the weight given from pounds to kilograms
    kilograms = static_cast<float>(pounds) / WEIGHT_CONVERSION;
    // This statement calculates the calories per minute.
    caloriesPerMinute = CAL_PER_MIN_NUM * mets * kilograms;
    // this statement calculates the total calories, then prints them out.
    totalCalories = caloriesPerMinute * minutes;
    cout << "Your total calories are: ";
    cout << fixed << setprecision(2) << totalCalories << endl;
    return 0;
    /*Test Run:
    Welcome to the calorie calculator.
    Enter your weight in pounds
    123
    Enter the number of METS for the activity.
    5
    Enter the number of minutes spent exercising.
    25
    Your total calories are: 122.05

    Process returned 0 (0x0)   execution time : 6.548 s
    Press any key to continue.
    */
}
