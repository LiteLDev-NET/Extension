#include "Objective.hpp"
#include "ScoreboardId.hpp"
namespace BedrockServer::Extension::Handle
{

    inline bool ObjectiveHandle::SetDisplay(String^ slotName, ObjectiveSortOrder sort)
    {
        return NativePtr->setDisplay(marshalString(slotName), ::ObjectiveSortOrder(sort));
    }
} // namespace BedrockServer::Extension::Handle
