/*
 * Make k Equal.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, k;
	long long int sum;
	std::vector<int> nums, pre_cnt, suf_cnt;
	std::vector<long long int> pre_sum, suf_sum;
	std::vector<std::pair<int, int>> num_cnt;

	std::cin >> n >> k, nums.resize(n);
	for (int i = 0; i < n; i++)
		std::cin >> nums[i];
	std::sort(nums.begin(), nums.end());

	for (int i = 0; i < n; i++)
		if (i > 0 && nums[i] == nums[i - 1])
			num_cnt.back().second++;
		else
			num_cnt.push_back( { nums[i], 1 });

	for (int i = 0, cnt; i < (int) num_cnt.size(); i++) {
		cnt = num_cnt[i].second, sum = (long long int) num_cnt[i].first * cnt;
		pre_sum.push_back(sum), pre_cnt.push_back(cnt);
		if (i > 0)
			pre_sum.back() += pre_sum[i - 1], pre_cnt.back() += pre_cnt[i - 1];
	}

	for (int i = 0, cnt, ind; i < (int) num_cnt.size(); i++) {
		ind = num_cnt.size() - 1 - i;
		cnt = num_cnt[ind].second;
		sum = (long long int) num_cnt[ind].first * cnt;
		suf_sum.push_back(sum), suf_cnt.push_back(cnt);
		if (i > 0)
			suf_sum.back() += suf_sum[i - 1], suf_cnt.back() += suf_cnt[i - 1];
	}
	std::reverse(suf_sum.begin(), suf_sum.end());
	std::reverse(suf_cnt.begin(), suf_cnt.end());

	long long int raise, ans = 1e18;
	for (int i = 0, need_less, need_more, need; i < (int) num_cnt.size(); i++) {
		need = std::max(0, k - num_cnt[i].second), need_less = 0, raise = 0;
// Calculate taking all of less
		if (i > 0)
			need_less = std::min(need, pre_cnt[i - 1]);
		need_more = std::max(0, need - need_less);

		if (i > 0 && need_less > 0)
			raise += (long long int) pre_cnt[i - 1] * (num_cnt[i].first - 1)
					- pre_sum[i - 1] + need_less;
		if (i + 1 < (int) num_cnt.size() && need_more > 0)
			raise += suf_sum[i + 1]
					- (long long int) suf_cnt[i + 1] * (num_cnt[i].first + 1)
					+ need_more;
		ans = std::min(ans, raise);
// Calculate taking all of more
		raise = 0, need_more = 0, need_less = 0;
		if (i + 1 < (int) num_cnt.size())
			need_more = std::min(need, suf_cnt[i + 1]);
		need_less = need - need_more;

		if (i > 0 && need_less > 0)
			raise += (long long int) pre_cnt[i - 1] * (num_cnt[i].first - 1)
					- pre_sum[i - 1] + need_less;
		if (i + 1 < (int) num_cnt.size() && need_more > 0)
			raise += suf_sum[i + 1]
					- (long long int) suf_cnt[i + 1] * (num_cnt[i].first + 1)
					+ need_more;
		ans = std::min(ans, raise);
	}
	std::cout << ans;
}
