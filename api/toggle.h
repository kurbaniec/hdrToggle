#ifndef TOGGLE_H
#define TOGGLE_H

#include <tuple>

#include "nvapi_deps.h"
#include "include/toggle.h"

namespace api
{
    class ToggleImpl : Toggle
    {

    public:
        NV_HDR_COLOR_DATA setHdrData(bool enabled);
        NV_COLOR_DATA setColorData(COLOR_MODE mode);
        std::tuple<unsigned long, SdkStatus> getPrimaryDispId();
    };

} // namespace core

#endif