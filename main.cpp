#include <iostream>
#include <vector>

template<class It, class Cmp>
void qsort(It beg, It end, Cmp cmp) {
    if (beg != end) {
        It left = beg;
        It right = end;
        It tmp = beg;
        left++;
        while (left != right) {

            if (cmp(*left, *tmp))
                ++left;

            else {
                --right;
                while ((left != right) && cmp(*tmp, *right))
                    --right;
                if (left != right) {
                    std::swap(*left, *right);
                }
            }

        }
        --left;
        std::swap( *tmp, *left );
        qsort(beg, left, cmp);
        qsort(right, end, cmp);
    }
}


int main()
{
    std::vector<int> a = { 5, 12, 13, 0, 35, 3, 1, 4 };
    qsort<std::vector<int>::iterator, std::less<int>>(a.begin(), a.end(), std::less<int>());
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        std::cout << *it << " ";
    }
    return 0;
}