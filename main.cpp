#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream input ("input.txt");
ofstream output ("output.txt");

struct ToySet {
    int d;
    int t;
    int index;
};

//For qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int s, n, m;
//    cin >> s >> n >> m;
    input >> s >> n >> m;

    vector<ToySet> sets(s);
    for (int i = 0; i < s; ++i) {
//        cin >> sets[i].d >> sets[i].t;
        input >> sets[i].d >> sets[i].t;
        sets[i].index = i + 1;
    }

    sort(sets.begin(), sets.end(), [](const ToySet& a, const ToySet& b) {
        if (a.t == b.t) {
            return a.d > b.d;
        }
        return a.t > b.t;
    });

    vector<vector<long long>> dp(s + 1, vector<long long>(n * m + 1, 0));
    vector<vector<int>> chosen(s + 1, vector<int>(n * m + 1, 0));

    for (int i = 1; i <= s; ++i) {
        for (int j = 1; j <= n * m; ++j) {
            if (sets[i - 1].d <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - sets[i - 1].d] + sets[i - 1].t);
                if (dp[i][j] > dp[i - 1][j]) {
                    chosen[i][j] = 1;
                }
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    int k = n * m;
    vector<int> result;
    for (int i = s; i >= 1; --i) {
        if (chosen[i][k] == 1) {
            result.push_back(sets[i - 1].index);
            k -= sets[i - 1].d;
        }
    }

//    int* resultArray = result.data();
//    int resultSize = result.size();
    qsort(result.data(), result.size(), sizeof(int), compare);

//    cout << result.size() << endl;
//    for (int box : result) {
//        cout << box << " ";
//    }

    output << result.size() << endl;
    for(int box : result) {
        output << box << " ";
    }

    cout << "All done!\n";

    input.close();
    output.close();

    return 0;
}
