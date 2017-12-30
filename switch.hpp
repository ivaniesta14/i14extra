#ifndef I14EXTRA_SWITCH_HPP
#define I14EXTRA_SWITCH_HPP

#include <i14extra/convenience.hpp>

namespace i14extra {

class switch_t{
public:
    bool value;
    constexpr switch_t():value(false){}
    constexpr switch_t(bool cref v):value(v){}
    constexpr switch_t(switch_t cref v):value(v.value){}
    inline constexpr operator bool()const{return value;}
    inline constexpr switch_t cref operator=(bool cref rhs){
        value=rhs;
        return *this;
    }
    inline constexpr switch_t cref operator=(switch_t cref rhs){
        value=rhs.value;
        return *this;
    }
    inline constexpr switch_t ref operator!(){
        value^=true;
        return *this;
    }
    inline constexpr switch_t ref toggle(bool tog=true){
        return tog?!*this:*this;
    }
};

typedef switch_t switcher;

}

#endif //I14EXTRA_SWITCH_HPP
