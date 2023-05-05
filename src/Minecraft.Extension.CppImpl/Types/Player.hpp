#pragma once
#include <mc/Player.hpp>
#include "Mob.hpp"
#include <mc/MobEffect.hpp>

namespace BedrockServer::Extension::Handle
{
    ref class AttributeHandle;
    ref class NetworkIdentifierHandle;
    ref class CertificateHandle;
    ref struct ScorePacketInfoHandle;
    ref class MobHandle;
    ref class ContainerHandle;
    ref class ItemStackHandle;
    ref class CompoundTagHandle;
    ref class PacketHandle;
    ref class SerializedSkinHandle;
} // namespace BedrockServer::Extension::Handle

namespace BedrockServer::Extension::Handle
{
    public ref class PlayerHandle : MobHandle
    {
        DEFAULT_DEF_OVERRIDE(PlayerHandle, ::Player, MobHandle)
    public:

        enum class PositionMode : char
        {
            NORMAL,
            RESPAWN,
            TELEPORT,
            HEAD_ROTATION,
        };

        property String^ Name { String^ get(); };
        property String^ RealName { String^ get(); };
        property String^ Uuid { String^ get(); };
        property String^ Xuid { String^ get(); };
        property String^ IP { String^ get(); };
        property String^ LanguageCode { String^ get(); };
        property String^ ServerAddress { String^ get(); };
        property NetworkIdentifierHandle^ NetworkIdentifierHandle { BedrockServer::Extension::Handle::NetworkIdentifierHandle^ get(); };
        property CertificateHandle^ CertificateHandle { BedrockServer::Extension::Handle::CertificateHandle^ get(); };
        property ContainerHandle^ EnderChestContainer { ContainerHandle^ get(); };
        property SerializedSkinHandle^ Skin { SerializedSkinHandle^ get(); }

        property unsigned char ClientSubId
        {
            unsigned char get();
        };
        property String^ DeviceTypeName { String^ get(); };
        property int AvgPing
        {
            int get();
        }
        property int LastPing
        {
            int get();
        }
        property System::ValueTuple<BedrockServer::BlockPos, int> RespawnPosition
        {
            System::ValueTuple<BedrockServer::BlockPos, int> get();
        };
        property float AvgPacketLoss
        {
            float get();
        }
        property String^ ClientId { String^ get(); };
        property int DeviceType
        {
            int get();
        }
        property bool IsOP
        {
            bool get();
        }

        property int CurrentExperience
        {
            int get();
            void set(int value);
        }

        property size_t TotalExperience
        {
            size_t get();
            void set(size_t value);
        }

        bool ReduceExperience(size_t exp);

        /// <summary>
        /// Experience required to upgrade to level from (level-1)
        /// </summary>
        static int GetXpNeededForLevel(int level);

        /// <summary>
        /// Experience required to upgrade to level from level 0
        /// </summary>
        static size_t GetTotalXpNeededForLevel(int level);

        inline bool Kick(String^ msg);
        inline bool CrashClient();
        /// <param name="type">:default = TextType::RAW</param>
        inline bool SendText(String^ text, TextType type);
        inline bool SendText(String^ text);

        inline bool TalkAs(String^ msg);
        inline bool GiveItem(ItemStackHandle^ item);
        inline int ClearItem(String^ typeName, unsigned int clearCount);
        inline bool Runcmd(String^ cmd);
        inline bool TransferServer(String^ address, unsigned short port);
        inline bool SetSidebar(String^ title, System::Collections::Generic::IList<System::ValueTuple<String^, int>>^ data, ObjectiveSortOrder sortOrder);
        inline bool RemoveSidebar();
        inline CompoundTagHandle^ GetNbt();
        inline bool SetNbt(CompoundTagHandle^ nbt);
        inline bool RefreshAttribute(BedrockServer::Extension::Handle::AttributeHandle^ attribute);
        inline bool RefreshAttributes(System::Collections::Generic::IList<BedrockServer::Extension::Handle::AttributeHandle^>^ attributes);

        inline int GetScore(String^ key);
        inline bool SetScore(String^ key, int value);
        inline bool AddScore(String^ key, int value);
        inline bool ReduceScore(String^ key, int value);
        inline bool DeleteScore(String^ key);
        // PacketEX
        inline void SendNetworkPacket(PacketHandle^ packet);
        /// <param name="Type">:default = TextType::RAW</param>
        inline bool SendTextPacket(String^ text, TextType Type);
        inline bool SendTitlePacket(String^ text, TitleType Type, int FadeInDuration, int RemainDuration,
            int FadeOutDuration);
        inline bool SendNotePacket(unsigned int tone);
        /// <param name="EntityUniqueID">:default = -1</param>
        inline bool SendSpawnParticleEffectPacket(Vec3 spawnPos, int dimid, String^ ParticleName,
            int64_t EntityUniqueID);
        /*bad*/
        inline bool SendPlaySoundPacket(String^ SoundName, Vec3 Position, float Volume, float Pitch);


        inline bool SendTransferPacket(String^ address, short port);
        inline bool SendSetDisplayObjectivePacket(String^ title, String^ name, char sortOrder);
        inline bool SendSetScorePacket(char type, System::Collections::Generic::IList<ScorePacketInfoHandle^>^ data);
        /// <param name="overlay">:default = 0</param>
        inline bool SendBossEventPacket(BossEvent type, String^ name, float percent, BossEventColour colour,
            int overlay);
        inline bool SendCommandRequestPacket(String^ cmd);
        inline bool SendTextTalkPacket(String^ msg);

        inline bool SendRawFormPacket(unsigned formId, String^ data);
        inline bool SendToastPacket(String^ title, String^ msg);
        delegate void callBackFunc_int(int);
        inline bool SendSimpleFormPacket(String^ title, String^ content, System::Collections::Generic::IList<String^>^ buttons, System::Collections::Generic::IList<String^>^ images,
            callBackFunc_int^ callback);
        delegate void callBackFunc_bool(bool);
        inline bool SendModalFormPacket(String^ title, String^ content, String^ button1, String^ button2,
            callBackFunc_bool^ callback);
        delegate void callBackFunc_String(std::string);
        inline bool SendCustomFormPacket(
            String^ data,
            callBackFunc_String^ callback);

        inline static bool IsValid(PlayerHandle^ player);
        delegate void ModalForm_callback(bool);
        delegate void SimpleForm_callback(int);
        delegate void CustomForm_callback(String^);


    private:
    public:
        bool SendModalForm(String^ title,
            String^ content,
            String^ button1,
            String^ button2,
            ModalForm_callback^ callback);

        bool SendSimpleForm(String^ title,
            String^ content,
            System::Collections::Generic::IList<String^>^ buttons,
            System::Collections::Generic::IList<String^>^ images,
            SimpleForm_callback^ callback);

    private:
        inline void CustomForm_Func(std::string str);
        delegate void dgCustomForm_Func(std::string);
        CustomForm_callback^ __func;

    public:
        bool SendCustomForm(String^ json, CustomForm_callback^ callback);

        enum class GameType
        {
            Survival = 0,
            Creative = 1,
            Adventure = 2,
        };

        virtual property GameType GameMode
        {
            GameType get();
            void set(GameType);
        }
    };
} // namespace BedrockServer::Extension::Handle
