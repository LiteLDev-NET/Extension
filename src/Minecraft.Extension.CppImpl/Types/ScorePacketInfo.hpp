#pragma once
#include <mc/ScorePacketInfo.hpp>
#include "Types.hpp"
#include "IdentityDefinition.hpp"

namespace BedrockServer::Extension
{
    ref class ScoreboardId;
}

namespace BedrockServer::Extension
{
    public ref struct ScorePacketInfo : SafeHandle, ICppClass
    {
        DEFAULT_DEF(ScorePacketInfo, ::ScorePacketInfo)
    public:
    };
} // namespace BedrockServer::Extension
