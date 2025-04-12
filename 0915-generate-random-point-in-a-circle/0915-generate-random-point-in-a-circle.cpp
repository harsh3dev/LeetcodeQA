class Solution {
public:
    double rad, xc, yc;
    Solution(double radius, double x_center, double y_center) {
        rad = radius;
        xc = x_center;
        yc = y_center;
    }
    double random(){
        return (double)rand() / RAND_MAX;
    }

    vector<double> randPoint() {
        double randR = sqrt(random()) * rad;
        double theta = 2 * M_PI * random();
        double rx = xc + randR * cos(theta);
        double ry = yc + randR * sin(theta);
        return {rx, ry};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */