#include "ActorDamageSource.hpp"
#include "Actor.hpp"

namespace BedrockServer::Extension
{
inline Actor ^ ActorDamageSource::Entity::get()
{
    return gcnew Actor(NativePtr->getEntity());
}
bool ActorDamageSource::IsEntitySource::get()
{
    return NativePtr->isEntitySource();
}
//void BedrockServer::Extension::ActorDamageSource::UnkVfn11()
//{
//    NativePtr->__unk_vfn_11();
//}
//void BedrockServer::Extension::ActorDamageSource::UnkVfn12()
//{
//    NativePtr->__unk_vfn_12();
//}
BedrockServer::ActorDamageCause BedrockServer::Extension::ActorDamageSource::LookupCause(::String^ causeName)
{
    return BedrockServer::ActorDamageCause(::ActorDamageSource::lookupCause(marshalString(causeName)));
}
String^ BedrockServer::Extension::ActorDamageSource::LookupCauseName(BedrockServer::ActorDamageCause cause)
{
    return marshalString(::ActorDamageSource::lookupCauseName(::ActorDamageCause(cause)));
}
bool BedrockServer::Extension::ActorDamageSource::IsChildEntitySource::get()
{
    return NativePtr->isChildEntitySource();
}
bool BedrockServer::Extension::ActorDamageSource::IsBlockSource::get()
{
    return NativePtr->isBlockSource();
}
bool BedrockServer::Extension::ActorDamageSource::IsFire::get()
{
    return NativePtr->isFire();
}
bool BedrockServer::Extension::ActorDamageSource::IsCreative::get()
{
    return NativePtr->getIsCreative();
}
bool BedrockServer::Extension::ActorDamageSource::IsWorldBuilder::get()
{
    return NativePtr->getIsWorldBuilder();
}
bool BedrockServer::Extension::ActorDamageSource::DamagingEntityIsCreative::get()
{
    return NativePtr->getDamagingEntityIsCreative();
}
bool BedrockServer::Extension::ActorDamageSource::DamagingEntityIsWorldBuilder::get()
{
    return NativePtr->getDamagingEntityIsWorldBuilder();
}
BedrockServer::ActorUniqueID BedrockServer::Extension::ActorDamageSource::DamagingEntityUniqueID::get()
{
    return NativePtr->getDamagingEntityUniqueID();
}
BedrockServer::ActorDamageCause BedrockServer::Extension::ActorDamageSource::Cause::get()
{
    return BedrockServer::ActorDamageCause(NativePtr->getCause());
}
void BedrockServer::Extension::ActorDamageSource::Cause::set(BedrockServer::ActorDamageCause cause)
{
    NativePtr->setCause(::ActorDamageCause(cause));
}
} // namespace BedrockServer::Extension