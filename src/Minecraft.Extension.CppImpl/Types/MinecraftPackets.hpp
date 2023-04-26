#pragma once
#include "Packet.hpp"
#include "Types.hpp"

ref class __Packet :BedrockServer::Extension::Packet
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
        :Packet(sharedPtr.get())
    {
        s_ptr = new std::shared_ptr<::Packet>(std::move(sharedPtr));
    }
};

namespace BedrockServer::Extension
{
    public ref class MinecraftPackets __static
    {
    public:
        static Packet^ CreatePacket(BedrockServer::MinecraftPacketIds packetId);
    };
}
