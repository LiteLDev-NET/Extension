#pragma once
#include <mc/Objective.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class ScoreboardIdHandle;
}

namespace BedrockServer::Extension::Handle
{
    public ref class ObjectiveHandle : SafeHandle, ICppClass
    {
        DEFAULT_DEF(ObjectiveHandle, ::Objective)
    public:
        inline bool SetDisplay(String^ slotName, ObjectiveSortOrder sort);

#ifdef INCLUDE_MCAPI
        property ::String^ DisplayName {
            ::String^ get();
        }

        property ::String^
            Name {
            ::String^ get();
        }

        property ::System::Collections::Generic::List<BedrockServer::Extension::Handle::ScoreboardId^>^
            Players {
            ::System::Collections::Generic::List<BedrockServer::Extension::Handle::ScoreboardId^>^ get();
        }
#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension::Handle
