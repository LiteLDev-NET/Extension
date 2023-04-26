#pragma once
#include "Tag.hpp"
#include <mc/ByteArrayTag.hpp>

namespace BedrockServer::Extension
{
    ref struct TagMemoryChunk;
}

namespace BedrockServer::Extension
{
    public ref class ByteArrayTag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(ByteArrayTag, ::ByteArrayTag, Tag)
    public:

        inline static ByteArrayTag^ Create();
        inline static ByteArrayTag^ Create(TagMemoryChunk^ val);
        inline static ByteArrayTag^ Create(array<char>^ data /*, size_t size*/);

        inline TagMemoryChunk^ Value();
        inline bool Set(TagMemoryChunk^ val);
        inline TagMemoryChunk^ Get();
        inline ByteArrayTag^ operator=(TagMemoryChunk^ val);
    };
} // namespace BedrockServer::Extension
