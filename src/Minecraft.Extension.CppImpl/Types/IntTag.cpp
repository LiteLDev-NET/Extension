#include "IntTag.hpp"
namespace BedrockServer::Extension::Handle
{
    inline int^ IntTagHandle::Value()
    {
        return NativePtr->value();
    }

    inline IntTagHandle^ IntTagHandle::operator=(int val)
    {
        *NativePtr = val;
        return this;
    }

    inline IntTagHandle^ IntTagHandle::Create()
    {
        return gcnew IntTagHandle(::IntTag::create().release(), true);
    }

    inline IntTagHandle^ IntTagHandle::Create(int val)
    {
        return gcnew IntTagHandle(::IntTag::create(val).release(), true);
    }

    inline bool IntTagHandle::Set(int val)
    {
        return NativePtr->set(val);
    }

    inline short IntTagHandle::Get()
    {
        return NativePtr->get();
    }
} // namespace BedrockServer::Extension::Handle
