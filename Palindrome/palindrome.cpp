#include <iostream>

using namespace std;

int reverse(int number)
{
	int reverse = 0;
	
	while(number != 0)
	{
		reverse = reverse*10 + number%10;
		number /= 10;
		
		cout << "reverse: " << reverse << " number: " << number << endl;
	}
	
	return reverse;
}

bool isPalindrome(int number)
{
	if(number == reverse(number))
		return true;
		
	return false;
}

int main()
{
	int number = 101;
	
	if(isPalindrome(number))
		cout << number << " is palindrome" << endl;
	else
		cout << number << " is not palindrome" << endl;

	return 0;
}
