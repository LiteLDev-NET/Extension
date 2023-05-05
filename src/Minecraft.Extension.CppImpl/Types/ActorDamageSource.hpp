#pragma once
#include <mc/ActorDamageSource.hpp>
#include "Types.hpp"

namespace BedrockServer
{
    public enum class ActorDamageCause : int {
        None = -0x01,
        Override = 0x00,
        Contact = 0x01,
        EntityAttack = 0x02,
        Projectile = 0x03,
        Suffocation = 0x04,
        Fall = 0x05,
        Fire = 0x06,
        FireTick = 0x07,
        Lava = 0x08,
        Drowning = 0x09,
        BlockExplosion = 0x0A,
        EntityExplosion = 0x0B,
        Void = 0x0C,
        Suicide = 0x0D,
        Magic = 0x0E,
        Wither = 0x0F,
        Starve = 0x10,
        Anvil = 0x11,
        Thorns = 0x12,
        FallingBlock = 0x13,
        Piston = 0x14,
        FlyIntoWall = 0x15,
        Magma = 0x16,
        Fireworks = 0x17,
        Lightning = 0x18,
        Charging = 0x19,
        Temperature = 0x1A,
        Freezing = 0x1B,
        Stalactite = 0x1C,
        Stalagmite = 0x1D,
        All = 0x1F,
    };
}

namespace BedrockServer::Extension::Handle
{
    ref class ActorHandle;
}

namespace BedrockServer::Extension::Handle
{
    public ref class ActorDamageSourceHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(ActorDamageSourceHandle, ::ActorDamageSource)
    public:

        property ActorHandle^ Entity { ActorHandle^ get(); };

        property bool IsEntitySource
        {
            bool get();
        }

        property bool IsChildEntitySource
        {
            bool get();
        }

        property bool IsBlockSource
        {
            bool get();
        }

        property bool IsFire
        {
            bool get();
        }

        property bool IsCreative
        {
            bool get();
        }

        property bool IsWorldBuilder
        {
            bool get();
        }

        property bool DamagingEntityIsCreative
        {
            bool get();
        }

        property bool DamagingEntityIsWorldBuilder
        {
            bool get();
        }

        property BedrockServer::ActorUniqueID  DamagingEntityUniqueID {
            BedrockServer::ActorUniqueID  get();
        }

        property BedrockServer::ActorDamageCause Cause
        {
            BedrockServer::ActorDamageCause get();
            void set(BedrockServer::ActorDamageCause);
        }

        //virtual void UnkVfn11();

        //virtual void UnkVfn12();

        static BedrockServer::ActorDamageCause LookupCause(::String^ _0);

        static String^ LookupCauseName(BedrockServer::ActorDamageCause _0);
    };
} // namespace BedrockServer::Extension::Handle