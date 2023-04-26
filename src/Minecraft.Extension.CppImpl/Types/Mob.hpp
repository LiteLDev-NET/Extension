#pragma once
#include <mc/Mob.hpp>
#include "Actor.hpp"


namespace BedrockServer::Extension
{
    ref class Player;

    public ref class Mob : Actor
    {
        DEFAULT_DEF_OVERRIDE(Mob, ::Mob, Actor)
    public:

        inline bool RefreshInventory();

        ref class JumpPreventionResult : SafeHandle, ICppClass
        {
            DEFAULT_DEF(JumpPreventionResult, ::Mob::JumpPreventionResult)
        public:
        };
    };
} // namespace BedrockServer::Extension
