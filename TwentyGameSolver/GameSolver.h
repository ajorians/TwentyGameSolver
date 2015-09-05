#pragma once

#include <vector>
#include <utility>
#include <string>

#include "InputNumbers.h"
#include "Results.h"

class GameSolver
{
public:
   GameSolver(const InputNumbers& numbers);

   void Solve(int nMin, int nMax);

   void PrintResults();

protected:
   void DoComputations();

   void DoMultipleDigitSimpleComputations();

protected:
   InputNumbers m_Numbers;

   Results m_Results;
};
