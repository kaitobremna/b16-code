#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
    assert(index<= A.size());

    for(int j = index;j+1<= A.size();j++)
    {
        A[j] = A[j+1];
    }

    A.pop_back();
}

#endif // __array_delete__