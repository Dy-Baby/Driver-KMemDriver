#pragma once

#include <winsock.h>

#define CE_PORT "52736"
#define MSG_WAITALL 0x8

#pragma warning(push)
#pragma warning(disable : 26812)
typedef enum ce_command {
	CMD_GETVERSION = 0,
	CMD_CLOSECONNECTION,
	CMD_TERMINATESERVER,
	CMD_OPENPROCESS,
	CMD_CREATETOOLHELP32SNAPSHOT,
	CMD_PROCESS32FIRST,
	CMD_PROCESS32NEXT,
	CMD_CLOSEHANDLE,
	CMD_VIRTUALQUERYEX,
	CMD_READPROCESSMEMORY,
	CMD_WRITEPROCESSMEMORY,
	CMD_STARTDEBUG,
	CMD_STOPDEBUG,
	CMD_WAITFORDEBUGEVENT,
	CMD_CONTINUEFROMDEBUGEVENT,
	CMD_SETBREAKPOINT,
	CMD_REMOVEBREAKPOINT,
	CMD_SUSPENDTHREAD,
	CMD_RESUMETHREAD,
	CMD_GETTHREADCONTEXT,
	CMD_SETTHREADCONTEXT,
	CMD_GETARCHITECTURE,
	CMD_MODULE32FIRST,
	CMD_MODULE32NEXT,
	CMD_GETSYMBOLLISTFROMFILE,
	CMD_LOADEXTENSION,
	CMD_ALLOC,
	CMD_FREE,
	CMD_CREATETHREAD,
	CMD_LOADMODULE,
	CMD_SPEEDHACK_SETSPEED,
	CMD_VIRTUALQUERYEXFULL,
	CMD_GETREGIONINFO,
	CMD_AOBSCAN = 200,
	CMD_COMMANDLIST2 = 255,

	CMD_MAX
} ce_command;

static inline char const* ce_command_to_string(enum ce_command cmd)
{
	static char const* const cmd_map[] = {
	"CMD_GETVERSION", "CMD_CLOSECONNECTION", "CMD_TERMINATESERVER", "CMD_OPENPROCESS",
	"CMD_CREATETOOLHELP32SNAPSHOT", "CMD_PROCESS32FIRST", "CMD_PROCESS32NEXT", "CMD_CLOSEHANDLE",
	"CMD_VIRTUALQUERYEX", "CMD_READPROCESSMEMORY", "CMD_WRITEPROCESSMEMORY", "CMD_STARTDEBUG",
	"CMD_STOPDEBUG", "CMD_WAITFORDEBUGEVENT", "CMD_CONTINUEFROMDEBUGEVENT", "CMD_SETBREAKPOINT",
	"CMD_REMOVEBREAKPOINT", "CMD_SUSPENDTHREAD", "CMD_RESUMETHREAD", "CMD_GETTHREADCONTEXT",
	"CMD_SETTHREADCONTEXT", "CMD_GETARCHITECTURE", "CMD_MODULE32FIRST", "CMD_MODULE32NEXT",
	"CMD_GETSYMBOLLISTFROMFILE", "CMD_LOADEXTENSION", "CMD_ALLOC", "CMD_FREE", "CMD_CREATETHREAD",
	"CMD_LOADMODULE", "CMD_SPEEDHACK_SETSPEED", "CMD_VIRTUALQUERYEXFULL", "CMD_GETREGIONINFO",
	"CMD_AOBSCAN", "CMD_COMMANDLIST2"
	};
	if (cmd < 0 || cmd >= CMD_MAX)
	{
		return "Unknown Command";
	}
	return cmd_map[cmd];
}
#pragma warning(pop)

#pragma pack(1)
typedef struct {
	DWORD dwFlags;
	DWORD th32ProcessID;
} CeCreateToolhelp32Snapshot, * PCeCreateToolhelp32Snapshot;

typedef struct {
	int result;
	int pid;
	int processnamesize;
	//processname
} CeProcessEntry, * PCeProcessEntry;
#pragma pack()

class CEConnection {
public:
	explicit CEConnection(SOCKET s) : sock(s) {}
	SOCKET getSocket(void) { return sock; }
	void closeSocket(void) { closesocket(sock); }
private:
	SOCKET sock;
};