#pragma once
#include <mc/ArmorStand.hpp>
#include "Types.hpp"
#include "Mob.hpp"

namespace BedrockServer::Extension
{
    public
    ref class ArmorStand : public Mob
    {
        DEFAULT_DEF_OVERRIDE(ArmorStand, ::ArmorStand, Mob)
    public:

        ref class Pose : SafeHandle, ICppClass
        {
            DEFAULT_DEF(Pose, ::ArmorStand::Pose)
        };
    };
} // namespace BedrockServer::Extension
