#pragma once
#include <mc/MCRESULT.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    public ref struct MCRESULTHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(MCRESULTHandle, ::MCRESULT)
    public:
        property array<unsigned char>^ Filler {
            inline array<unsigned char>^ get();
            inline void set(array<unsigned char>^ arg);
        };
        inline operator bool();
        inline int GetFullCode();
        inline bool IsSuccess();
    };
} // namespace BedrockServer::Extension::Handle
