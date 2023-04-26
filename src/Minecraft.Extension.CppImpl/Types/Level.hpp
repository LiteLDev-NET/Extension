#pragma once
#include <mc/Level.hpp>
#include "Types.hpp"

namespace BedrockServer
{
    value class BlockInstance;
}

namespace BedrockServer::Extension
{
    ref class MapItemSavedData;
    ref class BlockPalette;
    ref class ActorDamageSource;
    ref class Packet;
    ref class ItemStack;
    ref class Block;
    ref class BlockSource;
    ref class BlockActor;
    ref class CompoundTag;
    ref class Container;
    ref class Dimension;
    ref class Player;
    ref class Actor;
} // namespace BedrockServer::Extension

namespace BedrockServer::Extension
{
    public ref class Level : SafeHandle , ICppClass
    {
        DEFAULT_DEF(Level, ::Level)
    public:
        delegate bool Callback(Player^);

    private:
        // inline static void forEachPlayer(Callback^ callback);
        delegate bool NativeCallback(::Player&);
        typedef bool (*pNativeCallback)(::Player&);
        static Callback^ _callback = nullptr;
        inline static bool CallbackFn(::Player& p);
        static List<GCHandle>^ gchList = nullptr;

    public:
        inline /*static*/ void ForEachPlayer(Callback^ callback);
        inline static array<Player^>^ GetAllPlayers();
        inline static void* __GetAllPlayers();
        /// name or xuid
        inline /*static*/ Player^ GetPlayer(String^ info);
        /// UniqueID
        inline /*static*/ Player^ GetPlayer(ActorUniqueID id);
        inline static Actor^ GetEntity(ActorUniqueID id);
        inline Actor^ GetRuntimeEntity(ActorRuntimeID id, bool _);
        inline Player^ GetRuntimePlayer(ActorRuntimeID id);
        inline static array<Actor^>^ GetAllEntities(int dimId);
        inline static array<Actor^>^ GetAllEntities();
        inline static Actor^ SpawnMob(Vec3 pos, int dimId, String^ typeName);
        inline static Actor^ SpawnItem(Vec3 pos, int dimId, ItemStack^ item);
        inline static bool CreateExplosion(Vec3 pos, int dimId, Actor^ source, float radius, bool createFire, bool canBreak, float maxResistance);
        inline static bool CreateExplosion(Vec3 pos, int dimId, Actor^ source, float radius, bool createFire, bool canBreak);
        inline /*static*/ BedrockServer::Extension::MapItemSavedData^ GetMapSavedData(ActorUniqueID^ a0);
        inline static Actor^ CloneMob(Vec3 pos, int dimid, Actor^ ac);

        // Block
        inline static Block^ GetBlock(BlockPos pos, int dimId);
        inline static Block^ GetBlock(BlockPos pos, BlockSource^ blockSource);
        inline static Block^ GetBlockEx(BlockPos pos, int dimId);
        inline static BedrockServer::BlockInstance GetBlockInstance(BedrockServer::BlockPos pos, int dimId);
        inline static BedrockServer::BlockInstance GetBlockInstance(BedrockServer::BlockPos pos, BlockSource^ blockSource);
        inline static BlockActor^ GetBlockEntity(BlockPos pos, int dimId);
        inline static BlockActor^ GetBlockEntity(BlockPos pos, BlockSource^ blockSource);
        inline static bool SetBlock(BlockPos pos, int dim, Block^ block);
        inline static bool SetBlock(BlockPos pos, int dim, String^ name, unsigned short tileData);
        inline static bool SetBlock(BlockPos pos, int dim, CompoundTag^ nbt);
        inline static bool BreakBlockNaturally(BlockSource^ bs, BlockPos pos);
        inline static bool BreakBlockNaturally(BlockSource^ bs, BlockPos pos, ItemStack^ tool);
        inline /*static*/ bool DestroyBlock(BlockSource^ bs, BlockPos pos, bool a2);
        inline /*static*/ void SpawnParticleEffect(String^ type, Vec3 pos, Dimension^ a2);
        //inline static void SpawnParticleEffect(String ^ type, Actor ^ a1, Vec3 a2);
        inline static bool HasContainer(Vec3 pos, int dim);
        inline static Container^ GetContainer(Vec3 pos, int dim);

        // Item
        inline static ItemStack^ GetItemStackFromId(short itemId, int aux);
        inline static ItemStack^ GetItemStackFromId(short a2);

        // Helper
        inline static BlockSource^ GetBlockSource(int dimid);
        inline static BlockSource^ GetBlockSource(Actor^ actor);
        inline /*static*/ BlockPalette^ GetBlockPalette();
        //inline /*static*/ Dimension ^ GetDimension(AutomaticID<Dimension ^, int> ^ a0);
        inline static Actor^ GetDamageSourceEntity(ActorDamageSource^ ads);
        inline static void BroadcastText(String^ text, TextType type);
        inline static void BroadcastTitle(String^ text, TitleType Type, int FadeInDuration, int RemainDuration, int FadeOutDuration);
        inline static void SendPacketForAllPlayers(Packet^ pkt);


        ref class ServerCommandOrigin : SafeHandle , ICppClass
        {
            DEFAULT_DEF(ServerCommandOrigin, ::Level::ServerCommandOrigin)
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
        inline static bool RuncmdAs(Player^ pl, String^ cmd);
        inline static System::ValueTuple<bool, String^> RuncmdEx(String^ cmd);
        inline static bool Runcmd(String^ cmd);
    };
} // namespace BedrockServer::Extension