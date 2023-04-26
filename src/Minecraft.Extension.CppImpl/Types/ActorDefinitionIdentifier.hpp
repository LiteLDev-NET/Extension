#pragma once
#include <mc/ActorDefinitionIdentifier.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    ref class HashedString;
}

namespace BedrockServer::Extension
{
    public
    ref struct ActorDefinitionIdentifier :SafeHandle, ICppClass
    {
        DEFAULT_DEF(ActorDefinitionIdentifier, ::ActorDefinitionIdentifier)
    public:

        static ActorDefinitionIdentifier^ Create();
        static ActorDefinitionIdentifier^ Create(String^ ns, String^ identifier, String^ event, String^ fullname, HashedString^ canonicalHash);

        property String^ Namespace {System::String^ get(); void set(System::String^ ns); };
        property String^ Identifier {System::String^ get(); void set(System::String^ identifier); };
        property String^ InitEvent {System::String^ get(); void set(System::String^ event); };
        property String^ Fullname {System::String^ get(); void set(System::String^ fullname); };
        property HashedString^ CanonicalName {HashedString^ get(); void set(HashedString^ canonicalHash); };
    };
} // namespace BedrockServer::Extension