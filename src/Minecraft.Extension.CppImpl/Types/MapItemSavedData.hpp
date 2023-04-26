#pragma once
#include <mc/MapItemSavedData.hpp>
#include "Types.hpp"
namespace BedrockServer::Extension
{
    public ref class MapItemSavedData :SafeHandle, ICppClass
    {
        DEFAULT_DEF(MapItemSavedData, ::MapItemSavedData)
    public:
    };
} // namespace BedrockServer::Extension
