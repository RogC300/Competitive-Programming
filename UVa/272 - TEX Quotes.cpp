/*
 * 272.cpp
 *
 *      Author: tempo
 */
#include <cstdio>
#include <cstring>
#include <fstream>

int main() {
	char c;
	bool open = true;
	while (scanf("%c", &c) == 1){
			if (c == '"'){
				if (open) printf("``");
				else printf("''");
				open = !(open);
			} else printf("%c", c);
	}
}
