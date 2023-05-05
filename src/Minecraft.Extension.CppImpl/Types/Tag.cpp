#include "Tag.hpp"

#include "EndTag.hpp"
#include "ByteTag.hpp"
#include "ShortTag.hpp"
#include "IntTag.hpp"
#include "Int64Tag.hpp"
#include "FloatTag.hpp"
#include "DoubleTag.hpp"
#include "ByteArrayTag.hpp"
#include "StringTag.hpp"
#include "ListTag.hpp"
#include "IntArrayTag.hpp"
#include "CompoundTag.hpp"

namespace BedrockServer::Extension::Handle
{
TagHandle::Type TagHandle::TagType::get()
{
    return Type(NativePtr->getTagType());
}

inline String^ TagHandle::ToJson(int formatIndent)
{
    return marshalString(NativePtr->toJson(formatIndent));
}

inline EndTagHandle ^ TagHandle::AsEndTag()
{
    return gcnew EndTagHandle(NativePtr->asEndTag());
}

inline ByteTagHandle ^ TagHandle::AsByteTag()
{
    return gcnew ByteTagHandle(NativePtr->asByteTag());
}

inline ShortTagHandle ^ TagHandle::AsShortTag()
{
    return gcnew ShortTagHandle(NativePtr->asShortTag());
}

inline IntTagHandle ^ TagHandle::AsIntTag()
{
    return gcnew IntTagHandle(NativePtr->asIntTag());
}

inline Int64TagHandle ^ TagHandle::AsInt64Tag()
{
    return gcnew Int64TagHandle(NativePtr->asInt64Tag());
}

inline FloatTagHandle ^ TagHandle::AsFloatTag()
{
    return gcnew FloatTagHandle(NativePtr->asFloatTag());
}

inline DoubleTagHandle ^ TagHandle::AsDoubleTag()
{
    return gcnew DoubleTagHandle(NativePtr->asDoubleTag());
}

inline StringTagHandle ^ TagHandle::AsStringTag()
{
    return gcnew StringTagHandle(NativePtr->asStringTag());
}

inline ListTagHandle ^ TagHandle::AsListTag()
{
    return gcnew ListTagHandle(NativePtr->asListTag());
}

inline ByteArrayTagHandle ^ TagHandle::AsByteArrayTag()
{
    return gcnew ByteArrayTagHandle(NativePtr->asByteArrayTag());
}

inline IntArrayTagHandle ^ TagHandle::AsIntArrayTag()
{
    return gcnew IntArrayTagHandle(NativePtr->asIntArrayTag());
}

inline CompoundTagHandle ^ TagHandle::AsCompoundTag()
{
    return gcnew CompoundTagHandle(NativePtr->asCompoundTag());
}
} // namespace BedrockServer::Extension::Handle
