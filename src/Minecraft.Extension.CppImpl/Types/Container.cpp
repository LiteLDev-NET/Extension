#include "Container.hpp"

#include "ItemStack.hpp"
#include <mc/Vec3.hpp>

namespace BedrockServer::Extension
{

    inline bool Container::AddItem_s(ItemStack^ item)
    {
        return NativePtr->addItem_s(item->NativePtr);
    }

    inline bool Container::AddItemToFirstEmptySlot_s(ItemStack^ item)
    {
        return NativePtr->addItemToFirstEmptySlot_s(item->NativePtr);
    }

    inline bool Container::RemoveItem_s(int slot, unsigned int number)
    {
        return NativePtr->removeItem_s(slot, number);
    }

    inline ItemStack^ Container::GetItem(int slot)
    {
        return gcnew ItemStack((::ItemStack*)&NativePtr->getItem(slot));
    }

    inline void Container::SetItem(int slot, ItemStack^ item)
    {
        NativePtr->setItem(slot, *item->NativePtr);
    }

    inline bool Container::HasContainer(Vec3 pos, int dim)
    {
        return NativePtr->hasContainer(*(::Vec3*)&pos, dim);
    }

    inline Container^ Container::GetContainerAt(Vec3 pos, int dim)
    {
        return gcnew Container(NativePtr->getContainerAt(*(::Vec3*)&pos, dim));
    }

    inline int Container::FindFirstSlotForItem(ItemStack^ item)
    {
        return NativePtr->findFirstSlotForItem(*item->NativePtr);
    }
} // namespace BedrockServer::Extension
