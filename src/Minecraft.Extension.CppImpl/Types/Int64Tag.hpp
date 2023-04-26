#pragma once
#include "Tag.hpp"
#include <mc/Int64Tag.hpp>

namespace BedrockServer::Extension
{
    public ref class Int64Tag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(Int64Tag, ::Int64Tag, Tag)
    public:

        inline int64_t^ Value();
        inline Int64Tag^ operator=(int64_t val);
        inline static Int64Tag^ Create();
        inline static Int64Tag^ Create(int64_t val);
        inline bool Set(int64_t val);
        inline int64_t Get();

#ifdef INCLUDE_MCAPI

        virtual void DeleteChildren() override;

        virtual ::String^ ToString() override;

        virtual BedrockServer::Extension::Tag::Type GetId();

        virtual bool Equals(BedrockServer::Extension::Tag^ _0) override;

        virtual unsigned long long hash();

        static operator BedrockServer::Extension::Int64Tag ^ (long long _0);
#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension
