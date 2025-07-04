//Fill Array With Random Numbers From 1 To 100.cpp

#include <iostream>  
#include<cstdlib>
#include<ctime>
using namespace std; 


int RandomNumber(int From, int To)
{
    
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}


void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";  
}

int main() {
    // Seed the random number generator with the current time.
    srand((unsigned)time(NULL));

    int arr[100];  
    int arrLength; 

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    return 0;  
}