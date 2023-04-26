#pragma once
#include "Tag.hpp"
#include <mc/StringTag.hpp>
namespace BedrockServer::Extension
{
    public ref class StringTag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(StringTag, ::StringTag, Tag)
    public:

        inline String^ Value();
        inline StringTag^ operator=(std::string val);
        inline static StringTag^ Create();
        inline bool Set(String^ val);
        inline String^ Get();
    };
} // namespace BedrockServer::Extension
