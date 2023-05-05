#include "MobEffectInstance.hpp"
namespace BedrockServer::Extension::Handle
{
    array<char>^ MobEffectInstanceHandle::Filler::get()
    {
        auto arr = gcnew array<char>(48);
        interior_ptr<char> I_ptr = &arr[0];
        char* L_ptr = NativePtr->filler;
        for (int i = 0; i < 48; i++)
            *(I_ptr++) = *(L_ptr++);
        return arr;
    }
    void MobEffectInstanceHandle::Filler::set(array<char>^ filler)
    {
        auto len = filler->Length < 48 ? filler->Length : 48;
        for (int i = 0; i < len; ++i)
            NativePtr->filler[i] = filler[i];
    }
} // namespace BedrockServer::Extension::Handle
