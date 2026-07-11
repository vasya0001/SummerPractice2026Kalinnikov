#include <iostream>
#include <algorithm>
 
int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
 
    int min_x1 = std::min(x1, x2), max_x1 = std::max(x1, x2);
    int min_y1 = std::min(y1, y2), max_y1 = std::max(y1, y2);
    
    int min_x2 = std::min(x3, x4), max_x2 = std::max(x3, x4);
    int min_y2 = std::min(y3, y4), max_y2 = std::max(y3, y4);
 
    long long s1 = (long long)(max_x1 - min_x1) * (max_y1 - min_y1);
    long long s2 = (long long)(max_x2 - min_x2) * (max_y2 - min_y2);
 
    //пересечение
    int inter_x1 = std::max(min_x1, min_x2);
    int inter_y1 = std::max(min_y1, min_y2);
    int inter_x2 = std::min(max_x1, max_x2);
    int inter_y2 = std::min(max_y1, max_y2);
 
    long long s_inter = 0;
    if (inter_x2 > inter_x1 && inter_y2 > inter_y1) {
        s_inter = (long long)(inter_x2 - inter_x1) * (inter_y2 - inter_y1);
    }
 
    std::cout << s1 + s2 - s_inter << std::endl;
 
    return 0;
}