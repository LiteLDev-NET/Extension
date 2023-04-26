#pragma once
#include "Tag.hpp"
#include <mc/DoubleTag.hpp>

namespace BedrockServer::Extension
{
    public ref class DoubleTag : public Tag
    {
        DEFAULT_DEF_OVERRIDE(DoubleTag, ::DoubleTag, Tag)
    public:

        inline double^ Value();
        inline DoubleTag^ operator=(double val);
        inline static DoubleTag^ Create();
        inline static DoubleTag^ Create(double val);
        inline bool Set(double val);
        inline double Get();

#ifdef INCLUDE_MCAPI

        virtual void DeleteChildren() override;

        virtual ::String^ ToString() override;

        virtual BedrockServer::Extension::Tag::Type GetId();

        virtual bool Equals(BedrockServer::Extension::Tag^ _0) override;

        virtual unsigned long long hash();

#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension