#include "MinecraftPackets.hpp"
#include <mc/MinecraftPackets.hpp>

BedrockServer::Extension::Packet^ BedrockServer::Extension::MinecraftPackets::CreatePacket(MinecraftPacketIds packetId)
{
    return static_cast<BedrockServer::Extension::Packet^>(gcnew __Packet(::MinecraftPackets::createPacket(static_cast<::MinecraftPacketIds>(packetId))));
}
