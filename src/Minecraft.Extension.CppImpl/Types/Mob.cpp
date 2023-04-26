#include "Mob.hpp"
namespace BedrockServer::Extension
{
    inline bool Mob::RefreshInventory()
    {
        return NativePtr->refreshInventory();
    }
} // namespace BedrockServer::Extension
