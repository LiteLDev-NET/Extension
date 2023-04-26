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

namespace BedrockServer::Extension
{
Tag::Type Tag::TagType::get()
{
    return Type(NativePtr->getTagType());
}

inline String^ Tag::ToJson(int formatIndent)
{
    return marshalString(NativePtr->toJson(formatIndent));
}

inline EndTag ^ Tag::AsEndTag()
{
    return gcnew EndTag(NativePtr->asEndTag());
}

inline ByteTag ^ Tag::AsByteTag()
{
    return gcnew ByteTag(NativePtr->asByteTag());
}

inline ShortTag ^ Tag::AsShortTag()
{
    return gcnew ShortTag(NativePtr->asShortTag());
}

inline IntTag ^ Tag::AsIntTag()
{
    return gcnew IntTag(NativePtr->asIntTag());
}

inline Int64Tag ^ Tag::AsInt64Tag()
{
    return gcnew Int64Tag(NativePtr->asInt64Tag());
}

inline FloatTag ^ Tag::AsFloatTag()
{
    return gcnew FloatTag(NativePtr->asFloatTag());
}

inline DoubleTag ^ Tag::AsDoubleTag()
{
    return gcnew DoubleTag(NativePtr->asDoubleTag());
}

inline StringTag ^ Tag::AsStringTag()
{
    return gcnew StringTag(NativePtr->asStringTag());
}

inline ListTag ^ Tag::AsListTag()
{
    return gcnew ListTag(NativePtr->asListTag());
}

inline ByteArrayTag ^ Tag::AsByteArrayTag()
{
    return gcnew ByteArrayTag(NativePtr->asByteArrayTag());
}

inline IntArrayTag ^ Tag::AsIntArrayTag()
{
    return gcnew IntArrayTag(NativePtr->asIntArrayTag());
}

inline CompoundTag ^ Tag::AsCompoundTag()
{
    return gcnew CompoundTag(NativePtr->asCompoundTag());
}
} // namespace BedrockServer::Extension
