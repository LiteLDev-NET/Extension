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

namespace BedrockServer::Extension::Handle
{
    inline bool LevelHandle::CallbackFn(::Player& p)
    {
        return _callback(gcnew PlayerHandle(&p));
    }
    inline void LevelHandle::ForEachPlayer(Callback^ callback)
    {
        if (callback == nullptr)
            throw gcnew System::ArgumentNullException;
        if (gchList == nullptr)
            gchList = gcnew List<GCHandle>;

        _callback = callback;

        auto deFn = gcnew NativeCallback(&LevelHandle::CallbackFn);

        gchList->Add(GCHandle::Alloc(deFn));

        auto pFn = static_cast<pNativeCallback>(
            Marshal::GetFunctionPointerForDelegate(_callback).ToPointer());

        NativePtr->forEachPlayer(pFn);
    }
    inline array<PlayerHandle^>^ LevelHandle::GetAllPlayers()
    {
        auto& stdvector = ::Level::getAllPlayers();
        auto ret = gcnew array<PlayerHandle^>(int(stdvector.size()));
        for (int i = 0; i < stdvector.size(); i++)
            ret[i] = gcnew PlayerHandle(stdvector[i]);
        return ret;
    }

    inline void* LevelHandle::__GetAllPlayers()
    {
        auto ret = new std::vector<::Player*>(std::move(::Level::getAllPlayers()));
        Console::WriteLine((uintptr_t)static_cast<void*>((*ret)[0]));

        Console::WriteLine(marshalString(((*ret)[0])->getRealName()));
        return ret;
    }
    inline PlayerHandle^ LevelHandle::GetPlayer(String^ info)
    {
        return gcnew PlayerHandle(NativePtr->getPlayer(marshalString(info)));
    }
    inline PlayerHandle^ LevelHandle::GetPlayer(ActorUniqueID id)
    {
        const auto player = NativePtr->getPlayer(*(::ActorUniqueID*)&id);
        return player != nullptr ? gcnew PlayerHandle(player) : nullptr;
    }
    inline ActorHandle^ LevelHandle::GetEntity(ActorUniqueID id)
    {
        const auto entity = ::Level::getEntity(*(::ActorUniqueID*)&id);
        return entity != nullptr ? gcnew ActorHandle(entity) : nullptr;
    }
    inline ActorHandle^ LevelHandle::GetRuntimeEntity(ActorRuntimeID id, bool _)
    {
        const auto entity = NativePtr->getRuntimeEntity(*(::ActorRuntimeID*)&id, _);
        return entity != nullptr ? gcnew ActorHandle(entity) : nullptr;
    }
    inline PlayerHandle^ LevelHandle::GetRuntimePlayer(ActorRuntimeID id)
    {
        const auto player = NativePtr->getRuntimePlayer(*(::ActorRuntimeID*)&id);
        return player != nullptr ? gcnew PlayerHandle(player) : nullptr;
    }
    inline array<ActorHandle^>^ LevelHandle::GetAllEntities(int dimId)
    {
        auto& stdvector = ::Level::getAllEntities(dimId);
        auto ret = gcnew array<ActorHandle^>(int(stdvector.size()));
        for (int i = 0; i < stdvector.size(); i++)
            ret[i] = gcnew ActorHandle(stdvector[i]);
        return ret;
    }
    inline array<ActorHandle^>^ LevelHandle::GetAllEntities()
    {
        auto& stdvector = ::Level::getAllEntities();
        auto ret = gcnew array<ActorHandle^>(int(stdvector.size()));
        for (int i = 0; i < stdvector.size(); i++)
            ret[i] = gcnew ActorHandle(stdvector[i]);
        return ret;
    }
    inline ActorHandle^ LevelHandle::SpawnMob(Vec3 pos, int dimId, String^ typeName)
    {
        return gcnew ActorHandle(::Level::spawnMob(
            *(::Vec3*)&pos, dimId, marshalString(typeName)));
    }
    inline ActorHandle^ LevelHandle::SpawnItem(Vec3 pos, int dimId, ItemStackHandle^ item)
    {
        return gcnew ActorHandle(::Level::spawnItem(
            *(::Vec3*)&pos, dimId, item->NativePtr));
    }
    inline bool LevelHandle::CreateExplosion(Vec3 pos, int dimId, ActorHandle^ source, float radius, bool createFire, bool canBreak, float maxResistance)
    {
        return ::Level::createExplosion(*(::Vec3*)&pos, dimId, source, radius, createFire, canBreak, maxResistance);
    }
    inline bool LevelHandle::CreateExplosion(Vec3 pos, int dimId, ActorHandle^ source, float radius, bool createFire, bool canBreak)
    {
        return ::Level::createExplosion(*(::Vec3*)&pos, dimId, source, radius, createFire, canBreak);
    }
    inline MapItemSavedDataHandle^ LevelHandle::GetMapSavedData(ActorUniqueID^ id)
    {
        const auto data = NativePtr->getMapSavedData(*id);
        return data != nullptr ? gcnew MapItemSavedDataHandle(data) : nullptr;
    }
    inline ActorHandle^ LevelHandle::CloneMob(Vec3 pos, int dimid, ActorHandle^ ac)
    {
        return gcnew ActorHandle(::Level::cloneMob(*(::Vec3*)&pos, dimid, ac->NativePtr));
    }
    inline BlockHandle^ LevelHandle::GetBlock(BlockPos pos, int dimId)
    {
        return gcnew BlockHandle(::Level::getBlock(*(::Vec3*)&pos, dimId));
    }
    inline BlockHandle^ LevelHandle::GetBlock(BlockPos pos, BlockSourceHandle^ blockSource)
    {
        return gcnew BlockHandle(::Level::getBlock(*(::Vec3*)&pos, blockSource));
    }
    inline BlockHandle^ LevelHandle::GetBlockEx(BlockPos pos, int dimId)
    {
        return gcnew BlockHandle(::Level::getBlockEx(*(::BlockPos*)&pos, dimId));
    }
    inline BedrockServer::BlockInstance LevelHandle::GetBlockInstance(BedrockServer::BlockPos pos, int dimId)
    {
        return *(BlockInstance*)&::Level::getBlockInstance(*(::BlockPos*)&pos, dimId);
    }
    inline BedrockServer::BlockInstance LevelHandle::GetBlockInstance(BedrockServer::BlockPos pos, BlockSourceHandle^ blockSource)
    {
        return *(BlockInstance*)&::Level::getBlockInstance(*(::BlockPos*)&pos, blockSource);
    }
    inline BlockActorHandle^ LevelHandle::GetBlockEntity(BlockPos pos, int dimId)
    {
        return gcnew BlockActorHandle(::Level::getBlockEntity(*(::BlockPos*)&pos, dimId));
    }
    inline BlockActorHandle^ LevelHandle::GetBlockEntity(BlockPos pos, BlockSourceHandle^ blockSource)
    {
        return gcnew BlockActorHandle(::Level::getBlockEntity(*(::BlockPos*)&pos, blockSource));
    }
    inline bool LevelHandle::SetBlock(BlockPos pos, int dim, BlockHandle^ block)
    {
        return ::Level::setBlock(*(::BlockPos*)&pos, dim, block);
    }
    inline bool LevelHandle::SetBlock(BlockPos pos, int dim, String^ name, unsigned short tileData)
    {
        return ::Level::setBlock(*(::BlockPos*)&pos, dim, marshalString(name), tileData);
    }
    inline bool LevelHandle::SetBlock(BlockPos pos, int dim, CompoundTagHandle^ nbt)
    {
        return ::Level::setBlock(*(::BlockPos*)&pos, dim, nbt->NativePtr);
    }
    inline bool LevelHandle::BreakBlockNaturally(BlockSourceHandle^ bs, BlockPos pos)
    {
        return ::Level::breakBlockNaturally(bs, *(::BlockPos*)&pos);
    }
    inline bool LevelHandle::BreakBlockNaturally(BlockSourceHandle^ bs, BlockPos pos, ItemStackHandle^ tool)
    {
        return ::Level::breakBlockNaturally(bs->NativePtr, *(::BlockPos*)&pos, tool->NativePtr);
    }
    inline bool LevelHandle::DestroyBlock(BlockSourceHandle^ bs, BlockPos pos, bool a2)
    {
        return NativePtr->destroyBlock(*bs->NativePtr, *(::BlockPos*)&pos, a2);
    }
    inline void LevelHandle::SpawnParticleEffect(String^ type, Vec3 pos, DimensionHandle^ a2)
    {
        NativePtr->spawnParticleEffect(marshalString(type), *(::Vec3*)&pos, a2->NativePtr);
    }
    //inline void Level::SpawnParticleEffect(String^ type, Actor ^ a1, Vec3 a2)
    //{
    //    ::Level::spawnParticleEffect(marshalString(type), *a1->NativePtr, a2);
    //}
    inline bool LevelHandle::HasContainer(Vec3 pos, int dim)
    {
        return ::Level::hasContainer(*(::Vec3*)&pos, dim);
    }
    inline ContainerHandle^ LevelHandle::GetContainer(Vec3 pos, int dim)
    {
        return gcnew ContainerHandle(::Level::getContainer(*(::Vec3*)&pos, dim));
    }
    inline ItemStackHandle^ LevelHandle::GetItemStackFromId(short itemId, int aux)
    {
        return gcnew ItemStackHandle(::Level::getItemStackFromId(itemId, aux));
    }
    inline ItemStackHandle^ LevelHandle::GetItemStackFromId(short itemId)
    {
        return gcnew ItemStackHandle(::Level::getItemStackFromId(itemId));
    }
    inline BlockSourceHandle^ LevelHandle::GetBlockSource(int dimid)
    {
        return gcnew BlockSourceHandle(::Level::getBlockSource(dimid));
    }
    inline BlockSourceHandle^ LevelHandle::GetBlockSource(ActorHandle^ actor)
    {
        return gcnew BlockSourceHandle(::Level::getBlockSource(actor));
    }
    inline BlockPaletteHandle^ LevelHandle::GetBlockPalette()
    {
        return gcnew BlockPaletteHandle(&NativePtr->getBlockPalette());
    }
    /*inline Dimension^ Level::GetDimension(AutomaticID<Dimension^, int>^ a0)
    {
        return gcnew Dimension(NativePtr->getDimension((int)a0));
    }*/
    inline ActorHandle^ LevelHandle::GetDamageSourceEntity(ActorDamageSourceHandle^ ads)
    {
        return gcnew ActorHandle(::Level::getDamageSourceEntity(ads));
    }
    inline void LevelHandle::BroadcastText(String^ text, TextType type)
    {
        ::Level::broadcastText(marshalString(text), ::TextType(type));
    }
    inline void LevelHandle::BroadcastTitle(String^ text, TitleType Type, int FadeInDuration, int RemainDuration, int FadeOutDuration)
    {
        ::Level::broadcastTitle(marshalString(text), ::TitleType(Type), FadeInDuration, RemainDuration, FadeOutDuration);
    }
    inline void LevelHandle::SendPacketForAllPlayers(PacketHandle^ pkt)
    {
        ::Level::sendPacketForAllPlayers(*pkt->NativePtr);
    }
    inline bool LevelHandle::RuncmdAs(PlayerHandle^ pl, String^ cmd)
    {
        return ::Level::runcmdAs(pl->NativePtr, marshalString(cmd));
    }
    inline System::ValueTuple<bool, String^> LevelHandle::RuncmdEx(String^ cmd)
    {
        auto& kvpair = ::Level::runcmdEx(marshalString(cmd));
        return System::ValueTuple<bool, String^>(kvpair.first, marshalString(kvpair.second));
    }
    inline bool LevelHandle::Runcmd(String^ cmd)
    {
        return ::Level::runcmd(marshalString(cmd));
    }
} // namespace BedrockServer::Extension::Handle
