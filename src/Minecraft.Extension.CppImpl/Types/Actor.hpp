#pragma once
#include <mc/Actor.hpp>

#include <Tools\Global.hpp>

namespace BedrockServer::Extension
{
    ref class UserEntityIdentifierComponent;
    ref class CompoundTag;
    ref class BlockSource;
    ref struct Tick;
    ref class ItemStack;
    ref class MobEffectInstance;
    ref class Level;
    ref class Mob;
    ref class Player;
    ref class AttributeInstance;
    ref class Attribute;
} // namespace BedrockServer::Extension

#include "BlockInstance.hpp"
#include "MobEffect.hpp"

namespace BedrockServer::Extension
{
    public
    ref class Actor : SafeHandle, ICppClass
    {
        DEFAULT_DEF(Actor, ::Actor)
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
        inline Actor^ GetActorFromViewVector(float maxDistance);
        inline bool SetOnFire(int time, bool isEffect);
        inline bool StopFire();
        inline bool HasTag(String^ tag);
        inline bool HurtEntity(float damage);
        inline bool Teleport(Vec3 pos, int dimid);
        inline bool RefreshActorData();
        inline bool AddEffect(MobEffect::EffectType type, int tick, int level, bool ambient, bool showParticles, bool showAnimation);
        inline bool AddEffect(MobEffect::EffectType type, int tick, int level, bool ambient, bool showParticles);
        inline bool AddEffect(MobEffect::EffectType type, int tick, int level, bool ambient);
        inline bool AddEffect(MobEffect::EffectType type, int tick, int level);
        inline bool Rename(String^ name);
        inline float QuickEvalMolangScript(String^ expression);

        property UserEntityIdentifierComponent^ UserEntityIdentifierComponent { BedrockServer::Extension::UserEntityIdentifierComponent^ get(); };
        property CompoundTag^ Nbt {CompoundTag^ get(); void set(CompoundTag^); };
        property BedrockServer::BlockPos BlockPos { BedrockServer::BlockPos get(); };
        property BlockInstance BlockStandingOn { BlockInstance get(); };
        property String^ TypeName { String^ get(); };
        property Vec3 Position { Vec3 get(); };
        property BlockSource^ Blocksource { BlockSource^ get(); };
        property Vec2% Direction { Vec2% get(); };
        property ActorUniqueID ActorUniqueId { ActorUniqueID get(); };
        property Vec3 CameraPos { Vec3 get(); };
        property Tick^ LastTick { Tick^ get(); };
        property ItemStack^ HandSlot { ItemStack^ get(); void set(ItemStack^); };
        property ItemStack^ OffhandSlot { ItemStack^ get(); void set(ItemStack^); };
        property BedrockServer::Extension::Level^ Level { BedrockServer::Extension::Level^ get(); };

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
} // namespace BedrockServer::Extension
