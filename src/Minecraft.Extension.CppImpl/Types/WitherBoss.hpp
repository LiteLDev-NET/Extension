#pragma once
#include <mc/WitherBoss.hpp>
#include "Types.hpp"
#include "Monster.hpp"

namespace BedrockServer::Extension
{
    public ref class WitherBoss : public Monster
    {
        DEFAULT_DEF_OVERRIDE(WitherBoss, ::WitherBoss, Monster)
    public:
    };
} // namespace BedrockServer::Extension
