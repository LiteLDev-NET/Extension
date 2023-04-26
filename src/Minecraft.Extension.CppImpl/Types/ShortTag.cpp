#include "ShortTag.hpp"
namespace BedrockServer::Extension
{
    inline short^ ShortTag::Value()
    {
        return NativePtr->value();
    }

    inline ShortTag^ ShortTag::operator=(short val)
    {
        *NativePtr = val;
        return this;
    }

    inline ShortTag^ ShortTag::Create()
    {
        return gcnew ShortTag(::ShortTag::create().release(), true);
    }

    inline ShortTag^ ShortTag::Create(short val)
    {
        return gcnew ShortTag(::ShortTag::create(val).release(), true);
    }

    inline bool ShortTag::Set(short val)
    {
        return NativePtr->set(val);
    }

    inline short ShortTag::Get()
    {
        return NativePtr->get();
    }
} // namespace BedrockServer::Extension
