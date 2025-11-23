#pragma once

#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include"MyInputLib.h"
#include "MyMathLib.h"
using namespace std;

namespace MyArrayLib {

	void ReadArray(int arr[100], int& arrLength)
	{
		cout << "\nEnter number of elements:\n";
		cin >> arrLength;

		cout << "\nEnter array elements: \n";
		for (int i = 0; i < arrLength; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
		}
		cout << endl;
	}

	void PrintArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			cout << arr[i] << " ";

		cout << "\n";
	}

	int Array_TimesRepeated(int Number, int arr[100], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
		{
			if (Number == arr[i])
			{
				count++;
			}
		}
		return count;
	}

	void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
	{
		cout << "\nEnter number of elements:\n";
		cin >> arrLength;

		for (int i = 0; i < arrLength; i++)
			arr[i] = MyInputLib::RandomNumberInRange(1, 100);
	}

	int MaxNumberInArray(int arr[100], int arrLength) {
		int sum = 0;

		for (int i = 0;i < arrLength;i++) {

			if (arr[i] > sum)
				sum = arr[i];
		}

		return sum;


	}

	int MinNumberInArray(int arr[100], int arrLength)
	{
		int Min = arr[0];

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < Min)
			{
				Min = arr[i];
			}
		}
		return Min;
	}

	int SumArray(int arr[100], int arrLength) {

		int sum = 0;

		for (int i = 0;i < arrLength;i++) {

			sum += arr[i];
		}
	}


	float AverageArray(int arr[100], int arrLength) {

		return  (float)SumArray(arr, arrLength) / arrLength;

	}


	void CopyArrayToAnotherArray(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}




	int CopyPrimeNumberArray(int arrSource[100], int arrDestination[100], int arrLength, int& arrLength2)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
			if (MyMathLib::CheckPrime(arrSource[i]) == 1) {

				arrDestination[Counter] = arrSource[i];

				Counter++;
			}

		return arrLength2 = --Counter;
	}


	void SumOf2ArraysToThirdArray(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arrSum[i] = arr1[i] + arr2[i];
		}
	}

	void ShuffleArray(int arr[100], int arrLength)
	{

		for (int i = 0;i < arrLength;i++) {

			MyInputLib::Swap(arr[MyInputLib::RandomNumberInRange(1, arrLength) - 1], arr[MyInputLib::RandomNumberInRange(1, arrLength) - 1]);

		}


	}


	void CopyArrayInReverseOrderToAnotherArray(int arrSource[100], int arrDestination[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[arrLength - 1 - i];
	}


	void FillArrayWithKeys(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = MyInputLib::GenerateKey();
	}


	short FindNumberIndexInArray(int Number, int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == Number)
				return i;
		}
		return -1;
	}


	bool IsNumberInArray(int Number, int arr[100], int arrLength)
	{
		return FindNumberIndexInArray(Number, arr, arrLength) != -1;
	}



	void AddArrayElement(int Number, int arr[100], int& arrLength) {

		arrLength++;
		arr[arrLength - 1] = Number;

	}

	void FillArrayByUser(int arr[100], int& arrLength) {


		bool AddMore;
		do {

			AddArrayElement(MyInputLib::ReadNumber("Please Enter A Number :"), arr, arrLength);
			AddMore = (bool)MyInputLib::ReadNumber("Do you want to add more numbers 0 [No]    1 [Yes] : ");

		} while (AddMore);



	}

	void CopyOddNumbersToArray(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (arrSource[i] % 2 != 0)
			{
				AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
			}
		}
	}


	void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (MyMathLib::CheckPrime(arrSource[i]) == 1)
			{
				AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
			}
		}
	}

	bool IsPalindromeArray(int arr[], int length)
	{
		for (int i = 0; i < length / 2; i++)
			if (arr[i] != arr[length - i - 1]) return false;
	}

	int CountOddNumbersInArray(int arr[], int length)
	{
		int count = 0;
		for (int i = 0; i < length; i++)
			if (arr[i] % 2) count++;
		return count;
	}

	int CountEvenNumbersInArray(int arr[], int length)
	{
		int count = 0;
		for (int i = 0; i < length; i++)
			if (arr[i] % 2 == 0) count++;
		return count;
	}

	int CountPositiveNumsInArray(int arr[], int length)
	{
		int count = 0;
		for (int i = 0; i < length; i++)
			if (arr[i] >= 0) count++;
		return count;
	}

	int CountNegativeNumsInArray(int arr[], int length)
	{
		int count = 0;
		for (int i = 0; i < length; i++)
			if (arr[i] < 0) count++;
		return count;
	}









}
