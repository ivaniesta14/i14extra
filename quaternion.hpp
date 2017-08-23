#ifndef I14EXTRA_QUATERNION
#define I14EXTRA_QUATERNION

#include <complex>
#include <type_traits>
#include <ostream>

namespace i14extra{

template<typename T> class quaternion_t{
protected:
    T v, vi, vj, vk;
public:
    typedef T value_type;
    inline T& r(){
        return v;
    }
    inline T& ri(){
        return vi;
    }
    inline T& rj(){
        return vj;
    }
    inline T& rk(){
        return vk;
    }
    quaternion_t(const T& va=*new T(),
                 const T& vb=*new T(),
                 const T& vc=*new T(),
                 const T& vd=*new T()){
        static_assert(std::is_arithmetic<T>::value,
            "quaternion_t: T must be arithmetic!");
            v=va; vi=vb; vj=vc; vk=vd;
    }
    template<typename U, typename V>
    quaternion_t(const std::complex<U>& z,
                 const std::complex<V>& zj=*new std::complex<int>()):
        quaternion_t<T>(
            static_cast<T>(z.real()),
            static_cast<T>(z.imag()),
            static_cast<T>(zj.real()),
            static_cast<T>(zj.imag())){}
    template<typename U, typename V, typename W>
    quaternion_t(const std::complex<U>& z,
                 const V& vc, const W& vd):
        quaternion_t<T>(
            static_cast<T>(z.real()),
            static_cast<T>(z.imag()),
            static_cast<T>(vc),
            static_cast<T>(vd)){}
    template<typename U>
    quaternion_t(const quaternion_t<U>& other):
        quaternion_t(static_cast<T>(other.r()), static_cast<T>(other.ri()),
                     static_cast<T>(other.rj()), static_cast<T>(other.rk())){}
    T real(){return r();}
    quaternion_t<T> unreal(){
        return *new quaternion_t<T>(0,vi, vj, vk);
    }
    T imag(){return ri();}
    operator T(){
        return v;
    }
    operator bool(){
        return! (v==static_cast<T>(0)&&
              vi==static_cast<T>(0)&&
              vj==static_cast<T>(0)&&
              vk==static_cast<T>(0));
    }
    template<typename U>
    std::complex<U> z(){
        return *new std::complex<U>(
            static_cast<U>(r()),
            static_cast<U>(r()));
    }
    template<typename U>
    std::complex<U> zj(){
        return *new std::complex<U>(
            static_cast<U>(rj()),
            static_cast<U>(rk()));
    }
    template<typename U>
    operator std::complex<U>(){
        return z();
    }
    ///ASSIGN
    template<typename U>
    const quaternion_t<T>& operator=(const quaternion_t<U>& other){
        r()=static_cast<T>(other.r());
        ri()=static_cast<T>(other.ri());
        rj()=static_cast<T>(other.rj());
        rk()=static_cast<T>(other.rk());
        return *this;
    }
    template<typename U>
    const quaternion_t<T>& operator=(const std::complex<U>& other){
        return *this=*new quaternion_t<U>(other);
    }
    const quaternion_t<int>& operator=(const int& other){
        return *this=*new quaternion_t<int>(other,0,0,0);
    }
    ///PLUS-ASSIGN
    template<typename U>
    quaternion_t<T>& operator+=(const quaternion_t<U>& other){
        r()+=other.r();
        ri()+=other.ri();
        rj()+=other.rj();
        rk()+=other.rk();
        return *this;
    }
    quaternion_t<T>& operator+=(const T& other){
        r()+=other;
        return *this;
    }
    template<typename U>
    quaternion_t<T>& operator+=(const std::complex<U>& other){
        *this+=*new quaternion_t<U>(other);
        return *this;
    }
    ///SUBS-ASSIGN
    template<typename U>
    quaternion_t<T>& operator-=(const quaternion_t<U>& other){
        r()-=other.r();
        ri()-=other.ri();
        rj()-=other.rj();
        rk()-=other.rk();
        return *this;
    }
    quaternion_t<T>& operator-=(const T& other){
        r()-=other;
        return *this;
    }
    template<typename U>
    quaternion_t<T>& operator-=(const std::complex<U>& other){
        return *this-=*new quaternion_t<U>(other);
    }
    ///MULT-ASSIGN
    template<typename U>
    quaternion_t<T>& operator*=(const quaternion_t<U>& other){
        quaternion_t<T> temp0(r()*other.r(),
                              ri()*other.r(),
                              rj()*other.r(),
                              rk()*other.r()),
                        temp1(-ri()*other.ri(),
                              r()*other.ri(),
                              -rk()*other.ri(),
                              rj()*other.ri()),
                        temp2(-rj()*other.rj(),
                              rk()*other.rj(),
                              r()*other.rj(),
                              -ri()*other.rj()),
                        temp3(-rk()*other.rk(),
                              -rj()*other.rk(),
                              ri()*other.rk(),
                              r()*other.rk());
        temp0+=temp1+=temp2+=temp3;
        return *this=temp0;
    }
    quaternion_t<T>& operator*=(const T& other){
        r()*=other;
        ri()*=other;
        rj()*=other;
        rk()*=other;
        return *this;
    }
    template<typename U>
    quaternion_t<T>& operator*=(const std::complex<U>& other){
        quaternion_t<T> temp0(r()*other.real,
                              ri()*other.real,
                              rj()*other.real,
                              rk()*other.real),
                        temp1(-ri()*other.imag,
                              r()*other.imag,
                              -rk()*other.imag,
                              rj()*other.imag);
        temp0+=temp1;
        return *this=temp0;
    }
    ///DIV-ASSIGN
    template<typename U>
    quaternion_t<T>& operator/=(const quaternion_t<U>& other){
        quaternion_t<T> temp0(r()/other.r(),
                              ri()/other.r(),
                              rj()/other.r(),
                              rk()/other.r()),
                        temp1(-ri()/other.ri(),
                              r()/other.ri(),
                              -rk()/other.ri(),
                              rj()/other.ri()),
                        temp2(-rj()/other.rj(),
                              rk()/other.rj(),
                              r()/other.rj(),
                              -ri()/other.rj()),
                        temp3(-rk()/other.rk(),
                              -rj()/other.rk(),
                              ri()/other.rk(),
                              r()/other.rk());
        temp0+=temp1+=temp2+=temp3;
        return *this=temp0;
    }
    quaternion_t<T>& operator/=(const T& other){
        r()/=other;
        ri()/=other;
        rj()/=other;
        rk()/=other;
        return *this;
    }
    template<typename U>
    quaternion_t<T>& operator/=(const std::complex<U>& other){
        quaternion_t<T> temp0(r()/other.real,
                              ri()/other.real,
                              rj()/other.real,
                              rk()/other.real),
                        temp1(-ri()/other.imag,
                              r()/other.imag,
                              -rk()/other.imag,
                              rj()/other.imag);
        temp0+=temp1;
        return *this=temp0;
    }
};
template<typename T, typename U>
bool operator==(const quaternion_t<T>& lhs, const quaternion_t<U>& rhs){
    return lhs.r()==static_cast<T>(rhs.r())&&lhs.ri()==static_cast<T>(rhs.ri())&&
        lhs.rj()==static_cast<T>(rhs.rj())&&lhs.rk()==static_cast<T>(rhs.rk());
}
template<typename T>
bool operator==(const quaternion_t<T>& lhs, const int& rhs){
    return lhs.r()==static_cast<T>(rhs)&&lhs.ri()==static_cast<T>(0)&&
        lhs.rj()==static_cast<T>(0)&&lhs.rk()==static_cast<T>(0);
}
template<typename T, typename U>
bool operator==(const quaternion_t<T>& lhs, const std::complex<U>& rhs){
    return lhs==*new quaternion_t<U>(rhs);
}
template<typename T>
bool operator==(const int& lhs, const quaternion_t<T>& rhs){
    return rhs==lhs;
}
template<typename T, typename U>
bool operator==(const std::complex<T>& lhs, const quaternion_t<U>& rhs){
    return rhs==lhs;
}
template<typename T, typename U>
bool operator!=(const quaternion_t<T>& lhs,const quaternion_t<U>& rhs){
    return !(lhs==rhs);
}
template<typename T>
bool operator!=(const quaternion_t<T>& lhs, const int& rhs){
    return !(lhs==rhs);
}
template<typename T, typename U>
bool operator!=(const quaternion_t<T>& lhs, const std::complex<U>& rhs){
    return !(lhs==rhs);
}
template<typename T>
bool operator!=(const int& lhs, const quaternion_t<T>& rhs){
    return !(rhs==lhs);
}
template<typename T, typename U>
bool operator!=(const std::complex<T>& lhs, const quaternion_t<U>& rhs){
    return !(rhs==lhs);
}
template<typename T>
std::ostream& operator<<(std::ostream& lhs,const quaternion_t<T> rhs){
    lhs<<"("<<rhs.r()<<", "<<rhs.ri()<<"i, "<<rhs.rj()<<"j, "<<rhs.rk()<<"k)";
}

}//namespace i14extra

#endif //I14EXTRA_QUATERNION
