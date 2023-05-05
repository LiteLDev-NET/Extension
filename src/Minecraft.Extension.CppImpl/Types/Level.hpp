#pragma once
#include <mc/Level.hpp>
#include "Types.hpp"

namespace BedrockServer
{
    value class BlockInstance;
}

namespace BedrockServer::Extension::Handle
{
    ref class MapItemSavedDataHandle;
    ref class BlockPaletteHandle;
    ref class ActorDamageSourceHandle;
    ref class PacketHandle;
    ref class ItemStackHandle;
    ref class BlockHandle;
    ref class BlockSourceHandle;
    ref class BlockActorHandle;
    ref class CompoundTagHandle;
    ref class ContainerHandle;
    ref class DimensionHandle;
    ref class PlayerHandle;
    ref class ActorHandle;
} // namespace BedrockServer::Extension::Handle

namespace BedrockServer::Extension::Handle
{
    public ref class LevelHandle : SafeHandle , ICppClass
    {
        DEFAULT_DEF(LevelHandle, ::Level)
    public:
        delegate bool Callback(PlayerHandle^);

    private:
        // inline static void forEachPlayer(Callback^ callback);
        delegate bool NativeCallback(::Player&);
        typedef bool (*pNativeCallback)(::Player&);
        static Callback^ _callback = nullptr;
        inline static bool CallbackFn(::Player& p);
        static List<GCHandle>^ gchList = nullptr;

    public:
        inline /*static*/ void ForEachPlayer(Callback^ callback);
        inline static array<PlayerHandle^>^ GetAllPlayers();
        inline static void* __GetAllPlayers();
        /// name or xuid
        inline /*static*/ PlayerHandle^ GetPlayer(String^ info);
        /// UniqueID
        inline /*static*/ PlayerHandle^ GetPlayer(ActorUniqueID id);
        inline static ActorHandle^ GetEntity(ActorUniqueID id);
        inline ActorHandle^ GetRuntimeEntity(ActorRuntimeID id, bool _);
        inline PlayerHandle^ GetRuntimePlayer(ActorRuntimeID id);
        inline static array<ActorHandle^>^ GetAllEntities(int dimId);
        inline static array<ActorHandle^>^ GetAllEntities();
        inline static ActorHandle^ SpawnMob(Vec3 pos, int dimId, String^ typeName);
        inline static ActorHandle^ SpawnItem(Vec3 pos, int dimId, ItemStackHandle^ item);
        inline static bool CreateExplosion(Vec3 pos, int dimId, ActorHandle^ source, float radius, bool createFire, bool canBreak, float maxResistance);
        inline static bool CreateExplosion(Vec3 pos, int dimId, ActorHandle^ source, float radius, bool createFire, bool canBreak);
        inline /*static*/ BedrockServer::Extension::Handle::MapItemSavedDataHandle^ GetMapSavedData(ActorUniqueID^ a0);
        inline static ActorHandle^ CloneMob(Vec3 pos, int dimid, ActorHandle^ ac);

        // Block
        inline static BlockHandle^ GetBlock(BlockPos pos, int dimId);
        inline static BlockHandle^ GetBlock(BlockPos pos, BlockSourceHandle^ blockSource);
        inline static BlockHandle^ GetBlockEx(BlockPos pos, int dimId);
        inline static BedrockServer::BlockInstance GetBlockInstance(BedrockServer::BlockPos pos, int dimId);
        inline static BedrockServer::BlockInstance GetBlockInstance(BedrockServer::BlockPos pos, BlockSourceHandle^ blockSource);
        inline static BlockActorHandle^ GetBlockEntity(BlockPos pos, int dimId);
        inline static BlockActorHandle^ GetBlockEntity(BlockPos pos, BlockSourceHandle^ blockSource);
        inline static bool SetBlock(BlockPos pos, int dim, BlockHandle^ block);
        inline static bool SetBlock(BlockPos pos, int dim, String^ name, unsigned short tileData);
        inline static bool SetBlock(BlockPos pos, int dim, CompoundTagHandle^ nbt);
        inline static bool BreakBlockNaturally(BlockSourceHandle^ bs, BlockPos pos);
        inline static bool BreakBlockNaturally(BlockSourceHandle^ bs, BlockPos pos, ItemStackHandle^ tool);
        inline /*static*/ bool DestroyBlock(BlockSourceHandle^ bs, BlockPos pos, bool a2);
        inline /*static*/ void SpawnParticleEffect(String^ type, Vec3 pos, DimensionHandle^ a2);
        //inline static void SpawnParticleEffect(String ^ type, Actor ^ a1, Vec3 a2);
        inline static bool HasContainer(Vec3 pos, int dim);
        inline static ContainerHandle^ GetContainer(Vec3 pos, int dim);

        // Item
        inline static ItemStackHandle^ GetItemStackFromId(short itemId, int aux);
        inline static ItemStackHandle^ GetItemStackFromId(short a2);

        // Helper
        inline static BlockSourceHandle^ GetBlockSource(int dimid);
        inline static BlockSourceHandle^ GetBlockSource(ActorHandle^ actor);
        inline /*static*/ BlockPaletteHandle^ GetBlockPalette();
        //inline /*static*/ Dimension ^ GetDimension(AutomaticID<Dimension ^, int> ^ a0);
        inline static ActorHandle^ GetDamageSourceEntity(ActorDamageSourceHandle^ ads);
        inline static void BroadcastText(String^ text, TextType type);
        inline static void BroadcastTitle(String^ text, TitleType Type, int FadeInDuration, int RemainDuration, int FadeOutDuration);
        inline static void SendPacketForAllPlayers(PacketHandle^ pkt);


        ref class ServerCommandOriginHandle : SafeHandle , ICppClass
        {
            DEFAULT_DEF(ServerCommandOriginHandle, ::Level::ServerCommandOrigin)
        public:
            property nint_t MyVTBL
            {
                nint_t get()
                {
                    return nint_t(NativePtr->myVTBL);
                };
                void set(nint_t value)
                {
                    NativePtr->myVTBL = value.ToPointer();
                };
            };
            property array<nint_t>^ UUID {
                array<nint_t>^ get() {
                    auto ret = gcnew array<nint_t>(2);
                    ret[0] = nint_t(NativePtr->UUID[0]);
                    ret[1] = nint_t(NativePtr->UUID[1]);
                    return ret;
                };
                void set(array<nint_t>^ value)
                {
                    if (value->Length != 2)
                        throw gcnew System::Exception;
                    NativePtr->UUID[0] = value[0].ToPointer();
                    NativePtr->UUID[1] = value[1].ToPointer();
                }
            };
            property nint_t ServerLevel
            {
                nint_t get()
                {
                    return nint_t(NativePtr->lvl);
                };
                void set(nint_t value)
                {
                    NativePtr->lvl = (::ServerLevel*)value.ToPointer();
                };
            };
            property String^ Name {
                String^ get() {
                    return marshalString(NativePtr->Name);
                };
                void set(String^ value)
                {
                    NativePtr->Name = marshalString(value);
                };
            };
            property unsigned char Perm
            {
                unsigned char get()
                {
                    return NativePtr->Perm;
                }
                void set(unsigned char value)
                {
                    NativePtr->Perm = value;
                }
            }
        };


        // For compatibility
        inline static bool RuncmdAs(PlayerHandle^ pl, String^ cmd);
        inline static System::ValueTuple<bool, String^> RuncmdEx(String^ cmd);
        inline static bool Runcmd(String^ cmd);
    };
} // namespace BedrockServer::Extension::Handle