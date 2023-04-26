#pragma once
#include <mc/SimulatedPlayer.hpp>
#include "ServerPlayer.hpp"

namespace BedrockServer::Extension
{
    ref class Dimension;
    ref class EntityContext;
} // namespace BedrockServer::Extension

namespace BedrockServer::Extension
{
    public ref class SimulatedPlayer : ServerPlayer
    {
        DEFAULT_DEF_OVERRIDE(SimulatedPlayer, ::SimulatedPlayer, ServerPlayer)
    public:

        //property gametest::BaseGameTestHelper^ GameTestHelper;

        static SimulatedPlayer^ Create(String^ name);
        static SimulatedPlayer^ Create(String^ name, AutomaticID<BedrockServer::Extension::Dimension^, int>^ dimensionId);
        static SimulatedPlayer^ Create(String^ name, BedrockServer::BlockPos blockPos);
        static SimulatedPlayer^ Create(String^ name, BedrockServer::BlockPos blockPos, AutomaticID<BedrockServer::Extension::Dimension^, int>^ dimensionId);
        //static SimulatedPlayer^ TryGetFromEntity(EntityContext^ entity, bool _0);

        inline bool SimulateDestroy();
        inline bool SimulateUseItem();
        inline bool SimulateSneak();
        inline bool SimulateStopSneaking();
        inline bool SimulateAttack();
        inline bool SimulateAttack(Actor^ actor);
        //inline bool SimulateDestroyBlock(BedrockServer::Extension::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing);
        inline void SimulateDisconnect();
        inline bool SimulateGiveItem(ItemStack^ item, bool _0);
        inline bool SimulateInteract();
        inline bool SimulateInteract(Actor^ actor);
        //inline bool SimulateInteract(BedrockServer::Extension::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing);
        inline bool SimulateJump();
        inline void SimulateLocalMove(Vec3 target, float speed);
        inline void SimulateLookAt(Actor^ actor);
        inline void SimulateLookAt(BedrockServer::BlockPos blockPos);
        inline void SimulateLookAt(Vec3 target);
        inline void SimulateMoveToLocation(Vec3 target, float speed);
        inline void SimulateNavigateToLocations(System::Collections::Generic::IList<Vec3>^ locations, float speed);
        inline void SimulateSetBodyRotation(float _0);
        inline bool SimulateSetItem(ItemStack^ item, bool _0, int _1);
        inline void SimulateStopDestroyingBlock();
        inline void SimulateStopInteracting();
        inline void SimulateStopMoving();
        inline void SimulateStopUsingItem();
        inline bool SimulateUseItem(ItemStack^ item);
        inline bool SimulateUseItemInSlot(int slot);
        //inline bool SimulateUseItemInSlotOnBlock(int slot, BedrockServer::Extension::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing, Vec3 target);
        //inline bool SimulateUseItemOnBlock(ItemStack^ item, BedrockServer::Extension::BlockPos blockPos, ScriptModuleBedrockServer::ScriptFacing facing, Vec3 target);
        inline void SimulateWorldMove(Vec3 target, float speed);
    };
}
