#pragma once
#include "Packet.hpp"
#include "Types.hpp"

ref class __Packet :BedrockServer::Extension::Handle::PacketHandle
{
internal:
    std::shared_ptr<::Packet>* s_ptr;

public:
    virtual void Destruct() override
    {
        ReleaseHandle();
    }

    virtual bool ReleaseHandle() override
    {
        delete s_ptr;
        return true;
    }

    __Packet(std::shared_ptr<::Packet> sharedPtr)
        :PacketHandle(sharedPtr.get())
    {
        s_ptr = new std::shared_ptr<::Packet>(std::move(sharedPtr));
    }
};

namespace BedrockServer::Extension
{
    public ref class MinecraftPackets __static
    {
    public:
        static BedrockServer::Extension::Handle::PacketHandle^ CreatePacket(BedrockServer::MinecraftPacketIds packetId);
    };
}
