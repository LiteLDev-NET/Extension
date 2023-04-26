#pragma once
#include <mc/Container.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension
{
    ref class ItemStack;
}

namespace BedrockServer::Extension
{
    public ref class Container : SafeHandle , ICppClass
    {
        DEFAULT_DEF(Container, ::Container)
    public:

        inline bool AddItem_s(ItemStack^ item);
        inline bool AddItemToFirstEmptySlot_s(ItemStack^ item);
        inline bool RemoveItem_s(int slot, unsigned int number);
        inline ItemStack^ GetItem(int slot);
        inline void SetItem(int, ItemStack^);
        inline bool HasContainer(Vec3 pos, int dim);
        inline Container^ GetContainerAt(Vec3 pos, int dim);
        inline int FindFirstSlotForItem(ItemStack^ item);
    };
} // namespace BedrockServer::Extension
