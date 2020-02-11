/*
 * Bounding Robots.cpp
 */
#include <iostream>

int main() {
	int w = 1, l = 1;
	char command;
	while (std::cin >> w >> l && w != 0 && l != 0) {
		int cmds, x = 0, y = 0, xx = 0, yy = 0;
		std::cin >> cmds;
		for (int i = 0, length; i < cmds; i++) {
			std::cin >> command >> length;
			switch (command) {
			case 'u':
				y += length;
				yy + length >= l ? yy = l - 1 : yy += length;
				break;
			case 'l':
				x -= length;
				xx - length < 0 ? xx = 0 : xx -= length;
				break;
			case 'r':
				x += length;
				xx + length >= w ? xx = w - 1 : xx += length;
				break;
			case 'd':
				y -= length;
				yy - length < 0 ? yy = 0 : yy -= length;
				break;
			}
		}
		printf("Robot thinks %d %d\n", x, y);
		printf("Actually at %d %d\n\n", xx, yy);
	}
}
