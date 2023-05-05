#pragma once
#include "Tag.hpp"
#include <mc/EndTag.hpp>

namespace BedrockServer::Extension::Handle
{
    public ref class EndTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(EndTagHandle, ::EndTag, TagHandle)
    public:

        inline const nullptr_t Value();
        inline static EndTagHandle^ Create();
        inline bool Set();
        inline const nullptr_t Get();
    };
} // namespace BedrockServer::Extension::Handle
