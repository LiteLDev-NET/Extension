#include "SimulatedPlayer.hpp"

#include "ItemStack.hpp"
#include <mc/Dimension.hpp>


namespace BedrockServer::Extension::Handle
{
    SimulatedPlayerHandle^ SimulatedPlayerHandle::Create(String^ name)
    {
        return gcnew SimulatedPlayerHandle(::SimulatedPlayer::create(marshalString(name)));
    }
    SimulatedPlayerHandle^ SimulatedPlayerHandle::Create(String^ name, BedrockServer::AutomaticID<BedrockServer::Extension::Handle::DimensionHandle^, int>^ dimensionId)
    {
        return gcnew SimulatedPlayerHandle(::SimulatedPlayer::create(marshalString(name), ::AutomaticID<::Dimension, int>(dimensionId)));
    }

    SimulatedPlayerHandle^ SimulatedPlayerHandle::Create(String^ name, BedrockServer::BlockPos blockPos)
    {
        return gcnew SimulatedPlayerHandle(::SimulatedPlayer::create(marshalString(name), *(::BlockPos*)&blockPos));
    }

    SimulatedPlayerHandle^ SimulatedPlayerHandle::Create(String^ name, BedrockServer::BlockPos blockPos, AutomaticID<BedrockServer::Extension::Handle::DimensionHandle^, int>^ dimensionId)
    {
        return gcnew SimulatedPlayerHandle(::SimulatedPlayer::create(marshalString(name), *(::BlockPos*)&blockPos, ::AutomaticID<::Dimension, int>(dimensionId)));
    }

    inline bool SimulatedPlayerHandle::SimulateDestroy()
    {
        return NativePtr->simulateDestroy();
    }

    inline bool SimulatedPlayerHandle::SimulateUseItem()
    {
        return NativePtr->simulateUseItem();
    }

    inline bool SimulatedPlayerHandle::SimulateSneak()
    {
        return NativePtr->simulateSneak();
    }

    inline bool SimulatedPlayerHandle::SimulateStopSneaking()
    {
        return NativePtr->simulateStopSneaking();
    }

    inline bool SimulatedPlayerHandle::SimulateAttack()
    {
        return NativePtr->simulateAttack();
    }

    inline bool SimulatedPlayerHandle::SimulateAttack(ActorHandle^ actor)
    {
        return NativePtr->simulateAttack(actor);
    }

    /*inline bool SimulatedPlayer::SimulateDestroyBlock(BedrockServer::Extension::Handle::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing)
    {
        return NativePtr->simulateDestroyBlock(blockPos, facing);
    }*/

    inline void SimulatedPlayerHandle::SimulateDisconnect()
    {
        return NativePtr->simulateDisconnect();
    }

    inline bool SimulatedPlayerHandle::SimulateGiveItem(ItemStackHandle^ item, bool _0)
    {
        return NativePtr->simulateGiveItem(*item->NativePtr, _0);
    }

    inline bool SimulatedPlayerHandle::SimulateInteract()
    {
        return NativePtr->simulateInteract();
    }

    inline bool SimulatedPlayerHandle::SimulateInteract(ActorHandle^ actor)
    {
        return NativePtr->simulateInteract(*actor->NativePtr);
    }

    /*inline bool SimulatedPlayer::SimulateInteract(BedrockServer::Extension::Handle::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing)
    {
        return NativePtr->simulateInteract(blockPos, facing);
    }*/

    inline bool SimulatedPlayerHandle::SimulateJump()
    {
        return NativePtr->simulateJump();
    }

    inline void SimulatedPlayerHandle::SimulateLocalMove(BedrockServer::Vec3 target, float speed)
    {
        return NativePtr->simulateLocalMove(*(::Vec3*)&target, speed);
    }

    inline void SimulatedPlayerHandle::SimulateLookAt(ActorHandle^ actor)
    {
        return NativePtr->simulateLookAt(*actor->NativePtr);
    }

    inline void SimulatedPlayerHandle::SimulateLookAt(BedrockServer::BlockPos blockPos)
    {
        return NativePtr->simulateLookAt(*(::BlockPos*)&blockPos);
    }

    inline void SimulatedPlayerHandle::SimulateLookAt(BedrockServer::Vec3 target)
    {
        return NativePtr->simulateLookAt(*(::Vec3*)&target);
    }

    inline void SimulatedPlayerHandle::SimulateMoveToLocation(BedrockServer::Vec3 target, float speed)
    {
        return NativePtr->simulateMoveToLocation(*(::Vec3*)&target, speed);
    }

    inline void SimulatedPlayerHandle::SimulateNavigateToLocations(System::Collections::Generic::IList<Vec3>^ locations, float speed)
    {
        auto count = locations->Count;
        std::vector<::Vec3> stdvector(count);
        for (int i = 0; i < count; ++i)
            stdvector.emplace_back(::Vec3(*(::Vec3*)&locations[i]));
        return NativePtr->simulateNavigateToLocations(std::move(stdvector), speed);
    }

    inline void SimulatedPlayerHandle::SimulateSetBodyRotation(float _0)
    {
        return NativePtr->simulateSetBodyRotation(_0);
    }

    inline bool SimulatedPlayerHandle::SimulateSetItem(ItemStackHandle^ item, bool _0, int _1)
    {
        return NativePtr->simulateSetItem(*item->NativePtr, _0, _1);
    }

    inline void SimulatedPlayerHandle::SimulateStopDestroyingBlock()
    {
        return NativePtr->simulateStopDestroyingBlock();
    }

    inline void SimulatedPlayerHandle::SimulateStopInteracting()
    {
        return NativePtr->simulateStopInteracting();
    }

    inline void SimulatedPlayerHandle::SimulateStopMoving()
    {
        return NativePtr->simulateStopMoving();
    }

    inline void SimulatedPlayerHandle::SimulateStopUsingItem()
    {
        return NativePtr->simulateStopUsingItem();
    }

    inline bool SimulatedPlayerHandle::SimulateUseItem(ItemStackHandle^ item)
    {
        return NativePtr->simulateUseItem(*item->NativePtr);
    }

    inline bool SimulatedPlayerHandle::SimulateUseItemInSlot(int slot)
    {
        return NativePtr->simulateUseItemInSlot(slot);
    }

    /*inline bool SimulatedPlayer::SimulateUseItemInSlotOnBlock(int slot, BedrockServer::Extension::Handle::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing, BedrockServer::Extension::Handle::Vec3 target)
    {
        return NativePtr->simulateUseItemInSlotOnBlock(slot, blockPos, facing, target);
    }*/

    /*inline bool SimulatedPlayer::SimulateUseItemOnBlock(ItemStack^ item, BedrockServer::Extension::Handle::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing, BedrockServer::Extension::Handle::Vec3 target)
    {
        return NativePtr->simulateUseItemOnBlock(*item->NativePtr, blockPos, facing, target);
    }*/

    inline void SimulatedPlayerHandle::SimulateWorldMove(BedrockServer::Vec3 target, float speed)
    {
        return NativePtr->simulateWorldMove(*(::Vec3*)&target, speed);
    }
}
