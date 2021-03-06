#include "sdk_status.h"

namespace api {

    SdkStatusImpl::SdkStatusImpl(const NvAPI_Status& status) {
        if(status == NVAPI_OK) {
            IsSuccessful = true;
        }
        else {
            NvAPI_ShortString szDesc = {0};
            NvAPI_GetErrorMessage(status, szDesc);
            Message = szDesc;
        }
    }

} // namespace core