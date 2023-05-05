#include "BlockSource.hpp"

#include "BlockInstance.hpp"
#include "Dimension.hpp"
#include "BlockActor.hpp"

namespace BedrockServer::Extension::Handle
{
    AutomaticID<DimensionHandle^, int> BlockSourceHandle::DimensionId::get()
    {
        return *(AutomaticID<DimensionHandle^, int>*) & NativePtr->getDimensionId();
    }
    BedrockServer::BlockInstance BlockSourceHandle::GetBlockInstance(BedrockServer::BlockPos pos)
    {
        return *(BlockInstance*)&NativePtr->getBlockInstance(*(::BlockPos*)&pos);
    }
} // namespace BedrockServer::Extension::Handle
