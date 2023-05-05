#pragma once
#include <mc/ServerPlayer.hpp>
#include "Player.hpp"

namespace BedrockServer::Extension::Handle
{
    public ref class ServerPlayerHandle : PlayerHandle
    {
        DEFAULT_DEF_OVERRIDE(ServerPlayerHandle, ::ServerPlayer, PlayerHandle)
    public:
    };
} // namespace BedrockServer::Extension::Handle