#include <Windows.h>
#include <iostream>

using namespace std;

DWORD WINAPI main(HMODULE a){
  AllocConsole();
  FILE* real;
  fopen_s(&real, "CONOUT$", "w", stdout);
  cout << "Jerking your dog off" << endl;
  Sleep(2000);
  FreeConsole();
  DWORD x = (DWORD)GetModuleHandle("ac_client.exe");
  DWORD proc;
  HANDLE b = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proc);
  cout << "Press SPACE for health." << endl;
  cout << "Press BACKSPACE for ammo." << endl;
  cout << "Press LEFTSHIT for sniper." << endl;
  for(;;){
    if(GetAsyncKeyState(VK_SPACE)){
      WriteProcessMemory(b, (LPVOID)000DF73C, &value, sizeof(value), 0);
    } else if(GetAsyncKeyState(VK_END)){
      WriteProcessMemory(b, (LPVOID)000DF73C, &value2, sizeof(value2), 0);
      cout << "Ammo: " << value << endl;
      value++;
    } else if(GetAsyncKeyState(VK_LSHIFT)){
      ReadProcessMemory(b, (PBYTE*)000DF73C, &read, sizeof(read), 0);
    }
    Sleep(1);
  }
  FreeLibraryAndExitThread(a, 0);
  return 0;
}

BOOL APIENTRY DLLmain(HMODULE a, DWORD b, LPVOID c){
  switch(b){
    case DLL_PROCESS_ATTACH:
      CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)main, b, 0, nullptr));
    case DLL_PROCESS_DETACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
      break;
  }
  return 0;
}
