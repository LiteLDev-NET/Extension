#pragma once
#include <mc/Monster.hpp>
#include "Types.hpp"
#include "Mob.hpp"
namespace BedrockServer::Extension
{
    public
    ref class Monster : public Mob
    {
        DEFAULT_DEF_OVERRIDE(Monster, ::Monster, Mob)
    public:
    };
} // namespace BedrockServer::Extension