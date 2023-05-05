#pragma once
#include <mc/NetworkIdentifier.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    public ref class NetworkIdentifierHandle : SafeHandle, ICppClass
    {
        DEFAULT_DEF(NetworkIdentifierHandle, ::NetworkIdentifier)
    public:
        property String^ IP { String^ get(); }
    };
} // namespace BedrockServer::Extension::Handle
