// DBService.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include <assert.h>

using namespace std;

string gc_sServiceName = "MSSQL$VAZSERVER";

int main()
{
    do 
    {
        SC_HANDLE hSCManager;
        hSCManager = OpenSCManagerA( nullptr, nullptr, SC_MANAGER_ALL_ACCESS );
        assert( hSCManager != nullptr );

        SC_HANDLE hService;
        hService = OpenServiceA( hSCManager, gc_sServiceName.c_str(), SERVICE_ALL_ACCESS );
        assert( hService != nullptr );

        SERVICE_STATUS ServiceStatus;
        do 
        {
            assert( QueryServiceStatus( hService, &ServiceStatus ) );
            switch (ServiceStatus.dwCurrentState)
            {
            case SERVICE_STOPPED:
                cout << "ServiceStatus.dwCurrentState = SERVICE_STOPPED:" << ServiceStatus.dwCurrentState << endl;
                break;
            case SERVICE_START_PENDING:
                cout << "ServiceStatus.dwCurrentState = SERVICE_START_PENDING:" << ServiceStatus.dwCurrentState << endl;
                break;
            case SERVICE_STOP_PENDING:
                cout << "ServiceStatus.dwCurrentState = SERVICE_STOP_PENDING:" << ServiceStatus.dwCurrentState << endl;
                break;
            case SERVICE_RUNNING:
                cout << "ServiceStatus.dwCurrentState = SERVICE_RUNNING:" << ServiceStatus.dwCurrentState << endl;
                break;
            case SERVICE_CONTINUE_PENDING:
                cout << "ServiceStatus.dwCurrentState = SERVICE_CONTINUE_PENDING:" << ServiceStatus.dwCurrentState << endl;
                break;
            case SERVICE_PAUSE_PENDING:
                cout << "ServiceStatus.dwCurrentState = SERVICE_PAUSE_PENDING:" << ServiceStatus.dwCurrentState << endl;
                break;
            case SERVICE_PAUSED:
                cout << "ServiceStatus.dwCurrentState = SERVICE_PAUSED:" << ServiceStatus.dwCurrentState << endl;
                break;
            default:
                break;
            }
            Sleep(500);
        } 
        while (ServiceStatus.dwCurrentState != SERVICE_RUNNING);

    } while (0);

    system( "pause" );

    return 0;
}

