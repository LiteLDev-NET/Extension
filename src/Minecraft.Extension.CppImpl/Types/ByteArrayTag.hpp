#pragma once
#include "Tag.hpp"
#include <mc/ByteArrayTag.hpp>

namespace BedrockServer::Extension::Handle
{
    ref struct TagMemoryChunkHandle;
}

namespace BedrockServer::Extension::Handle
{
    public ref class ByteArrayTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(ByteArrayTagHandle, ::ByteArrayTag, TagHandle)
    public:

        inline static ByteArrayTagHandle^ Create();
        inline static ByteArrayTagHandle^ Create(TagMemoryChunkHandle^ val);
        inline static ByteArrayTagHandle^ Create(array<char>^ data /*, size_t size*/);

        inline TagMemoryChunkHandle^ Value();
        inline bool Set(TagMemoryChunkHandle^ val);
        inline TagMemoryChunkHandle^ Get();
        inline ByteArrayTagHandle^ operator=(TagMemoryChunkHandle^ val);
    };
} // namespace BedrockServer::Extension::Handle
