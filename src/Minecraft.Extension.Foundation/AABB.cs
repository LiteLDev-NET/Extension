using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security;

namespace BedrockServer;

[StructLayout(LayoutKind.Sequential)]
public unsafe struct AABB
{
    internal Vec3 min;
    internal Vec3 max;

    public Vec3 Min { get => min; set => min = value; }
    public Vec3 Max { get => max; set => max = value; }

    private static readonly AABB* BLOCK_SHAPE_ptr;
    private static readonly AABB* BOX_AT_ORIGIN_WITH_NO_VOLUME_ptr;

    public static AABB BLOCK_SHAPE => *BLOCK_SHAPE_ptr;

    public static AABB BOX_AT_ORIGIN_WITH_NO_VOLUME => *BOX_AT_ORIGIN_WITH_NO_VOLUME_ptr;

    static AABB()
    {
        BLOCK_SHAPE_ptr = (AABB*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(BLOCK_SHAPE)}@AABB@@2V1@B");
        BOX_AT_ORIGIN_WITH_NO_VOLUME_ptr = (AABB*)DlsymRealThrowIfNull<NullReferenceException>($"?{nameof(BOX_AT_ORIGIN_WITH_NO_VOLUME)}@AABB@@2V1@B");
    }

    public unsafe ref Vec3 this[int index]
    {
        get
        {
            fixed (AABB* ptr = &this)
            {
                long num = (nint)ptr;
                return ref *(Vec3*)(index == 1 ? num + 12 : num);
            }
        }
    }

    public bool IsValid
    {
        get
        {
            [DllImport(BDS, EntryPoint = "?isValid@AABB@@QEBA_NXZ")]
            [return: MarshalAs(UnmanagedType.U1)]
            [SuppressUnmanagedCodeSecurity]
            static extern bool __invoke(ref AABB @this);

            return __invoke(ref this);
        }
    }

    public float Volume
    {
        get
        {
            [DllImport(BDS, EntryPoint = "?getVolume@AABB@@QEBAMXZ")]
            [SuppressUnmanagedCodeSecurity]
            static extern float __invoke(ref AABB @this);

            return __invoke(ref this);
        }
    }

    public float Size
    {
        get
        {
            [DllImport(BDS, EntryPoint = "?getSize@AABB@@QEBAMXZ")]
            [SuppressUnmanagedCodeSecurity]
            static extern float __invoke(ref AABB @this);

            return __invoke(ref this);
        }
    }

    public Vec3 Center
    {
        get
        {
            [DllImport(BDS, EntryPoint = "?getCenter@AABB@@QEBA?AVVec3@@XZ")]
            [SuppressUnmanagedCodeSecurity]
            static extern Vec3 __invoke(ref AABB @this);

            return __invoke(ref this);
        }
    }

    public Vec3 Bounds
    {
        get
        {
            [DllImport(BDS, EntryPoint = "?getBounds@AABB@@QEBA?AVVec3@@XZ")]
            [SuppressUnmanagedCodeSecurity]
            static extern Vec3 __invoke(ref AABB @this);

            return __invoke(ref this);
        }
    }
}
