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


enum class GameType;

namespace BedrockServer::Extension
{
    inline String^ Player::Name::get()
    {
        return marshalString(NativePtr->getName());
    }

    inline String^ Player::RealName::get()
    {
        return marshalString(NativePtr->getRealName());
    }

    inline String^ Player::Uuid::get()
    {
        return marshalString(NativePtr->getUuid());
    }

    inline String^ Player::Xuid::get()
    {
        return marshalString(NativePtr->getXuid());
    }

    inline unsigned char Player::ClientSubId::get()
    {
        return NativePtr->getClientSubId();
    }

    inline String^ Player::DeviceTypeName::get()
    {
        return marshalString(NativePtr->getDeviceTypeName());
    }

    inline int Player::AvgPing::get()
    {
        return NativePtr->getAvgPing();
    }

    inline int Player::LastPing::get()
    {
        return NativePtr->getLastPing();
    }

    inline String^ Player::IP::get()
    {
        return marshalString(NativePtr->getIP());
    }

    inline String^ Player::LanguageCode::get()
    {
        return marshalString(NativePtr->getLanguageCode());
    }

    inline String^ Player::ServerAddress::get()
    {
        return marshalString(NativePtr->getServerAddress());
    }

    inline NetworkIdentifier^ Player::NetworkIdentifier::get()
    {
        return gcnew BedrockServer::Extension::NetworkIdentifier(NativePtr->getNetworkIdentifier());
    }

    inline Certificate^ Player::Certificate::get()
    {
        return gcnew BedrockServer::Extension::Certificate(NativePtr->getCertificate());
    }

    inline Container^ Player::EnderChestContainer::get()
    {
        return gcnew Container(NativePtr->getEnderChestContainer());
    }

    inline SerializedSkin^ Player::Skin::get()
    {
        return gcnew SerializedSkin(&NativePtr->getSkin());
    }

    inline System::ValueTuple<BlockPos, int> Player::RespawnPosition::get()
    {
        auto& p = NativePtr->getRespawnPosition();
        return System::ValueTuple<BedrockServer::BlockPos, int>(
            *(BedrockServer::BlockPos*)&(p.first), p.second);
    }

    inline float Player::AvgPacketLoss::get()
    {
        return NativePtr->getAvgPacketLoss();
    }

    inline String^ Player::ClientId::get()
    {
        return marshalString(NativePtr->getClientId());
    }

    inline int Player::DeviceType::get()
    {
        return NativePtr->getDeviceType();
    }

    inline bool Player::IsOP::get()
    {
        return NativePtr->isOP();
    }

    inline int Player::CurrentExperience::get()
    {
        return NativePtr->getCurrentExperience();
    }

    inline void Player::CurrentExperience::set(int value)
    {
        if (NativePtr->setTotalExperience(value))
            throw gcnew Exception("Failed to set current experience.");
    }

    inline size_t Player::TotalExperience::get()
    {
        return NativePtr->getCurrentExperience();
    }

    inline void Player::TotalExperience::set(size_t value)
    {
        if (NativePtr->setTotalExperience(value))
            throw gcnew Exception("Failed to set total experience.");
    }

    inline bool Player::ReduceExperience(size_t exp) { return NativePtr->reduceExperience(exp); }

    /// <summary>
    /// Experience required to upgrade to level from (level-1)
    /// </summary>

    inline int Player::GetXpNeededForLevel(int level) { return ::Player::getXpNeededForLevel(level); }

    /// <summary>
    /// Experience required to upgrade to level from level 0
    /// </summary>

    inline size_t Player::GetTotalXpNeededForLevel(int level) { return ::Player::getTotalXpNeededForLevel(level); }

    inline bool Player::Kick(String^ msg)
    {
        return NativePtr->kick(marshalString(msg));
    }

    inline bool Player::CrashClient()
    {
        return NativePtr->crashClient();
    }

    /// <param name="type">:default = TextType::RAW</param>
    inline bool Player::SendText(String^ text, TextType type)
    {
        return NativePtr->sendText(marshalString(text), static_cast<::TextType>(type));
    }

    inline bool Player::SendText(String^ text) { return SendText(text, TextType::RAW); }

    inline bool Player::TalkAs(String^ msg)
    {
        return NativePtr->talkAs(marshalString(msg));
    }

    inline bool Player::GiveItem(ItemStack^ item)
    {
        return NativePtr->giveItem(item->NativePtr);
    }

    inline int Player::ClearItem(String^ typeName, unsigned int clearCount)
    {
        return NativePtr->clearItem(marshalString(typeName), clearCount);
    }

    inline bool Player::Runcmd(String^ cmd)
    {
        return NativePtr->runcmd(marshalString(cmd));
    }

    inline bool Player::TransferServer(String^ address, unsigned short port)
    {
        return NativePtr->transferServer(marshalString(address), port);
    }

