#include "ByteTag.hpp"
namespace BedrockServer::Extension
{
inline unsigned char ByteTag::Value()
{
    return NativePtr->value();
}

inline ByteTag ^ ByteTag::operator=(unsigned char val)
{
    *NativePtr = val;
    return this;
}

inline ByteTag ^ ByteTag::Create()
{
    return gcnew ByteTag(::ByteTag::create().release(), true);
}

inline bool ByteTag::Set(unsigned char val)
{
    return NativePtr->set(val);
}

inline unsigned char ByteTag::Get()
{
    return NativePtr->get();
}
} // namespace BedrockServer::Extension
