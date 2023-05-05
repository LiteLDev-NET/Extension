#pragma once
#include <mc/Types.hpp>

#include <Tools/Global.hpp>
#include "Mce.hpp"

namespace BedrockServer
{
    [StructLayout(LayoutKind::Sequential, Size = sizeof(::ActorUniqueID))]
    public value struct ActorUniqueID
    {
        long long id;
    internal:
        operator ::ActorUniqueID();
        static operator ActorUniqueID(::ActorUniqueID const& obj)
        {
            return ActorUniqueID{ obj.id };
        }
        ActorUniqueID(::ActorUniqueID const* p);
    public:
        ActorUniqueID(long long i);
        property long long Id
        {
            long long get();
            void set(long long value);
        }
        static operator long long(ActorUniqueID obj);
    };

    generic<typename A, typename T> public value class AutomaticID
    {
        T id;

    public:
        AutomaticID(T x);
        inline static operator T(AutomaticID<A, T>^);
    };

    public value class ActorRuntimeID
    {
    public:
        unsigned long long id;

        ActorRuntimeID(unsigned long long id);
        property unsigned long long Id { unsigned long long get(); void set(unsigned long long); }
        static operator unsigned long long(ActorRuntimeID id);
    };

    public enum class ContainerType : char {
        NONE = -9,
        INVENTORY = -1,
        CONTAINER = 0,
        WORKBENCH = 1,
        FURNACE = 2,
        ENCHANTMENT = 3,
        BREWINGSTAND = 4,
        ANVIL = 5,
        DISPENSER = 6,
        DROPPER = 7,
        HOPPER = 8,
        CAULDRON = 9,
        MINECARTCHEST = 10,
        MINECARTHOPPER = 11,
        HORSE = 12,
        BEACON = 13,
        STRUCTUREEDITOR = 14,
        TRADE = 15, // NotGenerated
        COMMANDBLOCK = 16,
        JUKEBOX = 17,
        ARMOR = 18,
        HAND = 19,
        COMPOUNDCREATOR = 20,
        ELEMENTCONSTRUCTOR = 21,
        MATERIALREDUCER = 22,
        LABTABLE = 23,
        LOOM = 24,
        LECTERN = 25,
        GRINDSTONE = 26,
        BLASTFURNACE = 27,
        SMOKER = 28,
        STONECUTTER = 29,
        CARTOGRAPHY = 30,
        HUD = 31,
        JIGSAWEDITOR = 32,
        SMITHINGTABLE = 33,
        BOATCHEST = 34,
    };

    public enum class GameType : int {
        GameTypeSurvival = 0,
        GameTypeCreative = 1,
        GameTypeAdventure = 2,
        GameTypeSpectator = 6
    };

    public enum class Difficulty : int {
        DifficultyPeaceful = 0,
        DifficultyEasy = 1,
        DifficultyNormal = 2,
        DifficultyHard = 3
    };

    public enum class PlayerPermissionLevel : int {
        PlayerPermissionLevelVisitor = 0,
        PlayerPermissionLevelMember = 1,
        PlayerPermissionLevelOperator = 2,
        PlayerPermissionLevelCustom = 3
    };

    public enum class CommandPermissionLevel : char {
        Any = 0,
        GameMasters = 1,
        Admin = 2,
        HostPlayer = 3,
        Console = 4,
        Internal = 5,
    };

    public enum class OriginType : char {
        PlayerHandle = 0,
        BlockHandle = 1,
        MinecartBlock = 2,
        DevConsole = 3,
        Test = 4,
        AutomationPlayer = 5,
        ClientAutomation = 6,
        Server = 7,
        ActorHandle = 8,
        Virtual = 9,
        GameArgument = 10,
        ActorServer = 11,
        Precompiled = 12,
        GameDirectorEntity = 13,
        Script = 14,
        ExecuteContext = 15,

        DedicatedServer = 7, // Server
    };

    public enum class CommandParameterDataType {
        NORMAL,
        ENUM,
        SOFT_ENUM,
        POSIFIX,
    };

    public enum class SemanticConstraint : unsigned char
    {
        NoneConstraint = 0,
        RequiresCheatsEnabled = 1,
        RequiresElevatedPermissions = 2,
        RequiresHostPermissions = 4,
        VALUE_MASK = 8,
    };

    public enum class CommandParameterOption : unsigned char
    {
        None = 0,
        EnumAutocompleteExpansion = 1,
        HasSemanticConstraint = 2, //be used in block or item name enum
        EnumAsChainedCommand = 4,  //be used in NewExecuteCommand
    };

    public enum class UpdateBlockLayer : int {
        UpdateBlockDefault,
        UpdateBlockLiquid
    };

