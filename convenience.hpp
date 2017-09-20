#ifndef I14EXTRA_CONVENIENCE_HPP
#define I14EXTRA_CONVENIENCE_HPP

#include <unordered_map>
#include <unordered_set>

namespace i14extra{
#ifndef QT_VERSION
typedef signed char schar;
typedef unsigned char uchar;
typedef signed short sshort;
typedef unsigned short ushort;
typedef signed sint;
typedef unsigned uint;
typedef signed long slong;
typedef unsigned long ulong;
typedef signed long long slonglong, sllong, llong;
typedef unsigned long long ulonglong, ullong;
typedef long double ldouble;
#define I_FWD_CLASS(c) class c;
#else
#define I_FWD_CLASS(c) QT_FORWARD_DECLARE_CLASS(c);
#endif
#define I_NO_COPY(c) \
    c(const c& other)=delete;\
    const c& operator=(const c& rhs)=delete;
#define nocopy(c) I_NO_COPY(c)
template<typename E,typename T>
using enum_unordered_map=std::unordered_map<E,T,std::hash<int>>;
template<typename E>
using enum_unordered_set=std::unordered_set<E,std::hash<int>>;
template<typename E,typename T>
using enum_unordered_multimap=std::unordered_multimap<E,T,std::hash<int>>;
template<typename E>
using enum_unordered_multiset=std::unordered_multiset<E,std::hash<int>>;
#define DELETED =delete;
#define deleted DELETED;
}//namespace i14extra

#endif //I14EXTRA_CONVENIENCE_HPP
