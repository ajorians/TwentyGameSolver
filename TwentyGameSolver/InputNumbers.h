#pragma once

#include <vector>

class InputNumbers
{
public:
   InputNumbers();
   InputNumbers(int n1, int n2, int n3, int n4);
   InputNumbers(const InputNumbers& rhs);

   void AddNumber(int n);

   int Count() const;
   int GetNumber(int nIndex) const;
   int operator[](int nIndex) const;

   void Remove(int nIndex);

protected:
   std::vector<int> m_arrNumbers;
};
