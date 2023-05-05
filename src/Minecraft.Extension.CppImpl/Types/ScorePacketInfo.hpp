#pragma once
#include <mc/ScorePacketInfo.hpp>
#include "Types.hpp"
#include "IdentityDefinition.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class ScoreboardIdHandle;
}

namespace BedrockServer::Extension::Handle
{
    public ref struct ScorePacketInfoHandle : SafeHandle, ICppClass
    {
        DEFAULT_DEF(ScorePacketInfoHandle, ::ScorePacketInfo)
    public:
    };
} // namespace BedrockServer::Extension::Handle
