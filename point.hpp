#ifndef I14EXTRA_POINT_HPP
#define I14EXTRA_POINT_HPP

#include <complex>
#include <utility>
#include <tuple>
#include <type_traits>
#include "i14extra/convenience.hpp"

namespace i14extra {

template <typename T>
class point_t{
    static_assert(std::is_arithmetic_v<T>,
                  "i14extra::point<T>: T must be arithmetic");
public:
    typedef T value_type;
    T x,y,z;
    constexpr point_t(const T& vx=*new T(),const T& vy=*new T(),
                      const T& vz=*new T()):
        x(static_cast<T>(vx)),y(static_cast<T>(vy)),z(static_cast<T>(vz)){}
    template<typename U>constexpr point_t(point_t<U> cref other):
        point_t(other.x,other.y,other.z){}
    template<typename U>
    constexpr point_t(const std::complex<U>& other):
        point_t(static_cast<T>(other.real()),static_cast<T>(other.imag())){}
    template<typename U,typename V>
    constexpr point_t(const std::pair<U,V>& other):
        point_t(static_cast<T>(other.first),static_cast<T>(other.second)){}
    template<typename U,typename V,typename W>
    constexpr point_t(const std::tuple<U,V,W>& other):point_t(
        static_cast<T>(std::get<U>(other)),
        static_cast<T>(std::get<V>(other)),
        static_cast<T>(std::get<W>(other))){}
    explicit inline operator T(){return x;}
    template<typename U=T> explicit
    inline operator std::complex<U>(){return *new std::complex<U>(x,y);}
    template<typename U=T,typename V=T> explicit
    inline operator std::pair<U,V>(){return std::make_pair(x,y);}
    template<typename U=T,typename V=T,typename W=T> explicit
    inline operator std::tuple<U,V,W>(){return std::make_tuple(x,y,z);}
    inline const point_t<T>& operator=(const point_t<T>& rhs){
        x=rhs.x;
        y=rhs.y;
        z=rhs.z;
        return *this;
    }
    inline const point_t<T>& operator=(const T& rhs){
        x=rhs;
        y=0;
        z=0;
        return *this;
    }
    inline const point_t<T>& operator=(const std::complex<T>& rhs){
        x=rhs.real();
        y=rhs.imag();
        z=0;
        return *this;
    }
    inline const point_t<T>& operator=(const std::pair<T,T>& rhs){
        x=rhs.first;
        y=rhs.second;
        z=0;
        return *this;
    }
    inline const point_t<T>& operator=(const std::tuple<T,T,T>& rhs){
        x=sget<0>(rhs);
        y=sget<1>(rhs);
        z=sget<2>(rhs);
        return *this;
    }

    template<typename U>
    inline constexpr bool operator==(point_t<U> cref rhs) const{
        return (x==rhs.x)&&(y==rhs.y)&&(z==rhs.z);
    }
    template<typename U>
    inline constexpr bool operator==(std::complex<U> cref rhs) const{
        return (x==rhs.real())&&(y==rhs.imag())&&(z==*new value_type());
    }
    template<typename U>
    inline constexpr bool operator==(U cref rhs) const{
        return (U(x)==rhs)&&(y==*new value_type())&&(z==*new value_type());
    }
};

template<typename T,typename U> inline constexpr i_eq(point_t<T>,point_t<U>)
template<typename T,typename U> inline constexpr i_eq(point_t<T>,U)
template<typename T,typename U> inline constexpr
i_eq(point_t<T>,std::complex<U>)
template<typename T,typename U> inline constexpr
bool operator==(T cref lhs,point_t<U> cref rhs){
    return rhs==lhs;
}
template<typename T,typename U> inline constexpr
bool operator==(std::complex<T> lhs,point_t<U> rhs){
    return rhs==lhs;
}

template<typename T, typename U> inline constexpr
i_not_eq(point_t<T>,point_t<U>)
template<typename T,typename U> inline constexpr i_not_eq(point_t<T>,U)
template<typename T,typename U> inline constexpr i_not_eq(T,point_t<U>)
template<typename T,typename U> inline constexpr
i_not_eq(point_t<T>,std::complex<U>)
template<typename T,typename U> inline constexpr
i_not_eq(std::complex<U>,point_t<T>)


typedef point_t<char> cpoint;
typedef point_t<schar> scpoint;
typedef point_t<uchar> ucpoint;
typedef point_t<sshort> spoint;
typedef point_t<ushort> uspoint;
typedef point_t<sint> point;
typedef point_t<uint> upoint;
typedef point_t<slong> lpoint;
typedef point_t<ulong> ulpoint;
typedef point_t<sllong> llpoint;
typedef point_t<ullong> ullpoint;
typedef point_t<float> fpoint,pointf;
typedef point_t<double> dpoint,pointd;
typedef point_t<ldouble> ldpoint, pointdl;

}

#endif //I14EXTRA_POINT_HPP
