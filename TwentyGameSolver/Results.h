#pragma once

#include <vector>
#include "ValidExpressions.h"

class Results
{
public:
   void SetPossibleResults(int nMin, int nMax);
   void Print() const;

   void TestEquation(const std::string& strEquation);

   bool IsAllFilledIn() const;
   int GetNumberFilledIn() const;

protected:
   int m_nEquationsTested = 0;
   std::vector<ValidExpressions> m_arrExpressions;
};
