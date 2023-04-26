#pragma once
#include "Tag.hpp"
#include <mc/FloatTag.hpp>

namespace BedrockServer::Extension
{
    public ref class FloatTag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(FloatTag, ::FloatTag, Tag)
    public:

        inline float^ Value();
        inline FloatTag^ operator=(float val);
        inline static FloatTag^ Create();
        inline static FloatTag^ Create(float val);
        inline bool Set(float val);
        inline float Get();
    };
} // namespace BedrockServer::Extension
