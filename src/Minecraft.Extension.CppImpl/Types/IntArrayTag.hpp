#pragma once
#include "Tag.hpp"
#include "TagMemoryChunk.hpp"
#include <mc/IntArrayTag.hpp>

namespace BedrockServer::Extension
{
    public ref class IntArrayTag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(IntArrayTag, ::IntArrayTag, Tag)
    public:

        inline TagMemoryChunk^ Value();
        inline IntArrayTag^ operator=(TagMemoryChunk^ val);
        inline static IntArrayTag^ Create();
        inline static IntArrayTag^ Create(TagMemoryChunk^ val);
        inline static IntArrayTag^ Create(array<int>^ data /*, size_t size*/);
        inline bool Set(TagMemoryChunk^ val);
        inline TagMemoryChunk^ Get();

#ifdef INCLUDE_MCAPI

        virtual void DeleteChildren() override;

        virtual ::String^ ToString() override;

        virtual BedrockServer::Extension::Tag::Type GetId();

        virtual bool Equals(BedrockServer::Extension::Tag^ _0) override;

        virtual unsigned long long hash();
#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension