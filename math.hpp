#ifndef I14EXTRA_MATH_HPP
#define I14EXTRA_MATH_HPP

#include <type_traits>

namespace i14extra{

template<typename T, typename U>
constexpr const T& min(const T& alpha, const U& beta){
    static_assert(std::is_arithmetic<T>::value, "i14extra::min: T must be arithmetic!");
    static_assert(std::is_arithmetic<U>::value, "i14extra::min: U must be arithmetic!");
    if(alpha < T(beta))
        return alpha;
    return beta;
}
template<typename T, typename U>
constexpr const T& max(const T& alpha, const U& beta){
    static_assert(std::is_arithmetic<T>::value, "i14extra::max: T must be arithmetic!");
    static_assert(std::is_arithmetic<U>::value, "i14extra::max: U must be arithmetic!");
    if(alpha > T(beta))
        return alpha;
    return beta;
}
template<typename T, typename U, typename V>
constexpr T& clamp(T& target, const U low, const V high){
    static_assert(std::is_arithmetic<T>::value, "i14extra::clamp: T must be arithmetic!");
    static_assert(std::is_arithmetic<U>::value, "i14extra::clamp: U must be arithmetic!");
    static_assert(std::is_arithmetic<V>::value, "i14extra::clamp: V must be arithmetic!");
    using i14extra::min;
    using i14extra::max;
    if(min(target,high)==high){
        target=high;
    }else if(max(target,low)==low){
        target=low;
    }
    return target;
}
template<typename T,typename U,typename V>
constexpr T& clamp_m(const T target,const U low,const V high){
    static_assert(std::is_arithmetic<T>::value, "i14extra::clamp_m: T must be arithmetic!");
    static_assert(std::is_arithmetic<U>::value, "i14extra::clamp_m: U must be arithmetic!");
    static_assert(std::is_arithmetic<V>::value, "i14extra::clamp_m: V must be arithmetic!");
    using i14extra::clamp;
    T dummy=target;
    return clamp(dummy,low,high);
}
template<typename T,typename U> constexpr T& clamp_u(T& target,const U high){
    static_assert(std::is_unsigned<T>::value,"i14extra::clamp_u: T must be unsigned!");
    static_assert(std::is_unsigned<U>::value,"i14extra::clamp_u: U must be unsigned!");
    using i14extra::min;
    if(min(target,high)==high){
        target=high;
    }
    return target;
}
template<typename T,typename U> constexpr T& clamp_u_m(T target,const U high){
    static_assert(std::is_unsigned<T>::value,"i14extra::clamp_u_m: T must be unsigned!");
    static_assert(std::is_unsigned<U>::value,"i14extra::clamp_u_m: U must be unsigned!");
    using i14extra::clamp_u;
    T dummy=target;
    return clamp_u(dummy,high);
}
template<typename U> constexpr unsigned& clamp_u_m(int target,const U high){
    return clamp_u_m(unsigned(target),high);
}
template<typename T,typename U> constexpr auto clamp_m_u=clamp_u_m<T,U>;

}

#endif //I14EXTRA_MATH_HPP
