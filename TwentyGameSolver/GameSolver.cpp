#include "GameSolver.h"
#include <string>
#include "Util.h"

#include <iostream>

using namespace std;

GameSolver::GameSolver(const InputNumbers& numbers)
   : m_Numbers(numbers)
{
}

void GameSolver::Solve(int nMin, int nMax)
{
   m_Results.SetPossibleResults(nMin, nMax);

   DoComputations();
}

void GameSolver::PrintResults()
{
   m_Results.Print();
}

void GameSolver::DoComputations()
{
   cout << "Computing..." << endl;

   DoMultipleDigitSimpleComputations();
}

void DoMultiDigitSimpleComputationsRecursive(Results& results, const InputNumbers& n, const std::string& strEquation)
{
   static const std::string arrOperations[] =
   {
      "+",
      "-",
      "*",
      "/",
      "^"
   };

   if (results.IsAllFilledIn())
      return;

   if (n.Count() == 0)
   {
      if( isNum(strEquation[strEquation.length()-1]) 
         || strEquation[strEquation.length()-1]==')' 
         || strEquation[strEquation.length()-1]=='!' )//If ends in a number or closing parentices or factorial
      {
         results.TestEquation(strEquation);
         return;
      }

      return;
   }

   for (int i = 0; i<n.Count(); i++)
   {
      InputNumbers numbers = n;
      std::string str = strEquation;
      str += NUM(numbers[i]);
      numbers.Remove(i);

      DoMultiDigitSimpleComputationsRecursive(results, numbers, str);

      //DoMultiDigitSimpleComputationsRecursive(results, numbers, str + "!");

      DoMultiDigitSimpleComputationsRecursive(results, numbers, "sqrt(" + str + ")");

      //DoMultiDigitSimpleComputationsRecursive(results, numbers, "abs(" + str + ")");

      for (int j = 0; j<SIZEOF(arrOperations); j++)
      {
         DoMultiDigitSimpleComputationsRecursive(results, numbers, str + arrOperations[j]);

         DoMultiDigitSimpleComputationsRecursive(results, numbers, str + "!" + arrOperations[j]);

         DoMultiDigitSimpleComputationsRecursive(results, numbers,  "sqrt(" + str + ")" + arrOperations[j]);

         DoMultiDigitSimpleComputationsRecursive(results, numbers,  "sqrt(" + str + ")" + arrOperations[j] + "sqrt(");

         //DoMultiDigitSimpleComputationsRecursive(results, numbers, "abs(" + str + ")" + arrOperations[j]);

         //DoMultiDigitSimpleComputationsRecursive(results, numbers, "abs(" + str + ")" + arrOperations[j] + "sqrt(" );
      }
   }
}

void GameSolver::DoMultipleDigitSimpleComputations()
{
   InputNumbers copyNumbers = m_Numbers;

   DoMultiDigitSimpleComputationsRecursive(m_Results, copyNumbers, std::string());
}



