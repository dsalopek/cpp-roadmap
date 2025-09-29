#include <iostream>
#include <string>

template<typename X, typename Y, typename Z>
class Triad {
public:
    Triad(const X &first, const Y &second, const Z &third) : m_first{first},
        m_second{second},
        m_third{third} {
    }

    const X &first() const { return m_first; }
    const Y &second() const { return m_second; }
    const Z &third() const { return m_third; }

    void print() const; //defined externally to class
private:
    X m_first{};
    Y m_second{};
    Z m_third{};
};

template<typename X, typename Y, typename Z>
void Triad<X, Y, Z>::print() const {
    std::cout << '[' << first() << ", " << second() << ", " <<
            third() << ']';
}

int main() {
    Triad<int, int, int> t1{1, 2, 3};
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2{1, 2.3, "Hello"s};
    t2.print();
    std::cout << '\n';

    return 0;
}
