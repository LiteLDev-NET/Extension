#include "FloatTag.hpp"
namespace BedrockServer::Extension::Handle
{
    inline float^ FloatTagHandle::Value()
    {
        return NativePtr->value();
    }

    inline FloatTagHandle^ FloatTagHandle::operator=(float val)
    {
        *NativePtr = val;
        return this;
    }

    inline FloatTagHandle^ FloatTagHandle::Create()
    {
        return gcnew FloatTagHandle(::FloatTag::create().release(), true);
    }

    inline FloatTagHandle^ FloatTagHandle::Create(float val)
    {
        return gcnew FloatTagHandle(::FloatTag::create(val).release(), true);
    }

    inline bool FloatTagHandle::Set(float val)
    {
        return NativePtr->set(val);
    }

    inline float FloatTagHandle::Get()
    {
        return NativePtr->get();
    }
} // namespace BedrockServer::Extension::Handle
