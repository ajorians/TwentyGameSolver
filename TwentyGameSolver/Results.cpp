#include "Results.h"
#include <iostream>

using namespace std;

void Results::SetPossibleResults(int nMin, int nMax)
{
   for (int i = nMin; i<=nMax; i++)
      m_arrExpressions.push_back(ValidExpressions(i));
}

void Results::Print() const
{
   for (std::vector<ValidExpressions>::size_type i = 0; i<m_arrExpressions.size(); i++)
   {
      cout << m_arrExpressions[i].GetValue() << ": " << m_arrExpressions[i].GetTopExpression() << endl;
   }
}

int GetOpenParentices(const std::string& str)
{
   int nCount = 0;
   for(std::string::size_type i=0; i<str.length(); i++)
      if( str[i] == '(' )
         nCount++;

   return nCount;
}

int GetCloseParentices(const std::string& str)
{
   int nCount = 0;
   for (std::string::size_type i = 0; i<str.length(); i++)
      if (str[i] == ')')
         nCount++;

   return nCount;
}

std::string FixEquation(const std::string& str)
{
   int nOpeningParentices = GetOpenParentices(str);
   int nClosingParentices = GetCloseParentices(str);

   if (nClosingParentices > nOpeningParentices)
      return std::string();

   std::string strRet = str;
   for(int i=nOpeningParentices; i<nClosingParentices; i++)
      strRet += ")";

   return strRet;
}

#include "exprtk/exprtk.hpp"
void Results::TestEquation(const std::string& strEquation)
{
   /*double d;
   bool b = exprtk::compute("abs(-9)", d);*/

   m_nEquationsTested++;
   if( m_nEquationsTested %1000 == 0 )
      cout << m_nEquationsTested << ": (" << GetNumberFilledIn() << "/" << m_arrExpressions.size() << ")" << endl;

   std::string str = FixEquation(strEquation);

   double dResult;
   bool bOK = exprtk::compute(str, dResult);
   if( !bOK )
      return;

   for ( std::vector<ValidExpressions>::iterator it = m_arrExpressions.begin(); it != m_arrExpressions.end(); it++)
   {
      if( /*!it->HasValue() &&*/ it->GetValue() == dResult )
         it->AddExpression(str);
   }
}

bool Results::IsAllFilledIn() const
{
   for (std::vector<ValidExpressions>::const_iterator it = m_arrExpressions.cbegin(); it != m_arrExpressions.cend(); it++)
      if ( !it->HasValue() )
         return false;

   return true;
}

int Results::GetNumberFilledIn() const
{
   int nCount = 0;
   for (std::vector<ValidExpressions>::const_iterator it = m_arrExpressions.cbegin(); it != m_arrExpressions.cend(); it++)
      if (it->HasValue())
         nCount++;

   return nCount;
}


