#pragma once
#include "Tag.hpp"
#include <mc/ShortTag.hpp>

namespace BedrockServer::Extension::Handle
{
    public ref class ShortTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(ShortTagHandle, ::ShortTag, TagHandle)
    public:
        inline short^ Value();
        inline ShortTagHandle^ operator=(short val);
        inline static ShortTagHandle^ Create(short val);
        inline static ShortTagHandle^ Create();
        inline bool Set(short val);
        inline short Get();
    };
} // namespace BedrockServer::Extension::Handle
