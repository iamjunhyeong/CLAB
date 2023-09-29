#include <iostream>
#include <vector>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main(void)
{
	FastIO;
	
	int n;
	cin >> n;

	vector<int> arr(n);
	list<int> st;
	vector<char> op;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
		st.push_back(i + 1);

	list<int>::iterator it = st.begin();
	op.push_back('+');

	for (int i = 0; i < n;)
	{
		cout << *it << "\n";
		if (it == st.end())
		{
			cout << "NO\n";
			exit(0);
		}

		if (*it == arr[i])
		{
			op.push_back('-');
			it = st.erase(it);
			--it;
			i++;
		}
		else
		{
			op.push_back('+');
			++it;
		}
	}

	for (int i = 0; i < op.size(); ++i)
		cout << op[i] << "\n";
}