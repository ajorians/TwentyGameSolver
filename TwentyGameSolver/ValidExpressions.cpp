#include "ValidExpressions.h"

ValidExpressions::ValidExpressions(int nValue)
   : m_nValue(nValue)
{
}

void ValidExpressions::AddExpression(const std::string& strExpression)
{
#ifdef _DEBUG
   const int nValue = GetValue();
#endif
   m_astrExpressions.push_back(strExpression);
}

std::string ValidExpressions::GetTopExpression() const
{
   if( m_astrExpressions.size() <= 0 )
      return std::string();

   return m_astrExpressions[0];
}

bool ValidExpressions::HasValue() const
{
   return m_astrExpressions.size() != 0;
}

