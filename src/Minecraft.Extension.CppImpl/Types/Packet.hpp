#pragma once
#include <mc/Packet.hpp>
#include "Types.hpp"
#include "BinaryStream.hpp"

namespace BedrockServer::Extension
{
    public enum class PacketReliability
    {
        Relible,
        RelibleOrdered
    };

    public ref class Packet : SafeHandle , ICppClass
    {
        DEFAULT_DEF(Packet, ::Packet)
    public:
    };
} // namespace BedrockServer::Extension
