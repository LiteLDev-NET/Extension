#include "Player.hpp"

#include "CompoundTag.hpp"
#include "NetworkIdentifier.hpp"
#include "Certificate.hpp"
#include "Container.hpp"
#include "ScorePacketInfo.hpp"
#include "ItemStack.hpp"
#include "Attribute.hpp"
#include "Tick.hpp"

#include "Packet.hpp"
#include "SerializedSkin.hpp"

#include <Tools/CallbackConverter.hpp>

#pragma unmanaged
#pragma managed


enum class GameType;

namespace BedrockServer::Extension::Handle
{
    inline String^ PlayerHandle::Name::get()
    {
        return marshalString(NativePtr->getName());
    }

    inline String^ PlayerHandle::RealName::get()
    {
        return marshalString(NativePtr->getRealName());
    }

    inline String^ PlayerHandle::Uuid::get()
    {
        return marshalString(NativePtr->getUuid());
    }

    inline String^ PlayerHandle::Xuid::get()
    {
        return marshalString(NativePtr->getXuid());
    }

    inline unsigned char PlayerHandle::ClientSubId::get()
    {
        return NativePtr->getClientSubId();
    }

    inline String^ PlayerHandle::DeviceTypeName::get()
    {
        return marshalString(NativePtr->getDeviceTypeName());
    }

    inline int PlayerHandle::AvgPing::get()
    {
        return NativePtr->getAvgPing();
    }

    inline int PlayerHandle::LastPing::get()
    {
        return NativePtr->getLastPing();
    }

    inline String^ PlayerHandle::IP::get()
    {
        return marshalString(NativePtr->getIP());
    }

    inline String^ PlayerHandle::LanguageCode::get()
    {
        return marshalString(NativePtr->getLanguageCode());
    }

    inline String^ PlayerHandle::ServerAddress::get()
    {
        return marshalString(NativePtr->getServerAddress());
    }

    inline NetworkIdentifierHandle^ PlayerHandle::NetworkIdentifierHandle::get()
    {
        return gcnew BedrockServer::Extension::Handle::NetworkIdentifierHandle(NativePtr->getNetworkIdentifier());
    }

    inline CertificateHandle^ PlayerHandle::CertificateHandle::get()
    {
        return gcnew BedrockServer::Extension::Handle::CertificateHandle(NativePtr->getCertificate());
    }

    inline ContainerHandle^ PlayerHandle::EnderChestContainer::get()
    {
        return gcnew ContainerHandle(NativePtr->getEnderChestContainer());
    }

    inline SerializedSkinHandle^ PlayerHandle::Skin::get()
    {
        return gcnew SerializedSkinHandle(&NativePtr->getSkin());
    }

    inline System::ValueTuple<BlockPos, int> PlayerHandle::RespawnPosition::get()
    {
        auto& p = NativePtr->getRespawnPosition();
        return System::ValueTuple<BedrockServer::BlockPos, int>(
            *(BedrockServer::BlockPos*)&(p.first), p.second);
    }

    inline float PlayerHandle::AvgPacketLoss::get()
    {
        return NativePtr->getAvgPacketLoss();
    }

    inline String^ PlayerHandle::ClientId::get()
    {
        return marshalString(NativePtr->getClientId());
    }

    inline int PlayerHandle::DeviceType::get()
    {
        return NativePtr->getDeviceType();
    }

    inline bool PlayerHandle::IsOP::get()
    {
        return NativePtr->isOP();
    }

    inline int PlayerHandle::CurrentExperience::get()
    {
        return NativePtr->getCurrentExperience();
    }

    inline void PlayerHandle::CurrentExperience::set(int value)
    {
        if (NativePtr->setTotalExperience(value))
            throw gcnew Exception("Failed to set current experience.");
    }

    inline size_t PlayerHandle::TotalExperience::get()
    {
        return NativePtr->getCurrentExperience();
    }

