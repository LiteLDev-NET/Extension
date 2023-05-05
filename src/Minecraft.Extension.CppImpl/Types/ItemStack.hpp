#pragma once

#include <mc/ItemStack.hpp>
#include <mc/ItemInstance.hpp>
#include "ItemStackBase.hpp"
#include "ItemInstance.hpp"
#include "Types.hpp"
#include "CompoundTag.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class ItemStackBaseHandle;
    ref class ItemInstanceHandle;
}

namespace BedrockServer::Extension::Handle
{
    public ref class ItemStackHandle : ItemStackBaseHandle
    {
        DEFAULT_DEF_OVERRIDE(ItemStackHandle, ::ItemStack, ItemStackBaseHandle)
    public:

        inline static ItemStackHandle^ Create();
        inline static ItemStackHandle^ Create(String^ type, int count);
        inline static ItemStackHandle^ Create(CompoundTagHandle^ tag);
        inline static ItemStackHandle^ Create(short itemId, int aux);
        inline static ItemStackHandle^ Create(short itemId, int aux, int count);
        inline static ItemStackHandle^ FromItemInstance(ItemInstanceHandle^ ins);

        inline ItemStackHandle^ Clone_s();
        inline bool SetItem(ItemStackHandle^ newItem);
        bool SetLore(array<String^>^ lores);
        inline CompoundTagHandle^ GetNbt();
        inline bool SetNbt(CompoundTagHandle^ nbt);

        property String^ TypeName { String^ get(); };

        property int Aux
        {
            int get();
        }
        property int Count
        {
            int get();
        }

#ifdef MANUAL_MAINTENANCE

        // property BedrockServer::Extension::Handle::ItemStackNetIdVariant ^ ItemStackNetIdVariant {
        //     BedrockServer::Extension::Handle::ItemStackNetIdVariant ^ get();
        // }

        property int MaxUseDuration
        {
            int get();
        }

        property BedrockServer::Extension::Handle::ItemStack^ StrippedNetworkItem {
            BedrockServer::Extension::Handle::ItemStack^ get();
        }

        property bool HasItemStackNetId
        {
            bool get();
        }

        virtual void SetNull() override;

        virtual ::String^ ToString() override;

        virtual ::String^ ToDebugString() override;

        // void Autoclassinit2(unsigned long long _0);

        void AssignNetIdVariant(BedrockServer::Extension::Handle::ItemStack^ _0);

        BedrockServer::Extension::Handle::ItemStack^ Clone();

        bool MatchesAndNetIdVariantMatches(BedrockServer::Extension::Handle::ItemStack^ _0);

        bool MatchesNetIdVariant(BedrockServer::Extension::Handle::ItemStack^ _0);

        bool SameItemAndAuxAndBlockData(BedrockServer::Extension::Handle::ItemStack^ _0);

        void ServerInitNetId();

        void UseAsFuel();

        static property BedrockServer::Extension::Handle::ItemStack^ EMPTY_ITEM {
            BedrockServer::Extension::Handle::ItemStack^ get();
        }
#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension::Handle
