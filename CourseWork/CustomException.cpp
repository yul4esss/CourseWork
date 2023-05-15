#include "CustomException.h"
#include <string>
#include <cctype>

const char* CustomException::what() const noexcept
{
    return error.c_str();
}
