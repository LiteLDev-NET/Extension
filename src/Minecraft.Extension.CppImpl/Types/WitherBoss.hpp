#pragma once
#include <mc/WitherBoss.hpp>
#include "Types.hpp"
#include "Monster.hpp"

namespace BedrockServer::Extension::Handle
{
    public ref class WitherBossHandle : public MonsterHandle
    {
        DEFAULT_DEF_OVERRIDE(WitherBossHandle, ::WitherBoss, MonsterHandle)
    public:
    };
} // namespace BedrockServer::Extension::Handle
