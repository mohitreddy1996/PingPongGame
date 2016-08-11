#include "utils.h"

std::string int2str(int x){
    std::stringstream ss;
    ss << x;
    return ss.str( );
}
