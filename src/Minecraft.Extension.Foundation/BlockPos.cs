using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security;

namespace BedrockServer;

[StructLayout(LayoutKind.Sequential)]
public unsafe struct BlockPos
{
    internal int x;
    internal int y;
    internal int z;

    public int X { get => x; set => x = value; }
    public int Y { get => y; set => y = value; }
    public int Z { get => z; set => z = value; }

    public BlockPos(int x, int y, int z)
    {
        this.x = x; this.y = y; this.z = z;
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


    private static BlockPos* MAX_ptr;

    private static BlockPos* MIN_ptr;

    private static BlockPos* ONE_ptr;

    private static BlockPos* ZERO_ptr;

    public static BlockPos MAX => *MAX_ptr;

    public static BlockPos MIN => *MIN_ptr;

    public static BlockPos ONE => *ONE_ptr;

    public static BlockPos ZERO => *ZERO_ptr;

    public override unsafe int GetHashCode()
    {
        fixed (BlockPos* pos = &this)
        {
            ulong num = (ulong)((((*(byte*)pos ^ -3750763034362895579L) * 1099511628211L ^ *(byte*)((ulong)(nint)pos + 1uL)) * 1099511628211L ^ *(byte*)((ulong)(nint)pos + 2uL)) * 1099511628211L ^ *(byte*)((ulong)(nint)pos + 3uL));
            ulong num2 = 2654435769L + num * 1099511628211L;
            ulong num3 = (num2 >> 2) + (ulong)(172538324985L + (((((*(byte*)((ulong)(nint)pos + 4uL) ^ -3750763034362895579L) * 1099511628211L ^ *(byte*)((ulong)(nint)pos + 5uL)) * 1099511628211L ^ *(byte*)((ulong)(nint)pos + 6uL)) * 1099511628211L ^ *(byte*)((ulong)(nint)pos + 7uL)) + (long)(num * 64)) * 1099511628211L) ^ num2;
            return (int)((num3 >> 2) + (ulong)(2654435769L + ((((*(byte*)((ulong)(nint)pos + 8uL) ^ -3750763034362895579L) * 1099511628211L ^ *(byte*)((ulong)(nint)pos + 9uL)) * 1099511628211L ^ *(byte*)((ulong)(nint)pos + 10uL)) * 1099511628211L ^ *(byte*)((ulong)(nint)pos + 11uL)) * 1099511628211L + (long)(num3 * 64)) ^ num3);
        }
    }

    public double Length
    {
        get
        {
            int z = this.z;
            int y = this.y;
            int x = this.x;
            return Math.Sqrt(x * x + y * y + z * z);
        }
    }

    public unsafe ref int this[int index]
    {
        get
        {
            fixed (BlockPos* ptr = &this)
            {
                long num = (nint)ptr;
                return ref *(int*)(index switch
                {
                    2 => (nint)(num + 8),
                    1 => (nint)(num + 4),
                    _ => (nint)num,
                });
            }
        }
    }

    public BlockPos[] Neighbors
    {
        get
        {
            return new BlockPos[6]
            {
                new(x,y-1,z),
                new(x,y+1,z),
                new(x,y,z-1),
                new(x,y,z+1),
                new(x-1,y,z),
                new(x+1,y,z),
            };
        }
    }

    public BlockPos Neighbor(byte val)
    {
        [DllImport(BDS, EntryPoint = "?neighbor@BlockPos@@QEBA?AV1@E@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern BlockPos __invoke(ref BlockPos @this, byte num);

        return __invoke(ref this, val);
    }

    public int RandomSeed()
    {
        [DllImport(BDS, EntryPoint = "?randomSeed@BlockPos@@QEBAHXZ")]
        [SuppressUnmanagedCodeSecurity]
        static extern int __invoke(ref BlockPos @this);

        return __invoke(ref this);
    }

    public BlockPos Relative(byte a1, int a2)
    {
        [DllImport(BDS, EntryPoint = "?relative@BlockPos@@QEBA?AV1@EH@Z")]
        [SuppressUnmanagedCodeSecurity]
        static extern BlockPos __invoke(ref BlockPos @this, byte a1, int a2);

        return __invoke(ref this, a1, a2);
    }

    public void BindType()
    {
        [DllImport(BDS, EntryPoint = "?bindType@BlockPos@@SAXXZ")]
        [SuppressUnmanagedCodeSecurity]
        static extern void __invoke(ref BlockPos @this);

        __invoke(ref this);
    }

    public BlockPos Add(int dx, int dy = 0, int dz = 0)
        => new(x + dx, y + dy, z + dz);

    public static bool operator ==(BlockPos obj, BlockPos b)
    {
        int num = obj.x == b.x && obj.y == b.y && obj.z == b.z ? 1 : 0;
        return (byte)num != 0;
    }

    public static bool operator !=(BlockPos obj, BlockPos b)
    {
        int num = obj.x != b.x || obj.y != b.y || obj.z != b.z ? 1 : 0;
        return (byte)num != 0;
    }

    public static BlockPos operator +(BlockPos obj, int b)
    {
        Unsafe.SkipInit(out BlockPos result);
        result.x = obj.x + b;
        result.y = obj.y + b;
        result.z = obj.z + b;
        return result;
    }

    public static BlockPos operator +(BlockPos obj, BlockPos b)
    {
        Unsafe.SkipInit(out BlockPos result);
        result.x = obj.x + b.x;
        result.y = obj.y + b.y;
        result.z = obj.z + b.z;
        return result;
    }

    public static BlockPos operator *(BlockPos obj, int b)
    {
        Unsafe.SkipInit(out BlockPos result);
        result.x = obj.x * b;
        result.y = obj.y * b;
        result.z = obj.z * b;
        return result;
    }

    public static BlockPos operator *(BlockPos obj, BlockPos b)
    {
        Unsafe.SkipInit(out BlockPos result);
        result.x = obj.x * b.x;
        result.y = obj.y * b.y;
        result.z = obj.z * b.z;
        return result;
    }

    public static BlockPos operator /(BlockPos obj, int b)
    {
        Unsafe.SkipInit(out BlockPos result);
        result.x = obj.x / b;
        result.y = obj.y / b;
        result.z = obj.z / b;
        return result;
    }

    public static BlockPos operator /(BlockPos obj, BlockPos b)
    {
        Unsafe.SkipInit(out BlockPos result);
        result.x = obj.x / b.x;
        result.y = obj.y / b.y;
        result.z = obj.z / b.z;
        return result;
    }

    public static BlockPos operator -(BlockPos obj, int b)
    {
        Unsafe.SkipInit(out BlockPos result);
        result.x = obj.x - b;
        result.y = obj.y - b;
        result.z = obj.z - b;
        return result;
    }

    public static BlockPos operator -(BlockPos obj, BlockPos b)
    {
        Unsafe.SkipInit(out BlockPos result);
        result.x = obj.x - b.x;
        result.y = obj.y - b.y;
        result.z = obj.z - b.z;
        return result;
    }

    public Vec3 BottomCenter
    {
        get
        {
            [DllImport(BDS, EntryPoint = "?bottomCenter@BlockPos@@QEBA?AVVec3@@XZ")]
            [SuppressUnmanagedCodeSecurity]
            static extern Vec3 __invoke(ref BlockPos @this);

            return __invoke(ref this);
        }
    }

    public Vec3 Center
    {
        get
        {
            [DllImport(BDS, EntryPoint = "?center@BlockPos@@QEBA?AVVec3@@XZ")]
            [SuppressUnmanagedCodeSecurity]
            static extern Vec3 __invoke(ref BlockPos @this);

            return __invoke(ref this);
        }
    }

    public override bool Equals(object? obj)
    {
        if (obj is BlockPos pos)
            return pos == this;

        return false;
    }

    static BlockPos()
    {
        MAX_ptr = (BlockPos*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(MAX)}@BlockPos@@2V1@B");
        MIN_ptr = (BlockPos*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(MIN)}@BlockPos@@2V1@B");
        ONE_ptr = (BlockPos*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(ONE)}@BlockPos@@2V1@B");
        ZERO_ptr = (BlockPos*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(ZERO)}@BlockPos@@2V1@B");
    }
}
