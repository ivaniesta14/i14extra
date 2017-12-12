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
public:
    typedef T value_type;
    T x,y,z;
    constexpr point_t(const T& vx=*new T(),const T& vy=*new T(),
                      const T& vz=*new T()):
        x(static_cast<T>(vx)),y(static_cast<T>(vy)),z(static_cast<T>(vz)){}
    constexpr point_t(point_t& other):
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
    inline operator T(){return x;}
    inline operator std::complex<T>(){return *new std::complex<T>(x,y);}
    inline operator std::pair<T,T>(){return std::make_pair(x,y);}
    inline operator std::tuple<T,T,T>(){return std::make_tuple(x,y,z);}
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
        x=std::get<0>(rhs);
        y=std::get<1>(rhs);
        z=std::get<2>(rhs);
        return *this;
    }
};

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
