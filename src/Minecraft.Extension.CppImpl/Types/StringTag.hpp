#pragma once
#include "Tag.hpp"
#include <mc/StringTag.hpp>
namespace BedrockServer::Extension::Handle
{
    public ref class StringTagHandle : public TagHandle
    {
        DEFAULT_DEF_OVERRIDE(StringTagHandle, ::StringTag, TagHandle)
    public:

        inline String^ Value();
        inline StringTagHandle^ operator=(std::string val);
        inline static StringTagHandle^ Create();
        inline bool Set(String^ val);
        inline String^ Get();
    };
} // namespace BedrockServer::Extension::Handle
