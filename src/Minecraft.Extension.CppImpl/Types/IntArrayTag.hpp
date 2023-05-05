#pragma once
#include "Tag.hpp"
#include "TagMemoryChunk.hpp"
#include <mc/IntArrayTag.hpp>

namespace BedrockServer::Extension::Handle
{
    public ref class IntArrayTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(IntArrayTagHandle, ::IntArrayTag, TagHandle)
    public:

        inline TagMemoryChunkHandle^ Value();
        inline IntArrayTagHandle^ operator=(TagMemoryChunkHandle^ val);
        inline static IntArrayTagHandle^ Create();
        inline static IntArrayTagHandle^ Create(TagMemoryChunkHandle^ val);
        inline static IntArrayTagHandle^ Create(array<int>^ data /*, size_t size*/);
        inline bool Set(TagMemoryChunkHandle^ val);
        inline TagMemoryChunkHandle^ Get();
    };
} // namespace BedrockServer::Extension::Handle