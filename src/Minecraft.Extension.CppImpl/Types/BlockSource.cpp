#include "BlockSource.hpp"

#include "BlockInstance.hpp"
#include "Dimension.hpp"
#include "BlockActor.hpp"

namespace BedrockServer::Extension
{
    AutomaticID<Dimension^, int> BlockSource::DimensionId::get()
    {
        return *(AutomaticID<Dimension^, int>*) & NativePtr->getDimensionId();
    }
    BedrockServer::BlockInstance BlockSource::GetBlockInstance(BedrockServer::BlockPos pos)
    {
        return *(BlockInstance*)&NativePtr->getBlockInstance(*(::BlockPos*)&pos);
    }
} // namespace BedrockServer::Extension
