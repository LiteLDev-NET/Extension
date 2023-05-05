#include "ByteTag.hpp"
namespace BedrockServer::Extension::Handle
{
inline unsigned char ByteTagHandle::Value()
{
    return NativePtr->value();
}

inline ByteTagHandle ^ ByteTagHandle::operator=(unsigned char val)
{
    *NativePtr = val;
    return this;
}

inline ByteTagHandle ^ ByteTagHandle::Create()
{
    return gcnew ByteTagHandle(::ByteTag::create().release(), true);
}

inline bool ByteTagHandle::Set(unsigned char val)
{
    return NativePtr->set(val);
}

inline unsigned char ByteTagHandle::Get()
{
    return NativePtr->get();
}
} // namespace BedrockServer::Extension::Handle
