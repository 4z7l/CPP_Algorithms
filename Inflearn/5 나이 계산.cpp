#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	string str;
	cin >> str;

	string birth = str.substr(0, 2);
	int gender_ind = str.find('-') + 1;
	char gender = str[gender_ind];


	if (gender == '1' || gender == '2') {
		birth = "19" + birth;
	}
	else {
		birth = "20" + birth;
	}

	int age = 2019 - stoi(birth) + 1;
	switch (gender) {
	case '1': case '3':
		gender = 'M'; break;
	default:
		gender = 'W'; break;
	}

	printf("%d %c\n", age, gender);


	return 0;
}