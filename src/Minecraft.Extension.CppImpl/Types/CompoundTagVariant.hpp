#pragma once

#include "Tag.hpp"
#include "EndTag.hpp"
#include "ByteTag.hpp"
#include "ShortTag.hpp"
#include "IntTag.hpp"
#include "Int64Tag.hpp"
#include "FloatTag.hpp"
#include "DoubleTag.hpp"
#include "StringTag.hpp"
#include "ListTag.hpp"
#include "ByteArrayTag.hpp"
#include "IntArrayTag.hpp"
#include "CompoundTag.hpp"

#include <mc/CompoundTagVariant.hpp>

namespace BedrockServer::Extension::Handle
{
    public ref class CompoundTagVariantHandle :SafeHandle, ICppClass
    {
        DEFAULT_DEF(CompoundTagVariantHandle, ::CompoundTagVariant)
    public:

        inline TagHandle^ AsTag();
        inline ByteTagHandle^ AsByteTag();
        inline ShortTagHandle^ AsShortTag();
        inline IntTagHandle^ AsIntTag();
        inline Int64TagHandle^ AsInt64Tag();
        inline FloatTagHandle^ AsFloatTag();
        inline DoubleTagHandle^ AsDoubleTag();
        inline StringTagHandle^ AsStringTag();
        inline ListTagHandle^ AsListTag();
        inline EndTagHandle^ AsEndTag();
        inline CompoundTagHandle^ AsCompoundTag();
        inline ByteArrayTagHandle^ AsByteArrayTag();
        inline IntArrayTagHandle^ AsIntArrayTag();

        property TagHandle::Type TagType
        {
            TagHandle::Type get();
        };
    };
} // namespace BedrockServer::Extension::Handle