/*
 * Ragaman.cpp
 */
#include <iostream>
#include <unordered_map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::unordered_map<char, int> orig, wild;
	std::string a, b;
	bool is_ana = true;

	std::cin >> a >> b;
	for (int i = 0; i < (int) a.length(); i++)
		orig[a[i]]++;

	for (int i = 0; i < (int) b.length(); i++) {
		if (b[i] == '*')
			continue;
		wild[b[i]]++;
		if (wild[b[i]] > orig[b[i]]) {
			is_ana = false;
			break;
		}
	}
	std::cout << (is_ana ? "A" : "N");
}
