/*++

Replace missing defines/typedefs/... wdk includes

Based on:

  - km/wdm.h      -- 0162
  - km/ntddk.h    -- 0184
  - km/mountmgr.h -- ????

--*/

#ifndef _WDK_INCLUDE_INCLUDE_
#define _WDK_INCLUDE_INCLUDE_

namespace NT {
extern "C" {

#include <ntdef.h>                                   // these are in <wdk_inc>/shared
#include <ntstatus.h>                                // apparently /{shared,um} are valid

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

typedef
VOID
(*PKNORMAL_ROUTINE) (
	_In_ PVOID NormalContext,
	_In_ PVOID SystemArgument1,
	_In_ PVOID SystemArgument2
	);  // got from different webpages (google query: PKNORMAL_ROUTINE)

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

#define DEVICE_TYPE ULONG  // km/wdm.h

typedef struct _FILE_FS_DEVICE_INFORMATION {
    DEVICE_TYPE DeviceType;
    ULONG Characteristics;
} FILE_FS_DEVICE_INFORMATION, *PFILE_FS_DEVICE_INFORMATION;  // km/wdm.h

#if (NTDDI_VERSION >= NTDDI_WIN2K)
_IRQL_requires_max_(PASSIVE_LEVEL)
_Must_inspect_result_
NTSYSAPI
NTSTATUS
NTAPI
RtlAnsiStringToUnicodeString(
    _When_(AllocateDestinationString, _Out_ _At_(DestinationString->Buffer, __drv_allocatesMem(Mem)))
    _When_(!AllocateDestinationString, _Inout_)
        PUNICODE_STRING DestinationString,
    _In_ PCANSI_STRING SourceString,
    _In_ BOOLEAN AllocateDestinationString
    );
#endif  // km/wdm.h


#if (NTDDI_VERSION >= NTDDI_WIN2K)

_When_(AllocateDestinationString,
       _At_(DestinationString->MaximumLength,
            _Out_range_(<=, (SourceString->MaximumLength / sizeof(WCHAR)))))
_When_(!AllocateDestinationString,
       _At_(DestinationString->Buffer, _Const_)
       _At_(DestinationString->MaximumLength, _Const_))
_IRQL_requires_max_(PASSIVE_LEVEL)
_When_(AllocateDestinationString, _Must_inspect_result_)
NTSYSAPI
NTSTATUS
NTAPI
RtlUnicodeStringToAnsiString(
    _When_(AllocateDestinationString, _Out_ _At_(DestinationString->Buffer, __drv_allocatesMem(Mem)))
    _When_(!AllocateDestinationString, _Inout_)
        PANSI_STRING DestinationString,
    _In_ PCUNICODE_STRING SourceString,
    _In_ BOOLEAN AllocateDestinationString
    );
#endif  // km/wdm.h

}
}

#if defined(_X86_)

//
// i386 Specific portions of Mm component.
//
// Define the page size for the Intel 386 as 4096 (0x1000).
//

#define PAGE_SIZE 0x1000

//
// Define the number of trailing zeroes in a page aligned virtual address.
// This is used as the shift count when shifting virtual addresses to
// virtual page numbers.
//

#define PAGE_SHIFT 12L

#elif defined(_AMD64_)

//
// AMD64 Specific portions of Mm component.
//
// Define the page size for the AMD64 as 4096 (0x1000).
//

#define PAGE_SIZE 0x1000

//
// Define the number of trailing zeroes in a page aligned virtual address.
// This is used as the shift count when shifting virtual addresses to
// virtual page numbers.
//

#define PAGE_SHIFT 12L

#elif defined(_ARM_)

//
// ARM Specific portions of Mm component.
//
// Define the page size for the ARM as 4096 (0x1000).
//

#define PAGE_SIZE 0x1000

//
// Define the number of trailing zeroes in a page aligned virtual address.
// This is used as the shift count when shifting virtual addresses to
// virtual page numbers.
//

#define PAGE_SHIFT 12L

#elif defined(_IA64_)

//
// IA64 Specific portions of Mm component.
//
// Define the page size for the IA64 as 8192 (0x2000).
//

#define PAGE_SIZE 0x2000

//
// Define the number of trailing zeroes in a page aligned virtual address.
// This is used as the shift count when shifting virtual addresses to
// virtual page numbers.
//

#define PAGE_SHIFT 13L

#endif  // km/wdm.h

#define IRP_MJ_CREATE                   0x00
#define IRP_MJ_CREATE_NAMED_PIPE        0x01
#define IRP_MJ_CLOSE                    0x02
#define IRP_MJ_READ                     0x03
#define IRP_MJ_WRITE                    0x04
#define IRP_MJ_QUERY_INFORMATION        0x05
#define IRP_MJ_SET_INFORMATION          0x06
#define IRP_MJ_QUERY_EA                 0x07
#define IRP_MJ_SET_EA                   0x08
#define IRP_MJ_FLUSH_BUFFERS            0x09
#define IRP_MJ_QUERY_VOLUME_INFORMATION 0x0a
#define IRP_MJ_SET_VOLUME_INFORMATION   0x0b
#define IRP_MJ_DIRECTORY_CONTROL        0x0c
#define IRP_MJ_FILE_SYSTEM_CONTROL      0x0d
#define IRP_MJ_DEVICE_CONTROL           0x0e
#define IRP_MJ_INTERNAL_DEVICE_CONTROL  0x0f
#define IRP_MJ_SHUTDOWN                 0x10
#define IRP_MJ_LOCK_CONTROL             0x11
#define IRP_MJ_CLEANUP                  0x12
#define IRP_MJ_CREATE_MAILSLOT          0x13
#define IRP_MJ_QUERY_SECURITY           0x14
#define IRP_MJ_SET_SECURITY             0x15
#define IRP_MJ_POWER                    0x16
#define IRP_MJ_SYSTEM_CONTROL           0x17
#define IRP_MJ_DEVICE_CHANGE            0x18
#define IRP_MJ_QUERY_QUOTA              0x19
#define IRP_MJ_SET_QUOTA                0x1a
#define IRP_MJ_PNP                      0x1b
#define IRP_MJ_PNP_POWER                IRP_MJ_PNP      // Obsolete....
#define IRP_MJ_MAXIMUM_FUNCTION         0x1b  // km/wdm.h

#define FILE_SUPERSEDE                  0x00000000	// km/wdm.h
#define FILE_OPEN                       0x00000001	// km/wdm.h
#define FILE_CREATE                     0x00000002	// km/wdm.h
#define FILE_OPEN_IF                    0x00000003	// km/wdm.h
#define FILE_OVERWRITE                  0x00000004	// km/wdm.h
#define FILE_OVERWRITE_IF               0x00000005	// km/wdm.h
#define FILE_MAXIMUM_DISPOSITION        0x00000005  // km/wdm.h

#define FILE_DIRECTORY_FILE                     0x00000001  // km/wdm.h
#define FILE_WRITE_THROUGH                      0x00000002	// km/wdm.h
#define FILE_SEQUENTIAL_ONLY                    0x00000004	// km/wdm.h
#define FILE_NO_INTERMEDIATE_BUFFERING          0x00000008	// km/wdm.h
															// km/wdm.h
#define FILE_SYNCHRONOUS_IO_ALERT               0x00000010	// km/wdm.h
#define FILE_SYNCHRONOUS_IO_NONALERT            0x00000020	// km/wdm.h
#define FILE_NON_DIRECTORY_FILE                 0x00000040	// km/wdm.h
#define FILE_CREATE_TREE_CONNECTION             0x00000080	// km/wdm.h
															// km/wdm.h
#define FILE_COMPLETE_IF_OPLOCKED               0x00000100	// km/wdm.h
#define FILE_NO_EA_KNOWLEDGE                    0x00000200	// km/wdm.h
#define FILE_OPEN_REMOTE_INSTANCE               0x00000400	// km/wdm.h
#define FILE_RANDOM_ACCESS                      0x00000800	// km/wdm.h
															// km/wdm.h
#define FILE_DELETE_ON_CLOSE                    0x00001000	// km/wdm.h
#define FILE_OPEN_BY_FILE_ID                    0x00002000	// km/wdm.h
#define FILE_OPEN_FOR_BACKUP_INTENT             0x00004000	// km/wdm.h
#define FILE_NO_COMPRESSION                     0x00008000	// km/wdm.h
															// km/wdm.h
#if (NTDDI_VERSION >= NTDDI_WIN7)							// km/wdm.h
#define FILE_OPEN_REQUIRING_OPLOCK              0x00010000	// km/wdm.h
#define FILE_DISALLOW_EXCLUSIVE                 0x00020000	// km/wdm.h
#endif /* NTDDI_VERSION >= NTDDI_WIN7 */					// km/wdm.h
#if (NTDDI_VERSION >= NTDDI_WIN8)							// km/wdm.h
#define FILE_SESSION_AWARE                      0x00040000	// km/wdm.h
#endif /* NTDDI_VERSION >= NTDDI_WIN8 */					// km/wdm.h
															// km/wdm.h
#define FILE_RESERVE_OPFILTER                   0x00100000	// km/wdm.h
#define FILE_OPEN_REPARSE_POINT                 0x00200000	// km/wdm.h
#define FILE_OPEN_NO_RECALL                     0x00400000	// km/wdm.h
#define FILE_OPEN_FOR_FREE_SPACE_QUERY          0x00800000	// km/wdm.h

#define FILE_VALID_OPTION_FLAGS                 0x00ffffff  // km/wdm.h
#define FILE_VALID_PIPE_OPTION_FLAGS            0x00000032	// km/wdm.h
#define FILE_VALID_MAILSLOT_OPTION_FLAGS        0x00000032	// km/wdm.h
#define FILE_VALID_SET_FLAGS                    0x00000036	// km/wdm.h

#define FILE_SUPERSEDED                 0x00000000  // km/wdm.h
#define FILE_OPENED                     0x00000001	// km/wdm.h
#define FILE_CREATED                    0x00000002	// km/wdm.h
#define FILE_OVERWRITTEN                0x00000003	// km/wdm.h
#define FILE_EXISTS                     0x00000004	// km/wdm.h
#define FILE_DOES_NOT_EXIST             0x00000005	// km/wdm.h

#define FILE_WRITE_TO_END_OF_FILE       0xffffffff  // km/wdm.h
#define FILE_USE_FILE_POINTER_POSITION  0xfffffffe	// km/wdm.h

#define FILE_BYTE_ALIGNMENT             0x00000000  // km/wdm.h
#define FILE_WORD_ALIGNMENT             0x00000001	// km/wdm.h
#define FILE_LONG_ALIGNMENT             0x00000003	// km/wdm.h
#define FILE_QUAD_ALIGNMENT             0x00000007	// km/wdm.h
#define FILE_OCTA_ALIGNMENT             0x0000000f	// km/wdm.h
#define FILE_32_BYTE_ALIGNMENT          0x0000001f	// km/wdm.h
#define FILE_64_BYTE_ALIGNMENT          0x0000003f	// km/wdm.h
#define FILE_128_BYTE_ALIGNMENT         0x0000007f	// km/wdm.h
#define FILE_256_BYTE_ALIGNMENT         0x000000ff	// km/wdm.h
#define FILE_512_BYTE_ALIGNMENT         0x000001ff	// km/wdm.h

#define MAXIMUM_FILENAME_LENGTH         256  // km/wdm.h

#define FILE_REMOVABLE_MEDIA                        0x00000001  // km/wdm.h
#define FILE_READ_ONLY_DEVICE                       0x00000002	// km/wdm.h
#define FILE_FLOPPY_DISKETTE                        0x00000004	// km/wdm.h
#define FILE_WRITE_ONCE_MEDIA                       0x00000008	// km/wdm.h
#define FILE_REMOTE_DEVICE                          0x00000010	// km/wdm.h
#define FILE_DEVICE_IS_MOUNTED                      0x00000020	// km/wdm.h
#define FILE_VIRTUAL_VOLUME                         0x00000040	// km/wdm.h
#define FILE_AUTOGENERATED_DEVICE_NAME              0x00000080	// km/wdm.h
#define FILE_DEVICE_SECURE_OPEN                     0x00000100	// km/wdm.h
#define FILE_CHARACTERISTIC_PNP_DEVICE              0x00000800	// km/wdm.h
#define FILE_CHARACTERISTIC_TS_DEVICE               0x00001000	// km/wdm.h
#define FILE_CHARACTERISTIC_WEBDAV_DEVICE           0x00002000	// km/wdm.h
#define FILE_CHARACTERISTIC_CSV                     0x00010000	// km/wdm.h
#define FILE_DEVICE_ALLOW_APPCONTAINER_TRAVERSAL    0x00020000	// km/wdm.h
#define FILE_PORTABLE_DEVICE                        0x00040000	// km/wdm.h

#define MOUNTMGRCONTROLTYPE                         0x0000006D // 'm'  // km/mountmgr.h
#define MOUNTDEVCONTROLTYPE                         0x0000004D // 'M'  // km/mountmgr.h

#define IOCTL_MOUNTMGR_CREATE_POINT                 CTL_CODE(MOUNTMGRCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)  // km/mountmgr.h
#define IOCTL_MOUNTMGR_DELETE_POINTS                CTL_CODE(MOUNTMGRCONTROLTYPE, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)	 // km/mountmgr.h
#define IOCTL_MOUNTMGR_QUERY_POINTS                 CTL_CODE(MOUNTMGRCONTROLTYPE, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)						 // km/mountmgr.h
#define IOCTL_MOUNTMGR_DELETE_POINTS_DBONLY         CTL_CODE(MOUNTMGRCONTROLTYPE, 3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)	 // km/mountmgr.h
#define IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER            CTL_CODE(MOUNTMGRCONTROLTYPE, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)	 // km/mountmgr.h
#define IOCTL_MOUNTMGR_AUTO_DL_ASSIGNMENTS          CTL_CODE(MOUNTMGRCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)	 // km/mountmgr.h
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED   CTL_CODE(MOUNTMGRCONTROLTYPE, 6, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)	 // km/mountmgr.h
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_DELETED   CTL_CODE(MOUNTMGRCONTROLTYPE, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)	 // km/mountmgr.h
#define IOCTL_MOUNTMGR_CHANGE_NOTIFY                CTL_CODE(MOUNTMGRCONTROLTYPE, 8, METHOD_BUFFERED, FILE_READ_ACCESS)						 // km/mountmgr.h
#define IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE      CTL_CODE(MOUNTMGRCONTROLTYPE, 9, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)	 // km/mountmgr.h
#define IOCTL_MOUNTMGR_CHECK_UNPROCESSED_VOLUMES    CTL_CODE(MOUNTMGRCONTROLTYPE, 10, METHOD_BUFFERED, FILE_READ_ACCESS)					 // km/mountmgr.h
#define IOCTL_MOUNTMGR_VOLUME_ARRIVAL_NOTIFICATION  CTL_CODE(MOUNTMGRCONTROLTYPE, 11, METHOD_BUFFERED, FILE_READ_ACCESS)					 // km/mountmgr.h

typedef struct _MOUNTMGR_CREATE_POINT_INPUT {
    USHORT  SymbolicLinkNameOffset;
    USHORT  SymbolicLinkNameLength;
    USHORT  DeviceNameOffset;
    USHORT  DeviceNameLength;
} MOUNTMGR_CREATE_POINT_INPUT, *PMOUNTMGR_CREATE_POINT_INPUT;  // km/mountmgr.h

typedef struct _MOUNTMGR_MOUNT_POINT {
    ULONG   SymbolicLinkNameOffset;
    USHORT  SymbolicLinkNameLength;
    ULONG   UniqueIdOffset;
    USHORT  UniqueIdLength;
    ULONG   DeviceNameOffset;
    USHORT  DeviceNameLength;
} MOUNTMGR_MOUNT_POINT, *PMOUNTMGR_MOUNT_POINT;  // km/mountmgr.h

typedef struct _MOUNTMGR_MOUNT_POINTS {
    ULONG                   Size;
    ULONG                   NumberOfMountPoints;
    MOUNTMGR_MOUNT_POINT    MountPoints[1];
} MOUNTMGR_MOUNT_POINTS, *PMOUNTMGR_MOUNT_POINTS;  // km/mountmgr.h

typedef struct _MOUNTMGR_TARGET_NAME {
    USHORT  DeviceNameLength;
    WCHAR   DeviceName[1];
} MOUNTMGR_TARGET_NAME, *PMOUNTMGR_TARGET_NAME;  // km/mountmgr.h

#define MOUNTMGR_IS_DRIVE_LETTER(s) (   \
    (s)->Length == 28 &&                \
    (s)->Buffer[0] == '\\' &&           \
    (s)->Buffer[1] == 'D' &&            \
    (s)->Buffer[2] == 'o' &&            \
    (s)->Buffer[3] == 's' &&            \
    (s)->Buffer[4] == 'D' &&            \
    (s)->Buffer[5] == 'e' &&            \
    (s)->Buffer[6] == 'v' &&            \
    (s)->Buffer[7] == 'i' &&            \
    (s)->Buffer[8] == 'c' &&            \
    (s)->Buffer[9] == 'e' &&            \
    (s)->Buffer[10] == 's' &&           \
    (s)->Buffer[11] == '\\' &&          \
    (s)->Buffer[12] >= 'A' &&           \
    (s)->Buffer[12] <= 'Z' &&           \
    (s)->Buffer[13] == ':')  // km/mountmgr.h

#endif // _WDK_INCLUDE_INCLUDE_