    inline bool Player::SetSidebar(String^ title,
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

    inline bool Player::RemoveSidebar()
    {
        return NativePtr->removeSidebar();
    }

    inline CompoundTag^ Player::GetNbt()
    {
        return gcnew CompoundTag(NativePtr->getNbt().release(), true);
    }

    inline bool Player::SetNbt(CompoundTag^ nbt)
    {
        return NativePtr->setNbt(nbt->NativePtr);
    }

    inline bool Player::RefreshAttribute(Attribute^ attribute)
    {
        return NativePtr->refreshAttribute(*attribute->NativePtr);
    }

    inline bool Player::RefreshAttributes(System::Collections::Generic::IList<Attribute^>^ attributes)
    {
        auto len = attributes->Count;
        std::vector<const ::Attribute*> stdvector(len);
        for (int i = 0; i < len; ++i)
            stdvector[i] = attributes[i];
        return NativePtr->refreshAttributes(stdvector);
    }

    inline int Player::GetScore(String^ key)
    {
        return NativePtr->getScore(marshalString(key));
    }

    inline bool Player::SetScore(String^ key, int value)
    {
        return NativePtr->setScore(marshalString(key), value);
    }

    inline bool Player::AddScore(String^ key, int value)
    {
        return NativePtr->addScore(marshalString(key), value);
    }

    inline bool Player::ReduceScore(String^ key, int value)
    {
        return NativePtr->reduceScore(marshalString(key), value);
    }

    inline bool Player::DeleteScore(String^ key)
    {
        return NativePtr->deleteScore(marshalString(key));
    }

    // PacketEX

    void Player::SendNetworkPacket(Packet^ packet)
    {
        NativePtr->sendNetworkPacket(*packet->NativePtr);
    }

    /// <param name="Type">:default = TextType::RAW</param>
    inline bool Player::SendTextPacket(String^ text, TextType Type)
    {
        return NativePtr->sendText(marshalString(text), static_cast<::TextType>(Type));
    }

    inline bool Player::SendTitlePacket(String^ text, TitleType Type, int FadeInDuration, int RemainDuration,
        int FadeOutDuration)
    {
        return NativePtr->sendTitlePacket(marshalString(text), static_cast<::TitleType>(Type), FadeInDuration,
            RemainDuration, FadeOutDuration);
    }

    inline bool Player::SendNotePacket(unsigned int tone)
    {
        return NativePtr->sendNotePacket(tone);
    }

    /// <param name="EntityUniqueID">:default = -1</param>
    inline bool Player::SendSpawnParticleEffectPacket(Vec3 spawnPos, int dimid, String^ ParticleName,
        int64_t EntityUniqueID)
    {
        return NativePtr->sendSpawnParticleEffectPacket(*(::Vec3*)&spawnPos, dimid, marshalString(ParticleName), EntityUniqueID);
    }

    /*bad*/
    inline bool Player::SendPlaySoundPacket(String^ SoundName, Vec3 Position, float Volume, float Pitch)
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

    inline bool Player::SendTransferPacket(String^ address, short port)
    {
        return NativePtr->sendTransferPacket(marshalString(address), port);
    }

    inline bool Player::SendSetDisplayObjectivePacket(String^ title, String^ name, char sortOrder)
    {
        return NativePtr->sendSetDisplayObjectivePacket(marshalString(title), marshalString(name), sortOrder);
    }

    inline bool Player::SendSetScorePacket(char type, System::Collections::Generic::IList<ScorePacketInfo^>^ data)
    {
        auto len = data->Count;
        vector<::ScorePacketInfo> stdvector = {};
        for (int i = 0; i < len; i++)
            stdvector.emplace_back(*data[i]->NativePtr);
        return NativePtr->sendSetScorePacket(type, stdvector);
    }

    /// <param name="overlay">:default = 0</param>
    inline bool Player::SendBossEventPacket(BossEvent type, String^ name, float percent, BossEventColour colour,
        int overlay)
    {
        return NativePtr->sendBossEventPacket(static_cast<::BossEvent>(type), marshalString(name), percent,
            static_cast<::BossEventColour>(colour), overlay);
    }

    inline bool Player::SendCommandRequestPacket(String^ cmd)
    {
        return NativePtr->sendCommandRequestPacket(marshalString(cmd));
    }

    inline bool Player::SendTextTalkPacket(String^ msg)
    {
        return NativePtr->sendTextTalkPacket(marshalString(msg));
    }

    inline bool Player::SendRawFormPacket(unsigned formId, String^ data)
    {
        return NativePtr->sendRawFormPacket(formId, marshalString(data));
    }

    inline bool Player::SendToastPacket(String^ title, String^ msg)
    {
        return NativePtr->sendToastPacket(marshalString(title), marshalString(msg));
    }

    inline bool Player::SendSimpleFormPacket(
        String^ title,
        String^ content,
        System::Collections::Generic::IList<String^>^ buttons,
        System::Collections::Generic::IList<String^>^ images,
        callBackFunc_int^ callback)
    {
        auto len1 = buttons->Count;
        vector<string> stdvector1(len1);
        for (int i = 0; i < len1; i++)
            stdvector1.emplace_back(marshalString(buttons[i]));
        auto len2 = images->Count;
        vector<string> stdvector2(len2);
        for (int j = 0; j < len2; j++)
            stdvector2.emplace_back(marshalString(images[j]));
        GCHandle gch = GCHandle::Alloc(callback);
        auto __ptr = Marshal::GetFunctionPointerForDelegate(callback);
        auto __funcptr = static_cast<void (*)(int)>(__ptr.ToPointer());
        return NativePtr->sendSimpleFormPacket(
            marshalString(title),
            marshalString(content),
            stdvector1,
            stdvector2,
            __funcptr);
    }

    inline bool Player::SendModalFormPacket(
        String^ title,
        String^ content,
        String^ button1,
        String^ button2,
        callBackFunc_bool^ callback)
    {
        GCHandle gch = GCHandle::Alloc(callback);
        auto __ptr = Marshal::GetFunctionPointerForDelegate(callback);
        auto __funcptr = static_cast<void (*)(bool)>(__ptr.ToPointer());
        return NativePtr->sendModalFormPacket(
            marshalString(title),
            marshalString(content),
            marshalString(button1),
            marshalString(button2),
            __funcptr);
    }

    delegate void callBackFunc_String(std::string);
    /// <summary>
    /// QAQ
    /// </summary>
    /// <param name="data"></param>
    /// <param name="callback"></param>
    /// <returns></returns>
    inline bool Player::SendCustomFormPacket(
        String^ data,
        callBackFunc_String^ callback)
    {
        GCHandle gch = GCHandle::Alloc(callback);
        auto __ptr = Marshal::GetFunctionPointerForDelegate(callback);
        auto __funcptr = static_cast<void (*)(std::string)>(__ptr.ToPointer());
        return NativePtr->sendCustomFormPacket(marshalString(data), __funcptr);
    }

    inline bool Player::IsValid(Player^ player)
    {
        return ::Player::isValid(player->NativePtr);
    }

    bool Player::SendModalForm(String^ title,
        String^ content,
        String^ button1,
        String^ button2,
        ModalForm_callback^ func)
    {
        GCHandle gch = GCHandle::Alloc(func);
        auto pfunc = static_cast<void (*)(bool)>(Marshal::GetFunctionPointerForDelegate(func).ToPointer());
        return NativePtr->sendModalFormPacket(
            marshalString(title),
            marshalString(content),
            marshalString(button1),
            marshalString(button2),
            pfunc);
    }

    bool Player::SendSimpleForm(String^ title,
        String^ content,
        System::Collections::Generic::IList<String^>^ buttons,
        System::Collections::Generic::IList<String^>^ images,
        SimpleForm_callback^ callback)
    {
        GCHandle gch = GCHandle::Alloc(callback);
        auto pfunc = static_cast<void (*)(int)>(Marshal::GetFunctionPointerForDelegate(callback).ToPointer());
        auto len = buttons->Count;
        std::vector<std::string> buttonsvector(len);
        for (int i = 0; i < len; ++i)
            buttonsvector.emplace_back(marshalString(buttons[i]));
        len = images->Count;
        std::vector<std::string> imagesvector(len);
        for (int i = 0; i < len; ++i)
            imagesvector.emplace_back(marshalString(images[i]));
        return NativePtr->sendSimpleFormPacket(
            marshalString(title),
            marshalString(content),
            buttonsvector,
            imagesvector,
            pfunc);
    }

    inline void Player::CustomForm_Func(std::string str)
    {
        try
        {
            __func(marshalString(str));
        }
        catch (Exception^)
        {
        }
    }

    bool Player::SendCustomForm(String^ json,
        CustomForm_callback^ callback)
    {
        __func = callback;
        auto dgfunc = gcnew dgCustomForm_Func(this, &Player::CustomForm_Func);
        GCHandle gch = GCHandle::Alloc(dgfunc);
        auto pfunc = static_cast<void (*)(std::string)>(
            Marshal::GetFunctionPointerForDelegate(dgfunc).ToPointer());
        return NativePtr->sendCustomFormPacket(
            marshalString(json),
            pfunc);
    }


    Player::GameType Player::GameMode::get()
    {
        return static_cast<GameType>(NativePtr->getPlayerGameType());
    }

    void Player::GameMode::set(GameType value)
    {
        NativePtr->setPlayerGameType(static_cast<::GameType>(value));
    }
} // namespace BedrockServer::Extension
