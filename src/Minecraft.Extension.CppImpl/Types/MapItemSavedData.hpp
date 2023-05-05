#pragma once
#include <mc/MapItemSavedData.hpp>
#include "Types.hpp"
namespace BedrockServer::Extension::Handle
{
    public ref class MapItemSavedDataHandle :SafeHandle, ICppClass
    {
        DEFAULT_DEF(MapItemSavedDataHandle, ::MapItemSavedData)
    public:
    };
} // namespace BedrockServer::Extension::Handle
