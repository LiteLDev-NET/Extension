#pragma once
#include <mc/Mob.hpp>
#include "Actor.hpp"


namespace BedrockServer::Extension::Handle
{
    ref class PlayerHandle;

    public ref class MobHandle : ActorHandle
    {
        DEFAULT_DEF_OVERRIDE(MobHandle, ::Mob, ActorHandle)
    public:

        inline bool RefreshInventory();

        ref class JumpPreventionResultHandle : SafeHandle, ICppClass
        {
            DEFAULT_DEF(JumpPreventionResultHandle, ::Mob::JumpPreventionResult)
        public:
        };
    };
} // namespace BedrockServer::Extension::Handle
