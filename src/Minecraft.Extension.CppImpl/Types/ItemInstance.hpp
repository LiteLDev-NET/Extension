#pragma once
#include <mc/ItemInstance.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    public
    ref class ItemInstance : SafeHandle , ICppClass
    {
        DEFAULT_DEF(ItemInstance, ::ItemInstance)
    public:
    };
} // namespace BedrockServer::Extension
