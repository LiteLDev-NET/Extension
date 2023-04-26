#pragma once
#include <mc/MobEffectInstance.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    public ref class MobEffectInstance : SafeHandle, ICppClass
    {
        DEFAULT_DEF(MobEffectInstance, ::MobEffectInstance)
    public:

        property array<char>^ Filler {
            array<char>^ get();
            void set(array<char>^ filler);
        };
    };
} // namespace BedrockServer::Extension