    public enum class UpdateBlockFlags : int {
        UpdateBlockNone = 0,
        BlockUpdateNeighbors = 1,
        BlockUpdateNetwork = 2,
        BlockUpdateAll = 3, // default value in BDS
        BlockUpdateNoGraphic = 4,
        BlockUpdatePriority = 8,
        BlockUpdateAllPriority = 11
        // old one not correctly ?
        // BlockUpdateNeighbours = 1,
        // BlockUpdateNetwork = 2,
        // BlockUpdateNoGraphics = 3,
        // BlockUpdatePriority = 4,
    };

    public enum class TextType : char {
        RAW = 0,
        CHAT = 1,
        TRANSLATION = 2,
        POPUP = 3,
        JUKEBOX_POPUP = 4,
        TIP = 5,
        SYSTEM = 6,
        WHISPER = 7,
        ANNOUNCEMENT = 8,
        JSON_WHISPER = 9,
        JSON = 10
    };

    /**
     * @brief The title type
     *
     */
    public enum class TitleType : int {
        Clear = 0,
        Reset = 1,

        /**
         * @brief The main title
         *
         */
        SetTitle = 2,

        /**
         * @brief The subtitle
         *
         */
        SetSubtitle = 3,

        /**
         * @brief The actionbar title
         *
         */
        SetActionBar = 4,

        SetDurations = 5,
        TitleTextObject = 6,
        SubtitleTextObject = 7,
        ActionbarTextObject = 8
    };

    public enum class BossEvent : int {
        Show = 0,
        RegisterPlayer = 1,
        Hide = 2,
        UnregisterPlayer = 3,
        HealthPercentage = 4,
        Title = 5,
        AppearanceProperties = 6,
        Texture = 7,
        ResendRaidBossEventData = 8,
    };

    public enum class BossEventColour : int {
        Grey = 0,
        Blue = 1,
        Red = 2,
        Green = 3,
        Yellow = 4,
        Purple = 5,
        White = 6
    };

    public enum class ContainerEnumName : int8_t {
        AnvilInputContainer = 0,
        AnvilMaterialContainer = 1,
        AnvilResultPreviewContainer = 2,
        SmithingTableInputContainer = 3,
        SmithingTableMaterialContainer = 4,
        SmithingTableResultPreviewContainer = 5,
        ArmorContainer = 6,
        LevelEntityContainer = 7,
        BeaconPaymentContainer = 8,
        BrewingStandInputContainer = 9,
        BrewingStandResultContainer = 10,
        BrewingStandFuelContainer = 11,
        CombinedHotbarAndInventoryContainer = 12,
        CraftingInputContainer = 13,
        CraftingOutputPreviewContainer = 14,
        RecipeConstructionContainer = 15,
        RecipeNatureContainer = 16,
        RecipeItemsContainer = 17,
        RecipeSearchContainer = 18,
        RecipeSearchBarContainer = 19,
        RecipeEquipmentContainer = 20,
        RecipeBookContainer = 21,
        EnchantingInputContainer = 22,
        EnchantingMaterialContainer = 23,
        FurnaceFuelContainer = 24,
        FurnaceIngredientContainer = 25,
        FurnaceResultContainer = 26,
        HorseEquipContainer = 27,
        HotbarContainer = 28,
        InventoryContainer = 29,
        ShulkerBoxContainer = 30,
        TradeIngredient1Container = 31,
        TradeIngredient2Container = 32,
        TradeResultPreviewContainer = 33,
        OffhandContainer = 34,
        CompoundCreatorInput = 35,
        CompoundCreatorOutputPreview = 36,
        ElementConstructorOutputPreview = 37,
        MaterialReducerInput = 38,
        MaterialReducerOutput = 39,
        LabTableInput = 40,
        LoomInputContainer = 41,
        LoomDyeContainer = 42,
        LoomMaterialContainer = 43,
        LoomResultPreviewContainer = 44,
        BlastFurnaceIngredientContainer = 45,
        SmokerIngredientContainer = 46,
        Trade2Ingredient1Container = 47,
        Trade2Ingredient2Container = 48,
        Trade2ResultPreviewContainer = 49,
        GrindstoneInputContainer = 50,
        GrindstoneAdditionalContainer = 51,
        GrindstoneResultPreviewContainer = 52,
        StonecutterInputContainer = 53,
        StonecutterResultPreviewContainer = 54,
        CartographyInputContainer = 55,
        CartographyAdditionalContainer = 56,
        CartographyResultPreviewContainer = 57,
        BarrelContainer = 58,
        CursorContainer = 59,
        CreatedOutputContainer = 60
    };

    public enum class ParticleType {
        dragondestroyblock = 0x40,
        none = 0x00,
        bubble = 0x01,
        bubblemanual = 0x02,
        crit = 0x03,
        blockforcefield = 0x04,
        smoke = 0x05,
        explode = 0x06,
        evaporation = 0x07,
        flame = 0x08,
        candleflame = 0x09,
        lava = 0x0a,
        largesmoke = 0x0b,
        reddust = 0x0c,
        risingborderdust = 0x0d,
        iconcrack = 0x0e,
        snowballpoof = 0x0f,
        largeexplode = 0x10,
        hugeexplosion = 0x11,
        mobflame = 0x12,
        heart = 0x13,
        terrain = 0x14,
        townaura = 0x15,
        portal = 0x16,
        watersplash = 0x18,
        watersplashmanual = 0x19,
        waterwake = 0x1a,
        dripwater = 0x1b,
        driplava = 0x1c,
        driphoney = 0x1d,
        stalactitedripwater = 0x1e,
        stalactitedriplava = 0x1f,
        fallingdust = 0x20,
        mobspell = 0x21,
        mobspellambient = 0x22,
        mobspellinstantaneous = 0x23,
        ink = 0x24,
        slime = 0x25,
        rainsplash = 0x26,
        villagerangry = 0x27,
        villagerhappy = 0x28,
        enchantingtable = 0x29,
        trackingemitter = 0x2a,
        note = 0x2b,
        witchspell = 0x2c,
        carrotboost = 0x2d,
        mobappearance = 0x2e,
        endrod = 0x2f,
        dragonbreath = 0x30,
        spit = 0x31,
        totem = 0x32,
        food = 0x33,
        fireworksstarter = 0x34,
        fireworks = 0x35,
        fireworksoverlay = 0x36,
        balloongas = 0x37,
        coloredflame = 0x38,
        sparkler = 0x39,
        conduit = 0x3a,
        bubblecolumnup = 0x3b,
        bubblecolumndown = 0x3c,
        sneeze = 0x3d,
        shulkerbullet = 0x3e,
        bleach = 0x3f,
        myceliumdust = 0x41,
        fallingborderdust = 0x42,
        campfiresmoke = 0x43,
        campfiresmoketall = 0x44,
        dragonbreathfire = 0x45,
        dragonbreathtrail = 0x46,
        soul = 0x48,
        obsidiantear = 0x49,
        portalreverse = 0x4a,
        snowflake = 0x4b,
        wax = 0x50,
        electricspark = 0x51,
        shriek = 0x52,
        sculksoul = 0x53
    };

    public enum class transactionType {
        NormalTransaction = 0x00,
        InventoryMismatch = 0x01,
        ItemUseTransaction = 0x02,
        ItemUseOnEntityTransaction = 0x03,
        ItemReleaseTransaction = 0x04
    };

    public enum class ItemStackRequestActionType : char {
        Take = 0x00,
        Place = 0x01,
        Swap = 0x02,
        Drop = 0x03,
        Destroy = 0x04,
        Consume = 0x05,
        Create = 0x06,
        PlaceInItemContainer = 0x07,
        TakeFromItemContainer = 0x08,
        ScreenLabTableCombine = 0x09,
        ScreenBeaconPayment = 0x0a,
        ScreenHUDMineBlock = 0x0b,
        CraftRecipe = 0x0c,
        CraftRecipeAuto = 0x0d,
        CraftCreative = 0x0e,
        CraftRecipeOptional = 0x0f,
        CraftRepairAndDisenchant = 0x10,
        CraftLoom = 0x11,
        CraftNonImplemented_DEPRECATEDASKTYLAING = 0x12,
        CraftResults_DEPRECATEDASKTYLAING = 0x13,
    };

    /**
     * @brief Ranking method of the objective
     *
     */
    public enum class ObjectiveSortOrder : char {
        /**
         * @brief Ascending
         *
         */
        Ascending = 0,

        /**
         * @brief Descending
         *
         */
        Descending = 1
    };

    public enum class PlayerScoreSetFunction : char {
        Set = 0,
        Add = 1,
        Remove = 2
    };

    public enum class ContainerID : uint8_t {
        Invalid = 0xff,
        Inventory = 0,
        First = 1,
        Last = 100,
        Offhand = 119,
        Armor = 120,
        SelectionSlots = 122,
        PlayerUIOnly = 124
    };

    public enum class FaceID : char {
        Unknown = -1,
        Down = 0,
        Up = 1,
        North = 2,
        South = 3,
        West = 4,
        East = 5,
    };

    public enum class MinecraftPacketIds : int {
        Login = 0x01,
        PlayStatus = 0x02,
        ServerToClientHandshake = 0x03,
        ClientToServerHandshake = 0x04,
        Disconnect = 0x05,
        ResourcePacksInfo = 0x06,
        ResourcePackStack = 0x07,
        ResourcePackClientResponse = 0x08,
        Text = 0x09,
        SetTime = 0x0A,
        StartGame = 0x0B,
        AddPlayer = 0x0C,
        AddActor = 0x0D,
        RemoveActor = 0x0E,
        AddItemActor = 0x0F,
        TakeItemActor = 0x11,
        MoveActorAbsolute = 0x12,
        MovePlayer = 0x13,
        PassengerJump = 0x14,
        UpdateBlock = 0x15,
        AddPainting = 0x16,
        TickSync = 0x17,
        LevelSoundEventV1 = 0x18,
        LevelEvent = 0x19,
        BlockEvent = 0x1A,
        ActorEvent = 0x1B,
        MobEffectHandle = 0x1C,
        UpdateAttributes = 0x1D,
        InventoryTransaction = 0x1E,
        MobEquipment = 0x1F,
        MobArmorEquipment = 0x20,
        Interact = 0x21,
        BlockPickRequest = 0x22,
        ActorPickRequest = 0x23,
        PlayerAction = 0x24,
        HurtArmor = 0x26,
        SetActorData = 0x27,
        SetActorMotion = 0x28,
        SetActorLink = 0x29,
        SetHealth = 0x2A,
        SetSpawnPosition = 0x2B,
        Animate = 0x2C,
        Respawn = 0x2D,
        ContainerOpen = 0x2E,
        ContainerClose = 0x2F,
        PlayerHotbar = 0x30,
        InventoryContent = 0x31,
        InventorySlot = 0x32,
        ContainerSetData = 0x33,
        CraftingData = 0x34,
        CraftingEvent = 0x35,
        GuiDataPickItem = 0x36,
        AdventureSettings = 0x37,// removed
        BlockActorData = 0x38,
        PlayerInput = 0x39,
        LevelChunk = 0x3A,
        SetCommandsEnabled = 0x3B,
        SetDifficulty = 0x3C,
        ChangeDimension = 0x3D,
        SetPlayerGameType = 0x3E,
        PlayerList = 0x3F,
        SimpleEvent = 0x40,
        Event = 0x41,
        SpawnExperienceOrb = 0x42,
        ClientboundMapItemData = 0x43,
        MapInfoRequest = 0x44,
        RequestChunkRadius = 0x45,
        ChunkRadiusUpdated = 0x46,
        ItemFrameDropItem = 0x47,
        GameRulesChanged = 0x48,
        Camera = 0x49,
        BossEvent = 0x4A,
        ShowCredits = 0x4B,
        AvailableCommands = 0x4C,
        CommandRequest = 0x4D,
        CommandBlockUpdate = 0x4E,
        CommandOutput = 0x4F,
        UpdateTrade = 0x50,
        UpdateEquip = 0x51,
        ResourcePackDataInfo = 0x52,
        ResourcePackChunkData = 0x53,
        ResourcePackChunkRequest = 0x54,
        Transfer = 0x55,
        PlaySound = 0x56,
        StopSound = 0x57,
        SetTitle = 0x58,
        AddBehaviorTree = 0x59,
        StructureBlockUpdate = 0x5A,
        ShowStoreOffer = 0x5B,
        PurchaseReceipt = 0x5C,
        PlayerSkin = 0x5D,
        SubClientLogin = 0x5E,
        AutomationClientConnect = 0x5F,
        SetLastHurtBy = 0x60,
        BookEdit = 0x61,
        NpcRequest = 0x62,
        PhotoTransfer = 0x63,
        ModalFormRequest = 0x64,
        ModalFormResponse = 0x65,
        ServerSettingsRequest = 0x66,
        ServerSettingsResponse = 0x67,
        ShowProfile = 0x68,
        SetDefaultGameType = 0x69,
        RemoveObjective = 0x6A,
        SetDisplayObjective = 0x6B,
        SetScore = 0x6C,
        LabTable = 0x6D,
        UpdateBlockSynced = 0x6E,
        MoveActorDelta = 0x6F,
        SetScoreboardIdentity = 0x70,
        SetLocalPlayerAsInitialized = 0x71,
        UpdateSoftEnum = 0x72,
        NetworkStackLatency = 0x73,
        ScriptCustomEvent = 0x75,
        SpawnParticleEffect = 0x76,
        AvailableActorIdentifiers = 0x77,
        LevelSoundEventV2 = 0x78,
        NetworkChunkPublisherUpdate = 0x79,
        BiomeDefinitionList = 0x7A,
        LevelSoundEvent = 0x7B,
        LevelEventGeneric = 0x7C,
        LecternUpdate = 0x7D,
        AddEntity = 0x7F,
        RemoveEntity = 0x80,
        ClientCacheStatus = 0x81,
        OnScreenTextureAnimation = 0x82,
        MapCreateLockedCopy = 0x83,
        StructureTemplateDataRequest = 0x84,
        StructureTemplateDataResponse = 0x85,
        ClientCacheBlobStatus = 0x87,
        ClientCacheMissResponse = 0x88,
        EducationSettings = 0x89,
        Emote = 0x8A,
        MultiplayerSettings = 0x8B,
        SettingsCommand = 0x8C,
        AnvilDamage = 0x8D,
        CompletedUsingItem = 0x8E,
        NetworkSettings = 0x8F,
        PlayerAuthInput = 0x90,
        CreativeContent = 0x91,
        PlayerEnchantOptions = 0x92,
        ItemStackRequest = 0x93,
        ItemStackResponse = 0x94,
        PlayerArmorDamage = 0x95,
        CodeBuilder = 0x96,
        UpdatePlayerGameType = 0x97,
        EmoteList = 0x98,
        PositionTrackingDBServerBroadcast = 0x99,
        PositionTrackingDBClientRequest = 0x9A,
        DebugInfo = 0x9B,
        PacketViolationWarning = 0x9C,
        MotionPredictionHints = 0x9D,
        AnimateEntity = 0x9E,
        CameraShake = 0x9F,
        PlayerFog = 0xA0,
        CorrectPlayerMovePrediction = 0xA1,
        ItemComponent = 0xA2,
        FilterText = 0xA3,
        ClientboundDebugRenderer = 0xA4,
        SyncActorProperty = 0xA5,
        AddVolumeEntity = 0xA6,
        RemoveVolumeEntity = 0xA7,
        SimulationType = 0xA8,
        NpcDialogue = 0xA9,
        EduUriResource = 0xAA,
        CreatePhoto = 0xAB,
        UpdateSubChunkBlocks = 0xAC,
        PhotoInfoRequest = 0xAD, // removed
        SubChunk = 0xAE,
        SubChunkRequest = 0xAF,
        PlayerStartItemCooldown = 0xB0,
        ScriptMessage = 0xB1,
        CodeBuilderSource = 0xB2,
        TickingAreasLoadStatus = 0xB3,
        DimensionData = 0xB4,
        AgentActionEvent = 0xB5,
        ChangeMobProperty = 0xB6,
        LessonProgress = 0xB7,
        RequestAbility = 0xB8,
        RequestPermissions = 0xB9,
        ToastRequest = 0xBA,
        UpdateAbilities = 0xBB,
        UpdateAdventureSettings = 0xBC,
        DeathInfo = 0xBD,
        EditorNetwork = 0xBE,
        FeatureRegistry = 0xBF,
        ServerStats = 0xC0,
        RequestNetworkSettings = 0xC1,
        GameTestRequest = 0XC2,
        GameTestResults = 0xC3,
        UpdateClientInputLocks = 0xC4,
        ClientCheatAbility = 0xC5,
        CameraPresets = 0xC6,
        UnlockedRecipes = 0xC7,
        CameraInstruction = 0x12C // 300
    };

