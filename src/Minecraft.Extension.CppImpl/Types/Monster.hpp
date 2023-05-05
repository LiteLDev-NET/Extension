#pragma once
#include <mc/Monster.hpp>
#include "Types.hpp"
#include "Mob.hpp"
namespace BedrockServer::Extension::Handle
{
    public
    ref class MonsterHandle : public MobHandle
    {
        DEFAULT_DEF_OVERRIDE(MonsterHandle, ::Monster, MobHandle)
    public:
    };
} // namespace BedrockServer::Extension::Handle