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

namespace BedrockServer::Extension
{
    String^ Actor::TypeName::get()
    {
        return marshalString(NativePtr->getTypeName());
    }

    inline Vec3 Actor::Position::get()
    {
        return *(Vec3*)&NativePtr->getPosition();
    }

    inline BlockSource^ Actor::Blocksource::get()
    {
        return gcnew BedrockServer::Extension::BlockSource(NativePtr->getBlockSource());
    }

    inline Vec2% Actor::Direction::get()
    {
        return *(Vec2*)NativePtr->getDirection();
    }

    inline ActorUniqueID Actor::ActorUniqueId::get()
    {
        return NativePtr->getActorUniqueId();
    }

    inline Vec3 Actor::CameraPos::get()
    {
        return *(Vec3*)&NativePtr->getCameraPos();
    }

    inline Tick^ Actor::LastTick::get()
    {
        return gcnew Tick(NativePtr->getLastTick());
    }

    inline BedrockServer::Extension::Level^ Actor::Level::get()
    {
        return gcnew BedrockServer::Extension::Level(&NativePtr->getLevel());
    }

    inline array<String^>^ Actor::GetAllTags()
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

    inline BlockInstance Actor::GetBlockFromViewVector(bool includeLiquid, bool solidOnly, float maxDistance, bool ignoreBorderBlocks, bool fullOnly)
    {
        return *(BlockInstance*)&NativePtr->getBlockFromViewVector(includeLiquid, solidOnly, maxDistance, ignoreBorderBlocks, fullOnly);
    }
    BlockInstance Actor::GetBlockFromViewVector(FaceID face, bool includeLiquid, bool solidOnly, float maxDistance, bool ignoreBorderBlocks, bool fullOnly)
    {
        return *(BlockInstance*)&NativePtr->getBlockFromViewVector((::FaceID&)face, includeLiquid, solidOnly, maxDistance, ignoreBorderBlocks, fullOnly);
    }

    inline UserEntityIdentifierComponent^ Actor::UserEntityIdentifierComponent::get()
    {
        return gcnew BedrockServer::Extension::UserEntityIdentifierComponent(
            NativePtr->getUserEntityIdentifierComponent());
    }

    inline Actor^ Actor::GetActorFromViewVector(float maxDistance)
    {
        return gcnew Actor(NativePtr->getActorFromViewVector(maxDistance));
    }

    inline BlockPos Actor::BlockPos::get()
    {
        return *(BedrockServer::BlockPos*)&NativePtr->getBlockPos();
    }

    inline BlockInstance Actor::BlockStandingOn::get()
    {
        return *(BlockInstance*)&NativePtr->getBlockStandingOn();
    }

    inline bool Actor::IsSimulatedPlayer::get()
    {
        return NativePtr->isSimulatedPlayer();
    }
    inline bool Actor::IsPlayer::get()
    {
        return NativePtr->isPlayer();
    }
    inline bool Actor::IsItemActor::get()
    {
        return NativePtr->isItemActor();
    }
    inline bool Actor::IsOnGround::get()
    {
        return NativePtr->isOnGround();
    }
    inline int Actor::DimensionId::get()
    {
        return (int)NativePtr->getDimensionId();
    }
    inline bool Actor::SetOnFire(int time, bool isEffect)
    {
        return NativePtr->setOnFire(time, isEffect);
    }
    inline bool Actor::StopFire()
    {
        return NativePtr->stopFire();
    }
    inline bool Actor::HasTag(String^ tag)
    {
        return NativePtr->hasTag(marshalString(tag));
    }
    inline bool Actor::HurtEntity(float damage)
    {
        return NativePtr->hurtEntity(damage);
    }
    inline bool Actor::Teleport(Vec3 pos, int dimid)
    {
        return NativePtr->teleport(*(::Vec3*)&pos, dimid);
    }
    inline ItemStack^ Actor::HandSlot::get()
    {
        return gcnew ItemStack(NativePtr->getHandSlot());
    }
    inline void Actor::HandSlot::set(ItemStack^ item)
    {
        if (!NativePtr->getHandSlot()->setItem(item->NativePtr))
            throw gcnew Exception();
    }
    inline ItemStack^ Actor::OffhandSlot::get()
    {
        return gcnew ItemStack((::ItemStack*)&NativePtr->getOffhandSlot());
    }
    inline void Actor::OffhandSlot::set(ItemStack^ item)
    {
        NativePtr->setOffhandSlot(*item->NativePtr);
    }
    inline bool Actor::Rename(String^ name)
    {
        return NativePtr->rename(marshalString(name));
    }
    inline float Actor::QuickEvalMolangScript(String^ expression)
    {
        return NativePtr->quickEvalMolangScript(marshalString(expression));
    }

    inline CompoundTag^ Actor::Nbt::get()
    {
        return gcnew CompoundTag(NativePtr->getNbt().release(), true);
    }
    inline void Actor::Nbt::set(CompoundTag^ nbt)
    {
        NativePtr->setNbt(nbt->NativePtr);
    }
    inline bool Actor::RefreshActorData()
    {
        return NativePtr->refreshActorData();
    }
    inline bool Actor::AddEffect(MobEffect::EffectType type, int tick, int level, bool ambient, bool showParticles, bool showAnimation)
    {
        return NativePtr->addEffect(::MobEffect::EffectType(type), tick, level, ambient, showParticles, showAnimation);
    }
    inline bool Actor::AddEffect(MobEffect::EffectType type, int tick, int level, bool ambient, bool showParticles)
    {
        return NativePtr->addEffect(::MobEffect::EffectType(type), tick, level, ambient, showParticles);
    }
    inline bool Actor::AddEffect(MobEffect::EffectType type, int tick, int level, bool ambient)
    {
        return NativePtr->addEffect(::MobEffect::EffectType(type), tick, level, ambient);
    }
    inline bool Actor::AddEffect(MobEffect::EffectType type, int tick, int level)
    {
        return NativePtr->addEffect(::MobEffect::EffectType(type), tick, level);
    }
} // namespace BedrockServer::Extension
