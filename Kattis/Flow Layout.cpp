/*
 * Flow Layout.cpp
 *
 *      Author: tempo
 */
#include <iostream>
#include <vector>
#include <cmath>

int main() {
	while (true) {
		int maxWidth, width = 0, currentWidth = 0, height = 0,
				currentHeight = 0;
		std::vector<int> widths, heights;
		std::cin >> maxWidth;
		if (maxWidth == 0)
			return 0;
		while (true) {
			int w, h;
			std::cin >> w >> h;
			if (w == -1 && h == -1)
				break;
			widths.push_back(w);
			heights.push_back(h);
		}

		for (unsigned int i = 0; i < widths.size(); i++) {

			if (currentWidth + widths[i] <= maxWidth) {
				currentWidth += widths[i];
				width = std::max(currentWidth, width);
			} else if (currentWidth + widths[i] > maxWidth) {
				currentWidth = widths[i];
				height += currentHeight;
				currentHeight = 0;
			}
			currentHeight = std::max(heights[i], currentHeight);

			if (i == widths.size() - 1)
				height += currentHeight;

			width = std::max(currentWidth, width);
		}

		std::cout << width << " x " << height << std::endl;
	}
}
