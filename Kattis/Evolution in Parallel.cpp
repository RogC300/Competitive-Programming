/*
 * Evolution in Parallel.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef std::string str;
typedef std::vector<str> vst;

bool subseq(str a, str b) {
	if (a.length() > b.length())
		std::swap(a, b);
	int j = 0;
	for (int i = 0; i < (int) b.length(); i++)
		if (a[j] == b[i])
			j++;
	if (j == (int) a.length())
		return true;
	return false;
}

bool input(vst &fossils, str &modern) {
	int n;
	std::map<int, int> count;

	std::cin >> n >> modern, fossils.resize(n);
	for (int i = 0; i < n; i++) {
		std::cin >> fossils[i], count[fossils[i].length()]++;
		if (!subseq(fossils[i], modern) || count[fossils[i].length()] == 3)
			return false;
	}
	std::sort(fossils.begin(), fossils.end(), [](str a, str b) {
		return a.length() > b.length();
	});
	return true;
}

std::vector<vst> find_paths(vst f, str modern) {
	std::vector<vst> paths, final(2);
	str a, b;
	paths.push_back( { modern });
	int p_index = 0, second = -1, n = f.size();
	for (int i = 0; i < n; i++) {
		a = paths[p_index][0];
		if (second >= 0)
			b = paths[second][paths[second].size() - 1];
		if (second >= 0 && i + 1 < n && f[i].length() == f[i + 1].length())
			if (subseq(a, f[i]) && subseq(b, f[i]) && subseq(a, f[i + 1])
					&& !subseq(b, f[i + 1]))
				std::swap(f[i], f[i + 1]);

		if (subseq(a, f[i]))
			paths.push_back( { f[i] }), p_index++;
		else if (second == -1) {
			for (int j = p_index; j >= 0; j--)
				if (subseq(f[i], paths[j][0])) {
					second = j, paths[j].push_back(f[i]);
					break;
				}
		} else if (subseq(b, f[i]))
			paths[second].push_back(f[i]);
		else
			return final;
	}
	for (int i = 0; i < (int) paths.size(); i++) {
		if (paths[i].size() > 1)
			for (int j = 1; j < (int) paths[i].size(); j++)
				final[0].push_back(paths[i][j]);
		if (i != 0)
			final[1].push_back(paths[i][0]);
	}
	std::reverse(final[0].begin(), final[0].end());
	std::reverse(final[1].begin(), final[1].end());
	return final;
}

int main() {
	vst fossils;
	std::vector<vst> paths;
	str modern;

	if (!input(fossils, modern)) {
		std::cout << "impossible";
		return 0;
	}

	paths = find_paths(fossils, modern);
	if (paths[0].size() == 0 && paths[1].size() == 0)
		std::cout << "impossible";
	else {
		for (auto i : paths)
			std::cout << i.size() << " ";
		puts("");
		for (int i = 0; i < (int) paths.size(); i++)
			for (auto j : paths[i])
				std::cout << j << "\n";
	}
}
