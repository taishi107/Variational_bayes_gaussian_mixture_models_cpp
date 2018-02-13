#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<int> x;
    x.push_back(3);
    x.push_back(8);
    x.push_back(1);
    x.push_back(2);

    std::vector<int>::iterator iter = std::max_element(x.begin(), x.end());
    size_t index = std::distance(x.begin(), iter);
    std::cout << "max element is " << x[index] << std::endl;
    return 0;
}
