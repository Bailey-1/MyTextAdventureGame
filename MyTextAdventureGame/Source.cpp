#include <iostream>

#include <string>

int main();

using std::cout;
using std::endl;
using std::cin;

// DECLARE functions
void wait_for_keypress(void);

int main()
{
	cout << "Hello World" << endl;
	wait_for_keypress();
}

// DEFINE functions
void wait_for_keypress(void)
{
	cout << "Press any key to continue" << endl;
	cin.get();
}