    inline void PlayerHandle::TotalExperience::set(size_t value)
    {
        if (NativePtr->setTotalExperience(value))
            throw gcnew Exception("Failed to set total experience.");
    }

    inline bool PlayerHandle::ReduceExperience(size_t exp) { return NativePtr->reduceExperience(exp); }

    /// <summary>
    /// Experience required to upgrade to level from (level-1)
    /// </summary>

    inline int PlayerHandle::GetXpNeededForLevel(int level) { return ::Player::getXpNeededForLevel(level); }

    /// <summary>
    /// Experience required to upgrade to level from level 0
    /// </summary>

    inline size_t PlayerHandle::GetTotalXpNeededForLevel(int level) { return ::Player::getTotalXpNeededForLevel(level); }

    inline bool PlayerHandle::Kick(String^ msg)
    {
        return NativePtr->kick(marshalString(msg));
    }

    inline bool PlayerHandle::CrashClient()
    {
        return NativePtr->crashClient();
    }

    /// <param name="type">:default = TextType::RAW</param>
    inline bool PlayerHandle::SendText(String^ text, TextType type)
    {
        return NativePtr->sendText(marshalString(text), static_cast<::TextType>(type));
    }

    inline bool PlayerHandle::SendText(String^ text) { return SendText(text, TextType::RAW); }

    inline bool PlayerHandle::TalkAs(String^ msg)
    {
        return NativePtr->talkAs(marshalString(msg));
    }

    inline bool PlayerHandle::GiveItem(ItemStackHandle^ item)
    {
        return NativePtr->giveItem(item->NativePtr);
    }

    inline bool PlayerHandle::GiveItem(String^ typeName, int amount)
    {
        return NativePtr->giveItem(marshalString(typeName), amount);
    }

    inline bool PlayerHandle::GiveItem(ItemStackHandle^ item, int amount)
    {
        return NativePtr->giveItem(item->NativePtr, amount);
    }

    inline int PlayerHandle::ClearItem(String^ typeName, unsigned int clearCount)
    {
        return NativePtr->clearItem(marshalString(typeName), clearCount);
    }

    inline bool PlayerHandle::Runcmd(String^ cmd)
    {
        return NativePtr->runcmd(marshalString(cmd));
    }

    inline bool PlayerHandle::TransferServer(String^ address, unsigned short port)
    {
        return NativePtr->transferServer(marshalString(address), port);
    }

    inline bool PlayerHandle::SetSidebar(String^ title,
        System::Collections::Generic::IList<System::ValueTuple<String^, int>>^ data,
        ObjectiveSortOrder sortOrder)
    {
        auto len = data->Count;
        std::vector<std::pair<std::string, int>> stdvector(len);
        for (int i = 0; i < len; ++i)
            stdvector.emplace_back(std::move(std::pair<std::string, int>(
                marshalString(data[i].Item1), data[i].Item2)));
        return NativePtr->setSidebar(
            marshalString(title), stdvector, static_cast<::ObjectiveSortOrder>(sortOrder));
    }

    inline bool PlayerHandle::RemoveSidebar()
    {
        return NativePtr->removeSidebar();
    }

    inline CompoundTagHandle^ PlayerHandle::GetNbt()
    {
        return gcnew CompoundTagHandle(NativePtr->getNbt().release(), true);
    }

    inline bool PlayerHandle::SetNbt(CompoundTagHandle^ nbt)
    {
        return NativePtr->setNbt(nbt->NativePtr);
    }

    inline bool PlayerHandle::RefreshAttribute(AttributeHandle^ attribute)
    {
        return NativePtr->refreshAttribute(*attribute->NativePtr);
    }

    inline bool PlayerHandle::RefreshAttributes(System::Collections::Generic::IList<AttributeHandle^>^ attributes)
    {
        auto len = attributes->Count;
        std::vector<const ::Attribute*> stdvector(len);
        for (int i = 0; i < len; ++i)
            stdvector[i] = attributes[i];
        return NativePtr->refreshAttributes(stdvector);
    }

