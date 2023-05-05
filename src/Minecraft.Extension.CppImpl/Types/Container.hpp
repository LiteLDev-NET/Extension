#pragma once
#include <mc/Container.hpp>
#include "Types.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class ItemStackHandle;
}

namespace BedrockServer::Extension::Handle
{
    public ref class ContainerHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(ContainerHandle, ::Container)
    public:

        inline bool AddItem_s(ItemStackHandle^ item);
        inline bool AddItemToFirstEmptySlot_s(ItemStackHandle^ item);
        inline bool RemoveItem_s(int slot, unsigned int number);
        inline ItemStackHandle^ GetItem(int slot);
        inline void SetItem(int, ItemStackHandle^);
        inline bool HasContainer(Vec3 pos, int dim);
        inline ContainerHandle^ GetContainerAt(Vec3 pos, int dim);
        inline int FindFirstSlotForItem(ItemStackHandle^ item);
    };
} // namespace BedrockServer::Extension::Handle
