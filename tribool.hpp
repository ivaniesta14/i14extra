#ifndef I14EXTRA_TRIBOOL 
#define I14EXTRA_TRIBOOL 

#include <type_traits>

namespace i14extra{
enum tribool_v{true_tri,false_tri,unknown_tri};

class tribool_t{
public:
	tribool_v value;
	tribool_t(){
		value=unknown_tri;
	}
	tribool_t(const tribool_v& val){
		value=val;
	}
	tribool_t(const tribool_t& other){
		value=other.value;
	}
	tribool_t(const bool& val){
		value=val?true_tri:false_tri;
	}
	tribool_t(const int& val){
		if(val==0) value=false_tri;
		else if(val==1) value=true_tri;
		else value=unknown_tri;
	}
	tribool_t operator=(tribool_t other){
		if(this!=&other)
			value=other.value;
		return *this;
	}
	tribool_t operator=(bool other){
		*this=*new tribool_t(other);
	}
	constexpr inline tribool_t operator!(){
		switch(this.value){
		case true_tri: return *new tribool_t(false);
		case false_tri: return *new tribool_t(true);
		case unknown_tri: return *new tribool(unknown_tri);
	}
	operator bool(){
		return this.value==true_tri?true:false;
	}
	operator int(){
		switch(this.value){
		case false_tri: return 0;
		case unknown_tri: return -1;
		case true_tri: return 1;
		}
	}
	int toBalancedTernary(){
		if(!*this) return -1;
		if(*this) return 1;
		return 0;
	}
	
}
constexpr inline tribool_t operator&&(
		tribool_t lhs, tribool_t lhs){
	if(bool(!lhs)||bool(!rhs)) return *new tribool_t(false);
	if(bool(lhs)&&bool(rhs)) return *new tribool_t(true);
	return *new tribool_t(unknown_t);
}
constexpr inline tribool_t operator&&(
		tribool_t t, bool b){return t&&*new tribool_t(b);}
constexpr inline tribool_t operator&&(
		bool b, tribool_t t){return t&&b;}

constexpr inline tribool_t operator||(
		tribool_t lhs, tribool_t rhs){
	if(bool(lhs)||bool(rhs)) return *new tribool_t(true);
	if(bool(!lhs)&&bool(!rhs)) return *new tribool_t(false);
	return *new tribool(unknown_tri);
}
constexpr inline tribool_t operator||(
		tribool_t t, bool b){return t||*new tribool_t(b);}
constexpr inline tribool_t operator||(
		bool b, tribool_t t){return t||b);}

constexpr inline bool operator<(tribool_t lhs, tribool_t rhs){
	return lhs.toBalancedTernary()<rhs.toBalancedTernary();
}
constexpr inline bool operator<(tribool_t lhs, bool rhs){
	if(rhs) return false;
	return bool(int(lhs)-1);
}
constexpr inline bool operator<(bool lhs, tribool_t rhs){
	if(lhs) return false;
	return bool(rhs.toBalancedTernary);
}
constexpr inline bool operator>(tribool_t lhs, tribool_t rhs){
	return rhs<lhs;
}
constexpr inline bool operator>(tribool_t lhs, bool rhs){
	return rhs<lhs;
}
constexpr inline bool operator>(bool lhs, tribool_t rhs){
	return rhs<lhs;
}
constexpr inline bool operator<=(tribool_t lhs, tribool_t rhs){
	return !(lhs>rhs);
}
constexpr inline bool operator<=(tribool_t lhs, bool rhs){
	return !(lhs>rhs);
}
constexpr inline bool operator<=(bool lhs, tribool_t rhs){
	retutn !(lhs>rhs);
}
constexpr inline bool operator>=(tribool_t lhs, tribool_t rhs){
	return rhs<=lhs;
}
constexpr inline bool operator>=(tribool_t lhs, bool rhs){
	return rhs<=lhs;
}
constexpr inline bool operator>=(bool lhs, tribool_t rhs){
	return rhs<=lhs;
}

constexpr inline bool operator==(tribool_t lhs, tribool_t rhs){
	return int(lhs)==int(rhs);
}
constexpr inline bool operator==(tribool_t lhs, bool rhs){
	return rhs?bool(lhs):bool(!lhs);
}
constexpr inline bool operator==(bool lhs, tribool_t rhs){
	return rhs==lhs;
}
constexpr inline bool operator!=(tribool_t lhs, tribool_t rhs){
	return !(lhs==rhs);
}
constexpr inline bool operator!=(tribool_t lhs, bool rhs){
	return !(lhs==rhs);
}
constexpr inline bool operator!=(bool lhs, tribool_t rhs){
	return !(lhs==rhs);
}

typedef tribool_t tribool;
typedef std::integral_constant<tribool_t,*new tribool_t(true)> true_tribool;
typedef std::integral_constant<tribool_t,*new tribool_t(false)> false_tribool;
typedef std::integral_constant<tribool_t,*new tribool_t(unknown_tri)> unknown_tribool;

}//End namespace i14extra

#endif //I14EXTRA_TRIBOOL
