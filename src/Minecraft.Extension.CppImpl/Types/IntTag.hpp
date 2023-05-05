#pragma once
#include "Tag.hpp"
#include <mc/IntTag.hpp>

namespace BedrockServer::Extension::Handle
{
    ref class TagHandle;
}

namespace BedrockServer::Extension::Handle
{
    public ref class IntTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(IntTagHandle, ::IntTag, TagHandle)
    public:

        inline int^ Value();
        inline IntTagHandle^ operator=(int val);
        inline static IntTagHandle^ Create();
        inline static IntTagHandle^ Create(int val);
        inline bool Set(int val);
        inline short Get();
    };
} // namespace BedrockServer::Extension::Handle
