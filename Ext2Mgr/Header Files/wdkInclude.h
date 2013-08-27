/*++

Replace missing defines/typedefs/... wdk includes

Based on:

  - km/wdm.h   -- 0162
  - km/ntddk.h -- 0184

--*/

#include <ntdef.h>                                   // this is in <wdk_inc>/shared

typedef struct _CLIENT_ID {
    HANDLE UniqueProcess;
    HANDLE UniqueThread;						
} CLIENT_ID;  // km/wdm.h
typedef CLIENT_ID *PCLIENT_ID;  // km/wdm.h
										             
typedef LONG KPRIORITY;  // km/wdm.h

typedef enum _KWAIT_REASON {
    Executive,
    FreePage,
    PageIn,
    PoolAllocation,
    DelayExecution,
    Suspended,
    UserRequest,
    WrExecutive,
    WrFreePage,
    WrPageIn,
    WrPoolAllocation,
    WrDelayExecution,
    WrSuspended,
    WrUserRequest,
    WrEventPair,
    WrQueue,
    WrLpcReceive,
    WrLpcReply,
    WrVirtualMemory,
    WrPageOut,
    WrRendezvous,
    WrKeyedEvent,
    WrTerminated,
    WrProcessInSwap,
    WrCpuRateControl,
    WrCalloutStack,
    WrKernel,
    WrResource,
    WrPushLock,
    WrMutex,
    WrQuantumEnd,
    WrDispatchInt,
    WrPreempted,
    WrYieldExecution,
    WrFastMutex,
    WrGuardedMutex,
    WrRundown,
    WrAlertByThreadId,
    WrDeferredPreempt,
    MaximumWaitReason								 
} KWAIT_REASON;  // km/wdm.h

typedef struct _VM_COUNTERS {
    SIZE_T PeakVirtualSize;
    SIZE_T VirtualSize;
    ULONG PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;						 
} VM_COUNTERS;  // km/ntddk.h

typedef _Enum_is_bitflag_ enum _POOL_TYPE {
    NonPagedPool,
    NonPagedPoolExecute = NonPagedPool,
    PagedPool,
    NonPagedPoolMustSucceed = NonPagedPool + 2,
    DontUseThisType,
    NonPagedPoolCacheAligned = NonPagedPool + 4,
    PagedPoolCacheAligned,
    NonPagedPoolCacheAlignedMustS = NonPagedPool + 6,
    MaxPoolType,

    //
    // Define base types for NonPaged (versus Paged) pool, for use in cracking
    // the underlying pool type.
    //

    NonPagedPoolBase = 0,
    NonPagedPoolBaseMustSucceed = NonPagedPoolBase + 2,
    NonPagedPoolBaseCacheAligned = NonPagedPoolBase + 4,
    NonPagedPoolBaseCacheAlignedMustS = NonPagedPoolBase + 6,

    //
    // Note these per session types are carefully chosen so that the appropriate
    // masking still applies as well as MaxPoolType above.
    //

    NonPagedPoolSession = 32,
    PagedPoolSession = NonPagedPoolSession + 1,
    NonPagedPoolMustSucceedSession = PagedPoolSession + 1,
    DontUseThisTypeSession = NonPagedPoolMustSucceedSession + 1,
    NonPagedPoolCacheAlignedSession = DontUseThisTypeSession + 1,
    PagedPoolCacheAlignedSession = NonPagedPoolCacheAlignedSession + 1,
    NonPagedPoolCacheAlignedMustSSession = PagedPoolCacheAlignedSession + 1,

    NonPagedPoolNx = 512,
    NonPagedPoolNxCacheAligned = NonPagedPoolNx + 4,
    NonPagedPoolSessionNx = NonPagedPoolNx + 32,
													 
} _Enum_is_bitflag_ POOL_TYPE;  // km/wdm.h

typedef enum _THREADINFOCLASS {
    ThreadBasicInformation,
    ThreadTimes,
    ThreadPriority,
    ThreadBasePriority,
    ThreadAffinityMask,
    ThreadImpersonationToken,
    ThreadDescriptorTableEntry,
    ThreadEnableAlignmentFaultFixup,
    ThreadEventPair_Reusable,
    ThreadQuerySetWin32StartAddress,
    ThreadZeroTlsCell,
    ThreadPerformanceCount,
    ThreadAmILastThread,
    ThreadIdealProcessor,
    ThreadPriorityBoost,
    ThreadSetTlsArrayAddress,   // Obsolete
    ThreadIsIoPending,
    ThreadHideFromDebugger,
    ThreadBreakOnTermination,
    ThreadSwitchLegacyState,
    ThreadIsTerminated,
    ThreadLastSystemCall,
    ThreadIoPriority,
    ThreadCycleTime,
    ThreadPagePriority,
    ThreadActualBasePriority,
    ThreadTebInformation,
    ThreadCSwitchMon,          // Obsolete
    ThreadCSwitchPmu,
    ThreadWow64Context,
    ThreadGroupInformation,
    ThreadUmsInformation,      // UMS
    ThreadCounterProfiling,
    ThreadIdealProcessorEx,
    ThreadCpuAccountingInformation,
    MaxThreadInfoClass								 
} THREADINFOCLASS;  // km/ntddk.h

// PKNORMAL_ROUTINE

typedef enum _PROCESSINFOCLASS {
    ProcessBasicInformation,
    ProcessQuotaLimits,
    ProcessIoCounters,
    ProcessVmCounters,
    ProcessTimes,
    ProcessBasePriority,
    ProcessRaisePriority,
    ProcessDebugPort,
    ProcessExceptionPort,
    ProcessAccessToken,
    ProcessLdtInformation,
    ProcessLdtSize,
    ProcessDefaultHardErrorMode,
    ProcessIoPortHandlers,          // Note: this is kernel mode only
    ProcessPooledUsageAndLimits,
    ProcessWorkingSetWatch,
    ProcessUserModeIOPL,
    ProcessEnableAlignmentFaultFixup,
    ProcessPriorityClass,
    ProcessWx86Information,
    ProcessHandleCount,
    ProcessAffinityMask,
    ProcessPriorityBoost,
    ProcessDeviceMap,
    ProcessSessionInformation,
    ProcessForegroundInformation,
    ProcessWow64Information,
    ProcessImageFileName,
    ProcessLUIDDeviceMapsEnabled,
    ProcessBreakOnTermination,
    ProcessDebugObjectHandle,
    ProcessDebugFlags,
    ProcessHandleTracing,
    ProcessIoPriority,
    ProcessExecuteFlags,
    ProcessTlsInformation,
    ProcessCookie,
    ProcessImageInformation,
    ProcessCycleTime,
    ProcessPagePriority,
    ProcessInstrumentationCallback,
    ProcessThreadStackAllocation,
    ProcessWorkingSetWatchEx,
    ProcessImageFileNameWin32,
    ProcessImageFileMapping,
    ProcessAffinityUpdateMode,
    ProcessMemoryAllocationMode,
    ProcessGroupInformation,
    ProcessTokenVirtualizationEnabled,
    ProcessConsoleHostProcess,
    ProcessWindowInformation,
    ProcessHandleInformation,
    ProcessMitigationPolicy,
    ProcessDynamicFunctionTableInformation,
    ProcessHandleCheckingMode,
    ProcessKeepAliveCount,
    ProcessRevokeFileHandles,
    ProcessWorkingSetControl,
    MaxProcessInfoClass             // MaxProcessInfoClass should always be the last enum
} PROCESSINFOCLASS;  // km/ntddk.h

