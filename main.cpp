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

int power(int var, int powerVar)
{
	int result = var;
	if (powerVar == 0)
	{
		result = 1;
	}
	else
	{
		while (powerVar > 1)
		{
			result *= var;
			powerVar--;
		}
	}
	return result;
}

int createNum(int num, int code)
{
	int finalNum = 0;
	if (code == 0)
	{
		return 0;
	}
	bool last = false;
	if (code < 0)
	{
		code *= -1;
		last = true;
	}
	for (int i = code; i >= 10; i /= 10)
	{
		if (i % 10 <= (i / 10) % 10)
		{
			return 0;
		}
	}
	for (int i = code; i > 0; i /= 10)
	{
		if (i % 10 > numLength(num))
		{
			return 0;
		}
	}
	for (int i = code; i > 0; i /= 10)
	{
		finalNum += ((num / power(10, numLength(num) - (i % 10))) % 10) * power(10, numLength(code) - numLength(i));
	}
	if (last == true)
	{
		finalNum += (num / (power(10, 9)) * power(10, 9));
	}
	return finalNum;
}

int main()
{
	int num;
	do
	{
		cin >> num;
	} while (num < 1);
	int minCode = 1;
	int maxCode = 123456789;
	if (numLength(num) > 9)
	{
		minCode = -maxCode;
	}
	while (numLength(maxCode) > numLength(num))
	{
		maxCode /= 10;
	}
	int sum = 0;
	for (int code = minCode; code <= maxCode; code++)
	{
		int buildNum = createNum(num, code);
		if (buildNum != 0 && repeatNumbers(buildNum) == false)
		{
			sum += buildNum;
		}
	}
	cout << sum;

	return 0;
}