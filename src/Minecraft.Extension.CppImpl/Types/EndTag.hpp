#pragma once
#include "Tag.hpp"
#include <mc/EndTag.hpp>

namespace BedrockServer::Extension
{
    public ref class EndTag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(EndTag, ::EndTag, Tag)
    public:

        inline const nullptr_t Value();
        inline static EndTag^ Create();
        inline bool Set();
        inline const nullptr_t Get();
    };
} // namespace BedrockServer::Extension
