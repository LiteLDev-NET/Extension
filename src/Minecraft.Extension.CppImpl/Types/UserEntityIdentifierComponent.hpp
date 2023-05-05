#pragma once
#include <mc/UserEntityIdentifierComponent.hpp>
#include "NetworkIdentifier.hpp"
#include "Certificate.hpp"
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    public
    ref class UserEntityIdentifierComponentHandle : SafeHandle, ICppClass
    {
        DEFAULT_DEF(UserEntityIdentifierComponentHandle, ::UserEntityIdentifierComponent)
    public:

        property NetworkIdentifierHandle^ NetworkId { NetworkIdentifierHandle^ get(); }
        property System::Byte ClientSubId { System::Byte get(); }
        property Mce::UUID Uuid { Mce::UUID get(); }
        property String^ PlayFabId { String^ get(); }
        property CertificateHandle^ CertificateHandle { BedrockServer::Extension::Handle::CertificateHandle^ get(); }
        property bool IsPrimaryClient { bool get(); }
    };
} // namespace BedrockServer::Extension::Handle
