#pragma once
#include <mc/UserEntityIdentifierComponent.hpp>
#include "NetworkIdentifier.hpp"
#include "Certificate.hpp"
#include "Types.hpp"

namespace BedrockServer::Extension
{
    public
    ref class UserEntityIdentifierComponent : SafeHandle, ICppClass
    {
        DEFAULT_DEF(UserEntityIdentifierComponent, ::UserEntityIdentifierComponent)
    public:

        property NetworkIdentifier^ NetworkId { NetworkIdentifier^ get(); }
        property System::Byte ClientSubId { System::Byte get(); }
        property Mce::UUID Uuid { Mce::UUID get(); }
        property String^ PlayFabId { String^ get(); }
        property Certificate^ Certificate { BedrockServer::Extension::Certificate^ get(); }
        property bool IsPrimaryClient { bool get(); }
    };
} // namespace BedrockServer::Extension
