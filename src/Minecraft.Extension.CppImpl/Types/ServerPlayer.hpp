#pragma once
#include <mc/ServerPlayer.hpp>
#include "Player.hpp"

namespace BedrockServer::Extension
{
    public ref class ServerPlayer : Player
    {
        DEFAULT_DEF_OVERRIDE(ServerPlayer, ::ServerPlayer, Player)
    public:
    };
} // namespace BedrockServer::Extension