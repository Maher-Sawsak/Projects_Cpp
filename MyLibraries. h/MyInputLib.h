#pragma once

#include <iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;
namespace MyInputLib {


	enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };


	int ReadNumber(string message) {
		int Number = 0;

		cout << message << "\n";
		cin >> Number;

		return Number;
	}

	int ReadPositiveNumber(string Message)
	{
		int Number = 0;
		do
		{
			cout << Message << endl;
			cin >> Number;
		} while (Number < 0);

		return Number;
	}

	int RandomNumberInRange(int From, int To) {


		int RandomNumber = rand() % (To - From + 1) + From;

		return RandomNumber;
	}

	void Swap(int& A, int& B)
	{
		int Temp = 0;

		Temp = A;
		A = B;
		B = Temp;

	}


	char RandomCharacter(enCharType CharType) {

		switch (CharType) {

		case enCharType::CapitalLetter:
			return char(RandomNumberInRange(65, 90));
			break;

		case enCharType::SmallLetter:
			return char(RandomNumberInRange(97, 122));
			break;

		case enCharType::SpecialCharacter:
			return char(RandomNumberInRange(33, 47));
			break;
		case enCharType::Digit:
			return char(RandomNumberInRange(48, 57));
			break;
		}

	}

	string EncryptMessage(string Statement, short EncryptionKey) {

		for (int i = 0;i <= Statement.length();i++) {

			Statement[i] = char((int)Statement[i] + EncryptionKey);
		}

		return Statement;

	}

	string DecryptMessage(string EncryptionsText, short DecryptionKey) {


		for (int i = 0; i <= EncryptionsText.length();i++) {

			EncryptionsText[i] = char((int)EncryptionsText[i] - DecryptionKey);

		}

		return EncryptionsText;
	}


	string GenerateWord(enCharType CharType, short Length)
	{
		string Word;

		// Loop for the number of characters specified by Length.
		for (int i = 1; i <= Length; i++)
		{
			// Append a random character of the specified type to the word.
			Word = Word + RandomCharacter(CharType);
		}
		return Word;
	}

	string GenerateKey()
	{
		string Key = "";

		Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

		return Key;
	}

	void GenerateKeys(short NumberOfKeys)
	{

		for (int i = 1; i <= NumberOfKeys; i++)
		{

			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}
	}












}


