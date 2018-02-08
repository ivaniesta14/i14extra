#ifndef I14EXTRA_MATH_HPP
#define I14EXTRA_MATH_HPP

#include <type_traits>
#include <i14extra/point.hpp>
#include <cmath>

namespace i14extra{

template<typename T, typename U>
const T& min(const T& alpha, const U& beta){
    static_assert(std::is_arithmetic<T>::value,
            "i14extra::min: T must be arithmetic!");
    static_assert(std::is_arithmetic<U>::value,
            "i14extra::min: U must be arithmetic!");
    return (alpha>T(beta))?beta:alpha;
}
template<typename T, typename U>
const T& max(const T& alpha, const U& beta){
    static_assert(std::is_arithmetic<T>::value,
            "i14extra::max: T must be arithmetic!");
    static_assert(std::is_arithmetic<U>::value,
            "i14extra::max: U must be arithmetic!");
    return (alpha>T(beta))?alpha:beta;
}
template<typename T, typename U, typename V>
T& clamp(T& target, const U low, const V high){
    static_assert(std::is_arithmetic<T>::value,
            "i14extra::clamp: T must be arithmetic!");
    static_assert(std::is_arithmetic<U>::value,
            "i14extra::clamp: U must be arithmetic!");
    static_assert(std::is_arithmetic<V>::value,
            "i14extra::clamp: V must be arithmetic!");
    static_assert(low<high,"i14extra::clamp: low must be lower than high!");
    using i14extra::min;
    using i14extra::max;
    if(min(target,high)==high){
        return high;
    }else if(max(target,low)==low){
        return low;
    }
    return target;
}
template<typename T,typename U> T& clamp_u(T& target,const U high){
    static_assert(std::is_unsigned<T>::value,
            "i14extra::clamp_u: T must be unsigned!");
    static_assert(std::is_unsigned<U>::value
            "i14extra::clamp_u: U must be unsigned!");
    using i14extra::min;
    if(min(target,high)==high){
        return high;
    }
    return target;
}

template<typename T> inline constexpr ldouble cref norm(point_t<T> cref v){
    return std::sqrt(std::pow(v.x,2)+std::pow(v.y,2)+std::pow(v.z,2));
}
template<typename T,typename U> inline constexpr
T cref dot_product(point_t<T> cref lhs,point_t<U> cref rhs){
    return lhs.x*rhs.x+lhs.y*rhs.y+lhs.z*rhs.z;
}
template<typename T,typename U> inline constexpr
ldouble cref vector_cos(point_t<T> cref lhs,point_t<U> cref rhs){
    return ldouble(inner_product(lhs,rhs))/(norm(lhs)+norm(rhs));
}
template<typename T,typename U> inline constexpr
ldouble cref vector_angle(point_t<T> cref lhs,point_t<U> cref rhs){
    return std::acos(vector_cos(lhs,rhs));
}
template<typename T,typename U> inline constexpr
bool cref are_perpendicular(point_t<T> cref lhs,point_t<U> cref rhs){
    return !bool(dot_product(lhs,rhs));
}
template<typename T> inline constexpr
bool cref is_unitary(point_t<T> cref lhs){
    return norm(lhs)==1;
}
template<typename T,typename U> inline constexpr
bool cref are_orthonormal(point_t<T> cref lhs,point_t<U> cref rhs){
    return are_perpendicular(lhs,rhs)&&is_unitary(lhs)&&is_unitary(rhs);
}
template<typename T> inline constexpr
point_t<T> cref to_unit_vector(point_t<T> cref v){
    return is_unitary(v)?v:*new point_t<T>(v.x/norm(v),v.y/norm(v),v.z/norm(v));
}
template<typename T> inline constexpr
point_t<T> find_2d_perpendicular(point_t<T> cref v){
    return *new point_t<T>(v.y,-v.x);
}
template<typename T> inline constexpr
point_t<T> find_opposite(point_t<T> cref v){
    return *new point_t<T>(-v.x,-v.y,-v.z);
}

}//namespace i14extra

#endif //I14EXTRA_MATH_HPP