    public enum class ItemStackNetResult : unsigned char {
        Success = 0,
        Error = 1,
        InvalidRequestActionType = 2,
        ActionRequestNotAllowed = 3,
        ScreenHandlerEndRequestFailed = 4,
        ItemRequestActionHandlerCommitFailed = 5,
        InvalidRequestCraftActionType = 6,
        InvalidCraftRequest = 7,
        InvalidCraftRequestScreen = 8,
        InvalidCraftResult = 9,
        InvalidCraftResultIndex = 10,
        InvalidCraftResultItem = 11,
        InvalidItemNetId = 12,
        MissingCreatedOutputContainer = 13,
        FailedToSetCreatedItemOutputSlot = 14,
        RequestAlreadyInProgress = 15,
        FailedToInitSparseContainer = 16,
        ResultTransferFailed = 17,
        ExpectedItemSlotNotFullyConsumed = 18,
        ExpectedAnywhereItemNotFullyConsumed = 19,
        ItemAlreadyConsumedFromSlot = 20,
        ConsumedTooMuchFromSlot = 21,
        MismatchSlotExpectedConsumedItem = 22,
        MismatchSlotExpectedConsumedItemNetIdVariant = 23,
        FailedToMatchExpectedSlotConsumedItem = 24,
        FailedToMatchExpectedAllowedAnywhereConsumedItem = 25,
        ConsumedItemOutOfAllowedSlotRange = 26,
        ConsumedItemNotAllowed = 27,
        PlayerNotInCreativeMode = 28,
        InvalidExperimentalRecipeRequest = 29,
        FailedToCraftCreative = 30,
        FailedToGetLevelRecipe = 31,
        FailedToFindRecipeByNetId = 32,
        MismatchedCraftingSize = 33,
        MissingInputSparseContainer = 34,
        MismatchedRecipeForInputGridItems = 35,
        EmptyCraftResults = 36,
        FailedToEnchant = 37,
        MissingInputItem = 38,
        InsufficientPlayerLevelToEnchant = 39,
        MissingMaterialItem = 40,
        MissingActor = 41,
        UnknownPrimaryEffect = 42,
        PrimaryEffectOutOfRange = 43,
        PrimaryEffectUnavailable = 44,
        SecondaryEffectOutOfRange = 45,
        SecondaryEffectUnavailable = 46,
        DstContainerEqualToCreatedOutputContainer = 47,
        DstContainerAndSlotEqualToSrcContainerAndSlot = 48,
        FailedToValidateSrcSlot = 49,
        FailedToValidateDstSlot = 50,
        InvalidAdjustedAmount = 51,
        InvalidItemSetType = 52,
        InvalidTransferAmount = 53,
        CannotSwapItem = 54,
        CannotPlaceItem = 55,
        UnhandledItemSetType = 56,
        InvalidRemovedAmount = 57,
        InvalidRegion = 58,
        CannotDropItem = 59,
        CannotDestroyItem = 60,
        InvalidSourceContainer = 61,
        ItemNotConsumed = 62,
        InvalidNumCrafts = 63,
        InvalidCraftResultStackSize = 64,
        CannotConsumeItem = 66,
        ScreenStackError = 67,
    };

