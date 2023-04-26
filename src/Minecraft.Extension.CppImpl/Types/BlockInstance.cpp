#include "BlockInstance.hpp"

#include "Block.hpp"
#include "BlockSource.hpp"
#include "BlockActor.hpp"
#include "Container.hpp"
#include "ItemStack.hpp"

namespace BedrockServer
{

    inline BlockInstance BlockInstance::CreateBlockinstance(BedrockServer::Extension::Block^ block, BlockPos pos, int dimId)
    {
        /*return BlockInstance(
            ::BlockInstance::createBlockInstance(block, *(::BlockPos*)&pos, dimId));*/
        auto ret = BlockInstance();
        *reinterpret_cast<::BlockInstance*>(&ret) = ::BlockInstance::createBlockInstance(block, *(::BlockPos*)&pos, dimId);
        return ret;
    }

    BlockInstance BlockInstance::Create(BedrockServer::Extension::Block^ block, BedrockServer::BlockPos pos, int dimid)
    {
        return *(BlockInstance*)&::BlockInstance::createBlockInstance(block->NativePtr, *(::BlockPos*)&pos, dimid);
    }

    BlockInstance BlockInstance::Create(BedrockServer::Extension::Block^ block, BedrockServer::BlockPos pos)
    {
        return *(BlockInstance*)&::BlockInstance::createBlockInstance(block->NativePtr, *(::BlockPos*)&pos, 0);
    }

    BlockInstance BlockInstance::Create()
    {
        return *(BlockInstance*)&::BlockInstance();
    }

    inline BedrockServer::Extension::Block^ BlockInstance::Block::get()
    {
        pin_ptr<BlockInstance> p = this;
        return gcnew BedrockServer::Extension::Block(((BlockInstance*)p)->block, false);
    }

    inline BlockPos BlockInstance::Position::get()
    {
        pin_ptr<BlockInstance> p = this;
        return *(BlockPos*)&((::BlockInstance*)p)->getPosition();
    }

    inline BedrockServer::Extension::BlockSource^ BlockInstance::BlockSource::get()
    {
        pin_ptr<BlockInstance> p = this;
        return gcnew BedrockServer::Extension::BlockSource(((::BlockInstance*)p)->getBlockSource());
    }

    inline int BlockInstance::DimensionId::get()
    {
        pin_ptr<BlockInstance> p = this;
        return ((::BlockInstance*)p)->getDimensionId();
    }

    inline bool BlockInstance::HasBlockEntity::get()
    {
        pin_ptr<BlockInstance> p = this;
        return ((::BlockInstance*)p)->hasBlockEntity();
    }

    inline BedrockServer::Extension::BlockActor^ BlockInstance::BlockEntity::get()
    {
        if (!HasBlockEntity)
            return nullptr;

        pin_ptr<BlockInstance> p = this;
        return gcnew BedrockServer::Extension::BlockActor(((::BlockInstance*)p)->getBlockEntity());
    }

    inline bool BlockInstance::HasContainer::get()
    {
        pin_ptr<BlockInstance> p = this;
        return ((::BlockInstance*)p)->hasContainer();
    }

    inline BedrockServer::Extension::Container^ BlockInstance::Container::get()
    {
        if (!HasContainer)
            return nullptr;

        pin_ptr<BlockInstance> p = this;
        return gcnew BedrockServer::Extension::Container(((::BlockInstance*)p)->getContainer());
    }

    inline bool BlockInstance::BreakNaturally(bool isCreativeMode)
    {
        pin_ptr<BlockInstance> p = this;
        return ((::BlockInstance*)p)->breakNaturally(isCreativeMode);
    }

    inline bool BlockInstance::BreakNaturally()
    {
        pin_ptr<BlockInstance> p = this;
        return ((::BlockInstance*)p)->breakNaturally(false);
    }

    inline bool BlockInstance::BreakNaturally(BedrockServer::Extension::ItemStack^ tool, bool isCreativeMode)
    {
        pin_ptr<BlockInstance> p = this;
        return ((::BlockInstance*)p)->breakNaturally(tool->NativePtr, isCreativeMode);
    }

    inline bool BlockInstance::BreakNaturally(BedrockServer::Extension::ItemStack^ tool)
    {
        pin_ptr<BlockInstance> p = this;
        return ((::BlockInstance*)p)->breakNaturally(tool->NativePtr, false);
    }

    inline BedrockServer::Extension::ItemStack^ BlockInstance::BlockDrops::get()
    {
        pin_ptr<BlockInstance> p = this;
        return gcnew BedrockServer::Extension::ItemStack(new ::ItemStack(((::BlockInstance*)p)->getBlockDrops()), true);
    }

    inline bool BlockInstance::IsNull::get()
    {
        pin_ptr<BlockInstance> p = this;
        return ((::BlockInstance*)p)->isNull();
    }

    inline short BlockInstance::BlockId::get() {
        pin_ptr<BlockInstance> p = this;
        return ((::BlockInstance*)p)->getBlock()->getId();
    }

    inline bool BlockInstance::operator==(BlockInstance a, BlockInstance b)
    {
        pin_ptr<BlockInstance> pa = &a;
        pin_ptr<BlockInstance> pb = &b;

        return *(::BlockInstance*)pa == *(::BlockInstance*)pb;
    }
} // namespace BedrockServer::Extension