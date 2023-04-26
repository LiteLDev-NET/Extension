#include "DoubleTag.hpp"
namespace BedrockServer::Extension
{
    inline double^ DoubleTag::Value()
    {
        return NativePtr->value();
    }

    inline DoubleTag^ DoubleTag::operator=(double val)
    {
        *NativePtr = val;
        return this;
    }

    inline DoubleTag^ DoubleTag::Create()
    {
        return gcnew DoubleTag(::DoubleTag::create().release(), true);
    }

    inline DoubleTag^ DoubleTag::Create(double val)
    {
        return gcnew DoubleTag(::DoubleTag::create(val).release(), true);
    }

    inline bool DoubleTag::Set(double val)
    {
        return NativePtr->set(val);
    }

    inline double DoubleTag::Get()
    {
        return NativePtr->get();
    }
} // namespace BedrockServer::Extension
