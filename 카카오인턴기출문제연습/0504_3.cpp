#include <string>
#include <vector>
#include <map>
using namespace std;

void convert_upper(string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a';
            str[i] += 'A';
        }
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> cache; // string, time
    int time = 0;
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        convert_upper(city);
        auto iter = cache.find(city);
        if (iter == cache.end()) {
            time += 5;
            cache[city] = i;
        }
        else {
            if (i - iter->second > cacheSize) {
                time += 5;
                iter->second = i;
            }
            else {
                time += 1;
                iter->second = i;
            }
        }
    }
    answer = time;
    return answer;
}

int main() {
    vector<string> cities = {
        "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"
    };
    int ans = solution(5, cities);

}