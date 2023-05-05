#pragma once
#include <mc/ArmorStand.hpp>
#include "Types.hpp"
#include "Mob.hpp"

namespace BedrockServer::Extension::Handle
{
    public
    ref class ArmorStandHandle : public MobHandle
    {
        DEFAULT_DEF_OVERRIDE(ArmorStandHandle, ::ArmorStand, MobHandle)
    public:

        ref class PoseHandle : SafeHandle, ICppClass
        {
            DEFAULT_DEF(PoseHandle, ::ArmorStand::Pose)
        };
    };
} // namespace BedrockServer::Extension::Handle
