#include "SimulatedPlayer.hpp"

#include "ItemStack.hpp"
#include <mc/Dimension.hpp>


namespace BedrockServer::Extension
{
    SimulatedPlayer^ SimulatedPlayer::Create(String^ name)
    {
        return gcnew SimulatedPlayer(::SimulatedPlayer::create(marshalString(name)));
    }
    SimulatedPlayer^ SimulatedPlayer::Create(String^ name, BedrockServer::AutomaticID<BedrockServer::Extension::Dimension^, int>^ dimensionId)
    {
        return gcnew SimulatedPlayer(::SimulatedPlayer::create(marshalString(name), ::AutomaticID<::Dimension, int>(dimensionId)));
    }

    SimulatedPlayer^ SimulatedPlayer::Create(String^ name, BedrockServer::BlockPos blockPos)
    {
        return gcnew SimulatedPlayer(::SimulatedPlayer::create(marshalString(name), *(::BlockPos*)&blockPos));
    }

    SimulatedPlayer^ SimulatedPlayer::Create(String^ name, BedrockServer::BlockPos blockPos, AutomaticID<BedrockServer::Extension::Dimension^, int>^ dimensionId)
    {
        return gcnew SimulatedPlayer(::SimulatedPlayer::create(marshalString(name), *(::BlockPos*)&blockPos, ::AutomaticID<::Dimension, int>(dimensionId)));
    }

    inline bool SimulatedPlayer::SimulateDestroy()
    {
        return NativePtr->simulateDestroy();
    }

    inline bool SimulatedPlayer::SimulateUseItem()
    {
        return NativePtr->simulateUseItem();
    }

    inline bool SimulatedPlayer::SimulateSneak()
    {
        return NativePtr->simulateSneak();
    }

    inline bool SimulatedPlayer::SimulateStopSneaking()
    {
        return NativePtr->simulateStopSneaking();
    }

    inline bool SimulatedPlayer::SimulateAttack()
    {
        return NativePtr->simulateAttack();
    }

    inline bool SimulatedPlayer::SimulateAttack(Actor^ actor)
    {
        return NativePtr->simulateAttack(actor);
    }

    /*inline bool SimulatedPlayer::SimulateDestroyBlock(BedrockServer::Extension::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing)
    {
        return NativePtr->simulateDestroyBlock(blockPos, facing);
    }*/

    inline void SimulatedPlayer::SimulateDisconnect()
    {
        return NativePtr->simulateDisconnect();
    }

    inline bool SimulatedPlayer::SimulateGiveItem(ItemStack^ item, bool _0)
    {
        return NativePtr->simulateGiveItem(*item->NativePtr, _0);
    }

    inline bool SimulatedPlayer::SimulateInteract()
    {
        return NativePtr->simulateInteract();
    }

    inline bool SimulatedPlayer::SimulateInteract(Actor^ actor)
    {
        return NativePtr->simulateInteract(*actor->NativePtr);
    }

    /*inline bool SimulatedPlayer::SimulateInteract(BedrockServer::Extension::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing)
    {
        return NativePtr->simulateInteract(blockPos, facing);
    }*/

    inline bool SimulatedPlayer::SimulateJump()
    {
        return NativePtr->simulateJump();
    }

    inline void SimulatedPlayer::SimulateLocalMove(BedrockServer::Vec3 target, float speed)
    {
        return NativePtr->simulateLocalMove(*(::Vec3*)&target, speed);
    }

    inline void SimulatedPlayer::SimulateLookAt(Actor^ actor)
    {
        return NativePtr->simulateLookAt(*actor->NativePtr);
    }

    inline void SimulatedPlayer::SimulateLookAt(BedrockServer::BlockPos blockPos)
    {
        return NativePtr->simulateLookAt(*(::BlockPos*)&blockPos);
    }

    inline void SimulatedPlayer::SimulateLookAt(BedrockServer::Vec3 target)
    {
        return NativePtr->simulateLookAt(*(::Vec3*)&target);
    }

    inline void SimulatedPlayer::SimulateMoveToLocation(BedrockServer::Vec3 target, float speed)
    {
        return NativePtr->simulateMoveToLocation(*(::Vec3*)&target, speed);
    }

    inline void SimulatedPlayer::SimulateNavigateToLocations(System::Collections::Generic::IList<Vec3>^ locations, float speed)
    {
        auto count = locations->Count;
        std::vector<::Vec3> stdvector(count);
        for (int i = 0; i < count; ++i)
            stdvector.emplace_back(::Vec3(*(::Vec3*)&locations[i]));
        return NativePtr->simulateNavigateToLocations(std::move(stdvector), speed);
    }

    inline void SimulatedPlayer::SimulateSetBodyRotation(float _0)
    {
        return NativePtr->simulateSetBodyRotation(_0);
    }

    inline bool SimulatedPlayer::SimulateSetItem(ItemStack^ item, bool _0, int _1)
    {
        return NativePtr->simulateSetItem(*item->NativePtr, _0, _1);
    }

    inline void SimulatedPlayer::SimulateStopDestroyingBlock()
    {
        return NativePtr->simulateStopDestroyingBlock();
    }

    inline void SimulatedPlayer::SimulateStopInteracting()
    {
        return NativePtr->simulateStopInteracting();
    }

    inline void SimulatedPlayer::SimulateStopMoving()
    {
        return NativePtr->simulateStopMoving();
    }

    inline void SimulatedPlayer::SimulateStopUsingItem()
    {
        return NativePtr->simulateStopUsingItem();
    }

    inline bool SimulatedPlayer::SimulateUseItem(ItemStack^ item)
    {
        return NativePtr->simulateUseItem(*item->NativePtr);
    }

    inline bool SimulatedPlayer::SimulateUseItemInSlot(int slot)
    {
        return NativePtr->simulateUseItemInSlot(slot);
    }

    /*inline bool SimulatedPlayer::SimulateUseItemInSlotOnBlock(int slot, BedrockServer::Extension::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing, BedrockServer::Extension::Vec3 target)
    {
        return NativePtr->simulateUseItemInSlotOnBlock(slot, blockPos, facing, target);
    }*/

    /*inline bool SimulatedPlayer::SimulateUseItemOnBlock(ItemStack^ item, BedrockServer::Extension::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing, BedrockServer::Extension::Vec3 target)
    {
        return NativePtr->simulateUseItemOnBlock(*item->NativePtr, blockPos, facing, target);
    }*/

    inline void SimulatedPlayer::SimulateWorldMove(BedrockServer::Vec3 target, float speed)
    {
        return NativePtr->simulateWorldMove(*(::Vec3*)&target, speed);
    }
}
