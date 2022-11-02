

#include <iostream>
using namespace std;

enum enCheckPrimeNotPrime { Prime = 1, NotPrime = 2 };
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From) + From + 1;
	return randNum;
}
int ReadNumber(string Message)
{
	int Number;
	cout << Message << endl;
	cin >> Number;
	return Number;
}
int AddArrayElement(int Number, int Arr[100], int& Length)
{
	Length++;
	return Arr[Length - 1] = Number;

}
void FillArrayWithRandomNumber(int Arr[100], int& Length)
{

	for (int i = 0;i < Length;i++)
	{
		Arr[i] = RandomNumber(0, 100);
	}
}
void PrintArrayData(int Arr[100], int Length)
{
	for (int i = 0;i < Length;i++)
	{
		cout << Arr[i] << " ";
	}
}
enCheckPrimeNotPrime CheckPrimeNumber(int Number)
{
	int M = round(Number / 2);
	for (int Counter = 2; Counter <= M;Counter++)
	{
		if (Number % Counter == 0)
			return enCheckPrimeNotPrime::NotPrime;

	}return enCheckPrimeNotPrime::Prime;
	
}
void CopyPrimeNumbersUsingAddArrayElement(int ArrSorce[100], int ArrDestention[100], int Length, int& Length2)
{

	for (int i = 0;i < Length;i++)
	{
		if (CheckPrimeNumber(ArrSorce[i]) == enCheckPrimeNotPrime::Prime)
		{
			AddArrayElement(ArrSorce[i], ArrDestention, Length2);
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Arr[100], Length = 0, Length2 = 0;
	Length = ReadNumber("Enter The Length Of Array?");
	FillArrayWithRandomNumber(Arr, Length);


	int Arr2[100];
	CopyPrimeNumbersUsingAddArrayElement(Arr, Arr2, Length, Length2);

	cout << "\nArray 1 Random Element:\n" << endl;
	PrintArrayData(Arr, Length);


	cout << "\nArray 2 Prime Numbers:\n" << endl;
	PrintArrayData(Arr2, Length2);

}

