#include "ActorDefinitionIdentifier.hpp"

#include "HashedString.hpp"

namespace BedrockServer::Extension
{
    inline String^ ActorDefinitionIdentifier::Namespace::get()
    {
        return marshalString(NativePtr->mNamespace);
    }
    inline void ActorDefinitionIdentifier::Namespace::set(String^ ns)
    {
        NativePtr->mNamespace = marshalString(ns);
    }
    inline String^ ActorDefinitionIdentifier::Identifier::get()
    {
        return marshalString(NativePtr->mIdentifier);
    }
    inline void ActorDefinitionIdentifier::Identifier::set(String^ identifier)
    {
        NativePtr->mIdentifier = marshalString(identifier);
    }
    inline String^ ActorDefinitionIdentifier::InitEvent::get()
    {
        return marshalString(NativePtr->mInitEvent);
    }
    inline void ActorDefinitionIdentifier::InitEvent::set(String^ initEvent)
    {
        NativePtr->mInitEvent = marshalString(initEvent);
    }
    inline String^ ActorDefinitionIdentifier::Fullname::get()
    {
        return marshalString(NativePtr->mFullName);
    }
    inline void ActorDefinitionIdentifier::Fullname::set(String^ fullname)
    {
        NativePtr->mFullName = marshalString(fullname);
    }
    inline HashedString^ ActorDefinitionIdentifier::CanonicalName::get()
    {
        return gcnew HashedString(&NativePtr->mCanonicalName);
    }
    inline void ActorDefinitionIdentifier::CanonicalName::set(HashedString^ canonicalName)
    {
        NativePtr->mCanonicalName = *canonicalName->NativePtr;
    }
    ActorDefinitionIdentifier^ ActorDefinitionIdentifier::Create()
    {
        return gcnew ActorDefinitionIdentifier(new ::ActorDefinitionIdentifier{}, true);
    }
    ActorDefinitionIdentifier^ ActorDefinitionIdentifier::Create(String^ ns, String^ identifier, String^ initEvent, String^ fullname, HashedString^ canonicalName)
    {
        ::ActorDefinitionIdentifier adi{};
        adi.mNamespace = marshalString(ns);
        adi.mIdentifier = marshalString(identifier);
        adi.mInitEvent = marshalString(initEvent);
        adi.mFullName = marshalString(fullname);
        adi.mCanonicalName = *canonicalName->NativePtr;
        return gcnew ActorDefinitionIdentifier(new ::ActorDefinitionIdentifier(std::move(adi)), true);
    }
} // namespace BedrockServer::Extension
