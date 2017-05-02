#include <iostream>
#include <vector>


template<class It, class Cmp>
void qsort(It beg, It end, Cmp cmp){
    if (beg != end){
        It ffirst = beg;
        It fend = end;
        It cen = beg+1;
        while (cen != fend) {

            if (cmp(*cen, *ffirst)) {
                ++cen;
            } else {
                while ((cen != fend) && cmp(*ffirst, *fend)) {
                    --fend;
                }
                std::swap(*cen, *fend);
            }
        }
        --cen;
        std::swap(*ffirst, *cen);
        qsort(beg, cen, cmp);
        qsort(fend, end, cmp);

    }
}


int main() {
    std::cout<< "Sort" << std::endl;
    return 0;

}