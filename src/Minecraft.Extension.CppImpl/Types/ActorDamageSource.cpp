#include "ActorDamageSource.hpp"
#include "Actor.hpp"

namespace BedrockServer::Extension::Handle
{
inline ActorHandle ^ ActorDamageSourceHandle::Entity::get()
{
    return gcnew ActorHandle(NativePtr->getEntity());
}
bool ActorDamageSourceHandle::IsEntitySource::get()
{
    return NativePtr->isEntitySource();
}
//void BedrockServer::Extension::Handle::ActorDamageSource::UnkVfn11()
//{
//    NativePtr->__unk_vfn_11();
//}
//void BedrockServer::Extension::Handle::ActorDamageSource::UnkVfn12()
//{
//    NativePtr->__unk_vfn_12();
//}
BedrockServer::ActorDamageCause BedrockServer::Extension::Handle::ActorDamageSourceHandle::LookupCause(::String^ causeName)
{
    return BedrockServer::ActorDamageCause(::ActorDamageSource::lookupCause(marshalString(causeName)));
}
String^ BedrockServer::Extension::Handle::ActorDamageSourceHandle::LookupCauseName(BedrockServer::ActorDamageCause cause)
{
    return marshalString(::ActorDamageSource::lookupCauseName(::ActorDamageCause(cause)));
}
bool BedrockServer::Extension::Handle::ActorDamageSourceHandle::IsChildEntitySource::get()
{
    return NativePtr->isChildEntitySource();
}
bool BedrockServer::Extension::Handle::ActorDamageSourceHandle::IsBlockSource::get()
{
    return NativePtr->isBlockSource();
}
bool BedrockServer::Extension::Handle::ActorDamageSourceHandle::IsFire::get()
{
    return NativePtr->isFire();
}
bool BedrockServer::Extension::Handle::ActorDamageSourceHandle::IsCreative::get()
{
    return NativePtr->getIsCreative();
}
bool BedrockServer::Extension::Handle::ActorDamageSourceHandle::IsWorldBuilder::get()
{
    return NativePtr->getIsWorldBuilder();
}
bool BedrockServer::Extension::Handle::ActorDamageSourceHandle::DamagingEntityIsCreative::get()
{
    return NativePtr->getDamagingEntityIsCreative();
}
bool BedrockServer::Extension::Handle::ActorDamageSourceHandle::DamagingEntityIsWorldBuilder::get()
{
    return NativePtr->getDamagingEntityIsWorldBuilder();
}
BedrockServer::ActorUniqueID BedrockServer::Extension::Handle::ActorDamageSourceHandle::DamagingEntityUniqueID::get()
{
    return NativePtr->getDamagingEntityUniqueID();
}
BedrockServer::ActorDamageCause BedrockServer::Extension::Handle::ActorDamageSourceHandle::Cause::get()
{
    return BedrockServer::ActorDamageCause(NativePtr->getCause());
}
void BedrockServer::Extension::Handle::ActorDamageSourceHandle::Cause::set(BedrockServer::ActorDamageCause cause)
{
    NativePtr->setCause(::ActorDamageCause(cause));
}
} // namespace BedrockServer::Extension::Handle