typedef struct _IO_STATUS_BLOCK {
    union {
        NTSTATUS Status;
        PVOID Pointer;
    } DUMMYUNIONNAME;

    ULONG_PTR Information;							 
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;  // km/wdm.h

typedef enum _KPROFILE_SOURCE {
    ProfileTime,
    ProfileAlignmentFixup,
    ProfileTotalIssues,
    ProfilePipelineDry,
    ProfileLoadInstructions,
    ProfilePipelineFrozen,
    ProfileBranchInstructions,
    ProfileTotalNonissues,
    ProfileDcacheMisses,
    ProfileIcacheMisses,
    ProfileCacheMisses,
    ProfileBranchMispredictions,
    ProfileStoreInstructions,
    ProfileFpInstructions,
    ProfileIntegerInstructions,
    Profile2Issue,
    Profile3Issue,
    Profile4Issue,
    ProfileSpecialInstructions,
    ProfileTotalCycles,
    ProfileIcacheIssues,
    ProfileDcacheAccesses,
    ProfileMemoryBarrierCycles,
    ProfileLoadLinkedIssues,
    ProfileMaximum
} KPROFILE_SOURCE;  // km/wdm.h
													         
typedef												         
VOID												         
(NTAPI *PIO_APC_ROUTINE) (							         
    _In_ PVOID ApcContext,							         
    _In_ PIO_STATUS_BLOCK IoStatusBlock,			         
    _In_ ULONG Reserved								         
    );  // km/wdm.h
#define PIO_APC_ROUTINE_DEFINED  // km/wdm.h
															 
typedef struct _FILE_FULL_EA_INFORMATION {
    ULONG NextEntryOffset;
    UCHAR Flags;
    UCHAR EaNameLength;
    USHORT EaValueLength;
    CHAR EaName[1];
} FILE_FULL_EA_INFORMATION, *PFILE_FULL_EA_INFORMATION;  // km/wdm.h

typedef enum _FSINFOCLASS {
    FileFsVolumeInformation       = 1,
    FileFsLabelInformation,      // 2
    FileFsSizeInformation,       // 3
    FileFsDeviceInformation,     // 4
    FileFsAttributeInformation,  // 5
    FileFsControlInformation,    // 6
    FileFsFullSizeInformation,   // 7
    FileFsObjectIdInformation,   // 8
    FileFsDriverPathInformation, // 9
    FileFsVolumeFlagsInformation,// 10
    FileFsSectorSizeInformation, // 11
    FileFsDataCopyInformation,   // 12
    FileFsMaximumInformation
} FS_INFORMATION_CLASS, *PFS_INFORMATION_CLASS;  // km/wdm.h

typedef struct _FILE_BASIC_INFORMATION {
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    ULONG FileAttributes;
} FILE_BASIC_INFORMATION, *PFILE_BASIC_INFORMATION;  // km/wdm.h

typedef struct _FILE_NETWORK_OPEN_INFORMATION {
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    ULONG FileAttributes;
} FILE_NETWORK_OPEN_INFORMATION, *PFILE_NETWORK_OPEN_INFORMATION;  // km/wdm.h

typedef enum _FILE_INFORMATION_CLASS {
    FileDirectoryInformation         = 1,
    FileFullDirectoryInformation,   // 2
    FileBothDirectoryInformation,   // 3
    FileBasicInformation,           // 4
    FileStandardInformation,        // 5
    FileInternalInformation,        // 6
    FileEaInformation,              // 7
    FileAccessInformation,          // 8
    FileNameInformation,            // 9
    FileRenameInformation,          // 10
    FileLinkInformation,            // 11
    FileNamesInformation,           // 12
    FileDispositionInformation,     // 13
    FilePositionInformation,        // 14
    FileFullEaInformation,          // 15
    FileModeInformation,            // 16
    FileAlignmentInformation,       // 17
    FileAllInformation,             // 18
    FileAllocationInformation,      // 19
    FileEndOfFileInformation,       // 20
    FileAlternateNameInformation,   // 21
    FileStreamInformation,          // 22
    FilePipeInformation,            // 23
    FilePipeLocalInformation,       // 24
    FilePipeRemoteInformation,      // 25
    FileMailslotQueryInformation,   // 26
    FileMailslotSetInformation,     // 27
    FileCompressionInformation,     // 28
    FileObjectIdInformation,        // 29
    FileCompletionInformation,      // 30
    FileMoveClusterInformation,     // 31
    FileQuotaInformation,           // 32
    FileReparsePointInformation,    // 33
    FileNetworkOpenInformation,     // 34
    FileAttributeTagInformation,    // 35
    FileTrackingInformation,        // 36
    FileIdBothDirectoryInformation, // 37
    FileIdFullDirectoryInformation, // 38
    FileValidDataLengthInformation, // 39
    FileShortNameInformation,       // 40
    FileIoCompletionNotificationInformation, // 41
    FileIoStatusBlockRangeInformation,       // 42
    FileIoPriorityHintInformation,           // 43
    FileSfioReserveInformation,              // 44
    FileSfioVolumeInformation,               // 45
    FileHardLinkInformation,                 // 46
    FileProcessIdsUsingFileInformation,      // 47
    FileNormalizedNameInformation,           // 48
    FileNetworkPhysicalNameInformation,      // 49
    FileIdGlobalTxDirectoryInformation,      // 50
    FileIsRemoteDeviceInformation,           // 51
    FileAttributeCacheInformation,           // 52
    FileNumaNodeInformation,                 // 53
    FileStandardLinkInformation,             // 54
    FileRemoteProtocolInformation,           // 55

        //
        //  These are special versions of these operations (defined earlier)
        //  which can be used by kernel mode drivers only to bypass security
        //  access checks for Rename and HardLink operations.  These operations
        //  are only recognized by the IOManager, a file system should never
        //  receive these.
        //
    FileRenameInformationBypassAccessCheck,  // 56
    FileLinkInformationBypassAccessCheck,    // 57
    FileVolumeNameInformation,               // 58
    FileIdInformation,                       // 59
    FileIdExtdDirectoryInformation,          // 60
    FileMaximumInformation
} FILE_INFORMATION_CLASS, *PFILE_INFORMATION_CLASS;  // km/wdm.h

typedef struct _FILE_STANDARD_INFORMATION {
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    ULONG NumberOfLinks;
    BOOLEAN DeletePending;
    BOOLEAN Directory;
} FILE_STANDARD_INFORMATION, *PFILE_STANDARD_INFORMATION;  // km/wdm.h

typedef struct _FILE_POSITION_INFORMATION {
    LARGE_INTEGER CurrentByteOffset;
} FILE_POSITION_INFORMATION, *PFILE_POSITION_INFORMATION;  // km/wdm.h

typedef struct _FILE_ALIGNMENT_INFORMATION {
    ULONG AlignmentRequirement;
} FILE_ALIGNMENT_INFORMATION, *PFILE_ALIGNMENT_INFORMATION;  // km/ntddk.h

typedef enum _KEY_SET_INFORMATION_CLASS {
    KeyWriteTimeInformation,
    KeyWow64FlagsInformation,
    KeyControlFlagsInformation,
    KeySetVirtualizationInformation,
    KeySetDebugInformation,
    KeySetHandleTagsInformation,
    MaxKeySetInfoClass  // MaxKeySetInfoClass should always be the last enum
} KEY_SET_INFORMATION_CLASS;  // km/wdm.h

typedef enum _KEY_INFORMATION_CLASS {
    KeyBasicInformation,
    KeyNodeInformation,
    KeyFullInformation,
    KeyNameInformation,
    KeyCachedInformation,
    KeyFlagsInformation,
    KeyVirtualizationInformation,
    KeyHandleTagsInformation,
    KeyTrustInformation,
    MaxKeyInfoClass  // MaxKeyInfoClass should always be the last enum
} KEY_INFORMATION_CLASS; // km/wdm.h

typedef enum _KEY_VALUE_INFORMATION_CLASS {
    KeyValueBasicInformation,
    KeyValueFullInformation,
    KeyValuePartialInformation,
    KeyValueFullInformationAlign64,
    KeyValuePartialInformationAlign64,
    MaxKeyValueInfoClass  // MaxKeyValueInfoClass should always be the last enum
} KEY_VALUE_INFORMATION_CLASS;  // km/wdm.h

typedef struct _KEY_VALUE_ENTRY {
    PUNICODE_STRING ValueName;
    ULONG           DataLength;
    ULONG           DataOffset;
    ULONG           Type;
} KEY_VALUE_ENTRY, *PKEY_VALUE_ENTRY;  // km/wdm.h
