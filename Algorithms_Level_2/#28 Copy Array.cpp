//Copy Array

#include <iostream>
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


void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[i];
}




int main() {

    srand((unsigned)time(NULL));
    
    int arr[100];
    int arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);


    cout << "\nArray1  Elements: \n";
    PrintArray(arr, arrLength);



    int arr2[100];
    CopyArray(arr, arr2, arrLength);


    cout << "\nArray 2 elements after Copy :\n ";
    PrintArray(arr2 , arrLength);

    return 0;
}