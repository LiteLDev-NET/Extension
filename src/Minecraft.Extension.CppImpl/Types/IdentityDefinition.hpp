#pragma once
#include <mc/IdentityDefinition.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    public ref class IdentityDefinitionHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(IdentityDefinitionHandle, ::IdentityDefinition)
    public:
        enum class Type : char
        {
            Invalid = 0,
            PlayerHandle = 1,
            ActorHandle = 2,
            Fake = 3
        };


        property ActorUniqueID  EntityId {
            ActorUniqueID  get();
        }

        property ::String^ FakePlayerName {
            ::String^ get();
        }

        property IdentityDefinitionHandle::Type IdentityType
        {
            IdentityDefinitionHandle::Type get();
        }

        property bool IsEntityType
        {
            bool get();
        }

        property bool IsPlayerType
        {
            bool get();
        }

        property bool IsValid
        {
            bool get();
        }

        static property IdentityDefinitionHandle^ Invalid {
            IdentityDefinitionHandle^ get();
        }

#ifdef INCLUDE_MCAPI


#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension::Handle