#pragma once
#include <mc/BlockActor.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class BlockHandle;
    ref class CompoundTagHandle;
}

namespace BedrockServer::Extension::Handle
{
    public ref class BlockActorHandle :SafeHandle, ICppClass
    {
        DEFAULT_DEF(BlockActorHandle, ::BlockActor)
    public:

        inline static int getBlockEntityType(BlockHandle^ block);

        inline bool RefreshData();
        inline CompoundTagHandle^ GetNbt();
        inline bool SetNbt(CompoundTagHandle^ nbt);
    };
} // namespace BedrockServer::Extension::Handle