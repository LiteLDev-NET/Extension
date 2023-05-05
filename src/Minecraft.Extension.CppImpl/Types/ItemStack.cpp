#include "../Tools/mutex.hpp"
#include "ItemStack.hpp"
#include <memory>
namespace BedrockServer::Extension::Handle
{

    inline ItemStackHandle^ ItemStackHandle::Create()
    {
        return gcnew ItemStackHandle(::ItemStack::create());
    }

    inline ItemStackHandle^ ItemStackHandle::Create(String^ type, int count)
    {
        return gcnew ItemStackHandle(::ItemStack::create(marshalString(type), count), true);
    }

    inline ItemStackHandle^ ItemStackHandle::Create(CompoundTagHandle^ tag)
    {
        return gcnew ItemStackHandle(::ItemStack::create(tag->NativePtr->clone()), true);
    }

    inline ItemStackHandle^ ItemStackHandle::Create(short itemId, int aux)
    {
        return gcnew ItemStackHandle(::ItemStack::create(itemId, aux), true);
    }

    inline ItemStackHandle^ ItemStackHandle::Create(short itemId, int aux, int count)
    {
        return gcnew ItemStackHandle(::ItemStack::create(itemId, aux, count), true);
    }

    inline ItemStackHandle^ ItemStackHandle::FromItemInstance(ItemInstanceHandle^ ins)
    {
        return gcnew ItemStackHandle(&::ItemStack::fromItemInstance(*ins->NativePtr), true);
    }

    inline ItemStackHandle^ ItemStackHandle::Clone_s()
    {
        return gcnew ItemStackHandle(NativePtr->clone_s());
    }

    inline String^ ItemStackHandle::TypeName::get()
    {
        return marshalString(NativePtr->getTypeName());
    }

    inline int ItemStackHandle::Aux::get()
    {
        return NativePtr->getAux();
    }

    inline int ItemStackHandle::Count::get()
    {
        return NativePtr->getCount();
    }

    inline bool ItemStackHandle::SetItem(ItemStackHandle^ newItem)
    {
        return NativePtr->setItem(newItem->NativePtr);
    }

    bool ItemStackHandle::SetLore(array<String^>^ lores)
    {
        std::vector<std::string> stdlores;
        for (int i = 0; i < lores->Length; ++i)
        {
            auto str = lores[i];
            stdlores.emplace_back(marshalString((str)));
        }
        return NativePtr->setLore(stdlores);
    }

    inline CompoundTagHandle^ ItemStackHandle::GetNbt()
    {
        return gcnew CompoundTagHandle(NativePtr->getNbt().release(), true);
    }

    inline bool ItemStackHandle::SetNbt(CompoundTagHandle^ nbt)
    {
        return NativePtr->setNbt(nbt->NativePtr);
    }
} // namespace BedrockServer::Extension::Handle
