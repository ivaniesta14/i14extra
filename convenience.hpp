#ifndef I14EXTRA_CONVENIENCE_HPP
#define I14EXTRA_CONVENIENCE_HPP

namespace i14extra{

typedef signed char schar;
typedef signed short sshort;
typedef signed sint;
typedef signed long slong;
typedef signed long long slonglong, sllong, llong;
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

#define I_NO_COPY_CONS(c)\
    c(const c& other)=delete
#define nocopycon(c) I_NO_COPY_CONS(c)
#define I_NO_COPY(c) \
    I_NO_COPY_CONS(c);\
    const c& operator=(const c& rhs)=delete
#define nocopy(c) I_NO_COPY(c)

#define I_NO_DEF_CONS(c) \
    c()=delete
#define nodefcon(c) I_NO_DEF_CONS(c)

#define DELETED =delete
#define deleted DELETED
#define DEFAULTED =default
#define defaulted DEFAULTED


#ifdef _GLIBCXX_UNORDERED_MAP
template<typename E,typename T>
using enum_unordered_map=std::unordered_map<E,T,std::hash<int>>;
template<typename E,typename T>
using enum_unordered_multimap=std::unordered_multimap<E,T,std::hash<int>>;
template<typename T,typename U> using umap=std::unordered_map<T,U>;
template<typename E,typename T> using enum_umap=enum_unordered_map<E,T>;
template<typename T,typename U> using ummap=std::unordered_multimap<T,U>;
template<typename E,typename T> using enum_ummap=enum_unordered_multimap<E,T>;
#endif //_GLIBCXX_UNORDERED_MAP
#ifdef _GLIBCXX_UNORDERED_SET
template<typename E>
using enum_unordered_set=std::unordered_set<E,std::hash<int>>;
template<typename E>
using enum_unordered_multiset=std::unordered_multiset<E,std::hash<int>>;
template<typename T> using uset=std::unordered_set<T>;
template<typename T> using enum_uset=enum_unordered_set<T>;
template<typename T> using umset=std::unordered_multiset<T>;
template<typename T> using enum_umset=enum_unordered_multiset<T>;
#endif //_GLIBCXX_UNORDERED_SET

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
template<typename T,typename U> constexpr bool eq(const T& lhs,const U& rhs){
    return lhs==rhs;
}
template<typename T,typename U> constexpr bool neq(const T& lhs,const U& rhs){
    return lhs!=rhs;
}

#define ref &
#define lref &
#define cref const &
#define cv const volatile

#define I_AUTO_EQ(left,right)\
    bool operator==(left cref lhs,right cref rhs){\
        return lhs.operator==(rhs);\
    }

#define I_AUTO_NOT_EQ(left,right) \
    bool operator!=(left cref lhs,right cref rhs){\
        return !(lhs==rhs);\
    }
#define I_AUTO_LT(left, right)\
    bool operator<(const left& lhs,const right& rhs){\
        return lhs<rhs;\
    }
#define I_AUTO_GT(left, right) I_AUTO_LT(right,left)
#define I_AUTO_LT_EQ(left, right)\
    bool operator<=(const left& lhs,const right& rhs){\
        return !(lhs>rhs);\
    }
#define I_AUTO_RT_EQ(left,right) I_AUTO_LT_EQ(right,left)

#define i_eq(left,right) I_AUTO_EQ(left,right)
#define i_not_eq(left,right) I_AUTO_NOT_EQ(left,right)
#define i_lt(left, right) I_AUTO_LT(left,right)
#define i_gt(left, right) I_AUTO_GT(left, right)
#define i_lt_eq(left, right) I_AUTO_LT_EQ(left,right)
#define i_gt_eq(left, right) I_AUTO_GT_EQ(left,right)


#define I_AUTO_GETTER(type,from,name,Name)\
    type get##Name(){\
        return from.name;\
    }
#define I_AUTO_SETTER(type,to,name,Name)\
    type ref set##Name(type cref val){\
        to.name=val;\
        return *this;\
    }
#define I_AUTO_VOID_SETTER(type,to,name,Name)\
    void set##Name(type cref val){\
        to.name=val;\
    }
#define I_AUTO_BOOL_GETTER(type,from,name,Name)\
    type is##Name(){\
        return from.name;\
    }
#define getter(type,from,name,Name) I_AUTO_GETTER(type,from,name,Name)
#define setter(type,to,name,Name) I_AUTO_SETTER(type,to,name,Name)
#define void_setter(type,to,name,Name)\
    I_AUTO_VOID_SETTER(type,to,name,Name)
#define bool_getter(type,from,name,Name)\
    I_AUTO_BOOL_GETTER(type,to,name,Name)

#define sget std::get

}//namespace i14extra

#endif //I14EXTRA_CONVENIENCE_HPP
