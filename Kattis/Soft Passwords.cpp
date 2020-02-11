/*
 * Soft Passwords.cpp
 */
#include <iostream>

std::string change_case(std::string in) {
	for (int i = 0; i < (int) in.length(); i++)
		if (isupper(in[i]))
			in[i] = tolower(in[i]);
		else if (islower(in[i]))
			in[i] = toupper(in[i]);
	return in;
}

int main() {
	std::string p, in, t1, t2;

	std::cin >> in >> p;

	bool allow = false;

	if (in[in.length() - 1] >= '0' && in[in.length() - 1] <= '9')
		t1 = in.substr(0, in.length() - 1);
	if (in[0] >= '0' && in[0] <= '9')
		t2 = in.substr(1, in.length());

	if (p == in || change_case(in) == p || t1 == p || t2 == p)
		allow = true;
//	std::cout << t1 << "\n" << t2 << "\n" << change_case(in);

	std::cout << (allow ? "Yes" : "No");
}
