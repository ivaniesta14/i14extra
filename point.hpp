#ifndef I14EXTRA_POINT_HPP
#define I14EXTRA_POINT_HPP

#include <complex>
#include <utility>
#include <tuple>
#include <type_traits>

namespace i14extra {

template <typename T>
class point_t{
    T x,y,z;
public:
    typedef T value_type;
    constexpr point_t(const T& vx=*new T(),const T& vy=*new T(),
                      const T& vz=*new T()):
        x(static_cast<T>(vx)),y(static_cast<T>(vy)),z(static_cast<T>(vz)){}
    constexpr point_t(point_t& other):
        point_t(other.rx(),other.ry(),other.rz()){}
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
    inline T& rx(){return x;}
    inline T& ry(){return y;}
    inline T& rz(){return z;}
    inline T& rx(T vx){x=vx;return x;}
    inline T& ry(T vy){y=vy;return y;}
    inline T& rz(T vz){z=vz;return z;}
    inline operator T(){return x;}
    inline operator std::complex<T>(){return *new std::complex<T>(x,y);}
    inline operator std::pair<T,T>(){return std::make_pair(x,y);}
    inline operator std::tuple<T,T,T>(){return std::make_tuple(x,y,z);}
    inline const point_t<T>& operator=(const point_t<T>& rhs){
        rx(rhs.rx());ry(rhs.ry());rz(rhs.rz()); return *this;
    }
    inline const point_t<T>& operator=(const T& rhs){
        rx()=rhs; ry()=0; rz()=0; return *this;
    }
    inline const point_t<T>& operator=(const std::complex<T>& rhs){
        rx()=rhs.real();ry()=rhs.imag();rz()=0; return *this;
    }
    inline const point_t<T>& operator=(const std::pair<T,T>& rhs){
        rx()=rhs.first;ry()=rhs.second;rz()=0; return *this;
    }
    inline const point_t<T>& operator=(const std::tuple<T,T,T>& rhs){
        rx(std::get<0>(rhs)); ry(std::get<1>(rhs));
        rz(std::get<2>(rhs)); return *this;
    }
};

}

#endif //I14EXTRA_POINT_HPP
