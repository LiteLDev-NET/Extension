#include "IntTag.hpp"
namespace BedrockServer::Extension
{
    inline int^ IntTag::Value()
    {
        return NativePtr->value();
    }

    inline IntTag^ IntTag::operator=(int val)
    {
        *NativePtr = val;
        return this;
    }

    inline IntTag^ IntTag::Create()
    {
        return gcnew IntTag(::IntTag::create().release(), true);
    }

    inline IntTag^ IntTag::Create(int val)
    {
        return gcnew IntTag(::IntTag::create(val).release(), true);
    }

    inline bool IntTag::Set(int val)
    {
        return NativePtr->set(val);
    }

    inline short IntTag::Get()
    {
        return NativePtr->get();
    }
} // namespace BedrockServer::Extension
