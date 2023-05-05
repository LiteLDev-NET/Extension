#include "ShortTag.hpp"
namespace BedrockServer::Extension::Handle
{
    inline short^ ShortTagHandle::Value()
    {
        return NativePtr->value();
    }

    inline ShortTagHandle^ ShortTagHandle::operator=(short val)
    {
        *NativePtr = val;
        return this;
    }

    inline ShortTagHandle^ ShortTagHandle::Create()
    {
        return gcnew ShortTagHandle(::ShortTag::create().release(), true);
    }

    inline ShortTagHandle^ ShortTagHandle::Create(short val)
    {
        return gcnew ShortTagHandle(::ShortTag::create(val).release(), true);
    }

    inline bool ShortTagHandle::Set(short val)
    {
        return NativePtr->set(val);
    }

    inline short ShortTagHandle::Get()
    {
        return NativePtr->get();
    }
} // namespace BedrockServer::Extension::Handle
