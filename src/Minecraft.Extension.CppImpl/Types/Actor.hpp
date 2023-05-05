#pragma once
#include <mc/Actor.hpp>

#include <Tools\Global.hpp>

namespace BedrockServer::Extension::Handle
{
    ref class UserEntityIdentifierComponentHandle;
    ref class CompoundTagHandle;
    ref class BlockSourceHandle;
    ref struct TickHandle;
    ref class ItemStackHandle;
    ref class MobEffectInstanceHandle;
    ref class LevelHandle;
    ref class MobHandle;
    ref class PlayerHandle;
    ref class AttributeInstanceHandle;
    ref class AttributeHandle;
} // namespace BedrockServer::Extension::Handle

#include "BlockInstance.hpp"
#include "MobEffect.hpp"

namespace BedrockServer::Extension::Handle
{
    public
    ref class ActorHandle : SafeHandle, ICppClass
    {
        DEFAULT_DEF(ActorHandle, ::Actor)
    public:
        inline array<String^>^ GetAllTags();
        inline BlockInstance GetBlockFromViewVector(
            __default(false) bool includeLiquid,
            __default(false) bool solidOnly,
            __default(5.25f) float maxDistance,
            __default(true) bool ignoreBorderBlocks,
            __default(false) bool fullOnly);
        inline BlockInstance GetBlockFromViewVector(
            FaceID face,
            __default(false) bool includeLiquid,
            __default(false) bool solidOnly,
            __default(5.25f) float maxDistance,
            __default(true) bool ignoreBorderBlocks,
            __default(false) bool fullOnly);
        inline ActorHandle^ GetActorFromViewVector(float maxDistance);
        inline bool SetOnFire(int time, bool isEffect);
        inline bool StopFire();
        inline bool HasTag(String^ tag);
        inline bool HurtEntity(float damage);
        inline bool Teleport(Vec3 pos, int dimid);
        inline bool RefreshActorData();
        inline bool AddEffect(MobEffectHandle::EffectType type, int tick, int level, bool ambient, bool showParticles, bool showAnimation);
        inline bool AddEffect(MobEffectHandle::EffectType type, int tick, int level, bool ambient, bool showParticles);
        inline bool AddEffect(MobEffectHandle::EffectType type, int tick, int level, bool ambient);
        inline bool AddEffect(MobEffectHandle::EffectType type, int tick, int level);
        inline bool Rename(String^ name);
        inline float QuickEvalMolangScript(String^ expression);

        property UserEntityIdentifierComponentHandle^ UserEntityIdentifierComponentHandle { BedrockServer::Extension::Handle::UserEntityIdentifierComponentHandle^ get(); };
        property CompoundTagHandle^ Nbt {CompoundTagHandle^ get(); void set(CompoundTagHandle^); };
        property BedrockServer::BlockPos BlockPos { BedrockServer::BlockPos get(); };
        property BlockInstance BlockStandingOn { BlockInstance get(); };
        property String^ TypeName { String^ get(); };
        property Vec3 Position { Vec3 get(); };
        property BlockSourceHandle^ Blocksource { BlockSourceHandle^ get(); };
        property Vec2% Direction { Vec2% get(); };
        property ActorUniqueID ActorUniqueId { ActorUniqueID get(); };
        property Vec3 CameraPos { Vec3 get(); };
        property TickHandle^ LastTick { TickHandle^ get(); };
        property ItemStackHandle^ HandSlot { ItemStackHandle^ get(); void set(ItemStackHandle^); };
        property ItemStackHandle^ OffhandSlot { ItemStackHandle^ get(); void set(ItemStackHandle^); };
        property BedrockServer::Extension::Handle::LevelHandle^ LevelHandle { BedrockServer::Extension::Handle::LevelHandle^ get(); };

        property bool IsSimulatedPlayer
        {
            bool get();
        };
        property bool IsPlayer
        {
            bool get();
        };
        property bool IsItemActor
        {
            bool get();
        };
        property bool IsOnGround
        {
            bool get();
        }
        property int DimensionId
        {
            int get();
        }
    };
} // namespace BedrockServer::Extension::Handle
