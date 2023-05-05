#pragma once
#include <mc/MobEffectInstance.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    public ref class MobEffectInstanceHandle : SafeHandle, ICppClass
    {
        DEFAULT_DEF(MobEffectInstanceHandle, ::MobEffectInstance)
    public:

        property array<char>^ Filler {
            array<char>^ get();
            void set(array<char>^ filler);
        };
    };
} // namespace BedrockServer::Extension::Handle