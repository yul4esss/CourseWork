#include "CustomException.h"
#include <string>

const char* CustomException::getError()
{
    return error.c_str();
}
