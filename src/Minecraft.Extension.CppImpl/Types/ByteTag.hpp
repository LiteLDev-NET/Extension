#pragma once
#include "Tag.hpp"
#include <mc/ByteTag.hpp>

namespace BedrockServer::Extension::Handle
{
    public ref class ByteTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(ByteTagHandle, ::ByteTag, TagHandle)
    public:

        inline unsigned char Value();
        inline ByteTagHandle^ operator=(unsigned char val);
        inline static ByteTagHandle^ Create();
        inline bool Set(unsigned char val);
        inline unsigned char Get();
    };
} // namespace BedrockServer::Extension::Handle
