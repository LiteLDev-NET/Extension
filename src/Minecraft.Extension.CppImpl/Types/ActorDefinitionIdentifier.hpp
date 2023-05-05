#pragma once
#include <mc/ActorDefinitionIdentifier.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class HashedStringHandle;
}

namespace BedrockServer::Extension::Handle
{
    public
    ref struct ActorDefinitionIdentifierHandle :SafeHandle, ICppClass
    {
        DEFAULT_DEF(ActorDefinitionIdentifierHandle, ::ActorDefinitionIdentifier)
    public:

        static ActorDefinitionIdentifierHandle^ Create();
        static ActorDefinitionIdentifierHandle^ Create(String^ ns, String^ identifier, String^ event, String^ fullname, HashedStringHandle^ canonicalHash);

        property String^ Namespace {System::String^ get(); void set(System::String^ ns); };
        property String^ Identifier {System::String^ get(); void set(System::String^ identifier); };
        property String^ InitEvent {System::String^ get(); void set(System::String^ event); };
        property String^ Fullname {System::String^ get(); void set(System::String^ fullname); };
        property HashedStringHandle^ CanonicalName {HashedStringHandle^ get(); void set(HashedStringHandle^ canonicalHash); };
    };
} // namespace BedrockServer::Extension::Handle