    inline int PlayerHandle::GetScore(String^ key)
    {
        return NativePtr->getScore(marshalString(key));
    }

    inline bool PlayerHandle::SetScore(String^ key, int value)
    {
        return NativePtr->setScore(marshalString(key), value);
    }

    inline bool PlayerHandle::AddScore(String^ key, int value)
    {
        return NativePtr->addScore(marshalString(key), value);
    }

    inline bool PlayerHandle::ReduceScore(String^ key, int value)
    {
        return NativePtr->reduceScore(marshalString(key), value);
    }

    inline bool PlayerHandle::DeleteScore(String^ key)
    {
        return NativePtr->deleteScore(marshalString(key));
    }

    // PacketEX

    void PlayerHandle::SendNetworkPacket(PacketHandle^ packet)
    {
        NativePtr->sendNetworkPacket(*packet->NativePtr);
    }

    /// <param name="Type">:default = TextType::RAW</param>
    inline bool PlayerHandle::SendTextPacket(String^ text, TextType Type)
    {
        return NativePtr->sendText(marshalString(text), static_cast<::TextType>(Type));
    }

    inline bool PlayerHandle::SendTitlePacket(String^ text, TitleType Type, int FadeInDuration, int RemainDuration,
        int FadeOutDuration)
    {
        return NativePtr->sendTitlePacket(marshalString(text), static_cast<::TitleType>(Type), FadeInDuration,
            RemainDuration, FadeOutDuration);
    }

    inline bool PlayerHandle::SendNotePacket(unsigned int tone)
    {
        return NativePtr->sendNotePacket(tone);
    }

    /// <param name="EntityUniqueID">:default = -1</param>
    inline bool PlayerHandle::SendSpawnParticleEffectPacket(Vec3 spawnPos, int dimid, String^ ParticleName,
        int64_t EntityUniqueID)
    {
        return NativePtr->sendSpawnParticleEffectPacket(*(::Vec3*)&spawnPos, dimid, marshalString(ParticleName), EntityUniqueID);
    }

    /*bad*/
    inline bool PlayerHandle::SendPlaySoundPacket(String^ SoundName, Vec3 Position, float Volume, float Pitch)
    {
        return NativePtr->sendPlaySoundPacket(marshalString(SoundName), *(::Vec3*)&Position, Volume, Pitch);
    }

    ///// <param name="DataItem">:default = {} (using null to substitute it.)</param>
    // inline bool Player::sendAddItemEntityPacket(unsigned long long runtimeID, int itemID, int stackSize, short aux, Vec3 pos, List<csFakeDataItem^>^ DataItem) {
    //    if (DataItem == nullptr) {
    //        return NativePtr->sendAddItemEntityPacket(runtimeID, itemID, stackSize, aux, *pos->Translate());
    //    }
    //    auto len = DataItem->Count;
    //    vector<FakeDataItem> stdvector = {};
    //    for (int i = 0; i < len; i++)
    //        stdvector.emplace_back(*DataItem[i]->Translate());
    //    return NativePtr->sendAddItemEntityPacket(runtimeID, itemID, stackSize, aux, *pos->Translate(), stdvector);
    // }
    ///// <param name="DataItem">:default = {} (using null to substitute it.)</param>
    // inline bool Player::sendAddEntityPacket(unsigned long long runtimeID, System::String^ entityType, Vec3 pos, Vec3 rotation, List<csFakeDataItem^>^ DataItem) {
    //    if (DataItem == nullptr) {
    //        return NativePtr->sendAddEntityPacket(runtimeID, marshalString(entityType), *pos->Translate(), *rotation->Translate());
    //    }
    //    auto len = DataItem->Count;
    //    vector<FakeDataItem> stdvector = {};
    //    for (int i = 0; i < len; i++)
    //        stdvector.emplace_back(*DataItem[i]->Translate());
    //    return NativePtr->sendAddEntityPacket(runtimeID, marshalString(entityType), *pos->Translate(), *rotation->Translate(), stdvector);
    // }

