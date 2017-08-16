#ifndef I14EXTRA_MATH_HPP
#define I14EXTRA_MATH_HPP

#include <type_traits>

namespace i14extra{

template<typename T, typename U>
const T& min(const T& alpha, const U& beta){
	static_assert(std::is_arithmetic<T>::value, "i14extra: min: T must be arithmetic!");
	static_assert(std::is_arithmetic<U>::value, "i14extra: min: U must be arithmetic!");
	if(alpha < T(beta))
		return alpha;
	return beta;
}
template<typename T, typename U>
const T& max(const T& alpha, const U& beta){
	static_assert(std::is_arithmetic<T>::value, "i14extra: max: T must be arithmetic!");
	static_assert(std::is_arithmetic<U>::value, "i14extra: max: U must be arithmetic!");
	if(alpha > T(beta))
		return alpha;
	return beta;
}

}

#endif //I14EXTRA_MATH_HPP
