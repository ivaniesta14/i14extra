#ifndef I14EXTRA_OCTONION_HPP
#define I14EXTRA_OCTONION_HPP

#include <type_traits>
#include <complex>
#include <stdexcept>

namespace i14extra{

template<typename T> class octonion{
    static_assert(std::is_integral<T>::value||
                  std::is_floating_point<T>::value,
                  "Cannot construct octonion for non-integer, non-float type!");
public:
    T r,i,j,k;
    T l,m,n,o;
    
    typedef T type;
    
    inline T& operator[](const unsigned& pos){
        static_assert(pos<=8,"octonion::operator[]: pos out of range 0..7!");
        switch(pos){
        case 0:
            return r;
        case 1:
            return i;
        case 2:
            return j;
        case 3:
            return k;
        case 4:
            return l;
        case 5:
            return m;
        case 6:
            return n;
        case 7:
            return o;
        }
    }
    
    ///CONSTRUCTORS
    constexpr octonion(
            const type& a=new type(),const type& b=new type(),
            const type& c=new type(),const type& d=new type(),
            const type& e=new type(),const type& f=new type(),
            const type& g=new type(),const type& h=new type()):
        r(a),i(b), j(c),k(d),
        l(e),m(f), n(g),o(h){}
    
    template<typename U> constexpr octonion(
            const std::complex<U>& z,
            const std::complex<U>& zj=*new std::complex<U>(),
            const std::complex<U>& zl=*new std::complex<U>(),
            const std::complex<U>& zn=*new std::complex<U>()):
        r(z.real()), i(z.imag()),  j(zj.real()),k(zj.imag()),
        l(zl.real()),m(zl.imag()), n(zn.real()),o(zn.imag()){}
    
    //TODO: quaternion constructor
    
    template<typename U> constexpr octonion(const octonion<U>& other):
        r(other.r),i(other.i),j(other.j),k(other.k),
        l(other.l),m(other.m),n(other.n),o(other.o){}
    
    ///OPERATOR EQ
    template<typename U> const octonion<T>& operator=(const octonion<U>& rhs){
        r=rhs.r;
        i=rhs.i;
        j=rhs.j;
        k=rhs.k;
        l=rhs.l;
        m=rhs.m;
        n=rhs.n;
        o=rhs.o;
        
        return *this;
    }
    template<typename U> const octonion<T>& operator=(const U& rhs){
        return *this=*new octonion<U>(rhs);
    }
    template<typename U>
    const octonion<T>& operator=(const std::complex<U>& rhs){
        return *this=*new octonion<U>(rhs);
    }
    //TODO: quaternion operator=
    
    ///CONVERSION OPERATOR
    explicit inline operator bool() const{
        return r&&i&&j&&k&&l&&m&&n&&o;
    }
    explicit inline operator T() const{
        return r;
    }
    explicit inline operator std::complex<T>() const{
        return *new std::complex<T>(r,i);
    }
    //TODO: operator quaternion
    
    ///MEMBER OPERATOR PLUS EQ
    template<typename U>
    inline const octonion<T>& operator+=(const octonion<U>& rhs){
        r+=rhs.r;
        i+=rhs.i;
        j+=rhs.j;
        k+=rhs.k;
        l+=rhs.l;
        m+=rhs.m;
        n+=rhs.n;
        o+=rhs.o;
        return *this;
    }
    template<typename U> inline const octonion<T>& operator+=(const U& rhs){
        return *this+=*new octonion<U>(rhs);
    }
    template<typename U>
    inline const octonion<T>& operator+=(const std::complex<U>& rhs){
        return *this+=*new octonion<U>(rhs);
    }
    //TODO: quaternion operator+=
    
    ///MEMBER OPERATOR LESS EQ
    template<typename U>
    inline const octonion<T>& operator-=(const octonion<U>& rhs){
        r-=rhs.r;
        i-=rhs.i;
        j-=rhs.j;
        k-=rhs.k;
        l-=rhs.l;
        m-=rhs.m;
        n-=rhs.n;
        o-=rhs.o;
        return *this;
    }
    template<typename U> inline const octonion<T>& operator-=(const U& rhs){
        return *this-=*new octonion<U>(rhs);
    }
    template<typename U>
    inline const octonion<T>& operator-=(const std::complex<U>& rhs){
        return *this-=*new octonion<U>(rhs);
    }
    //TODO: quaternion operator-=
    
    ///MEMBER OPERATOR MULT EQ
    template<typename U>
    inline const octonion<T>& operator*=(const octonion<U>& rhs){
#define _mult(o,s,l,r) out[o] s##= lhs[l]*rhs[r]
        octonion<T> out=0;
        octonion<T>& lhs=*this;
        _mult(0,+,0,0);
        
    }
    
    template<typename U> inline const octonion<T>& operator*=(const U& rhs){
        return *this*=*new octonion<U>(rhs);
    }
    template<typename U>
    inline const octonion<T>& operator*=(const std::complex<U>& rhs){
        return *this*=*new octonion<U>(rhs);
    }
    //TODO: quaternion operator*=
    
    //TODO: member operator/=
    
}

///OPERATOR "" _o*
template<typename T> constexpr octonion<T> operator "" _o (const T& lhs){
    return *new octonion(lhs);
}
template<typename T> constexpr octonion<T> operator "" _oi(const T& lhs){
    return *new octonion(0,lhs);
}
template<typename T> constexpr octonion<T> operator "" _oj(const T& lhs){
    return *new octonion(0,0,lhs);
}
template<typename T> constexpr octonion<T> operator "" _ok(const T& lhs){
    return *new octonion(0,0,0,lhs);
}
template<typename T> constexpr octonion<T> operator "" _ol(const T& lhs){
    return *new octonion(0,0,0,0,lhs);
}
template<typename T> constexpr octonion<T> operator "" _om(const T& lhs){
    return *new octonion(0,0,0,0,0,lhs);
}
template<typename T> constexpr octonion<T> operator "" _on(const T& lhs){
    return *new octonion(0,0,0,0,0,0,lhs);
}
template<typename T> constexpr octonion<T> operator "" _oo(const T& lhs){
    return *new octonion(0,0,0,0,0,0,0,lhs);
}


///NON-MEMBER OPERATOR PLUS
template<typename T,typename U>
constexpr octonion<T> operator+(const octonion<T>& lhs,const octonion<T>& rhs){
    octonion<T> temp=lhs;
    return temp+=rhs;
}
template<typename T,typename U>
constexpr octonion<T> operator+(const octonion<T>& lhs,const U& rhs){
    return lhs+*new octonion<U>(rhs);
}
template<typename T,typename U>
constexpr octonion<T> operator+(const U& lhs,const octonion<T>& rhs){
    return rhs+lhs;
}
template<typename T,typename U> constexpr
octonion<T> operator+(const octonion<T>& lhs,const std::complex<U>& rhs){
    return lhs+*new octonion<U>(rhs);
}
template<typename T,typename U> constexpr
octonion<T> operator+(const std::complex<U>& lhs,const octonion<T>& rhs){
    return rhs+lhs;
}
//TODO: operator+ quaternion

///NON-MEMBER OPERATOR LESS
template<typename T,typename U>
constexpr octonion<T> operator-(const octonion<T>& lhs,const octonion<T>& rhs){
    octonion<T> temp=lhs;
    return temp-=rhs;
}
template<typename T,typename U>
constexpr octonion<T> operator-(const octonion<T>& lhs,const U& rhs){
    return lhs-*new octonion<U>(rhs);
}
template<typename T,typename U>
constexpr octonion<T> operator-(const U& lhs,const octonion<T>& rhs){
    return rhs-lhs;
}
template<typename T,typename U> constexpr
octonion<T> operator-(const octonion<T>& lhs,const std::complex<U>& rhs){
    return lhs-*new octonion<U>(rhs);
}
template<typename T,typename U> constexpr
octonion<T> operator-(const std::complex<U>& lhs,const octonion<T>& rhs){
    return rhs-lhs;
}
//TODO: operator- quaternion

///NON-MEMBER OPERATOR MULT
template<typename T,typename U>
constexpr octonion<T> operator*(const octonion<T>& lhs,const octonion<T>& rhs){
    octonion<T> temp=lhs;
    return temp*=rhs;
}
template<typename T,typename U>
constexpr octonion<T> operator*(const octonion<T>& lhs,const U& rhs){
    return lhs**new octonion<U>(rhs);
}
template<typename T,typename U>
constexpr octonion<T> operator*(const U& lhs,const octonion<T>& rhs){
    return rhs*lhs;
}
template<typename T,typename U> constexpr
octonion<T> operator*(const octonion<T>& lhs,const std::complex<U>& rhs){
    return lhs**new octonion<U>(rhs);
}
template<typename T,typename U> constexpr
octonion<T> operator*(const std::complex<U>& lhs,const octonion<T>& rhs){
    return rhs*lhs;
}
//TODO: operator* quaternion

///NON-MEMBER OPERATOR DIV
template<typename T,typename U>
constexpr octonion<T> operator/(const octonion<T>& lhs,const octonion<T>& rhs){
    octonion<T> temp=lhs;
    return temp/=rhs;
}
template<typename T,typename U>
constexpr octonion<T> operator/(const octonion<T>& lhs,const U& rhs){
    return lhs/ *new octonion<U>(rhs);
}
template<typename T,typename U>
constexpr octonion<T> operator/(const U& lhs,const octonion<T>& rhs){
    return rhs/lhs;
}
template<typename T,typename U> constexpr
octonion<T> operator/(const octonion<T>& lhs,const std::complex<U>& rhs){
    return lhs/ *new octonion<U>(rhs);
}
template<typename T,typename U> constexpr
octonion<T> operator/(const std::complex<U>& lhs,const octonion<T>& rhs){
    return rhs/lhs;
}
//TODO: operator/ quaternion


}//namespace i14extra

#endif //I14EXTRA_OCTONION_HPP
