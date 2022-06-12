#include "bits/stdc++.h"

#define DEFIN(x) int _##x; scanf("%d", &_##x); const int x = _##x
#define DEFIN2(x, y) DEFIN(x); DEFIN(y)
#define DEFIN3(x, y, z) DEFIN(x); DEFIN(y); DEFIN(z)
#define DEFIN4(x, y, z, w) DEFIN(x); DEFIN(y); DEFIN(z); DEFIN(w)
#define DEFIN5(x, y, z, w, v) DEFIN(x); DEFIN(y); DEFIN(z); DEFIN(w); DEFIN(v)
#define DEFCIN(type, x) type _##x; ::std::cin >> _##x ; const type x = ::std::move(_##x)
#define DEFLINE(x) \
    ::std::string _##x; ::std::getline(::std::cin, _##x); const ::std::string x = ::std::move(_##x)
#define IN(x) scanf("%d", &x)
#define IN2(x, y) IN(x); IN(y)
#define IN3(x, y, z) IN(x); IN(y); IN(z)
#define IN4(x, y, z, w) IN(x); IN(y); IN(z); IN(w)
#define IN5(x, y, z, w, v) IN(x); IN(y); IN(z); IN(w); IN(v)
#define FILLIN(arr, N) \
    ::std::vector<int> arr(N); for (auto& e : arr) { IN(e); } ((void)0)
#define CIN(x) ::std::cin >> x

#define OUT(x) printf("%d", x)
#define OUTSP(x) OUT(x); printf(" ")
#define OUTLN(x) OUT(x); printf("\n")
#define LN() printf("\n")
#define COUT(x) ::std::cout << x << " "
#define COUTLN(x) ::std::cout << x << "\n"
#define PRINT(...) ::std::cout << format(__VA_ARGS__);
#define PRINTLN(...) ::std::cout << format(__VA_ARGS__) << "\n";
#define CIN_DUMMY_LINE() { ::std::string line; ::std::getline(::std::cin, line); }

#define LOOP(x) for (int _loop_macro = 0; _loop_macro < (x); ++_loop_macro)
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FOR1(i, n) for (int i = 1; i <= (n); ++i)

#define RANGE(x) begin(x), end(x)

#define MP(x, y) ::std::make_pair(x, y)
#define L first
#define R second
#define TIE ::std::forward_as_tuple

#define ARR(N) ::std::array<int, N>

///////////////////////////////////////////////////////////////////////////////
// macro-like functions & helpers
///////////////////////////////////////////////////////////////////////////////

void detach_stdio() {
    ::std::ios::sync_with_stdio(0);
    ::std::cin.tie(0);
    ::std::cout.tie(0);
}

template <typename T>
void Maxin(T& x, const T& y) { x = ::std::max(x, y); }

template <typename T>
void Minin(T& x, const T& y) { x = ::std::min(x, y); }

template <typename T>
bool Board(const T& x, const T& y, const T& N, const T& M) { return 0 <= x && x < N && 0 <= y && y < M; }

///////////////////////////////////////////////////////////////////////////////
// container sfinae & helper
///////////////////////////////////////////////////////////////////////////////

template <typename> struct _is_container : std::false_type {};
template <typename T, size_t N> struct _is_container<std::array<T, N>> : std::true_type {};
template <typename T, typename Alloc> struct _is_container<std::vector<T, Alloc>> : std::true_type {};
template <typename T, typename Alloc> struct _is_container<std::list<T, Alloc>> : std::true_type {};
template <typename T, typename Alloc> struct _is_container<std::deque<T, Alloc>> : std::true_type {};
template <typename T, typename Alloc> struct _is_container<std::set<T, Alloc>> : std::true_type {};
template <typename T, typename Alloc> struct _is_container<std::map<T, Alloc>> : std::true_type {};
template <typename T, typename Alloc> struct _is_container<std::multiset<T, Alloc>> : std::true_type {};
template <typename T, typename Alloc> struct _is_container<std::multimap<T, Alloc>> : std::true_type {};
template <typename T, typename Alloc> struct _is_container<std::unordered_set<T, Alloc>> : std::true_type {};
template <typename T, typename Alloc> struct _is_container<std::unordered_map<T, Alloc>> : std::true_type {};

