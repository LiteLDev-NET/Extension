#pragma once
#include "Tag.hpp"
#include <mc/IntTag.hpp>

namespace BedrockServer::Extension
{
    ref class Tag;
}

namespace BedrockServer::Extension
{
    public ref class IntTag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(IntTag, ::IntTag, Tag)
    public:

        inline int^ Value();
        inline IntTag^ operator=(int val);
        inline static IntTag^ Create();
        inline static IntTag^ Create(int val);
        inline bool Set(int val);
        inline short Get();
#ifdef INCLUDE_MCAPI

        virtual void DeleteChildren() override;

        virtual ::String^ ToString() override;

        virtual BedrockServer::Extension::Tag::Type GetId();

        virtual bool Equals(BedrockServer::Extension::Tag^ _0) override;

        virtual unsigned long long hash();

        static operator BedrockServer::Extension::IntTag ^ (int _0);
#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension
