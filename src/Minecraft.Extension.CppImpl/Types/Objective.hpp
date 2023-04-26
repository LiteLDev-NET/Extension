#pragma once
#include <mc/Objective.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    ref class ScoreboardId;
}

namespace BedrockServer::Extension
{
    public ref class Objective : SafeHandle, ICppClass
    {
        DEFAULT_DEF(Objective, ::Objective)
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

        property ::System::Collections::Generic::List<BedrockServer::Extension::ScoreboardId^>^
            Players {
            ::System::Collections::Generic::List<BedrockServer::Extension::ScoreboardId^>^ get();
        }
#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension
