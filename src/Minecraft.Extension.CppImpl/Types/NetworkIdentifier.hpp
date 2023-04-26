#pragma once
#include <mc/NetworkIdentifier.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    public ref class NetworkIdentifier : SafeHandle, ICppClass
    {
        DEFAULT_DEF(NetworkIdentifier, ::NetworkIdentifier)
    public:
        property String^ IP { String^ get(); }
    };
} // namespace BedrockServer::Extension
