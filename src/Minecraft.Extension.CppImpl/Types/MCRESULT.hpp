#pragma once
#include <mc/MCRESULT.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    public ref struct MCRESULT : SafeHandle , ICppClass
    {
        DEFAULT_DEF(MCRESULT, ::MCRESULT)
    public:
        property array<unsigned char>^ Filler {
            inline array<unsigned char>^ get();
            inline void set(array<unsigned char>^ arg);
        };
        inline operator bool();
        inline int GetFullCode();
        inline bool IsSuccess();
    };
} // namespace BedrockServer::Extension
