//
// Created by 今村秀明 on 2018/01/07.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <tuple>

typedef std::tuple<long long, long long, long long> tri;

int main() {
    long long N, H, ai, bi;
    std::vector<tri> input_data;
    scanf("%lld %lld", &N, &H);
    for (long long i = 0; i < N; ++i) {
        scanf("%lld %lld", &ai, &bi);
        input_data.push_back(std::make_tuple(i, ai, bi));
    }

    std::sort(
            input_data.begin(),
            input_data.end(),
            [](tri const &lhs, tri const &rhs) {
                if (std::get<1>(lhs) != std::get<1>(rhs)) return std::get<1>(lhs) > std::get<1>(rhs);
                if (std::get<2>(lhs) != std::get<2>(rhs)) return std::get<2>(lhs) < std::get<2>(rhs);
                return std::get<0>(lhs) > std::get<0>(rhs);
            }
    );

    long long i_max = std::get<0>(input_data[0]);
    long long a_max = std::get<1>(input_data[0]);
    long long b_max = std::get<2>(input_data[0]);

    std::sort(
            input_data.begin(),
            input_data.end(),
            [](tri const &lhs, tri const &rhs) {
                if (std::get<2>(lhs) != std::get<2>(rhs)) return std::get<2>(lhs) > std::get<2>(rhs);
                if (std::get<1>(lhs) != std::get<1>(rhs)) return std::get<1>(lhs) > std::get<1>(rhs);
                return std::get<0>(lhs) > std::get<0>(rhs);
            }
    );

    long long i = 0;
    long long ans = 0;
    bool flag = false;
    while (H > 0) {
        if (std::get<2>(input_data[i]) <= a_max || i == N) {
            if (flag) {
                if (H - b_max <= 0) {
                    ans += 1;
                } else {
                    ans += ((H - b_max) / a_max + ((H - b_max) % a_max > 0) + 1);
                }
            } else {
                ans += (H / a_max + (H % a_max > 0));
            }
            H = -1;
        } else {
            if (i_max == std::get<0>(input_data[i])) {
                flag = true;
                i++;
            } else {
                H -= std::get<2>(input_data[i]);
                i++;
                ans++;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
