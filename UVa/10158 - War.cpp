/*
 * 10158 - War.cpp
 */
#include <iostream>
#include <vector>

// UNFINISHED IDK HOW TO MAKE ENEMIES ENIMIES FRIENDS

class ds {
public:
	std::vector <int> friends, enemies;
	ds (int n) {
		friends.resize(n+1);
		enemies.resize(n+1);
		for (int i = 0; i < n; i++)
			friends[i] = -1, enemies[i] = -1;
	}
	void make_set (int v, bool fr) {
		if (fr)
			friends[v] = v;
		else
			enemies[v] = v;
	}

	int find_set (int v, bool fr) {
		if (fr) {
			if (friends[v] == -1)
				return -1;
			if (friends[v] == v)
				return v;
			return find_set (friends[v], fr);
		}
		else {
			if (enemies[v] == -1)
				return -1;
			if (enemies[v] == v)
				return v;
			return find_set (enemies[v], fr);
		}
	} // make enemies of your enemies your friends
	bool union_sets (int a, int b, bool fr) {
		if (find_set(a, !fr) == find_set (b, !fr) && find_set(a, !fr) != -1)
			return false;
		if (find_set(a, fr) == -1)
			make_set(a, fr);
		if (find_set(b, fr) == -1)
			make_set(b, fr);
		a = find_set(a, fr), b = find_set(b, fr);
		if (fr && a != b)
			friends[a] = b;
		else if (a != b)
			enemies[a] = b;
		return true;
	}
};

/*
c = 1, setFriends
c = 2, setEnemies
c = 3, areFriends
c = 4, areEnemies
 */
/*
10
1 2 0
2 0 5
1 5 2
0 0 0
 */
int main () {
	int command, a, b, people;
	std::cin >> people >> command >> a >> b;
	ds net (people);
	while (command != 0) {
		if (command == 1 && !net.union_sets (a, b, true))
			printf ("-1\n");
		if (command == 2 && !net.union_sets (a, b, false))
			printf ("-1\n");

		if (command == 3) {

		}
		if (command == 4) {


		}
		std::cin >> command >> a >> b;
	}


}
