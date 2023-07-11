using BedrockServer.Extension.Handle;
using LiteLoader.NET.InteropServices;

namespace BedrockServer.Extension;

public class Actor : ActorHandle, IConstructableCppClass<Actor>
{
    public Actor()
    {
    }

    public Actor(nint ptr, bool ownInstance) : base(ptr, ownInstance)
    {
    }

    public Actor ConstructInstance(nint ptr, bool ownsInstance)
        => new(ptr, ownsInstance);

    public void SetNativePointer(nint ptr, bool ownsInstance)
    {
        NativePointer = ptr;
        OwnsNativeInstance = ownsInstance;
    }
}
