#include "ActorDefinitionIdentifier.hpp"

#include "HashedString.hpp"

namespace BedrockServer::Extension::Handle
{
    inline String^ ActorDefinitionIdentifierHandle::Namespace::get()
    {
        return marshalString(NativePtr->mNamespace);
    }
    inline void ActorDefinitionIdentifierHandle::Namespace::set(String^ ns)
    {
        NativePtr->mNamespace = marshalString(ns);
    }
    inline String^ ActorDefinitionIdentifierHandle::Identifier::get()
    {
        return marshalString(NativePtr->mIdentifier);
    }
    inline void ActorDefinitionIdentifierHandle::Identifier::set(String^ identifier)
    {
        NativePtr->mIdentifier = marshalString(identifier);
    }
    inline String^ ActorDefinitionIdentifierHandle::InitEvent::get()
    {
        return marshalString(NativePtr->mInitEvent);
    }
    inline void ActorDefinitionIdentifierHandle::InitEvent::set(String^ initEvent)
    {
        NativePtr->mInitEvent = marshalString(initEvent);
    }
    inline String^ ActorDefinitionIdentifierHandle::Fullname::get()
    {
        return marshalString(NativePtr->mFullName);
    }
    inline void ActorDefinitionIdentifierHandle::Fullname::set(String^ fullname)
    {
        NativePtr->mFullName = marshalString(fullname);
    }
    inline HashedStringHandle^ ActorDefinitionIdentifierHandle::CanonicalName::get()
    {
        return gcnew HashedStringHandle(&NativePtr->mCanonicalName);
    }
    inline void ActorDefinitionIdentifierHandle::CanonicalName::set(HashedStringHandle^ canonicalName)
    {
        NativePtr->mCanonicalName = *canonicalName->NativePtr;
    }
    ActorDefinitionIdentifierHandle^ ActorDefinitionIdentifierHandle::Create()
    {
        return gcnew ActorDefinitionIdentifierHandle(new ::ActorDefinitionIdentifier{}, true);
    }
    ActorDefinitionIdentifierHandle^ ActorDefinitionIdentifierHandle::Create(String^ ns, String^ identifier, String^ initEvent, String^ fullname, HashedStringHandle^ canonicalName)
    {
        ::ActorDefinitionIdentifier adi{};
        adi.mNamespace = marshalString(ns);
        adi.mIdentifier = marshalString(identifier);
        adi.mInitEvent = marshalString(initEvent);
        adi.mFullName = marshalString(fullname);
        adi.mCanonicalName = *canonicalName->NativePtr;
        return gcnew ActorDefinitionIdentifierHandle(new ::ActorDefinitionIdentifier(std::move(adi)), true);
    }
} // namespace BedrockServer::Extension::Handle
