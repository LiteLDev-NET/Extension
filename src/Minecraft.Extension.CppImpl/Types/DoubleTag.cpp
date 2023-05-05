#include "DoubleTag.hpp"
namespace BedrockServer::Extension::Handle
{
    inline double^ DoubleTagHandle::Value()
    {
        return NativePtr->value();
    }

    inline DoubleTagHandle^ DoubleTagHandle::operator=(double val)
    {
        *NativePtr = val;
        return this;
    }

    inline DoubleTagHandle^ DoubleTagHandle::Create()
    {
        return gcnew DoubleTagHandle(::DoubleTag::create().release(), true);
    }

    inline DoubleTagHandle^ DoubleTagHandle::Create(double val)
    {
        return gcnew DoubleTagHandle(::DoubleTag::create(val).release(), true);
    }

    inline bool DoubleTagHandle::Set(double val)
    {
        return NativePtr->set(val);
    }

    inline double DoubleTagHandle::Get()
    {
        return NativePtr->get();
    }
} // namespace BedrockServer::Extension::Handle
