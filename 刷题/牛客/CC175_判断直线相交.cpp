//
// Created by lixiaoqing on 2022/5/30.
//

class CrossLine {
public:
    bool checkCrossLine(double s1, double s2, double y1, double y2) {
        if (s1 == s1 && y1 != y2) {
            return false;
        }
        return true;
    }
};