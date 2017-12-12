#ifndef I14EXTRA_OCTONION_HPP
#define I14EXTRA_OCTONION_HPP

#include <type_traits>
#include <complex>

namespace i14extra{

template<typename T> class octonion{
    static_assert(std::is_integral<T>::value||
                  std::is_floating_point<T>::value,
                  "Cannot construct octonion for non-integer, non-float type!");
public:
    T r,i,j,k;
    T l,m,n,o;
    
    typedef T type;
    typedef std:complex<T> complex_type;
    //TODO: quaternion typedef
    typedef octonion<T> octonion_type;
    
    constexpr octonion(
            const type& a=new type(),const type& b=new type(),
            const type& c=new type(),const type& d=new type(),
            const type& e=new type(),const type& f=new type(),
            const type& g=new type(),const type& h=new type()):
        r=a,i=b, j=c,k=d,
        l=e,m=f, n=g,o=h{}
    
    constexpr octonion(const complex_type& z,
                       const complex_type& zj=*new complex_type(),
                       const complex_type& zl=*new complex_type(),
                       const complex_type& zn=*new complex_type()):
        r=z.real(), i=z.imag(),  j=zj.real(),k=zj.imag(),
        l=zl.real(),m=zl.imag(), n=zn.real(),o=zn.imag(){}
    
    //TODO: quaternion constructor
    
    constexpr octonion(const octonion_type& other):
        r=other.r,i=other.i,j=other.j,k=other.k,
        l=other.l,m=other.m,n=other.n,o=other.o{}
    
    const octonion& operator=(const octonion_type& rhs){
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
}

}

#endif //I14EXTRA_OCTONION_HPP
