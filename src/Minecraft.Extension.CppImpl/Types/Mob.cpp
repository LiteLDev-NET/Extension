#include "Mob.hpp"
namespace BedrockServer::Extension::Handle
{
    inline bool MobHandle::RefreshInventory()
    {
        return NativePtr->refreshInventory();
    }
} // namespace BedrockServer::Extension::Handle
