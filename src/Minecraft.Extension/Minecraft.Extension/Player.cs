using BedrockServer.Extension.Handle;
using LiteLoader.NET;
using LiteLoader.NET.CppStd;
using LiteLoader.NET.InteropServices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace BedrockServer.Extension;

public class Player : PlayerHandle, IConstructableCppClass<Player>
{
    public Player()
    {
    }

    public Player(nint ptr, bool ownInstance) : base(ptr, ownInstance)
    {
    }

    public Player ConstructInstance(nint ptr, bool ownsInstance)
    {
        return new(ptr, ownsInstance);
    }

    public void SetNativePointer(nint ptr, bool ownsInstance)
    {
        NativePointer = ptr;
        OwnsNativeInstance = ownsInstance;
    }

    //public delegate void SimpleFormCallback(Player player, int chosen);
    //public delegate void ModalFormCallback(Player player, [MarshalAs(UnmanagedType.U1)] bool chosen);
    //public delegate void CustomFormCallback(Player player, string data);

    //private unsafe delegate void __SimpleFormCallback(void* player, int chosen);
    //private unsafe delegate void __ModalFormCallback(void* player, [MarshalAs(UnmanagedType.U1)] bool chosen);
    //private unsafe delegate void __CustomFormCallback(void* player, void* str);

    //private unsafe class CallbackHandler
    //{
    //    Delegate @delegate;
    //    GCHandle handle;

    //    public CallbackHandler(Delegate @delegate)
    //    {
    //        this.@delegate = @delegate;
    //        handle = GCHandle.Alloc(this);
    //    }

    //    public void SendModalFormCallback(void* pl, [MarshalAs(UnmanagedType.U1)] bool val)
    //    {
    //        (@delegate as ModalFormCallback)!(new Player((nint)pl, false), val);
    //        if (handle.IsAllocated)
    //        {
    //            handle.Free();
    //        }
    //    }

    //    public void SendSimpleFormCallback(void* pl, int val)
    //    {
    //        (@delegate as SimpleFormCallback)!(new Player((nint)pl, false), val);
    //        if (handle.IsAllocated)
    //        {
    //            handle.Free();
    //        }
    //    }

    //    public void SendCustomFormCallback(void* pl, void* val)
    //    {
    //        (@delegate as CustomFormCallback)!(new Player((nint)pl, false), new @string((nint)val, false).ToString());
    //        if (handle.IsAllocated)
    //        {
    //            handle.Free();
    //        }
    //    }
    //}


    public unsafe bool SendSimpleForm(string title, string content, IList<string> buttons, IList<string> images, function<Action<pointer<Player>, int>> callback)
    {
        return __SendSimpleForm(title, content, buttons, images, (void*)callback.NativePointer);
    }

    public unsafe bool SendModalForm(string title, string content, string button1, string button2, function<Action<pointer<Player>, byte>> callback)
    {
        return __SendModalForm(title, content, button1, button2, (void*)callback.NativePointer);
    }


    public unsafe bool SendCustomForm(string data, function<Action<pointer<Player>, instance<@string>>> callback)
    {
        return __SendCustomForm(data, (void*)callback.NativePointer);
    }
}
