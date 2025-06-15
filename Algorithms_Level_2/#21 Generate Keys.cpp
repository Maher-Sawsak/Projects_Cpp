//Generate Keys.

#include <iostream>  
#include <string>    
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for time() to seed the random generator.

using namespace std;  


enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };


int RandomNumber(int From, int To)
{
     int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SamallLetter:
    {

        return char(RandomNumber(97, 122));
        break; 
    }
    case enCharType::CapitalLetter:
    {

        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {

        return char(RandomNumber(33, 47));
        break;
    }
    case enCharType::Digit:
    {
        
        return char(RandomNumber(48, 57));
        break;
    }
    }

    return '\0';
}


int ReadPositiveNumber(string Message)
{
    int Number = 0;  
    do
    {
        cout << Message << endl; 
        cin >> Number;           
    } while (Number <= 0);       
    return Number;
}


string GenerateWord(enCharType CharType, short Length)
{
    string Word;  

    // Loop for the number of characters specified by Length.
    for (int i = 1; i <= Length; i++)
    {
        // Append a random character of the specified type to the word.
        Word = Word + GetRandomCharacter(CharType);
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


int main()
{

    srand((unsigned)time(NULL));


    GenerateKeys(ReadPositiveNumber("Pleaes enter how many keys to generate? \n "));

    return 0;  
}