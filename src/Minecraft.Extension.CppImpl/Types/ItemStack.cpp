#include "../Tools/mutex.hpp"
#include "ItemStack.hpp"
#include <memory>
namespace BedrockServer::Extension
{

    inline ItemStack^ ItemStack::Create()
    {
        return gcnew ItemStack(::ItemStack::create());
    }

    inline ItemStack^ ItemStack::Create(String^ type, int count)
    {
        return gcnew ItemStack(::ItemStack::create(marshalString(type), count), true);
    }

    inline ItemStack^ ItemStack::Create(CompoundTag^ tag)
    {
        return gcnew ItemStack(::ItemStack::create(((::CompoundTag*)tag)->clone()), true);
    }

    inline ItemStack^ ItemStack::Create(short itemId, int aux)
    {
        return gcnew ItemStack(::ItemStack::create(itemId, aux), true);
    }

    inline ItemStack^ ItemStack::Create(short itemId, int aux, int count)
    {
        return gcnew ItemStack(::ItemStack::create(itemId, aux, count), true);
    }

    inline ItemStack^ ItemStack::FromItemInstance(ItemInstance^ ins)
    {
        return gcnew ItemStack(&::ItemStack::fromItemInstance(*ins->NativePtr), true);
    }

    inline ItemStack^ ItemStack::Clone_s()
    {
        return gcnew ItemStack(NativePtr->clone_s());
    }

    inline String^ ItemStack::TypeName::get()
    {
        return marshalString(NativePtr->getTypeName());
    }

    inline int ItemStack::Aux::get()
    {
        return NativePtr->getAux();
    }

    inline int ItemStack::Count::get()
    {
        return NativePtr->getCount();
    }

    inline bool ItemStack::SetItem(ItemStack^ newItem)
    {
        return NativePtr->setItem(newItem->NativePtr);
    }

    bool ItemStack::SetLore(array<String^>^ lores)
    {
        std::vector<std::string> stdlores;
        for (int i = 0; i < lores->Length; ++i)
        {
            auto str = lores[i];
            stdlores.emplace_back(marshalString((str)));
        }
        return NativePtr->setLore(stdlores);
    }

    inline CompoundTag^ ItemStack::GetNbt()
    {
        return gcnew CompoundTag(NativePtr->getNbt().release(), true);
    }

    inline bool ItemStack::SetNbt(CompoundTag^ nbt)
    {
        return NativePtr->setNbt(nbt->NativePtr);
    }
} // namespace BedrockServer::Extension
