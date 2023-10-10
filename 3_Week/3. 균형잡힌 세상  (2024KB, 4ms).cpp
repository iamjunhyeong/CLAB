#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

bool check(string str)
{
	list<char> stack;

	for (int i = 0; str[i] != '.'; i++)
	{
		if (str[i] == '(')
			stack.push_back('(');
		else if (str[i] == '[')
			stack.push_back('[');
		else if (str[i] == ')')
		{
			if (stack.empty() || stack.back() != '(')
				return false;
			else
				stack.pop_back();
		}
		else if (str[i] == ']')
		{
			if (stack.empty() || stack.back() != '[')
				return false;
			else
				stack.pop_back();
		}
	}
	if (stack.empty())
		return true;
	return false;
}

int main(void)
{
	FastIO;
	while (true)
	{
		string str;
		getline(cin, str);
		if (str == ".")
			break;
		
		if (check(str))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}