    inline bool PlayerHandle::SendTransferPacket(String^ address, short port)
    {
        return NativePtr->sendTransferPacket(marshalString(address), port);
    }

    inline bool PlayerHandle::SendSetDisplayObjectivePacket(String^ title, String^ name, char sortOrder)
    {
        return NativePtr->sendSetDisplayObjectivePacket(marshalString(title), marshalString(name), sortOrder);
    }

    inline bool PlayerHandle::SendSetScorePacket(char type, System::Collections::Generic::IList<ScorePacketInfoHandle^>^ data)
    {
        auto len = data->Count;
        vector<::ScorePacketInfo> stdvector = {};
        for (int i = 0; i < len; i++)
            stdvector.emplace_back(*data[i]->NativePtr);
        return NativePtr->sendSetScorePacket(type, stdvector);
    }

    /// <param name="overlay">:default = 0</param>
    inline bool PlayerHandle::SendBossEventPacket(BossEvent type, String^ name, float percent, BossEventColour colour,
        int overlay)
    {
        return NativePtr->sendBossEventPacket(static_cast<::BossEvent>(type), marshalString(name), percent,
            static_cast<::BossEventColour>(colour), overlay);
    }

    inline bool PlayerHandle::SendCommandRequestPacket(String^ cmd)
    {
        return NativePtr->sendCommandRequestPacket(marshalString(cmd));
    }

    inline bool PlayerHandle::SendTextTalkPacket(String^ msg)
    {
        return NativePtr->sendTextTalkPacket(marshalString(msg));
    }

    inline bool PlayerHandle::SendRawFormPacket(unsigned formId, String^ data)
    {
        return NativePtr->sendRawFormPacket(formId, marshalString(data));
    }

    inline bool PlayerHandle::SendToastPacket(String^ title, String^ msg)
    {
        return NativePtr->sendToastPacket(marshalString(title), marshalString(msg));
    }

    inline bool PlayerHandle::__SendSimpleForm(
        String^ title,
        String^ content,
        System::Collections::Generic::IList<String^>^ buttons,
        System::Collections::Generic::IList<String^>^ images,
        void* pStdFunction)
    {
        auto len1 = buttons->Count;
        vector<string> stdvector1(len1);
        for (int i = 0; i < len1; i++)
            stdvector1.emplace_back(marshalString(buttons[i]));
        auto len2 = images->Count;
        vector<string> stdvector2(len2);
        for (int j = 0; j < len2; j++)
            stdvector2.emplace_back(marshalString(images[j]));
        return
            NativePtr->sendSimpleForm(
                marshalString(title),
                marshalString(content),
                stdvector1,
                stdvector2,
                *reinterpret_cast<std::function<void __clrcall(::Player*, int)>*>(pStdFunction));
    }

    inline bool PlayerHandle::__SendModalForm(
        String^ title,
        String^ content,
        String^ button1,
        String^ button2,
        void* pStdFunction)
    {
        return
            NativePtr->sendModalForm(
                marshalString(title),
                marshalString(content),
                marshalString(button1),
                marshalString(button2),
                *reinterpret_cast<std::function<void __clrcall(::Player*, bool)>*>(pStdFunction));
    }

    inline bool PlayerHandle::__SendCustomForm(
        String^ data,
        void* pStdFunction)
    {
        return NativePtr->sendCustomForm(marshalString(data),
            *reinterpret_cast<std::function<void __clrcall(::Player*, std::string)>*>(pStdFunction));
    }

    inline bool PlayerHandle::IsValid(PlayerHandle^ player)
    {
        return ::Player::isValid(player->NativePtr);
    }


    PlayerHandle::GameType PlayerHandle::GameMode::get()
    {
        return static_cast<GameType>(NativePtr->getPlayerGameType());
    }

    void PlayerHandle::GameMode::set(GameType value)
    {
        NativePtr->setPlayerGameType(static_cast<::GameType>(value));
    }
} // namespace BedrockServer::Extension::Handle
