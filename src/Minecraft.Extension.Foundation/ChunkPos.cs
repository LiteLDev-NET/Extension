using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using System.Threading.Tasks;

namespace BedrockServer;

[StructLayout(LayoutKind.Sequential)]
public unsafe struct ChunkPos
{
    internal int x;
    internal int z;

    public int X { get => x; set => x = value; }
    public int Z { get => z; set => z = value; }

    public ChunkPos(int ix, int iz)
    {
        x = ix;
        z = iz;
    }

    public int this[ulong index]
        => index switch { 1 => z, _ => x };

    public ChunkPos(in Vec3 pos)
    {
        [DllImport(BDS, EntryPoint = "??0ChunkPos@@QEAA@AEBVVec3@@@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern void ctor(ref ChunkPos @this, in Vec3 pos);

        ctor(ref this, pos);
    }

    public ChunkPos(in BlockPos pos)
    {
        [DllImport(BDS, EntryPoint = "??0ChunkPos@@QEAA@AEBVBlockPos@@@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern void ctor(ref ChunkPos @this, in BlockPos pos);

        ctor(ref this, pos);
    }

    public bool IsWithinBounds(in ChunkPos pos1, in ChunkPos pos2)
    {
        [DllImport(BDS, EntryPoint = "?isWithinBounds@ChunkPos@@QEBA_NAEBV1@0@Z")]
        [return: MarshalAs(UnmanagedType.U1)]
        [SuppressUnmanagedCodeSecurity]
        static extern bool __invoke(ref ChunkPos @this, in ChunkPos pos1, in ChunkPos pos2);

        return __invoke(ref this, pos1, pos2);
    }

    public Vec3 toBlockSpaceVec3(float num)
    {
        [DllImport(BDS, EntryPoint = "?isWithinBounds@ChunkPos@@QEBA_NAEBV1@0@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern Vec3 __invoke(ref ChunkPos @this, float num);

        return __invoke(ref this, num);
    }

    private static ChunkPos* INVALID_ptr;
    private static ChunkPos* MAX_ptr;
    private static ChunkPos* MIN_ptr;
    private static ChunkPos* ONE_ptr;

    public static ChunkPos INVALID => *INVALID_ptr;
    public static ChunkPos MAX => *MAX_ptr;
    public static ChunkPos MIN => *MIN_ptr;
    public static ChunkPos ONE => *ONE_ptr;

    static ChunkPos()
    {
        INVALID_ptr = (ChunkPos*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(INVALID)}@ChunkPos@@2V1@B");
        MAX_ptr = (ChunkPos*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(MAX)}@ChunkPos@@2V1@B");
        MIN_ptr = (ChunkPos*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(MIN)}@ChunkPos@@2V1@B");
        ONE_ptr = (ChunkPos*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(ONE)}@ChunkPos@@2V1@B");
    }
}