    // class CommandVersion {
    // public:
    //     int Min = 1, Max = 0x7FFFFFFF;
    // };

    public enum class ClientPlayMode {
        Normal = 0,
        Teaser = 1,
        Screen = 2,
        Viewer = 3,
        VR = 4,
        Placement = 5,
        LivingRoom = 6,
        ExitLevel = 7,
        ExitLevelLivingRoom = 8
    };

    public enum class InputMode {
        Mouse = 1,
        Touch = 2,
        GamePad = 3,
        MotionController = 4
    };

    public enum class InventoryTransactionError {
        Unknown = 0,
        NoError = 1,
        BalanceMismatch = 2,
        SourceItemMismatch = 3,
        InventoryMismatch = 4,
        SizeMismatch = 5,
        AuthorityMismatch = 6,
        StateMismatch = 7,
        ApiDenied = 8
    };

    public enum class InventorySourceType {
        Invalid = -1,
        ContainerHandle = 0,
        Global = 1,
        World = 2,
        Creative = 3,
        UntrackedInteractionUI = 100,
        NONIMPLEMENTEDTODO = 99999
    };

    public enum class Mirror : unsigned char {
        None = 0,
        X,
        Z,
        XZ,
    };
    public enum class Rotation : unsigned char {
        None = 0,
        Rotate90,
        Rotate180,
        Rotate270,
        Total,
    };

    public enum class EquipmentSlot : int {
        _none = 0xFF,
        _begin = 0x0,
        _handSlot = 0x0,
        Mainhand = 0x0,
        Offhand = 0x1,
        _armorSlot = 0x2,
        Head = 0x2,
        Torso = 0x3,
        Legs = 0x4,
        Feet = 0x5,
        _containerSlot = 0x6,
        Hotbar = 0x6,
        Inventory = 0x7,
        EnderChest = 0x8,
        Saddle = 0x9,
        EntityArmor = 0xA,
        Chest = 0xB,
        _count = 0xC,
    };

    public enum class CommandOperator : unsigned char {
        Invalid = 0x0,
        Equals = 0x1,
        PlusEquals = 0x2,
        MinusEquals = 0x3,
        TimesEquals = 0x4,
        DivideEquals = 0x5,
        ModEquals = 0x6,
        MinEquals = 0x7,
        MaxEquals = 0x8,
        Swap = 0x9,
    };

    public enum class ActorLocation : int {
        Feet = 0x0,
        Body = 0x1,
        WeaponAttachPoint = 0x2,
        Head = 0x3,
        DropAttachPoint = 0x4,
        ExplosionPoint = 0x5,
        Eyes = 0x6,
        BreathingPoint = 0x7,
        Mouth = 0x8,
    };

    public enum class StreamReadResult : int {
        Malformed = 0x0,
        Valid = 0x1,
    };

    public enum class BossEventUpdateType
    {
        BossEventShow = 0,
        // BossEventRegisterPlayer is sent by the client to the server to request being shown the boss bar.
        BossEventRegisterPlayer = 1,
        BossEventHide = 2,
        // BossEventUnregisterPlayer is sent by the client to request the removal of the boss bar.
        BossEventUnregisterPlayer = 3,
        BossEventHealthPercentage = 4,
        BossEventTitle = 5,
        BossEventAppearanceProperties = 6,
        BossEventTexture = 7,
    };

    public enum class BuildPlatform : int {
        Android = 0x1,
        iOS = 0x2,
        OSX = 0x3,
        Amazon = 0x4,
        GearVR = 0x5,
        WIN10 = 0x7,
        Win32 = 0x8,
        Dedicated = 0x9,
        PS4 = 0xB,
        Nx = 0xC,
        Xbox = 0xD,
        WindowsPhone = 0xE,
        Linux = 0xF,
        Unknown = 0xFF,
    };

    public enum class AbilitiesIndex : int16_t {
        Build = 0,
        Mine = 1,
        DoorsAndSwitches = 2,
        OpenContainers = 3,
        AttackPlayers = 4,
        AttackMobs = 5,
        OperatorCommands = 6,
        Teleport = 7,
        ExposedAbilityCount = 8,
        Invulnerable = 8,
        Flying = 9,
        MayFly = 10,
        Instabuild = 11,
        Lightning = 12,
        FlySpeed = 13,
        WalkSpeed = 14,
        Muted = 15,
        WorldBuilder = 16,
        NoClip = 17,
        AbilityCount = 18
    };

