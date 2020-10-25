#ifndef SDK_STATUS_PUB_H
#define SDK_STATUS_PUB_H

#include <string>

namespace api
{
    struct SdkStatus
    {
        std::string Message = "";
        bool IsSuccessful = false;
    };

} // namespace core
#endif