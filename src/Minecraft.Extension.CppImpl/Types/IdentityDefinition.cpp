#include "IdentityDefinition.hpp"

BedrockServer::ActorUniqueID  BedrockServer::Extension::Handle::IdentityDefinitionHandle::EntityId::get()
{
    return NativePtr->getEntityId();
}

::String^ BedrockServer::Extension::Handle::IdentityDefinitionHandle::FakePlayerName::get()
{
    auto& __ret = NativePtr->getFakePlayerName();
    return (::String^)(clix::marshalString<clix::E_UTF8>(__ret));
}

BedrockServer::Extension::Handle::IdentityDefinitionHandle::Type BedrockServer::Extension::Handle::IdentityDefinitionHandle::IdentityType::get()
{
    auto __ret = NativePtr->getIdentityType();
    return (BedrockServer::Extension::Handle::IdentityDefinitionHandle::Type)__ret;
}

bool BedrockServer::Extension::Handle::IdentityDefinitionHandle::IsEntityType::get()
{
    auto __ret = NativePtr->isEntityType();
    return __ret;
}

bool BedrockServer::Extension::Handle::IdentityDefinitionHandle::IsPlayerType::get()
{
    auto __ret = NativePtr->isPlayerType();
    return __ret;
}

bool BedrockServer::Extension::Handle::IdentityDefinitionHandle::IsValid::get()
{
    auto __ret = NativePtr->isValid();
    return __ret;
}

BedrockServer::Extension::Handle::IdentityDefinitionHandle^ BedrockServer::Extension::Handle::IdentityDefinitionHandle::Invalid::get()
{
    return (&::IdentityDefinition::Invalid == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::Handle::IdentityDefinitionHandle((class ::IdentityDefinition*) & ::IdentityDefinition::Invalid);
}
