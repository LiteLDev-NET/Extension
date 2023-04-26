#include "Level.hpp"

#include "Player.hpp"
#include "ItemStack.hpp"
#include "MapItemSavedData.hpp"
#include "Block.hpp"
#include "BlockSource.hpp"
#include "BlockInstance.hpp"
#include "BlockActor.hpp"
#include "Dimension.hpp"
#include "Container.hpp"
#include "BlockPalette.hpp"
#include "ActorDamageSource.hpp"
#include "Packet.hpp"

namespace BedrockServer::Extension
{
    inline bool Level::CallbackFn(::Player& p)
    {
        return _callback(gcnew Player(&p));
    }
    inline void Level::ForEachPlayer(Callback^ callback)
    {
        if (callback == nullptr)
            throw gcnew System::ArgumentNullException;
        if (gchList == nullptr)
            gchList = gcnew List<GCHandle>;

        _callback = callback;

        auto deFn = gcnew NativeCallback(&Level::CallbackFn);

        gchList->Add(GCHandle::Alloc(deFn));

        auto pFn = static_cast<pNativeCallback>(
            Marshal::GetFunctionPointerForDelegate(_callback).ToPointer());

        NativePtr->forEachPlayer(pFn);
    }
    inline array<Player^>^ Level::GetAllPlayers()
    {
        auto& stdvector = ::Level::getAllPlayers();
        auto ret = gcnew array<Player^>(int(stdvector.size()));
        for (int i = 0; i < stdvector.size(); i++)
            ret[i] = gcnew Player(stdvector[i]);
        return ret;
    }

