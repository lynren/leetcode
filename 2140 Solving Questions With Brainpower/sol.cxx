#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long mostPoints(vector<vector<int>> &questions)
{
	vector<long long> res(questions.size());
	res.back() = *questions.back().begin();
	for (int i = questions.size() - 2; i >= 0; i--)
	{
		int pi = questions[i][0], bi = questions[i][1];
		res[i] = max(
			(pi + (i + 1 + bi < questions.size() ? res[i + 1 + bi] : 0)),
			res[i + 1]);
	}

	return res[0];
}

int main()
{
	vector<vector<int>> arr = {
		{3, 2},
		{4, 3},
		{4, 4},
		{2, 5}};

	vector<vector<int>> arr2 = {
		{1, 1},
		{2, 2},
		{3, 3},
		{4, 4},
		{5, 5}};

	cout << mostPoints(arr2) << endl;

	return 0;
}