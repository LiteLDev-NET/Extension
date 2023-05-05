#pragma once
#include <mc/BlockSource.hpp>
#include "Types.hpp"
#include "BlockInstance.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class DimensionHandle;
    ref class BlockActorHandle;
} // namespace BedrockServer::Extension::Handle

namespace BedrockServer::Extension::Handle
{
    public ref class BlockSourceHandle :SafeHandle, ICppClass
    {
        DEFAULT_DEF(BlockSourceHandle, ::BlockSource)
    public:

        BedrockServer::BlockInstance GetBlockInstance(BedrockServer::BlockPos pos);
        property AutomaticID<DimensionHandle^, int> DimensionId
        {
            AutomaticID<DimensionHandle^, int> get();
        }
    };
} // namespace BedrockServer::Extension::Handle
