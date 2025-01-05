
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

// Source: https://stackoverflow.com/a/31116392/12128483
template <typename Type, unsigned N, unsigned Last>
struct TuplePrinter {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value) << ", ";
        TuplePrinter<Type, N + 1, Last>::print(out, value);
    }
};

template <typename Type, unsigned N>
struct TuplePrinter<Type, N, N> {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value);
    }
};

template <typename... Types>
std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& value) {
    out << '(';
    TuplePrinter<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out,
                                                                       value);
    return out << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& deq);

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out,
                         const std::unordered_map<T1, T2>& map);

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& map);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& set);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::multiset<T>& set);

template <typename T>
std::ostream& operator<<(std::ostream& out,
                         const std::unordered_multiset<T>& set);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    out << '[';
    string sep;
    for (const T& x : vec) out << sep << x, sep = ", ";
    return out << ']';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& deq) {
    out << '[';
    string sep;
    for (const T& x : deq) out << sep << x, sep = ", ";
    return out << ']';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out,
                         const std::unordered_map<T1, T2>& map) {
    out << '{';
    string sep;
    for (const auto& [k, v] : map) {
        out << sep << '(' << k << ": " << v << ')', sep = ", ";
    }
    return out << '}';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& map) {
    out << '{';
    string sep;
    for (const auto& [k, v] : map) {
        out << sep << '(' << k << ": " << v << ')', sep = ", ";
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& set) {
    out << '{';
    string sep;
    for (const T& element : set) {
        out << sep << element, sep = ", ";
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set) {
    out << '{';
    string sep;
    for (const T& element : set) {
        out << sep << element, sep = ", ";
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::multiset<T>& set) {
    out << '{';
    string sep;
    for (const T& element : set) {
        out << sep << element, sep = ", ";
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out,
                         const std::unordered_multiset<T>& set) {
    out << '{';
    string sep;
    for (const T& element : set) {
        out << sep << element, sep = ", ";
    }
    return out << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

template <typename T>
void pa(T arr[], int n) {
    cout << '[';
    string sep;
    for (int i = 0; i < n; ++i) cout << sep << arr[i], sep = ", ";
    cout << ']';
}

#define dbg(...)                                             \
    cerr << 'L' << __LINE__ << " (" << #__VA_ARGS__ << "):", \
        dbg_out(__VA_ARGS__)
