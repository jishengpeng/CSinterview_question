//大模拟，没有拿满，后面再想想
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	double res = 0.0;
	string tmp;
	for (int i = 0; i < n; i++) {
		int flag = 0;
		cin >> tmp;
		for (unsigned int j = 0; j < tmp.size(); j++) {
			if (!((tmp[j] >= '0' && tmp[j] <= '9') || (tmp[j] == '.') || (tmp[j] == '-' && j == 0))) {
				cout << "ERROR: " << tmp << " is not a legal number" << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			continue;
		}
		if (tmp.find('.') == string::npos) {
			int tmp1 = stoi(tmp);
			if (tmp1 >= -1000 && tmp1 <= 1000) {
				sum++;
				res = res + tmp1;
				//cout << "res:" << res << endl;
			}
			else {
				cout << "ERROR: " << tmp << " is not a legal number" << endl;
			}
		}
		else {
			int ji = tmp.find('.');
			if (ji == tmp.size() - 1) {
				string str1 = tmp.substr(0, ji);
				int str3 = stoi(str1);
				if (str3 >= -1000 && str3 <= 1000) {
					sum++;
					res = res + str3;
				}
				else {
					cout << "ERROR: " << tmp << " is not a legal number" << endl;
				}
			}
			else {
				if (tmp.find('.', ji + 1) != string::npos) {
					cout << "ERROR: " << tmp << " is not a legal number" << endl;
				}
				else {
					string str1 = tmp.substr(0, ji);
					string str2 = tmp.substr(ji + 1);
					double str3;
					if (str2.size() > 2) {
						cout << "ERROR: " << tmp << " is not a legal number" << endl;
					}
					else {
						if (stoi(str1) < 0) {
							if (str2.size() <= 1) {
								str3 = stoi(str1) - stoi(str2) / 10.0;
							}
							else {
								str3 = stoi(str1) - stoi(str2) / 100.0;
							}
						}
						else {
							if (str2.size() <= 1) {
								str3 = stoi(str1) + stoi(str2) / 10.0;
							}
							else {
								str3 = stoi(str1) + stoi(str2) / 100.0;
							}

						}
						if (str3 >= -1000 && str3 <= 1000) {
							sum++;
							res = res + str3;
							/*					cout << "res:" << " "<< stoi(str1)<<" "<< stoi(str2)<<" "<<res << endl;*/
						}
						else {
							cout << "ERROR: " << tmp << " is not a legal number" << endl;
						}
					}
				}
			}
		}
	}
	if (sum == 0) {
		cout << "The average of 0 numbers is Undefined";
	}
	else {
		if (sum == 1) {
			cout << "The average of 1 numbers is " << res;
			return 0;
		}
		cout << "The average of " << sum << " numbers is ";
		//cout << res << endl;
		printf("%.2lf", res / sum);
	}



	return 0;
}