template <typename> struct _is_pair : std::false_type {};
template <typename T1, typename T2> struct _is_pair<std::pair<T1, T2>> : std::true_type {};

template <typename> struct _is_string : std::false_type {};
template <> struct _is_string<std::string> : std::true_type {};
template <typename T> using _is_string_decay = _is_string<std::decay_t<T>>;

template <typename Container>
int len(const Container& c) {
    return c.size();
}

///////////////////////////////////////////////////////////////////////////////
// STL ostream
///////////////////////////////////////////////////////////////////////////////

template <typename T, typename std::enable_if_t<_is_pair<T>::value>* = nullptr>
std::ostream& operator<< (std::ostream& out, const T& v) {
    out << "(" << v.first << ", " << v.second << ")";
    return out;
}

// TODO: make it generic
std::ostream& operator<< (std::ostream& out, const std::tuple<int, int, int>& t) {
    auto [a, b, c] = t;
    out << "(" << a << ", " << b << ", " << c << ")";
    return out;
}

// TODO: make it generic
std::ostream& operator<< (std::ostream& out, const std::tuple<int, int, int, int>& t) {
    auto [a, b, c, d] = t;
    out << "(" << a << ", " << b << ", " << c << ", " << d << ")";
    return out;
}

template <typename T, typename std::enable_if_t<_is_container<T>::value>* = nullptr>
std::ostream& operator<< (std::ostream& out, const T& v) {
    if (v.empty()) {
        out << "[]";
    } else {
        out << "[";
        for (const auto& e : v) {
            out << e << ", ";
        }
        out << "\b\b]";
    }
    return out;
}

///////////////////////////////////////////////////////////////////////////////
// string formatter
///////////////////////////////////////////////////////////////////////////////

std::string format() {
    return {};
}

std::string format(const char* fmt) {
    return {fmt};
}

template <typename T>
std::string format(const char* fmt, T&& arg) {
    bool substituted = false;
    std::string res;
    while (*fmt != 0) {
        if (!substituted && *fmt == '{' && *(fmt + 1) == '}') {
            std::stringstream ss;
            ss << arg;
            res.append(ss.str());
            substituted = true;
            fmt += 2;
        } else {
            res.push_back(*fmt);
            ++fmt;
        }
    }
    return res;
}

template <typename T, typename... Args>
std::string format(const char* fmt, T&& arg, Args&&... args) {
    std::string res;
    while (*fmt != 0) {
        if (*fmt == '{' && *(fmt + 1) == '}') {
            std::stringstream ss;
            ss << arg;
            res.append(ss.str());
            res.append(format(fmt + 2, std::forward<Args>(args)...));
            break;

        } else {
            res.push_back(*fmt);
            ++fmt;
        }
    }
    return res;
}

///////////////////////////////////////////////////////////////////////////////
// improved pair
///////////////////////////////////////////////////////////////////////////////

template <typename T1, typename T2>
std::pair<T1, T2>& operator+=(std::pair<T1, T2>& a, const std::pair<T1, T2>& b) {
	a.first += b.first, a.second += b.second;
	return a;
}

template <typename T1, typename T2>
std::pair<T1, T2>& operator-=(std::pair<T1, T2>& a, const std::pair<T1, T2>& b) {
	a.first -= b.first, a.second -= b.second;
	return a;
}

namespace std {

template <typename T1, typename T2>
struct hash<std::pair<T1, T2>> {
public:
    size_t operator()(const std::pair<T1, T2>& p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

}   // namespace std

///////////////////////////////////////////////////////////////////////////////
// end of prelude
///////////////////////////////////////////////////////////////////////////////
// #include "stdio_ll.h"

constexpr int INF = INT_MAX / 2;
constexpr int NOP = -1;
constexpr int xs[4] = {-1, 0, 0, 1};
constexpr int ys[4] = {0, -1, 1, 0};

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ivec = vector<int>;

int main() {
  DEFCIN(string, s);
  DEFCIN(string, t);
  string ss;
  ss.reserve(s.size());
  for (auto e : s) {
    ss.push_back(e);
    if (ss.size() >= t.size() && ss.substr(ss.size() - t.size()) == t) {
      ss.resize(ss.size() - t.size());
    }
  }
  COUTLN((ss.empty() ? string("FRULA") : ss));
  return 0;
}
