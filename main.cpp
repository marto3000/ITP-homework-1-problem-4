#include <iostream>
using namespace std;

int numLength(int num)
{
	int length = 0;
	while (num > 0)
	{
		num /= 10;
		length++;
	}
	return length;
}

bool repeatNumbers(int testNum)
{
	while (testNum >= 10)
	{
		int tempTest = testNum / 10;
		while (tempTest > 0)
		{
			if (testNum % 10 == tempTest % 10)
			{
				return true;
			}
			tempTest /= 10;
		}
		testNum /= 10;
	}
	return false;
}

//int removeLeftNum(int num)
//{
//	int currentPos = 1;
//	for (int i = num; i >= 10; i /= 10)
//	{
//		currentPos *= 10;
//	}
//	num = num % currentPos;
//	return num;
//}

//int power(int var, int powerVar)
//{
//	int result = var;
//	if (powerVar == 0)
//	{
//		result = 1;
//	}
//	else
//	{
//		while (powerVar > 1)
//		{
//			result *= var;
//			powerVar--;
//		}
//	}
//	return result;
//}

int numberWithLengthX(int x, int originalX, int num, int finallSum)
{
	int buildNum;
	for (int i = num; i > 0 && numLength(i) >= x; i /= 10)
	{
		buildNum = i % 10;
		if (numLength(buildNum) < x)
		{
			buildNum += numberWithLengthX(x - 1, x, i / 10, 0) * 10;
		}
		if (numLength(buildNum) < originalX)
		{
			return buildNum;
		}
		else
		{
			if (repeatNumbers(buildNum) == false)
			{
				finallSum += buildNum;
			}
		}
	}
	return finallSum;
}

int main()
{
	int num;
	do
	{
		cin >> num;
	} while (num < 1);
	int lengthRestriction;
	if (numLength(num) > 10)
	{
		lengthRestriction = 10;
	}
	else
	{
		lengthRestriction = numLength(num);
	}
	int sum = 0;
	for (int i = 1; i <= lengthRestriction; i++)
	{
		sum += numberWithLengthX(i, i, num, 0);
	}
	cout << sum;

	return 0;
}