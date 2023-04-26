#include "BlockActor.hpp"

#include "CompoundTag.hpp"
#include "Block.hpp"

enum class BlockActorType;

namespace BedrockServer::Extension
{

inline bool BlockActor::RefreshData()
{
    return NativePtr->refreshData();
}

inline CompoundTag ^ BlockActor::GetNbt()
{
    return gcnew CompoundTag(NativePtr->getNbt().release(), true);
}

inline bool BlockActor::SetNbt(CompoundTag ^ nbt)
{
    return NativePtr->setNbt(nbt->NativePtr);
}

inline int BlockActor::getBlockEntityType(Block ^ block)
{
    return (int)block->NativePtr->getBlockEntityType();
}

} // namespace BedrockServer::Extension
