using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using System.Threading.Tasks;

namespace BedrockServer;

[StructLayout(LayoutKind.Sequential)]
public struct ChunkLocalHeight
{
    public short val;

    public ChunkLocalHeight(short v)
    {
        val = v;
    }

    public static implicit operator ChunkLocalHeight(short v) => new(v);
}

[StructLayout(LayoutKind.Sequential)]
public struct ChunkBlockPos
{
    public byte X;
    public byte Z;
    ChunkLocalHeight Y;

    public ChunkBlockPos(byte x, short y, byte z)
    {
        X = x;
        Z = z;
        Y = new(y);
    }

    public ushort ToLegacyIndex()
        => (ushort)((Y.val & 0xF) + 16 * (Z + 16 * X));

    public ChunkBlockPos(byte x, ChunkLocalHeight y, byte z)
    {
        [DllImport(BDS, EntryPoint = "??0ChunkBlockPos@@QEAA@EVChunkLocalHeight@@E@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern void ctor(ref ChunkBlockPos @this, byte x, ChunkLocalHeight y, byte z);

        ctor(ref this, x, y, z);
    }

    public ChunkBlockPos(in BlockPos pos, short num)
    {
        [DllImport(BDS, EntryPoint = "??0ChunkBlockPos@@QEAA@AEBVBlockPos@@F@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern void ctor(ref ChunkBlockPos @this, in BlockPos pos, short num);

        ctor(ref this, pos, num);
    }

    public static ChunkBlockPos From2D(byte num1, byte num2)
    {
        [DllImport(BDS, EntryPoint = "?from2D@ChunkBlockPos@@SA?AV1@EE@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern ChunkBlockPos __invoke(byte num1, byte num2);

        return __invoke(num1, num2);
    }

    public static ChunkBlockPos FromLegacyIndex(ushort index)
    {
        [DllImport(BDS, EntryPoint = "?fromLegacyIndex@ChunkBlockPos@@SA?AV1@G@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern ChunkBlockPos __invoke(ushort index);

        return __invoke(index);
    }

}
