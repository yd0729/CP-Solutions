class Solution {
  private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;

  public:
    Solution(double radius, double x_center, double y_center)
        : dis(0, 1), xc(x_center), yc(y_center), r(radius) {}

    vector<double> randPoint() {
        double u = dis(gen), theta = dis(gen) * 2 * acos(-1.0);  // * 2 pi
        double rr = sqrt(u);
        return {xc + rr * cos(theta) * r, yc + rr * sin(theta) * r};
    }
};