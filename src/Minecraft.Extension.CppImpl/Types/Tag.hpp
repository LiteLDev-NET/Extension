#pragma once
#include "Types.hpp"
#include <mc/Tag.hpp>

namespace BedrockServer::Extension::Handle
{
    ref class EndTagHandle;
    ref class ByteTagHandle;
    ref class ShortTagHandle;
    ref class IntTagHandle;
    ref class Int64TagHandle;
    ref class FloatTagHandle;
    ref class DoubleTagHandle;
    ref class StringTagHandle;
    ref class ListTagHandle;
    ref class ByteArrayTagHandle;
    ref class EndTagHandle;
    ref class IntArrayTagHandle;
    ref class CompoundTagHandle;
} // namespace BedrockServer::Extension::Handle

namespace BedrockServer::Extension::Handle
{
    public ref class TagHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(TagHandle, ::Tag)
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

        inline EndTagHandle^ AsEndTag();
        inline ByteTagHandle^ AsByteTag();
        inline ShortTagHandle^ AsShortTag();
        inline IntTagHandle^ AsIntTag();
        inline Int64TagHandle^ AsInt64Tag();
        inline FloatTagHandle^ AsFloatTag();
        inline DoubleTagHandle^ AsDoubleTag();
        inline StringTagHandle^ AsStringTag();
        inline ListTagHandle^ AsListTag();
        inline ByteArrayTagHandle^ AsByteArrayTag();
        inline IntArrayTagHandle^ AsIntArrayTag();
        inline CompoundTagHandle^ AsCompoundTag();

        inline String^ ToJson(int formatIndent);
    };
} // namespace BedrockServer::Extension::Handle
