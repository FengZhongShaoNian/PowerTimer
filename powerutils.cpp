#include "powerutils.h"

#ifdef Q_OS_WIN
#include <windows.h>
#endif

PowerUtils::PowerUtils(QObject *parent) : QObject(parent)
{

}

#ifdef Q_OS_WIN
void shutdown_os()
{
    HANDLE hToken = NULL;
    TOKEN_PRIVILEGES tkp;
    OpenProcessToken(GetCurrentProcess(),
            TOKEN_ADJUST_PRIVILEGES |
            TOKEN_QUERY, &hToken);
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

    ExitWindowsEx(EWX_SHUTDOWN, NULL);
}

void reboot_os()
{
    HANDLE hToken = NULL;
    TOKEN_PRIVILEGES tkp;
    OpenProcessToken(GetCurrentProcess(),
            TOKEN_ADJUST_PRIVILEGES |
            TOKEN_QUERY, &hToken);
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

    ExitWindowsEx(EWX_REBOOT, NULL);
}
#endif

void PowerUtils::shutdown()
{
#ifdef Q_OS_WIN
    shutdown_os();
#endif
}

void PowerUtils::reboot()
{
#ifdef Q_OS_WIN
    reboot_os();
#endif
}

