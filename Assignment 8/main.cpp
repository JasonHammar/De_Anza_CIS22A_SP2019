#include <iostream>
#include <fstream>
// 6/19/19 CIS 22A Spring 2019 Assignment 8.
// This program reads numbers from a text file,
// puts them into an array, sorts the array,
// finds a specific number you are looking for,
// then calculates the mean of the array.
using namespace std;
int binary(int[], int, int);
void sort(int[], int);
double findMean(int[], int);

int main()
{
    ifstream infile;
    int nums, count = 0, numtoSearch;
    infile.open("nums-1.txt");// Opens the file
    cout << "Enter an integer to search for: " << endl;
    cin >> numtoSearch;
    if(!infile){
        cout << "Error";
    }else{
    // The code below counts how many numbers are in the file
    //in order to make the array.
        while(infile >> nums){
            count++;
        }
        cout << "This array has " << count << " items." << endl;
    }
    int fileArr[count];
    infile.close();
    infile.open("nums-1.txt");
// Closes and reopens the file to put the numbers in the array.
    if(!infile){
        cout << "Error";
    }else{
    // Puts the numbers from the file into the array.
        for(int i = 0; i < count; i++){
            infile >> nums;
            fileArr[i] = nums;
        }
        cout << "The array entered by the user is as follows:" << endl;
        for(int j = 0; j < count; j++)
    // Prints out the contents of the array.
            cout << fileArr[j] << " ";
        cout << endl;
        sort(fileArr, count);
        // The sort function is called to sort the array.
        if(binary(fileArr, count, numtoSearch) == -1){
    // If the number is not in the array,
    // the program prints out that it can't find the number.
            cout << "Number not found." << endl;
        }else{
        // If the number is found,
        // the program prints out where the number is in the array.
        cout << numtoSearch << " is in position number ";
        cout << binary(fileArr, count, numtoSearch) + 1 << " on the list.";
        cout << endl;
        }
        cout << "The mean of all the elements in the array is ";
        cout << findMean(fileArr, count) << endl;
        // The average of the contents of the array is calculated.
    }
    return 0;
}
void sort(int arr[], int n){
    bool swap = true;
    // bool swap set to true, for the while loop.
    while(swap){
        swap = false;
        // While there is a swap, the loop will continue going
        // until the array has been sorted into ascending order.
        for(int i = 0; i < n; i++){
            int changes = arr[i];
            if(arr[i] > arr[i + 1] && i + 1 != n + 1){
                arr[i] = arr[i + 1];
                arr[i + 1] = changes;
                swap = true;
            }

        }

    }
    // Once the array is sorted, the program prints out the sorted array.
    cout << "The sorted array is as follows: " << endl;
    for(int i = 0; i < n; i++){

        cout << arr[i] << " ";
    }
    cout << endl;
}

int binary(int arr[], int n, int nums){
    int first = 0, last = n - 1, middle, index = -1;
    bool isThere = false;
    while(!isThere && first <= last){
    // While the number the user is looking for is not there
    // and the first number is lees than or equal to the last,
    // the program does a binary search by narrowing the interval
    // by adding and subtracting 1 to the first and last variables.
    // If it's found, it returns the index it was found in,
    // otherwise it returns -1.
        middle = (first + last) / 2;
        if(arr[middle] == nums){
            isThere = true;
            index = middle;
        }else if(arr[middle] > nums)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return index;
}

double findMean(int arr[], int n){
    double total = 0;
    for(int i = 0; i < n; i++){
        // Adds all elements of the array into one variable.
        total += arr[i];
    }
    total = total / n;
    // divides total by number of elements in the array to get the mean,
    // and returns the mean, which is saved in total.
    return total;
}

/*
Sample Run:
Enter an integer to search for:
39
This array has 12 items.
The array entered by the user is as follows:
22 -4 5 100 39 20 88 10 55 3 10 78
The sorted array is as follows:
-4 3 5 10 10 20 22 39 55 78 88 100
39 is in position number 8 on the list.
The mean of all the elements in the array is 35.5

Process returned 0 (0x0)   execution time : 2.594 s
Press any key to continue.
*/
