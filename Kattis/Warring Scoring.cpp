/*
 * Warring Scoring.cpp
 */
#include <iostream>

int main() {
	int n, yr = 0, no = 0;
	std::cin >> n;
	std::string in;
	int y_s = 0, n_s = 0, m_y = 0, m_n = 0;

	int yr_diff = 0, no_diff = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> in;
		if (in[0] == 'N') {
			no++, n_s++, y_s = 0;
			m_n = std::max(m_n, n_s);
			if (no > yr)
				no_diff = std::max(no_diff, no - yr);
		} else {
			yr++, y_s++, n_s = 0;
			m_y = std::max(y_s, m_y);
			if (yr > no)
				yr_diff = std::max(yr_diff, yr - no);
		}
	}
//	std::cout << m_y << " " << m_n << " " << yr_diff << " " << no_diff;

	if ((m_y > m_n) && (yr_diff > no_diff))
		std::cout << "Agree";
	else if ((m_y == m_n) && (yr_diff == no_diff))
		std::cout << "Agree";
	else if ((m_y < m_n) && (yr_diff < no_diff))
		std::cout << "Agree";
	else
		std::cout << "Disagree";
}
