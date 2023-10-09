#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream input("input.txt");   // Открываем файл для чтения входных данных
ofstream output("output.txt"); // Открываем файл для записи выходных данных

struct ToySet {
    int d;       // Количество игрушек в наборе
    int t;       // Время изготовления набора
    int index;   // Индекс набора (порядковый номер)
};

// Функция сравнения для сортировки наборов игрушек
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int s, n, m;
    input >> s >> n >> m; // Считываем количество наборов, размеры коробки

    vector<ToySet> sets(s); // Создаем вектор, чтобы хранить информацию о наборах игрушек
    for (int i = 0; i < s; ++i) {
        input >> sets[i].d >> sets[i].t; // Считываем количество игрушек и время изготовления наборов
        sets[i].index = i + 1; // Присваиваем индекс набору (начиная с 1)
    }

    // Сортируем наборы игрушек в порядке убывания времени изготовления и убывания количества игрушек
    sort(sets.begin(), sets.end(), [](const ToySet& a, const ToySet& b) {
        if (a.t == b.t) {
            return a.d > b.d;
        }
        return a.t > b.t;
    });

    // Инициализируем двумерные массивы для динамического программирования
    vector<vector<long long>> dp(s + 1, vector<long long>(n * m + 1, 0));
    vector<vector<int>> chosen(s + 1, vector<int>(n * m + 1, 0));

    // Заполняем двумерный массив dp
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

    // Сортируем номера выбранных наборов для вывода в порядке возрастания
    qsort(result.data(), result.size(), sizeof(int), compare);

    // Выводим количество выбранных наборов и их номера в файл output.txt
    output << result.size() << endl;
    for (int box : result) {
        output << box << " ";
    }

    cout << "All done!\n";

    input.close();  // Закрываем файл ввода
    output.close(); // Закрываем файл вывода

    return 0;
}