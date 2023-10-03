#include <fstream>
#include <iostream>
#include <queue>
#include <string>

template <typename T>
class Calories {
private:
    std::priority_queue<T> calories;

public:
    Calories();
    T get_top();
    std::tuple<T, T, T> get_top_three();
};

template <typename T>
Calories<T>::Calories() {
    static_assert(std::is_arithmetic_v<T>, "T must be a numeric type");

    try {
        std::ifstream file("input.txt");

        T total_calories = 0;

        std::string line;

        T temp = 0;

        while (std::getline(file, line)) {
            if (line.length()) {
                temp += std::stoi(line);
            } else if (temp != 0) {
                this->calories.push(temp);
                temp = 0;
            }
        }

        this->calories.push(temp);
        file.close();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        throw;
    }
}

template <typename T>
T Calories<T>::get_top() { return this->calories.top(); }

template <typename T>
std::tuple<T, T, T> Calories<T>::get_top_three() {
    T arr[3];
    for (short int i = 0; i < 3; i++) {
        arr[i] = this->calories.top();
        this->calories.pop();
    }

    for (auto i : arr) {
        this->calories.push(i);
    }

    return std::make_tuple(arr[0], arr[1], arr[2]);
}

template <std::size_t I = 0, typename... Args>
typename std::enable_if<I == sizeof...(Args), int>::type
sum_tuple_elements(const std::tuple<Args...> &t, int sum = 0) {
    return sum;
}

template <std::size_t I = 0, typename... Args>
    typename std::enable_if < I<sizeof...(Args), int>::type
                              sum_tuple_elements(const std::tuple<Args...> &t, int sum = 0) {
    return sum + std::get<I>(t) + sum_tuple_elements<I + 1, Args...>(t, sum);
}

int main(int argc, char const *argv[]) {
    Calories<int> day1;

    auto top3 = day1.get_top_three();

    [](const auto &top) {
        std::apply([](const auto &...args) { ((std::cout << args << "\n"), ...); },
                   top);
    }(top3);

    const auto print = [](const auto &...args) {
        ((std::cout << args), ...);
    };

    auto i = sum_tuple_elements(top3);

    std::tuple<int, int> tt;

    print(sum_tuple_elements(tt), "\n");
    print("top element = ", day1.get_top(), "\n");
    print("sum of top 3 = ", i);
    return 0;
}
