#pragma once
#include "Tag.hpp"
#include <mc/ShortTag.hpp>

namespace BedrockServer::Extension
{
    public ref class ShortTag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(ShortTag, ::ShortTag, Tag)
    public:
        inline short^ Value();
        inline ShortTag^ operator=(short val);
        inline static ShortTag^ Create(short val);
        inline static ShortTag^ Create();
        inline bool Set(short val);
        inline short Get();
    };
} // namespace BedrockServer::Extension
