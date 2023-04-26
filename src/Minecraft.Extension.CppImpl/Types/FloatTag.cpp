#include "FloatTag.hpp"
namespace BedrockServer::Extension
{
    inline float^ FloatTag::Value()
    {
        return NativePtr->value();
    }

    inline FloatTag^ FloatTag::operator=(float val)
    {
        *NativePtr = val;
        return this;
    }

    inline FloatTag^ FloatTag::Create()
    {
        return gcnew FloatTag(::FloatTag::create().release(), true);
    }

    inline FloatTag^ FloatTag::Create(float val)
    {
        return gcnew FloatTag(::FloatTag::create(val).release(), true);
    }

    inline bool FloatTag::Set(float val)
    {
        return NativePtr->set(val);
    }

    inline float FloatTag::Get()
    {
        return NativePtr->get();
    }
} // namespace BedrockServer::Extension
