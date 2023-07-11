using BedrockServer.Extension.Handle;
using LiteLoader.NET.InteropServices;

namespace BedrockServer.Extension;

public class ServerPlayer : ServerPlayerHandle, IConstructableCppClass<ServerPlayer>
{
    public ServerPlayer()
    {
    }

    public ServerPlayer(nint ptr, bool ownInstance) : base(ptr, ownInstance)
    {
    }

    public ServerPlayer ConstructInstance(nint ptr, bool ownsInstance)
        => new(ptr, ownsInstance);

    public void SetNativePointer(nint ptr, bool ownsInstance)
    {
        NativePointer = ptr;
        OwnsNativeInstance = ownsInstance;
    }
}
