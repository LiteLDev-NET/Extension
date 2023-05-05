#include "CompoundTagVariant.hpp"

#include "ByteArrayTag.hpp"
#include "ByteTag.hpp"
#include "CompoundTag.hpp"
#include "DoubleTag.hpp"
#include "ShortTag.hpp"
#include "EndTag.hpp"
#include "FloatTag.hpp"
#include "Int64Tag.hpp"
#include "IntArrayTag.hpp"
#include "IntTag.hpp"
#include "ListTag.hpp"
#include "ShortTag.hpp"
#include "StringTag.hpp"
#include "Tag.hpp"

namespace BedrockServer::Extension::Handle
{

    inline TagHandle::Type CompoundTagVariantHandle::TagType::get()
    {
        return TagHandle::Type(NativePtr->getTagType());
    }
    inline TagHandle^ CompoundTagVariantHandle::AsTag()
    {
        return gcnew TagHandle(NativePtr->asTag());
    }
    inline ByteTagHandle^ CompoundTagVariantHandle::AsByteTag()
    {
        return gcnew ByteTagHandle(NativePtr->asByteTag());
    }
    inline ShortTagHandle^ CompoundTagVariantHandle::AsShortTag()
    {
        return gcnew ShortTagHandle(NativePtr->asShortTag());
    }
    inline IntTagHandle^ CompoundTagVariantHandle::AsIntTag()
    {
        return gcnew IntTagHandle(NativePtr->asIntTag());
    }
    inline Int64TagHandle^ CompoundTagVariantHandle::AsInt64Tag()
    {
        return gcnew Int64TagHandle(NativePtr->asInt64Tag());
    }
    inline FloatTagHandle^ CompoundTagVariantHandle::AsFloatTag()
    {
        return gcnew FloatTagHandle(NativePtr->asFloatTag());
    }
    inline DoubleTagHandle^ CompoundTagVariantHandle::AsDoubleTag()
    {
        return gcnew DoubleTagHandle(NativePtr->asDoubleTag());
    }
    inline StringTagHandle^ CompoundTagVariantHandle::AsStringTag()
    {
        return gcnew StringTagHandle(NativePtr->asStringTag());
    }
    inline ListTagHandle^ CompoundTagVariantHandle::AsListTag()
    {
        return gcnew ListTagHandle(NativePtr->asListTag());
    }
    inline EndTagHandle^ CompoundTagVariantHandle::AsEndTag()
    {
        return gcnew EndTagHandle(NativePtr->asEndTag());
    }

    inline CompoundTagHandle^ CompoundTagVariantHandle::AsCompoundTag()
    {
        return gcnew CompoundTagHandle(NativePtr->asCompoundTag());
    }

    inline ByteArrayTagHandle^ CompoundTagVariantHandle::AsByteArrayTag()
    {
        return gcnew ByteArrayTagHandle(NativePtr->asByteArrayTag());
    }
    inline IntArrayTagHandle^ CompoundTagVariantHandle::AsIntArrayTag()
    {
        return gcnew IntArrayTagHandle(NativePtr->asIntArrayTag());
    }
} // namespace BedrockServer::Extension::Handle