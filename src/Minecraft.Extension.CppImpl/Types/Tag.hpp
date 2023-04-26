#pragma once
#include "Types.hpp"
#include <mc/Tag.hpp>

namespace BedrockServer::Extension
{
    ref class EndTag;
    ref class ByteTag;
    ref class ShortTag;
    ref class IntTag;
    ref class Int64Tag;
    ref class FloatTag;
    ref class DoubleTag;
    ref class StringTag;
    ref class ListTag;
    ref class ByteArrayTag;
    ref class EndTag;
    ref class IntArrayTag;
    ref class CompoundTag;
} // namespace BedrockServer::Extension

namespace BedrockServer::Extension
{
    public ref class Tag : SafeHandle , ICppClass
    {
        DEFAULT_DEF(Tag, ::Tag)
    public:
        enum class Type : uint8_t
        {
            End,
            Byte,
            Short,
            Int,
            Int64,
            Float,
            Double,
            ByteArray,
            String,
            List,
            Compound,
            IntArray,
        };
        property Type TagType
        {
            Type get();
        };

        inline EndTag^ AsEndTag();
        inline ByteTag^ AsByteTag();
        inline ShortTag^ AsShortTag();
        inline IntTag^ AsIntTag();
        inline Int64Tag^ AsInt64Tag();
        inline FloatTag^ AsFloatTag();
        inline DoubleTag^ AsDoubleTag();
        inline StringTag^ AsStringTag();
        inline ListTag^ AsListTag();
        inline ByteArrayTag^ AsByteArrayTag();
        inline IntArrayTag^ AsIntArrayTag();
        inline CompoundTag^ AsCompoundTag();

        inline String^ ToJson(int formatIndent);
    };
} // namespace BedrockServer::Extension
