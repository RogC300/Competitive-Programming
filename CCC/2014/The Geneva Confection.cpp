/*
 * The Geneva Confection.cpp
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, ind = 1;
	std::cin >> n;

	stack<int> mountain, branch;

	for (int i = 0, in; i < n; i++)
		std::cin >> in, mountain.push(in);

	while (!mountain.empty() || !branch.empty()) {
		while (!mountain.empty() && mountain.top() == ind)
			mountain.pop(), ind++;
		while (!branch.empty() && branch.top() == ind)
			branch.pop(), ind++;
		while (!mountain.empty() && mountain.top() != ind)
			branch.push(mountain.top()), mountain.pop();
		if (mountain.empty() && !branch.empty() && branch.top() != ind)
			break;
	}
	std::cout << (branch.empty() ? "Y" : "N") << "\n";
}

int main() {
	int tc;
	std::cin >> tc;
	while (tc--)
		solve();
}