    public enum class AdventureFlag : int
    {
        WorldImmutable = 1,
        NoPvM = 2,
        NoMvP = 4,
        Unused = 8,
        ShowNameTags = 16,
        AutoJump = 32,
        AllowFlight = 64,
        NoClip = 128,
        WorldBuilder = 256,
        Flying = 512,
        Muted = 1024,
    };

    public enum class TargetSelectionMethod {
        Nearest = 0,
        Random = 1,
    };

    public enum class ActorCategory {
        None = 0,
        PlayerHandle = 1,
        MobHandle = 2,
        MonsterHandle = 4,
        Humandoid = 8,
        HumanoidMonster = 12,
        Animal = 16,
        WaterSpawning = 32,
        WaterAnimal = 48,
        Pathable = 64,
        Tamable = 128,
        TamableAnimal = 144,
        Ridable = 256,
        Item = 1024,
        Ambient = 2048,
        Villager = 4096,
        EvocationIllagerMonster = 4108,
        Arthropod = 8192,
        Undead = 16384,
        UndeadMob = 16388,
        Zombie = 32768,
        ZombieMonster = 32772,
        Minecart = 65536,
        MinecartRidable = 65792,
        Boat = 131072,
        BoatRideable = 131328,
        NonTargetable = 262144,
    };

    public enum class ActorType : __int32 {
        Undefined_2 = 0x1,
        TypeMask = 0xFF,
        MobHandle = 0x100,
        PathfinderMob = 0x300,
        MonsterHandle = 0xB00,
        Animal = 0x1300,
        TamableAnimal = 0x5300,
        Ambient = 0x8100,
        UndeadMob = 0x10B00,
        ZombieMonster = 0x30B00,
        Arthropod = 0x40B00,
        Minecart = 0x80000,
        SkeletonMonster = 0x110B00,
        EquineAnimal = 0x205300,
        Projectile = 0x400000,
        AbstractArrow = 0x800000,
        WaterAnimal = 0x2300,
        VillagerBase = 0x1000300,
        Chicken = 0x130A,
        Cow = 0x130B,
        Pig = 0x130C,
        Sheep = 0x130D,
        Wolf = 0x530E,
        Villager = 0x100030F,
        MushroomCow = 0x1310,
        Squid = 0x2311,
        Rabbit = 0x1312,
        Bat = 0x8113,
        IronGolem = 0x314,
        SnowGolem = 0x315,
        Ocelot = 0x5316,
        Horse = 0x205317,
        PolarBear = 0x131C,
        Llama = 0x131D,
        Parrot = 0x531E,
        Dolphin = 0x231F,
        Donkey = 0x205318,
        Mule = 0x205319,
        SkeletonHorse = 0x215B1A,
        ZombieHorse = 0x215B1B,
        Zombie = 0x30B20,
        Creeper = 0xB21,
        Skeleton = 0x110B22,
        Spider = 0x40B23,
        PigZombie = 0x10B24,
        Slime = 0xB25,
        EnderMan = 0xB26,
        Silverfish = 0x40B27,
        CaveSpider = 0x40B28,
        Ghast = 0xB29,
        LavaSlime = 0xB2A,
        Blaze = 0xB2B,
        ZombieVillager = 0x30B2C,
        Witch = 0xB2D,
        Stray = 0x110B2E,
        Husk = 0x30B2F,
        WitherSkeleton = 0x110B30,
        Guardian = 0xB31,
        ElderGuardian = 0xB32,
        Npc = 0x133,
        WitherBossHandle = 0x10B34,
        Dragon = 0xB35,
        Shulker = 0xB36,
        Endermite = 0x40B37,
        Agent = 0x138,
        Vindicator = 0xB39,
        Phantom = 0x10B3A,
        IllagerBeast = 0xB3B,
        ArmorStandHandle = 0x13D,
        TripodCamera = 0x13E,
        Player_0 = 0x13F,
        ItemEntity = 0x40,
        PrimedTnt = 0x41,
        FallingBlock = 0x42,
        MovingBlock = 0x43,
        ExperiencePotion = 0x400044,
        Experience = 0x45,
        EyeOfEnder = 0x46,
        EnderCrystal = 0x47,
        FireworksRocket = 0x48,
        Trident = 0xC00049,
        Turtle = 0x134A,
        Cat = 0x534B,
        ShulkerBullet = 0x40004C,
        FishingHook = 0x4D,
        Chalkboard = 0x4E,
        DragonFireball = 0x40004F,
        Arrow = 0xC00050,
        Snowball = 0x400051,
        ThrownEgg = 0x400052,
        Painting = 0x53,
        LargeFireball = 0x400055,
        ThrownPotion = 0x400056,
        Enderpearl = 0x400057,
        LeashKnot = 0x58,
        WitherSkull = 0x400059,
        BoatRideable = 0x5A,
        WitherSkullDangerous = 0x40005B,
        LightningBolt = 0x5D,
        SmallFireball = 0x40005E,
        AreaEffectCloud = 0x5F,
        LingeringPotion = 0x400065,
        LlamaSpit = 0x400066,
        EvocationFang = 0x400067,
        EvocationIllager = 0xB68,
        Vex = 0xB69,
        MinecartRideable = 0x80054,
        MinecartHopper = 0x80060,
        MinecartTNT = 0x80061,
        MinecartChest = 0x80062,
        MinecartFurnace = 0x80063,
        MinecartCommandBlock = 0x80064,
        IceBomb = 0x40006A,
        Balloon = 0x6B,
        Pufferfish = 0x236C,
        Salmon = 0x236D,
        Drowned = 0x30B6E,
        Tropicalfish = 0x236F,
        Fish = 0x2370,
        Panda = 0x1371,
        Pillager = 0xB72,
        VillagerV2 = 0x1000373,
        ZombieVillagerV2 = 0x30B74,
        Shield = 0x75,
        WanderingTrader = 0x376,
        Lectern = 0x77,
        ElderGuardianGhost = 0xB78,
        Fox = 0x1379,
        Bee = 0x17A,
    };

