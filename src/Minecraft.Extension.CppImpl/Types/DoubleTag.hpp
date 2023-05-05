#pragma once
#include "Tag.hpp"
#include <mc/DoubleTag.hpp>

namespace BedrockServer::Extension::Handle
{
    public ref class DoubleTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(DoubleTagHandle, ::DoubleTag, TagHandle)
    public:

        inline double^ Value();
        inline DoubleTagHandle^ operator=(double val);
        inline static DoubleTagHandle^ Create();
        inline static DoubleTagHandle^ Create(double val);
        inline bool Set(double val);
        inline double Get();
    };
} // namespace BedrockServer::Extension::Handle