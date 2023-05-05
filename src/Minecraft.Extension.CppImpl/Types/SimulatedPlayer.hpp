#pragma once
#include <mc/SimulatedPlayer.hpp>
#include "ServerPlayer.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class DimensionHandle;
    ref class EntityContext;
} // namespace BedrockServer::Extension::Handle

namespace BedrockServer::Extension::Handle
{
    public ref class SimulatedPlayerHandle : ServerPlayerHandle
    {
        DEFAULT_DEF_OVERRIDE(SimulatedPlayerHandle, ::SimulatedPlayer, ServerPlayerHandle)
    public:

        //property gametest::BaseGameTestHelper^ GameTestHelper;

        static SimulatedPlayerHandle^ Create(String^ name);
        static SimulatedPlayerHandle^ Create(String^ name, AutomaticID<BedrockServer::Extension::Handle::DimensionHandle^, int>^ dimensionId);
        static SimulatedPlayerHandle^ Create(String^ name, BedrockServer::BlockPos blockPos);
        static SimulatedPlayerHandle^ Create(String^ name, BedrockServer::BlockPos blockPos, AutomaticID<BedrockServer::Extension::Handle::DimensionHandle^, int>^ dimensionId);
        //static SimulatedPlayer^ TryGetFromEntity(EntityContext^ entity, bool _0);

        inline bool SimulateDestroy();
        inline bool SimulateUseItem();
        inline bool SimulateSneak();
        inline bool SimulateStopSneaking();
        inline bool SimulateAttack();
        inline bool SimulateAttack(ActorHandle^ actor);
        //inline bool SimulateDestroyBlock(BedrockServer::Extension::Handle::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing);
        inline void SimulateDisconnect();
        inline bool SimulateGiveItem(ItemStackHandle^ item, bool _0);
        inline bool SimulateInteract();
        inline bool SimulateInteract(ActorHandle^ actor);
        //inline bool SimulateInteract(BedrockServer::Extension::Handle::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing);
        inline bool SimulateJump();
        inline void SimulateLocalMove(Vec3 target, float speed);
        inline void SimulateLookAt(ActorHandle^ actor);
        inline void SimulateLookAt(BedrockServer::BlockPos blockPos);
        inline void SimulateLookAt(Vec3 target);
        inline void SimulateMoveToLocation(Vec3 target, float speed);
        inline void SimulateNavigateToLocations(System::Collections::Generic::IList<Vec3>^ locations, float speed);
        inline void SimulateSetBodyRotation(float _0);
        inline bool SimulateSetItem(ItemStackHandle^ item, bool _0, int _1);
        inline void SimulateStopDestroyingBlock();
        inline void SimulateStopInteracting();
        inline void SimulateStopMoving();
        inline void SimulateStopUsingItem();
        inline bool SimulateUseItem(ItemStackHandle^ item);
        inline bool SimulateUseItemInSlot(int slot);
        //inline bool SimulateUseItemInSlotOnBlock(int slot, BedrockServer::Extension::Handle::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing, Vec3 target);
        //inline bool SimulateUseItemOnBlock(ItemStack^ item, BedrockServer::Extension::Handle::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing, Vec3 target);
        inline void SimulateWorldMove(Vec3 target, float speed);
    };
}
