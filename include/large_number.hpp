#ifndef INCLUDE_LARGE_NUMBER
#define INCLUDE_LARGE_NUMBER

template <typename T>
struct large_number {
    std::vector<T> num;
    large_number(std::vector<T>& n) : num{n} {}
    large_number() : num{} {}
    large_number(unsigned long long n) : num{} {
        while (n > 0ull) {
            num.push_back(static_cast<T>(n % 10ull));
            n /= 10ull;
        }
    }
    constexpr size_t size() const { return this->num.size(); }
};

large_number<unsigned> add(const large_number<unsigned>& n1, const large_number<unsigned>& n2);
void println(large_number<unsigned>& n);

#endif