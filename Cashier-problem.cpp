/*
Given a value V, if we want to make a change for V Tk, and we have an infinite supply
of each of the denominations in Bangladeshi currency,
i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000}
valued coins/notes, what is the minimum number of coins and/or notes needed
to make the change?
*/
#include<bits/stdc++.h>
using namespace std;
int note[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int x = sizeof(note) / sizeof(note[0]);
void findM(int z)
{
	sort(note, note + x);
	vector<int>v;
	for (int i = x - 1; i >= 0; i--)
	{
		while (z >= note[i])
		{
			z -= note[i];
			v.push_back(note[i]);
		}
	}
	for (int i = 0; i < v.size(); i++)

		cout << v[i] << ",\n"[i == v.size() - 1];

}
int main()
{	int n;
	cout << "Please enter the price of your product: ";
	cin >> n;
	cout << endl;
	cout << "Following is the minimal number of change for " << n << " :" << endl;
	findM(n);

}
/*
Please enter the price of your product: 99
Following is the minimal number of change for 99 :
50,20,20,5,2,2
*/

/*The above approach may not work for all denominations. For example,
it doesn’t work for denominations {9, 6, 5, 1} and V = 11. 
The above approach would print 9, 1 and 1. 
But we can use 2 denominations 5 and 6. 
*/

// A Naive recursive C++ program to find minimum of coins
// to make a given change V
#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
// base case
if (V == 0) return 0;

// Initialize result
int res = INT_MAX;

// Try every coin that has smaller value than V
for (int i=0; i<m; i++)
{
	if (coins[i] <= V)
	{
		int sub_res = minCoins(coins, m, V-coins[i]);

		// Check for INT_MAX to avoid overflow and see if
		// result can minimized
		if (sub_res != INT_MAX && sub_res + 1 < res)
			res = sub_res + 1;
	}
}
return res;
}

// Driver program to test above function
int main()
{
	int coins[] = {9, 6, 5, 1};
	int m = sizeof(coins)/sizeof(coins[0]);
	int V = 11;
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V);
	return 0;
}
