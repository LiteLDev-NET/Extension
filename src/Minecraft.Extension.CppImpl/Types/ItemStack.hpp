#pragma once

#include <mc/ItemStack.hpp>
#include <mc/ItemInstance.hpp>
#include "ItemStackBase.hpp"
#include "ItemInstance.hpp"
#include "Types.hpp"
#include "CompoundTag.hpp"

namespace BedrockServer::Extension
{
    ref class ItemStackBase;
    ref class ItemInstance;
}

namespace BedrockServer::Extension
{
    public ref class ItemStack : ItemStackBase
    {
        DEFAULT_DEF_OVERRIDE(ItemStack, ::ItemStack, ItemStackBase)
    public:

        inline static ItemStack^ Create();
        inline static ItemStack^ Create(String^ type, int count);
        inline static ItemStack^ Create(CompoundTag^ tag);
        inline static ItemStack^ Create(short itemId, int aux);
        inline static ItemStack^ Create(short itemId, int aux, int count);
        inline static ItemStack^ FromItemInstance(ItemInstance^ ins);

        inline ItemStack^ Clone_s();
        inline bool SetItem(ItemStack^ newItem);
        bool SetLore(array<String^>^ lores);
        inline CompoundTag^ GetNbt();
        inline bool SetNbt(CompoundTag^ nbt);

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

        // property BedrockServer::Extension::ItemStackNetIdVariant ^ ItemStackNetIdVariant {
        //     BedrockServer::Extension::ItemStackNetIdVariant ^ get();
        // }

        property int MaxUseDuration
        {
            int get();
        }

        property BedrockServer::Extension::ItemStack^ StrippedNetworkItem {
            BedrockServer::Extension::ItemStack^ get();
        }

        property bool HasItemStackNetId
        {
            bool get();
        }

        virtual void SetNull() override;

        virtual ::String^ ToString() override;

        virtual ::String^ ToDebugString() override;

        // void Autoclassinit2(unsigned long long _0);

        void AssignNetIdVariant(BedrockServer::Extension::ItemStack^ _0);

        BedrockServer::Extension::ItemStack^ Clone();

        bool MatchesAndNetIdVariantMatches(BedrockServer::Extension::ItemStack^ _0);

        bool MatchesNetIdVariant(BedrockServer::Extension::ItemStack^ _0);

        bool SameItemAndAuxAndBlockData(BedrockServer::Extension::ItemStack^ _0);

        void ServerInitNetId();

        void UseAsFuel();

        static property BedrockServer::Extension::ItemStack^ EMPTY_ITEM {
            BedrockServer::Extension::ItemStack^ get();
        }
#endif // INCLUDE_MCAPI
    };
} // namespace BedrockServer::Extension
