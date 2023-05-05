#include "Container.hpp"

#include "ItemStack.hpp"
#include <mc/Vec3.hpp>

namespace BedrockServer::Extension::Handle
{

    inline bool ContainerHandle::AddItem_s(ItemStackHandle^ item)
    {
        return NativePtr->addItem_s(item->NativePtr);
    }

    inline bool ContainerHandle::AddItemToFirstEmptySlot_s(ItemStackHandle^ item)
    {
        return NativePtr->addItemToFirstEmptySlot_s(item->NativePtr);
    }

    inline bool ContainerHandle::RemoveItem_s(int slot, unsigned int number)
    {
        return NativePtr->removeItem_s(slot, number);
    }

    inline ItemStackHandle^ ContainerHandle::GetItem(int slot)
    {
        return gcnew ItemStackHandle((::ItemStack*)&NativePtr->getItem(slot));
    }

    inline void ContainerHandle::SetItem(int slot, ItemStackHandle^ item)
    {
        NativePtr->setItem(slot, *item->NativePtr);
    }

    inline bool ContainerHandle::HasContainer(Vec3 pos, int dim)
    {
        return NativePtr->hasContainer(*(::Vec3*)&pos, dim);
    }

    inline ContainerHandle^ ContainerHandle::GetContainerAt(Vec3 pos, int dim)
    {
        return gcnew ContainerHandle(NativePtr->getContainerAt(*(::Vec3*)&pos, dim));
    }

    inline int ContainerHandle::FindFirstSlotForItem(ItemStackHandle^ item)
    {
        return NativePtr->findFirstSlotForItem(*item->NativePtr);
    }
} // namespace BedrockServer::Extension::Handle
