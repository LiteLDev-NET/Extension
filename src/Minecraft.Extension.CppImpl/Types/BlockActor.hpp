#pragma once
#include <mc/BlockActor.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    ref class Block;
    ref class CompoundTag;
}

namespace BedrockServer::Extension
{
    public ref class BlockActor :SafeHandle, ICppClass
    {
        DEFAULT_DEF(BlockActor, ::BlockActor)
    public:

        inline static int getBlockEntityType(Block^ block);

        inline bool RefreshData();
        inline CompoundTag^ GetNbt();
        inline bool SetNbt(CompoundTag^ nbt);
    };
} // namespace BedrockServer::Extension