#include "Actor.hpp"

#include "BlockSource.hpp"
#include "Tick.hpp"
#include "BlockInstance.hpp"
#include "UserEntityIdentifierComponent.hpp"
#include "MobEffect.hpp"
#include "ItemStack.hpp"
#include "CompoundTag.hpp"
#include "MobEffectInstance.hpp"
#include "Level.hpp"
#include "Player.hpp"

#include "Attribute.hpp"
#include "AttributeInstance.hpp"

#include <mc/Minecraft.hpp>

namespace BedrockServer::Extension::Handle
{
    String^ ActorHandle::TypeName::get()
    {
        return marshalString(NativePtr->getTypeName());
    }

    inline Vec3 ActorHandle::Position::get()
    {
        return *(Vec3*)&NativePtr->getPosition();
    }

    inline BlockSourceHandle^ ActorHandle::Blocksource::get()
    {
        return gcnew BedrockServer::Extension::Handle::BlockSourceHandle(NativePtr->getBlockSource());
    }

    inline Vec2% ActorHandle::Direction::get()
    {
        return *(Vec2*)NativePtr->getDirection();
    }

    inline ActorUniqueID ActorHandle::ActorUniqueId::get()
    {
        return NativePtr->getActorUniqueId();
    }

    inline Vec3 ActorHandle::CameraPos::get()
    {
        return *(Vec3*)&NativePtr->getCameraPos();
    }

    inline TickHandle^ ActorHandle::LastTick::get()
    {
        return gcnew TickHandle(NativePtr->getLastTick());
    }

    inline BedrockServer::Extension::Handle::LevelHandle^ ActorHandle::LevelHandle::get()
    {
        return gcnew BedrockServer::Extension::Handle::LevelHandle(&NativePtr->getLevel());
    }

    inline array<String^>^ ActorHandle::GetAllTags()
    {
        std::vector<std::string>& stdTags = NativePtr->getAllTags();
        auto len = stdTags.size();
        auto Tags = gcnew array<String^>(int(len));
        for (auto i = 0; i < len; i++)
        {
            Tags[i] = marshalString(stdTags[i]);
        }
        return Tags;
    }

    inline BlockInstance ActorHandle::GetBlockFromViewVector(bool includeLiquid, bool solidOnly, float maxDistance, bool ignoreBorderBlocks, bool fullOnly)
    {
        return *(BlockInstance*)&NativePtr->getBlockFromViewVector(includeLiquid, solidOnly, maxDistance, ignoreBorderBlocks, fullOnly);
    }
    BlockInstance ActorHandle::GetBlockFromViewVector(FaceID face, bool includeLiquid, bool solidOnly, float maxDistance, bool ignoreBorderBlocks, bool fullOnly)
    {
        return *(BlockInstance*)&NativePtr->getBlockFromViewVector((::FaceID&)face, includeLiquid, solidOnly, maxDistance, ignoreBorderBlocks, fullOnly);
    }

    inline UserEntityIdentifierComponentHandle^ ActorHandle::UserEntityIdentifierComponentHandle::get()
    {
        return gcnew BedrockServer::Extension::Handle::UserEntityIdentifierComponentHandle(
            NativePtr->getUserEntityIdentifierComponent());
    }

    inline ActorHandle^ ActorHandle::GetActorFromViewVector(float maxDistance)
    {
        return gcnew ActorHandle(NativePtr->getActorFromViewVector(maxDistance));
    }

    inline BlockPos ActorHandle::BlockPos::get()
    {
        return *(BedrockServer::BlockPos*)&NativePtr->getBlockPos();
    }

    inline BlockInstance ActorHandle::BlockStandingOn::get()
    {
        return *(BlockInstance*)&NativePtr->getBlockStandingOn();
    }

    inline bool ActorHandle::IsSimulatedPlayer::get()
    {
        return NativePtr->isSimulatedPlayer();
    }
    inline bool ActorHandle::IsPlayer::get()
    {
        return NativePtr->isPlayer();
    }
    inline bool ActorHandle::IsItemActor::get()
    {
        return NativePtr->isItemActor();
    }
    inline bool ActorHandle::IsOnGround::get()
    {
        return NativePtr->isOnGround();
    }
    inline int ActorHandle::DimensionId::get()
    {
        return (int)NativePtr->getDimensionId();
    }
    inline bool ActorHandle::SetOnFire(int time, bool isEffect)
    {
        return NativePtr->setOnFire(time, isEffect);
    }
    inline bool ActorHandle::StopFire()
    {
        return NativePtr->stopFire();
    }
    inline bool ActorHandle::HasTag(String^ tag)
    {
        return NativePtr->hasTag(marshalString(tag));
    }
    inline bool ActorHandle::HurtEntity(float damage)
    {
        return NativePtr->hurtEntity(damage);
    }
    inline bool ActorHandle::Teleport(Vec3 pos, int dimid)
    {
        return NativePtr->teleport(*(::Vec3*)&pos, dimid);
    }
    inline ItemStackHandle^ ActorHandle::HandSlot::get()
    {
        return gcnew ItemStackHandle(NativePtr->getHandSlot());
    }
    inline void ActorHandle::HandSlot::set(ItemStackHandle^ item)
    {
        if (!NativePtr->getHandSlot()->setItem(item->NativePtr))
            throw gcnew Exception();
    }
    inline ItemStackHandle^ ActorHandle::OffhandSlot::get()
    {
        return gcnew ItemStackHandle((::ItemStack*)&NativePtr->getOffhandSlot());
    }
    inline void ActorHandle::OffhandSlot::set(ItemStackHandle^ item)
    {
        NativePtr->setOffhandSlot(*item->NativePtr);
    }
    inline bool ActorHandle::Rename(String^ name)
    {
        return NativePtr->rename(marshalString(name));
    }
    inline float ActorHandle::QuickEvalMolangScript(String^ expression)
    {
        return NativePtr->quickEvalMolangScript(marshalString(expression));
    }

    inline CompoundTagHandle^ ActorHandle::Nbt::get()
    {
        return gcnew CompoundTagHandle(NativePtr->getNbt().release(), true);
    }
    inline void ActorHandle::Nbt::set(CompoundTagHandle^ nbt)
    {
        NativePtr->setNbt(nbt->NativePtr);
    }
    inline bool ActorHandle::RefreshActorData()
    {
        return NativePtr->refreshActorData();
    }
    inline bool ActorHandle::AddEffect(MobEffectHandle::EffectType type, int tick, int level, bool ambient, bool showParticles, bool showAnimation)
    {
        return NativePtr->addEffect(::MobEffect::EffectType(type), tick, level, ambient, showParticles, showAnimation);
    }
    inline bool ActorHandle::AddEffect(MobEffectHandle::EffectType type, int tick, int level, bool ambient, bool showParticles)
    {
        return NativePtr->addEffect(::MobEffect::EffectType(type), tick, level, ambient, showParticles);
    }
    inline bool ActorHandle::AddEffect(MobEffectHandle::EffectType type, int tick, int level, bool ambient)
    {
        return NativePtr->addEffect(::MobEffect::EffectType(type), tick, level, ambient);
    }
    inline bool ActorHandle::AddEffect(MobEffectHandle::EffectType type, int tick, int level)
    {
        return NativePtr->addEffect(::MobEffect::EffectType(type), tick, level);
    }
} // namespace BedrockServer::Extension::Handle
