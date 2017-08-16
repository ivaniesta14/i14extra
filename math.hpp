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
constexpr T& clamp(T& target, const U& low, const V& high){
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
template<typename T>
constexpr unsigned factorial(T value){
	static_assert(std::is_unsigned<T>::value, "i14extra::factorial: T must be unsigned!");
	if(value==0)
		return 1;
	return value * factorial(value-1);
}

}

#endif //I14EXTRA_MATH_HPP
