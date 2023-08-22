#include <iostream>
#include <string>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::string v[n][m];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			std::cin >> v[i][j];
		}
	}

	int q = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			std::string s = v[i][j];

			if(v[i][j+1] == s) {
q += (s == v[i][j+2] && s == v[i][j+3]);
			}

			if(v[i+1][j] == s) {
q += (s == v[i+2][j] && s == v[i+3][j]);
			}
			
			if(v[i+1][j+1] == s) {
q += (s == v[i+2][j+2] && s == v[i+3][j+3]);
			}

			if(v[i-1][j+1] == s) {
q += (s == v[i-2][j+2] && s == v[i-3][j+3]);
			}
		}
	}

	std::cout << q << "\n";

	return 0;
}
