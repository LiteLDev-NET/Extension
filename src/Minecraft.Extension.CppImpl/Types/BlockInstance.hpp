#pragma once
#include <mc/BlockInstance.hpp>
#include "Types.hpp"
#include "Block.hpp"
#include "BlockActor.hpp"
#include "Container.hpp"

namespace BedrockServer::Extension::Handle
{
    ref class BlockSourceHandle;
    ref class ItemStackHandle;
    ref class ContainerHandle;
    ref class BlockActorHandle;
    ref class BlockHandle;
}

namespace BedrockServer
{
    [StructLayout(LayoutKind::Sequential)]
    public value class BlockInstance
    {
    private:
        nint_t block;
        BedrockServer::BlockPos pos;
        int dim;
    public:

        inline static BlockInstance CreateBlockinstance(BedrockServer::Extension::Handle::BlockHandle^ block, BlockPos pos, int dimId);


        /// <summary>
        /// Create a instance of the MC.BlockInstance class from block, position, and dimension id.
        /// </summary>
        /// <param name="block">-Block</param>
        /// <param name="pos">-Position</param>
        /// <param name="dimid">
        /// -Dimension id
        /// <para>　</para>
        /// <para>dimid:</para>
        /// <para>　　0 : OverWorld</para>
        /// <para>　　1 : The Nether</para>
        /// <para>　　2 : The End</para>
        /// </param>
        /// <returns>A instance of the MC.BlockInstance</returns>
        static BlockInstance Create(BedrockServer::Extension::Handle::BlockHandle^ block, BedrockServer::BlockPos pos, int dimid);


        /// <summary>
        /// Create a instance of the MC.BlockInstance class from block and block position with default dimension id.
        /// </summary>
        /// <param name="block">-Block</param>
        /// <param name="pos">-Block Position</param>
        /// <returns>A instance of the MC.BlockInstance</returns>
        static BlockInstance Create(BedrockServer::Extension::Handle::BlockHandle^ block, BedrockServer::BlockPos pos);


        /// <summary>
        /// Create a instance of the MC.BlockInstance class that is empty
        /// </summary>
        /// <returns>A instance of the MC.BlockInstance</returns>
        static BlockInstance Create();


        /// <summary>
        /// Break this block naturally.
        /// </summary>
        inline bool BreakNaturally(bool isCreativeMode);


        /// <summary>
        /// Break this block naturally.
        /// </summary>
        inline bool BreakNaturally();


        /// <summary>
        /// Break this block naturally with tool.
        /// </summary>
        /// <param name="tool">-The item of tool</param>
        inline bool BreakNaturally(BedrockServer::Extension::Handle::ItemStackHandle^ tool, bool isCreativeMode);


        /// <summary>
        /// Break this block naturally with tool.
        /// </summary>
        /// <param name="tool">-The item of tool</param>
        inline bool BreakNaturally(BedrockServer::Extension::Handle::ItemStackHandle^ tool);


        /// <summary>
        /// Get the block in the current MC.BlockInstance object.
        /// </summary>
        property BedrockServer::Extension::Handle::BlockHandle^ BlockHandle { BedrockServer::Extension::Handle::BlockHandle^ get(); };


        /// <summary>
        /// Get the position in the current MC.BlockInstance object.
        /// </summary>
        property BlockPos Position { BlockPos get(); };


        /// <summary>
        /// Get the block source in the current MC.BlockInstance object.
        /// </summary>
        property BedrockServer::Extension::Handle::BlockSourceHandle^ BlockSourceHandle { BedrockServer::Extension::Handle::BlockSourceHandle^ get(); };


        /// <summary>
        /// Get the block entity owned by the current MC.BlockInstance object.
        /// </summary>
        property BedrockServer::Extension::Handle::BlockActorHandle^ BlockEntity { BedrockServer::Extension::Handle::BlockActorHandle^ get(); };


        /// <summary>
        /// Get the container owned by the current MC.BlockInstance object.
        /// </summary>
        property BedrockServer::Extension::Handle::ContainerHandle^ ContainerHandle { BedrockServer::Extension::Handle::ContainerHandle^ get(); };


        /// <summary>
        /// Get the drop item in the current MC.BlockInstance object.
        /// </summary>
        property BedrockServer::Extension::Handle::ItemStackHandle^ BlockDrops { BedrockServer::Extension::Handle::ItemStackHandle^ get(); };


        /// <summary>
        /// Get the dimension id in the current MC.BlockInstance object.
        /// </summary>
        property int DimensionId
        {
            int get();
        }


        /// <summary>
        ///    Determine if this block instance has a block entity.
        /// </summary>
        property bool HasBlockEntity
        {
            bool get();
        }


        /// <summary>
        /// Determine if this block instance is null.
        /// </summary>
        property bool IsNull
        {
            bool get();
        }


        /// <summary>
        /// Determine if this block instance has a container.
        /// </summary>
        property bool HasContainer
        {
            bool get();
        }


        /// <summary>
        /// Get the block id in the current MC.BlockInstance object.
        /// </summary>
        property short BlockId
        {
            short get();
        }

        static bool operator==(BlockInstance a, BlockInstance b);

    };
} // namespace BedrockServer::Extension::Handle