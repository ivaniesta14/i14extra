#ifndef I14EXTRA_CONVENIENCE_HPP
#define I14EXTRA_CONVENIENCE_HPP

#include <unordered_map>
#include <unordered_set>

namespace i14extra{

typedef signed char schar;
typedef signed short sshort;
typedef signed sint;
typedef signed long long slonglong, sllong, llong;
typedef signed long slong;
typedef unsigned long long ulonglong, ullong;
typedef long double ldouble;
#ifndef QGLOBAL_H
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned uint;
typedef unsigned long ulong;
#define I_FWD_CLASS(c) class c
#else //QGLOBAL_H
using uchar=::uchar;
using ushort=::ushort;
using uint=::uint;
using ulong=::ulong;
#define I_FWD_CLASS(c) QT_FORWARD_DECLARE_CLASS(c);
#endif //QGLOBAL_H

#define I_NO_COPY(c) \
    c(const c& other)=delete;\
    const c& operator=(const c& rhs)=delete
#define nocopy(c) I_NO_COPY(c)
template<typename E,typename T>
using enum_unordered_map=std::unordered_map<E,T,std::hash<int>>;
template<typename E>
using enum_unordered_set=std::unordered_set<E,std::hash<int>>;
template<typename E,typename T>
using enum_unordered_multimap=std::unordered_multimap<E,T,std::hash<int>>;
template<typename E>
using enum_unordered_multiset=std::unordered_multiset<E,std::hash<int>>;
#define DELETED =delete
#define deleted DELETED

template<typename T,typename U> constexpr bool gt(const T& lhs, const U& rhs){
    return lhs>rhs;
}
template<typename T,typename U> constexpr bool lt(const T& lhs, const U& rhs){
    return rhs>lhs;
}
template<typename T,typename U>
constexpr bool not_gt(const T& lhs,const U& rhs){
    return not(gt(lhs,rhs));
}
template<typename T,typename U>
constexpr bool not_lt(const T& lhs,const U& rhs){
    return not(gt(rhs,lhs));
}

}//namespace i14extra

#endif //I14EXTRA_CONVENIENCE_HPP
