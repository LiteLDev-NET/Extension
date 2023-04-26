#include "Objective.hpp"
#include "ScoreboardId.hpp"
namespace BedrockServer::Extension
{

    inline bool Objective::SetDisplay(String^ slotName, ObjectiveSortOrder sort)
    {
        return NativePtr->setDisplay(marshalString(slotName), ::ObjectiveSortOrder(sort));
    }
} // namespace BedrockServer::Extension
