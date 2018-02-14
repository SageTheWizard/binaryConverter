#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

void getInput(); // Get integer in base 10 from user
void processInput(unsigned int); // Convert base 10 to Binary
void outputNum(stack<int>); // Output Binary 

int main() // Driver: Calls getInput and allows user to process multiple base 10 integers
{
	bool goAgain = true;
	char yesOrNo;

	do
	{
		getInput();
		cout << "Would you like do another? (Y/N)";
		cin >> yesOrNo;

		if (toupper(yesOrNo) == 'Y')
			goAgain = true;
		else
			goAgain = false;

	}while(goAgain);	
	return 0;
}

void getInput()
{
	unsigned int num;
	cout << "Input a non negative integer in base 10: ";
	cin >> num;
	processInput(num);
	
}
void processInput(unsigned int baseTen)
{
	stack<int> binary;

	do
	{
		binary.push((baseTen % 2));
		baseTen /= 2;
	}while(baseTen != 0);

	outputNum(binary);
}
void outputNum(stack<int> bi)
{
	do
	{
		cout << bi.top();
		bi.pop();
	}while(!bi.empty());	
	cout << "\n";
}