    public enum class BlockActorType {
        Undefined = 0x0,
        Furnace = 0x1,
        Chest = 0x2,
        NetherReactor = 0x3,
        Sign = 0x4,
        MobSpawner = 0x5,
        Skull = 0x6,
        FlowerPot = 0x7,
        BrewingStand = 0x8,
        EnchantingTable = 0x9,
        DaylightDetector = 0xA,
        Music = 0xB,
        Comparator = 0xC,
        Dispenser = 0xD,
        Dropper = 0xE,
        Hopper = 0xF,
        Cauldron = 0x10,
        ItemFrame = 0x11,
        PistonArm = 0x12,
        MovingBlock = 0x13,
        Chalkboard = 0x14,
        Beacon = 0x15,
        EndPortal = 0x16,
        EnderChest = 0x17,
        EndGateway = 0x18,
        ShulkerBox = 0x19,
        CommandBlock = 0x1A,
        Bed = 0x1B,
        Banner = 0x1C,
        StructureBlock = 0x20,
        Jukebox = 0x21,
        ChemistryTable = 0x22,
        Conduit = 0x23,
        JigsawBlock = 0x24,
        Lectern = 0x25,
        BlastFurnace = 0x26,
        Smoker = 0x27,
        Bell = 0x28,
        Campfire = 0x29,
        BarrelBlock = 0x2A,
        Beehive = 0x2B,
        Lodestone = 0x2C,
        SculkSensor = 0x2D,
        SporeBlossom = 0x2E,
        GlowItemFrame = 0x2F,
        SculkCatalyst = 0x30,
        SculkShrieker = 0x31,
    };

    public enum class BlockProperty : int64_t {
        None = 0x0,
        Stair = 0x1,
        HalfSlab = 0x2,
        Hopper = 0x4,
        TopSnow = 0x8,
        FenceGate = 0x10,
        Leaf = 0x20,
        ThinConnects2D = 0x40,
        Connects2D = 0x80,
        Carpet = 0x100,
        Button = 0x200,
        Door = 0x400,
        Portal = 0x800,
        Heavy = 0x1000,
        Snow = 0x2000,
        Trap = 0x4000,
        Sign = 0x8000,
        Walkable = 0x10000,
        PressurePlate = 0x20000,
        PistonBlockGrabber = 0x40000,
        TopSolidBlocking = 0x80000,
        SolidBlocking = 0x100000,
        CubeShaped = 0x200000,
        Power_NO = 0x400000,
        Power_BlockDown = 0x800000,
        Immovable = 0x1000000,
        BreakOnPush = 0x2000000,
        Piston = 0x4000000,
        InfiniBurn = 0x8000000,
        RequiresWorldBuilder = 0x10000000,
        CausesDamage = 0x20000000,
        BreaksWhenFallenOnByHeavy = 0x40000000,
        OnlyPistonPush = 0x80000000,
        Liquid = 0x100000000,
        CanBeBuiltOver = 0x200000000,
        SnowRecoverable = 0x400000000,
        Scaffolding = 0x800000000,
        CanSupportCenterHangingBlock = 0x1000000000,
        BreaksWhenHitByArrow = 0x2000000000,
        Unwalkable = 0x4000000000,
        Hollow = 0x10000000000,
        OperatorBlock = 0x20000000000,
        SupportedByFlowerPot = 0x40000000000,
        PreventsJumping = 0x80000000000,
        ContainsHoney = 0x100000000000,
        Slime = 0x200000000000,
        SculkReplaceable = 0x400000000000,
        Climbable = 0x800000000000,
        CanHaltWhenClimbing = 0x1000000000000,
    };
#pragma endregion
}
