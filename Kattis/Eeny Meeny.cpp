/*
 * Eeny Meeny.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::string in;
	std::vector<std::string> team_a, team_b, people;
	int n_words, n_people, index = 0;
	bool team = true;

	getline(std::cin, in), std::cin >> n_people, people.resize(n_people);
	n_words = count(in.begin(), in.end(), ' ');
	for (int i = 0; i < n_people; i++)
		std::cin >> people[i];

	while (!people.empty()) {
		index = (index + n_words) % people.size();
		team ? team_a.push_back(people[index]) : team_b.push_back(people[index]);
		people.erase(people.begin() + index), team = !team;
	}

	std::cout << team_a.size() << "\n";
	for (auto i : team_a)
		std::cout << i << "\n";
	std::cout << team_b.size() << "\n";
	for (auto i : team_b)
		std::cout << i << "\n";
}
