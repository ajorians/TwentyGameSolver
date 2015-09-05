#include "GameSolver.h"
#include "InputNumbers.h"
#include <iostream>

#ifdef WIN32
#include <windows.h>
#endif

using namespace std;

GameSolver* g_pG;
int g_nMin = 0;
int g_nMax = 20;

void RunGame(InputNumbers& numbers, int nMin, int nMax)
{
   g_pG = new GameSolver (numbers);
   g_pG->Solve(nMin, nMax);

   g_pG->PrintResults();
   delete g_pG;
   g_pG = NULL;

   cout << "Done executing" << endl;
}

void RunGame()
{
   cout << "Give me four digits" << endl;
   InputNumbers numbers;
   for (int i = 0; i<4; i++)
   {
      cout << "Digit " << i+1 << ": ";
      cout.flush();
      int n;
      cin >> n;
      numbers.AddNumber(n);
   }

   RunGame(numbers, g_nMin, g_nMax);
}

void Print()
{
   if( g_pG == NULL )
      return;

   g_pG->PrintResults();
}

#ifdef WIN32
BOOL WINAPI ConsoleHandlerRoutine(DWORD dwCtrlType)
{
   if (dwCtrlType == CTRL_C_EVENT)
   {
      Print();
      return FALSE;
   }

   return FALSE;
}
#endif

int main(int argc, char *argv[])
{
#ifdef WIN32
   BOOL ret = SetConsoleCtrlHandler(ConsoleHandlerRoutine, TRUE);
#endif

   if( argc >= 2 )
      g_nMin = std::stoi(argv[1]);
   if (argc >= 3)
      g_nMax = std::stoi(argv[2]);

   if( argc >= 6 )
   {
      InputNumbers numbers;
      for(int i=3; i<argc; i++)
         numbers.AddNumber(std::stoi(argv[i]));
      RunGame(numbers, g_nMin, g_nMax);
      return 0;
   }

   while (true)
   {
      RunGame();

      cout << "Do it again (y/n) ";
      char ch;
      cin >> ch;
      if (ch != 'y')
         break;

      cout << endl;
   }
}
