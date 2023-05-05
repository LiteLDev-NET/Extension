#include "UserEntityIdentifierComponent.hpp"

#include "NetworkIdentifier.hpp"

namespace BedrockServer::Extension::Handle
{
    inline NetworkIdentifierHandle^ UserEntityIdentifierComponentHandle::NetworkId::get()
    {
        return gcnew NetworkIdentifierHandle(&NativePtr->mNetworkId);
    }

    inline System::Byte UserEntityIdentifierComponentHandle::ClientSubId::get()
    {
        return NativePtr->mClientSubId;
    }

    inline Mce::UUID UserEntityIdentifierComponentHandle::Uuid::get()
    {
        return *(Mce::UUID*)&NativePtr->mUUID;
    }

    inline String^ UserEntityIdentifierComponentHandle::PlayFabId::get()
    {
        return marshalString(NativePtr->mPlayFabId);
    }

    inline CertificateHandle^ UserEntityIdentifierComponentHandle::CertificateHandle::get()
    {
        return gcnew BedrockServer::Extension::Handle::CertificateHandle(NativePtr->mCertificate.get());
    }

    inline bool UserEntityIdentifierComponentHandle::IsPrimaryClient::get()
    {
        return NativePtr->isPrimaryClient();
    }
}