    inline void* Level::__GetAllPlayers()
    {
        auto ret = new std::vector<::Player*>(std::move(::Level::getAllPlayers()));
        Console::WriteLine((uintptr_t)static_cast<void*>((*ret)[0]));

        Console::WriteLine(marshalString(((*ret)[0])->getRealName()));
        return ret;
    }
    inline Player^ Level::GetPlayer(String^ info)
    {
        return gcnew Player(NativePtr->getPlayer(marshalString(info)));
    }
    inline Player^ Level::GetPlayer(ActorUniqueID id)
    {
        const auto player = NativePtr->getPlayer(*(::ActorUniqueID*)&id);
        return player != nullptr ? gcnew Player(player) : nullptr;
    }
    inline Actor^ Level::GetEntity(ActorUniqueID id)
    {
        const auto entity = ::Level::getEntity(*(::ActorUniqueID*)&id);
        return entity != nullptr ? gcnew Actor(entity) : nullptr;
    }
    inline Actor^ Level::GetRuntimeEntity(ActorRuntimeID id, bool _)
    {
        const auto entity = NativePtr->getRuntimeEntity(*(::ActorRuntimeID*)&id, _);
        return entity != nullptr ? gcnew Actor(entity) : nullptr;
    }
    inline Player^ Level::GetRuntimePlayer(ActorRuntimeID id)
    {
        const auto player = NativePtr->getRuntimePlayer(*(::ActorRuntimeID*)&id);
        return player != nullptr ? gcnew Player(player) : nullptr;
    }
    inline array<Actor^>^ Level::GetAllEntities(int dimId)
    {
        auto& stdvector = ::Level::getAllEntities(dimId);
        auto ret = gcnew array<Actor^>(int(stdvector.size()));
        for (int i = 0; i < stdvector.size(); i++)
            ret[i] = gcnew Actor(stdvector[i]);
        return ret;
    }
    inline array<Actor^>^ Level::GetAllEntities()
    {
        auto& stdvector = ::Level::getAllEntities();
        auto ret = gcnew array<Actor^>(int(stdvector.size()));
        for (int i = 0; i < stdvector.size(); i++)
            ret[i] = gcnew Actor(stdvector[i]);
        return ret;
    }
    inline Actor^ Level::SpawnMob(Vec3 pos, int dimId, String^ typeName)
    {
        return gcnew Actor(::Level::spawnMob(
            *(::Vec3*)&pos, dimId, marshalString(typeName)));
    }
    inline Actor^ Level::SpawnItem(Vec3 pos, int dimId, ItemStack^ item)
    {
        return gcnew Actor(::Level::spawnItem(
            *(::Vec3*)&pos, dimId, item->NativePtr));
    }
    inline bool Level::CreateExplosion(Vec3 pos, int dimId, Actor^ source, float radius, bool createFire, bool canBreak, float maxResistance)
    {
        return ::Level::createExplosion(*(::Vec3*)&pos, dimId, source, radius, createFire, canBreak, maxResistance);
    }
    inline bool Level::CreateExplosion(Vec3 pos, int dimId, Actor^ source, float radius, bool createFire, bool canBreak)
    {
        return ::Level::createExplosion(*(::Vec3*)&pos, dimId, source, radius, createFire, canBreak);
    }
    inline MapItemSavedData^ Level::GetMapSavedData(ActorUniqueID^ id)
    {
        const auto data = NativePtr->getMapSavedData(*id);
        return data != nullptr ? gcnew MapItemSavedData(data) : nullptr;
    }
    inline Actor^ Level::CloneMob(Vec3 pos, int dimid, Actor^ ac)
    {
        return gcnew Actor(::Level::cloneMob(*(::Vec3*)&pos, dimid, ac->NativePtr));
    }
    inline Block^ Level::GetBlock(BlockPos pos, int dimId)
    {
        return gcnew Block(::Level::getBlock(*(::Vec3*)&pos, dimId));
    }
    inline Block^ Level::GetBlock(BlockPos pos, BlockSource^ blockSource)
    {
        return gcnew Block(::Level::getBlock(*(::Vec3*)&pos, blockSource));
    }
    inline Block^ Level::GetBlockEx(BlockPos pos, int dimId)
    {
        return gcnew Block(::Level::getBlockEx(*(::BlockPos*)&pos, dimId));
    }
    inline BedrockServer::BlockInstance Level::GetBlockInstance(BedrockServer::BlockPos pos, int dimId)
    {
        return *(BlockInstance*)&::Level::getBlockInstance(*(::BlockPos*)&pos, dimId);
    }
    inline BedrockServer::BlockInstance Level::GetBlockInstance(BedrockServer::BlockPos pos, BlockSource^ blockSource)
    {
        return *(BlockInstance*)&::Level::getBlockInstance(*(::BlockPos*)&pos, blockSource);
    }
    inline BlockActor^ Level::GetBlockEntity(BlockPos pos, int dimId)
    {
        return gcnew BlockActor(::Level::getBlockEntity(*(::BlockPos*)&pos, dimId));
    }
    inline BlockActor^ Level::GetBlockEntity(BlockPos pos, BlockSource^ blockSource)
    {
        return gcnew BlockActor(::Level::getBlockEntity(*(::BlockPos*)&pos, blockSource));
    }
    inline bool Level::SetBlock(BlockPos pos, int dim, Block^ block)
    {
        return ::Level::setBlock(*(::BlockPos*)&pos, dim, block);
    }
    inline bool Level::SetBlock(BlockPos pos, int dim, String^ name, unsigned short tileData)
    {
        return ::Level::setBlock(*(::BlockPos*)&pos, dim, marshalString(name), tileData);
    }
    inline bool Level::SetBlock(BlockPos pos, int dim, CompoundTag^ nbt)
    {
        return ::Level::setBlock(*(::BlockPos*)&pos, dim, nbt->NativePtr);
    }
    inline bool Level::BreakBlockNaturally(BlockSource^ bs, BlockPos pos)
    {
        return ::Level::breakBlockNaturally(bs, *(::BlockPos*)&pos);
    }
    inline bool Level::BreakBlockNaturally(BlockSource^ bs, BlockPos pos, ItemStack^ tool)
    {
        return ::Level::breakBlockNaturally(bs->NativePtr, *(::BlockPos*)&pos, tool->NativePtr);
    }
    inline bool Level::DestroyBlock(BlockSource^ bs, BlockPos pos, bool a2)
    {
        return NativePtr->destroyBlock(*bs->NativePtr, *(::BlockPos*)&pos, a2);
    }
    inline void Level::SpawnParticleEffect(String^ type, Vec3 pos, Dimension^ a2)
    {
        NativePtr->spawnParticleEffect(marshalString(type), *(::Vec3*)&pos, a2->NativePtr);
    }
    //inline void Level::SpawnParticleEffect(String^ type, Actor ^ a1, Vec3 a2)
    //{
    //    ::Level::spawnParticleEffect(marshalString(type), *a1->NativePtr, a2);
    //}
    inline bool Level::HasContainer(Vec3 pos, int dim)
    {
        return ::Level::hasContainer(*(::Vec3*)&pos, dim);
    }
    inline Container^ Level::GetContainer(Vec3 pos, int dim)
    {
        return gcnew Container(::Level::getContainer(*(::Vec3*)&pos, dim));
    }
    inline ItemStack^ Level::GetItemStackFromId(short itemId, int aux)
    {
        return gcnew ItemStack(::Level::getItemStackFromId(itemId, aux));
    }
    inline ItemStack^ Level::GetItemStackFromId(short itemId)
    {
        return gcnew ItemStack(::Level::getItemStackFromId(itemId));
    }
    inline BlockSource^ Level::GetBlockSource(int dimid)
    {
        return gcnew BlockSource(::Level::getBlockSource(dimid));
    }
    inline BlockSource^ Level::GetBlockSource(Actor^ actor)
    {
        return gcnew BlockSource(::Level::getBlockSource(actor));
    }
    inline BlockPalette^ Level::GetBlockPalette()
    {
        return gcnew BlockPalette(&NativePtr->getBlockPalette());
    }
    /*inline Dimension^ Level::GetDimension(AutomaticID<Dimension^, int>^ a0)
    {
        return gcnew Dimension(NativePtr->getDimension((int)a0));
    }*/
    inline Actor^ Level::GetDamageSourceEntity(ActorDamageSource^ ads)
    {
        return gcnew Actor(::Level::getDamageSourceEntity(ads));
    }
    inline void Level::BroadcastText(String^ text, TextType type)
    {
        ::Level::broadcastText(marshalString(text), ::TextType(type));
    }
    inline void Level::BroadcastTitle(String^ text, TitleType Type, int FadeInDuration, int RemainDuration, int FadeOutDuration)
    {
        ::Level::broadcastTitle(marshalString(text), ::TitleType(Type), FadeInDuration, RemainDuration, FadeOutDuration);
    }
    inline void Level::SendPacketForAllPlayers(Packet^ pkt)
    {
        ::Level::sendPacketForAllPlayers(*pkt->NativePtr);
    }
    inline bool Level::RuncmdAs(Player^ pl, String^ cmd)
    {
        return ::Level::runcmdAs(pl->NativePtr, marshalString(cmd));
    }
    inline System::ValueTuple<bool, String^> Level::RuncmdEx(String^ cmd)
    {
        auto& kvpair = ::Level::runcmdEx(marshalString(cmd));
        return System::ValueTuple<bool, String^>(kvpair.first, marshalString(kvpair.second));
    }
    inline bool Level::Runcmd(String^ cmd)
    {
        return ::Level::runcmd(marshalString(cmd));
    }
} // namespace BedrockServer::Extension
