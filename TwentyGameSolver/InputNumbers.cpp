#include "InputNumbers.h"
#include <cassert>

InputNumbers::InputNumbers()
{
}

InputNumbers::InputNumbers(int n1, int n2, int n3, int n4)
{
   m_arrNumbers.push_back(n1);
   m_arrNumbers.push_back(n2);
   m_arrNumbers.push_back(n3);
   m_arrNumbers.push_back(n4);
}

InputNumbers::InputNumbers(const InputNumbers& rhs)
{
   for(int i=0; i<rhs.Count(); i++)
      m_arrNumbers.push_back(rhs.GetNumber(i));
}

void InputNumbers::AddNumber(int n)
{
   m_arrNumbers.push_back(n);
}

int InputNumbers::Count() const
{
   return (int)m_arrNumbers.size();
}

int InputNumbers::GetNumber(int nIndex) const
{
   assert( !(nIndex < 0 || nIndex >= Count()) );

   return m_arrNumbers[nIndex];
}

int InputNumbers::operator[](int nIndex) const
{
   return GetNumber(nIndex);
}

void InputNumbers::Remove(int nIndex)
{
   assert( !(nIndex < 0 || nIndex >= Count()) );

   m_arrNumbers.erase(m_arrNumbers.begin() + nIndex);
}
