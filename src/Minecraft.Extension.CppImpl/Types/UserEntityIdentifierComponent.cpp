#include "UserEntityIdentifierComponent.hpp"

#include "NetworkIdentifier.hpp"

namespace BedrockServer::Extension
{
    inline NetworkIdentifier^ UserEntityIdentifierComponent::NetworkId::get()
    {
        return gcnew NetworkIdentifier(&NativePtr->mNetworkId);
    }

    inline System::Byte UserEntityIdentifierComponent::ClientSubId::get()
    {
        return NativePtr->mClientSubId;
    }

    inline Mce::UUID UserEntityIdentifierComponent::Uuid::get()
    {
        return *(Mce::UUID*)&NativePtr->mUUID;
    }

    inline String^ UserEntityIdentifierComponent::PlayFabId::get()
    {
        return marshalString(NativePtr->mPlayFabId);
    }

    inline Certificate^ UserEntityIdentifierComponent::Certificate::get()
    {
        return gcnew BedrockServer::Extension::Certificate(NativePtr->mCertificate.get());
    }

    inline bool UserEntityIdentifierComponent::IsPrimaryClient::get()
    {
        return NativePtr->isPrimaryClient();
    }
}
