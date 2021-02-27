#include <iostream>
#include <functional>
template<typename T, int S>
void for_each(T _[S], std::function<void(T&)>);
int main() {
    std::string names[] = {
        "james", "jeff", "noah", "jimmeh",
        "james", "jeff", "noah", "jimmeh",
    };

    for_each<std::string, sizeof(names)/sizeof(std::string)>(names, [](std::string s) {
        std::cout << "   [+] moving over " << s+'\n';
    });
};

template<typename T, int S>
void for_each(T data[S], std::function<void(T&)> fn) {
    for(int i=0; i <= S-1; i++)
        fn(data[i]);
}