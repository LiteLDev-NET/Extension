#pragma once
#include "Tag.hpp"
#include <mc/FloatTag.hpp>

namespace BedrockServer::Extension::Handle
{
    public ref class FloatTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(FloatTagHandle, ::FloatTag, TagHandle)
    public:

        inline float^ Value();
        inline FloatTagHandle^ operator=(float val);
        inline static FloatTagHandle^ Create();
        inline static FloatTagHandle^ Create(float val);
        inline bool Set(float val);
        inline float Get();
    };
} // namespace BedrockServer::Extension::Handle
