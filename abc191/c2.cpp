#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) { cin >> s[i]; }

    int p = 0;
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            int count = 0;
            if (s[i][j] == '#') count++;
            if (s[i + 1][j] == '#') count++;
            if (s[i][j + 1] == '#') count++;
            if (s[i + 1][j + 1] == '#') count++;

            if (count == 1 || count == 3) p++;
        }
    }

    cout << p << endl;
    return 0;
}