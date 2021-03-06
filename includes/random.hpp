#pragma once

#include <limits>

class Random{   //gives out non-zero values only
public:
    template<typename T>    //only integer types
    static T random(){
        static_assert(std::is_integral_v<T>);
        return random( 0, std::numeric_limits<T>::max() );
    }

    template<typename T>    //only integer types
    static T random(T max){
        static_assert(std::is_integral_v<T>);
        return random(T{0}, max);
    }

    template<typename T>    //only integer types
    static T random(T min, T max){ // including `min`, but excluding `max`
        static_assert(std::is_integral_v<T>);
        // @todo

        return T{};
    }

private:
    //static mt1667
};

    // @todo - Ensure this is thread_safe, to concurrently create multiple entities in different worlds IN DIFFERENT VERSES
class _ID{  // no reuse of IDs, since it's enough
    public:
        const uint32_t _id;
        _ID(): _id(++(_ID::_curr_ID)){}
    private:
        static uint32_t _curr_ID;
};
