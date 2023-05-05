#include "BlockActor.hpp"

#include "CompoundTag.hpp"
#include "Block.hpp"

enum class BlockActorType;

namespace BedrockServer::Extension::Handle
{

inline bool BlockActorHandle::RefreshData()
{
    return NativePtr->refreshData();
}

inline CompoundTagHandle ^ BlockActorHandle::GetNbt()
{
    return gcnew CompoundTagHandle(NativePtr->getNbt().release(), true);
}

inline bool BlockActorHandle::SetNbt(CompoundTagHandle ^ nbt)
{
    return NativePtr->setNbt(nbt->NativePtr);
}

inline int BlockActorHandle::getBlockEntityType(BlockHandle ^ block)
{
    return (int)block->NativePtr->getBlockEntityType();
}

} // namespace BedrockServer::Extension::Handle
