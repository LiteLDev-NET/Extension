#pragma once
#include <mc/BlockSource.hpp>
#include "Types.hpp"
#include "BlockInstance.hpp"

namespace BedrockServer::Extension
{
    ref class Dimension;
    ref class BlockActor;
} // namespace BedrockServer::Extension

namespace BedrockServer::Extension
{
    public ref class BlockSource :SafeHandle, ICppClass
    {
        DEFAULT_DEF(BlockSource, ::BlockSource)
    public:

        BedrockServer::BlockInstance GetBlockInstance(BedrockServer::BlockPos pos);
        property AutomaticID<Dimension^, int> DimensionId
        {
            AutomaticID<Dimension^, int> get();
        }
    };
} // namespace BedrockServer::Extension
