//
// Created by lixiaoqing on 2022/6/7.
//

#include <vector>

using namespace std;

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};

class Bipartition {
public:
    vector<double> getBipartition(vector<Point> A, vector<Point> B) {
        // 平分两个正方形的直线必然经过两个正方形的中心。A、B的坐标有可能是混乱的
        double x1 = (A[0].x + A[1].x + A[2].x + A[3].x) / 4.0;
        double y1 = (A[0].y + A[1].y + A[2].y + A[3].y) / 4.0;
        double x2 = (B[0].x + B[1].x + B[2].x + B[3].x) / 4.0;
        double y2 = (B[0].y + B[1].y + B[2].y + B[3].y) / 4.0;
        double k = (y1 - y2) / (x1 - x2);
        double b = y1 - k * x1;
        return {k, b};
    }
};