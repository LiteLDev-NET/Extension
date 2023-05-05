#pragma once
#include <mc/Packet.hpp>
#include "Types.hpp"
#include "BinaryStream.hpp"

namespace BedrockServer::Extension::Handle
{
    public enum class PacketReliability
    {
        Relible,
        RelibleOrdered
    };

    public ref class PacketHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(PacketHandle, ::Packet)
    public:
    };
} // namespace BedrockServer::Extension::Handle
