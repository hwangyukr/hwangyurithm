#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int n = food_times.size();
    long long round = k / n; // 음식당 먹은개수
    long long offset = k % n;
    long long reverse = 0; // 음식을 K번 먹기까지 부족했던 음식 수
    vector<int> ates(n,0);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int ate = round;
        if (i < offset) ate += 1;
        if (food_times[i] < ate) { // 음식이 부족했던 만큼 reverse
            reverse += ate - (long long)food_times[i];
        }
        ates[i] = ate;

        total += food_times[i];
    }

    if (reverse > total) return -1; // 음식부족

    long long new_k = k + reverse + 1;
    long long new_offset = new_k % n;
    answer = new_offset + 1;
    return answer;
}

int main() {
    int ans4 = solution({ 3, 1, 2 }, 5); cout << ans4 << endl;
    int ans5 = solution({ 10, 10, 100 }, 300); cout << ans5 << endl;
    int ans2 = solution({ 3000, 99, 99 }, 300); cout << ans2 << endl;
    int ans1 = solution({ 3000, 1, 1 }, 300); cout << ans1 << endl;
    int ans6 = solution({ 99, 1, 3000 }, 300); cout << ans6 << endl;
    int ans3 = solution({ 2, 2, 2 }, 5); cout << ans3 << endl;
    return 0;
}
