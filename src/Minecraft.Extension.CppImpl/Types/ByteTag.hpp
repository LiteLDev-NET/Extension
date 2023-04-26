#pragma once
#include "Tag.hpp"
#include <mc/ByteTag.hpp>

namespace BedrockServer::Extension
{
    public ref class ByteTag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(ByteTag, ::ByteTag, Tag)
    public:

        inline unsigned char Value();
        inline ByteTag^ operator=(unsigned char val);
        inline static ByteTag^ Create();
        inline bool Set(unsigned char val);
        inline unsigned char Get();
    };
} // namespace BedrockServer::Extension
