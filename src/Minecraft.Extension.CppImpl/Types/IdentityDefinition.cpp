#include "IdentityDefinition.hpp"

BedrockServer::ActorUniqueID  BedrockServer::Extension::IdentityDefinition::EntityId::get()
{
    return NativePtr->getEntityId();
}

::String^ BedrockServer::Extension::IdentityDefinition::FakePlayerName::get()
{
    auto& __ret = NativePtr->getFakePlayerName();
    return (::String^)(clix::marshalString<clix::E_UTF8>(__ret));
}

BedrockServer::Extension::IdentityDefinition::Type BedrockServer::Extension::IdentityDefinition::IdentityType::get()
{
    auto __ret = NativePtr->getIdentityType();
    return (BedrockServer::Extension::IdentityDefinition::Type)__ret;
}

bool BedrockServer::Extension::IdentityDefinition::IsEntityType::get()
{
    auto __ret = NativePtr->isEntityType();
    return __ret;
}

bool BedrockServer::Extension::IdentityDefinition::IsPlayerType::get()
{
    auto __ret = NativePtr->isPlayerType();
    return __ret;
}

bool BedrockServer::Extension::IdentityDefinition::IsValid::get()
{
    auto __ret = NativePtr->isValid();
    return __ret;
}

BedrockServer::Extension::IdentityDefinition^ BedrockServer::Extension::IdentityDefinition::Invalid::get()
{
    return (&::IdentityDefinition::Invalid == nullptr) ? nullptr : gcnew ::BedrockServer::Extension::IdentityDefinition((class ::IdentityDefinition*) & ::IdentityDefinition::Invalid);
}
