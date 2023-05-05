#pragma once
#include "Tag.hpp"
#include <mc/Int64Tag.hpp>

namespace BedrockServer::Extension::Handle
{
    public ref class Int64TagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(Int64TagHandle, ::Int64Tag, TagHandle)
    public:

        inline int64_t^ Value();
        inline Int64TagHandle^ operator=(int64_t val);
        inline static Int64TagHandle^ Create();
        inline static Int64TagHandle^ Create(int64_t val);
        inline bool Set(int64_t val);
        inline int64_t Get();
    };
} // namespace BedrockServer::Extension::Handle
