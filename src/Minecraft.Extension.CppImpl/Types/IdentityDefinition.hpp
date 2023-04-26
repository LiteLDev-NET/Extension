#pragma once
#include <mc/IdentityDefinition.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    public
    ref class IdentityDefinition : SafeHandle , ICppClass
    {
        DEFAULT_DEF(IdentityDefinition, ::IdentityDefinition)
    public:
        enum class Type : char
        {
            Invalid = 0,
            Player = 1,
            Actor = 2,
            Fake = 3
        };


        property ActorUniqueID  EntityId {
            ActorUniqueID  get();
        }

        property ::String^ FakePlayerName {
            ::String^ get();
        }

        property IdentityDefinition::Type IdentityType
        {
            IdentityDefinition::Type get();
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

        static property IdentityDefinition^ Invalid {
            IdentityDefinition^ get();
        }

#ifdef INCLUDE_MCAPI


#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension