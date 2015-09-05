#pragma once

#include <string>
#include <vector>

class ValidExpressions
{
public:
   ValidExpressions(int nValue);

   void AddExpression(const std::string& strExpression);

   int GetValue() const { return m_nValue; }
   std::string GetTopExpression() const;

   bool HasValue() const;

protected:
   int m_nValue;
   std::vector<std::string> m_astrExpressions;
};
