#pragma once

#include "memory"

template<typename T, typename B>
std::shared_ptr<
    typename std::enable_if<(!std::is_same<B,T>::value)
                            &&(std::is_base_of<B,T>::value),T>::type
>
shared_type_cast(std::shared_ptr<B> ptr){
    return std::static_pointer_cast<T>(ptr);
}

