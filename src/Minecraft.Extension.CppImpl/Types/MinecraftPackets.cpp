#include "MinecraftPackets.hpp"
#include <mc/MinecraftPackets.hpp>

BedrockServer::Extension::Handle::PacketHandle^ BedrockServer::Extension::MinecraftPackets::CreatePacket(MinecraftPacketIds packetId)
{
    return static_cast<BedrockServer::Extension::Handle::PacketHandle^>(gcnew __Packet(::MinecraftPackets::createPacket(static_cast<::MinecraftPacketIds>(packetId))));
}
