// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _IO_H
#define _IO_H 1
#include <_types.h>

namespace std {
template <typename InputIterator>
ostream &print(InputIterator first, InputIterator last, ostream &out = cout);
//

template <typename InputIterator>
inline ostream &println(InputIterator first, InputIterator last, ostream &out = cout) {
    return print(first, last, out) << '\n';
}

template <typename Tp>
inline ostream &operator<<(ostream &out, const vector<Tp> &v) {
    return print(v.begin(), v.end(), out);
}

template <typename Tp, size_t N>
inline ostream &operator<<(ostream &out, const array<Tp, N> &arr) {
    return print(arr.begin(), arr.end(), out);
}

template <typename Tp>
inline ostream &operator<<(ostream &out, const deque<Tp> &dq) {
    return print(dq.begin(), dq.end(), out);
}
template <typename Tp>
inline ostream &operator<<(ostream &out, const forward_list<Tp> &l) {
    return print(l.begin(), l.end(), out);
}
template <typename Tp>
inline ostream &operator<<(ostream &out, const list<Tp> &l) {
    return print(l.begin(), l.end(), out);
}
template <typename Tp>
inline ostream &operator<<(ostream &out, const multiset<Tp> &s) {
    return print(s.begin(), s.end(), out);
}
//
template <typename Tp>
inline ostream &operator<<(ostream &out, const unordered_set<Tp> &us) {
    return print(us.begin(), us.end(), out);
}

template <typename T1, typename T2>
inline ostream &operator<<(ostream &out, const unordered_map<T1, T2> &um) {
    return print(um.begin(), um.end(), out);
}
//
template <typename Tp, typename Sequence>
inline ostream &operator<<(ostream &out, const stack<Tp, Sequence> &st) {
    stack<Tp, Sequence> temp(st);
    vector<Tp> v(st.size());
    for (typename vector<Tp>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit) {
        *rit = move(temp.top());
        temp.pop();
    }
    return out << v;
}
template <typename Tp, typename Sequence>
inline ostream &operator<<(ostream &out, const queue<Tp, Sequence> &q) {
    queue<Tp, Sequence> temp(q);
    vector<Tp> v(q.size());
    for (typename vector<Tp>::iterator it = v.begin(); it != v.end(); ++it) {
        *it = move(temp.front());
        temp.pop();
    }
    return out << v;
}
//
template <typename Tp>
inline ostream &operator<<(ostream &out, const optional<Tp> &opt) {
    if (opt.has_value()) {
        out << opt.value();
    } else {
        out << "null";
    }
    return out;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
    out << '<' << p.first << ", " << p.second << '>';
    return out;
}

template <typename InputIterator>
ostream &print(InputIterator first, InputIterator last, ostream &out) {
    if (first == last) {
        out << "[]";
        return out;
    }
    //
    out << '[';
    out << *first;
    while (++first != last) {
        out << ", " << *first;
    }
    out << ']';
    return out;
}

void setting_io_faster() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  // cout.tie(nullptr);
}

}  // namespace std
#endif
