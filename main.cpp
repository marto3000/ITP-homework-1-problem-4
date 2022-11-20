#include <iostream>
using namespace std;

bool repeatNumbers(int testNum)
{
	int length = 0;
	for (int i = testNum; i > 0; i /= 10)
	{
		length++;
	}
	bool check = true;
	while (testNum >= 10)
	{
		int tempTest = testNum;
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

int removeLeftNum(int num)
{
	int currentPos = 1;
	for (int i = num; i >= 10; i /= 10)
	{
		currentPos *= 10;
	}
	num = num % currentPos;
	return num;
}

int power(int var, int powerVar)
{
	int result = var;
	while (powerVar > 1)
	{
		result *= var;
		powerVar--;
	}
	return result;
}

int main()
{
	int num;
	do
	{
		cin >> num;
	} while (num < 1);
	int numLengthRestriction = 0;
	for (int i = num; i > 0; i /= 10)
	{
		numLengthRestriction++;
	}
	if (numLengthRestriction > 10)
	{
		numLengthRestriction = 10;
	}

	int sum = 0;
	int buildNum;
	for (int i = 1; i <= numLengthRestriction; i++)//using all possible lengths
	{
		for (int j = num; j > 0; j /= 10)//going through all starting possitions from "num"
		{
			buildNum = j % 10;
			if (i == 1)
			{
				sum += buildNum;
			}
			for (int k = 1; j / power(10, k) > 0 && k < i; k++)//building a number by going through all possitions of "j" (k = 1 starts from position 2 (10) )
			{
				buildNum += ((j / power(10, k)) % 10) * power(10, k);
				if (repeatNumbers(buildNum))
				{
					buildNum = removeLeftNum(buildNum);
				}
				else
				{
					if (buildNum < power(10, i) && buildNum >= power(10, i - 1))
					{
						sum += buildNum;
						buildNum = removeLeftNum(buildNum);
					}
				}
			}
		}
	}//12234
	cout << sum;

	return 0;
}