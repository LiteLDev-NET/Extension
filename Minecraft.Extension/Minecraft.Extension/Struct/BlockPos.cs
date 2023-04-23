using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using System.Threading.Tasks;

namespace Minecraft;

[StructLayout(LayoutKind.Sequential)]
public struct BlockPos
{
    public int X;
    public int Y;
    public int Z;

    public BlockPos(int x, int y, int z)
    {
        X = x; Y = y; Z = z;
    }


    public BlockPos(in Vec3 pos)
    {
        [DllImport(BDS, EntryPoint = "??0BlockPos@@QEAA@AEBVVec3@@@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern void ctor(ref BlockPos @this, in Vec3 vec);

        ctor(ref this, pos);
    }

    public BlockPos(float x, float y, float z)
    {
        [DllImport(BDS, EntryPoint = "??0BlockPos@@QEAA@MMM@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern void ctor(ref BlockPos @this, float x, float y, float z);
        ctor(ref this, x, y, z);
    }

    public BlockPos(in ChunkPos chunkPos, int num)
    {
        [DllImport(BDS, EntryPoint = "??0BlockPos@@QEAA@AEBVChunkPos@@H@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern void ctor(ref BlockPos @this, in ChunkPos chunkPos, int num);

        ctor(ref this, chunkPos, num);
    }
    public BlockPos(in SubChunkPos chunkPos)
    {
        [DllImport(BDS, EntryPoint = "??0BlockPos@@QEAA@AEBVChunkPos@@H@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern void ctor(ref BlockPos @this, in SubChunkPos chunkPos);

        ctor(ref this, chunkPos);
    }
}
