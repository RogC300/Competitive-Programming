/*
 * Miniature Golf.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// TLE

typedef long long int ll;
typedef std::vector<ll> vi;
typedef std::vector<vi> vii;

void pv(std::vector<int> v) {
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << (i == (int) v.size() - 1 ? "\n" : " ");
//  puts("");
}

void input(vii &scores, std::vector<int> &unique) {
	int people, holes;
	std::set<int> possible_l;

	std::cin >> people >> holes, scores.resize(people);

	for (int i = 0; i < people; i++)
		for (int j = 0, s; j < holes; j++)
			std::cin >> s, scores[i].push_back(s), possible_l.insert(s);

	for (auto i : possible_l)
		unique.push_back(i);
}

void find_ranks(int l, vii scores, vi &min_ranks) {
	std::vector<std::pair<ll, ll>> score_sum, rank_score;

	for (int i = 0; i < (int) scores.size(); i++) {
		ll sum = 0;
		for (int j = 0; j < (int) scores[i].size(); j++)
			if (scores[i][j] > l)
				sum += l;
			else
				sum += scores[i][j];
		score_sum.push_back( { sum, i });
	}

	std::sort(score_sum.begin(), score_sum.end());

//  for (int i = 0; i < (int)score_sum.size(); i++)
//      std::cout << score_sum[i].first << " " << score_sum[i].second << "\n";

	for (int i = 0, r, pos = 0; i < (int) score_sum.size(); i++) {
		r = 1;
		for (int j = i + 1; j < (int) score_sum.size(); j++)
			if (score_sum[j].first == score_sum[i].first)
				r++;
		pos += r;
		for (int j = i; j < i + r; j++)
			rank_score.push_back( { score_sum[j].second, pos });
		i += r - 1;
	}
	std::sort(rank_score.begin(), rank_score.end());
	for (int i = 0; i < (int) rank_score.size(); i++)
		min_ranks[i] = std::min(min_ranks[i], rank_score[i].second);
}

int main() {
	vii scores;
	vi min_ranks;
	std::vector<int> unique;
	input(scores, unique);

	min_ranks.assign(scores.size(), 1e9);

	for (int i = unique[0]; i <= unique[unique.size() - 1]; i++)
		find_ranks(i, scores, min_ranks);
	for (int i = 0; i < (int) min_ranks.size(); i++)
		std::cout << min_ranks[i] << "\n";
}
