#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    map<int, int> birthData;
    int n;

    cout << "Nhập số năm cần thêm dữ liệu: ";
    cin >> n;

    // Nhập dữ liệu năm sinh và số người sinh 
    for (int i = 0; i < n; ++i) {
        int year, births;
        cout << "Nhập năm và số người sinh ra (năm số người): ";
        cin >> year >> births;
        birthData[year] = births;
    }

    map<int, vector<int>> countYears;

    for (const auto& entry : birthData) {
        int year = entry.first;
        int births = entry.second;
        countYears[births].push_back(year);
    }

    // Tìm số lượng sinh ra lớn nhất và bé nhất
    int maxBirths = max_element(birthData.begin(), birthData.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        })->second;

    int minBirths = min_element(birthData.begin(), birthData.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        })->second;

    // Lấy các năm tương ứng
    vector<int> yearsMax = countYears[maxBirths];
    vector<int> yearsMin = countYears[minBirths];

    cout << "Năm có số lượng người sinh ra lớn nhất: ";
    for (int year : yearsMax) {
        cout << year << " ";
    }
    cout << "với số lượng: " << maxBirths << endl;

    cout << "Năm có số lượng người sinh ra bé nhất: ";
    for (int year : yearsMin) {
        cout << year << " ";
    }
    cout << "với số lượng: " << minBirths << endl;

    // In ra các năm có cùng số lượng người sinh ra
    cout << "Các năm có cùng số lượng người sinh ra:" << endl;
    for (const auto& entry : countYears) {
        if (entry.second.size() > 1) {
            cout << "Số lượng " << entry.first << " có các năm: ";
            for (int year : entry.second) {
                cout << year << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
