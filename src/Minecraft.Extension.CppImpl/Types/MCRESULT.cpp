#include "MCRESULT.hpp"
namespace BedrockServer::Extension::Handle
{
    array<unsigned char>^ MCRESULTHandle::Filler::get()
    {
        return gcnew array<unsigned char>{
            NativePtr->filler[0],
                NativePtr->filler[1],
                NativePtr->filler[2],
                NativePtr->filler[3]};
    }
    inline void MCRESULTHandle::Filler::set(array<unsigned char>^ arg)
    {
        NativePtr->filler[0] = arg[0];
        NativePtr->filler[1] = arg[1];
        NativePtr->filler[2] = arg[2];
        NativePtr->filler[3] = arg[3];
    }
    inline MCRESULTHandle::operator bool()
    {
        return bool(NativePtr->filler[0]);
    }

    inline int MCRESULTHandle::GetFullCode()
    {
        return NativePtr->getFullCode();
    }

    inline bool MCRESULTHandle::IsSuccess()
    {
        return NativePtr->isSuccess();
    }
} // namespace BedrockServer::Extension::Handle
