// PROBLEM : Given a set of N >= 4 points in the X-Y plane, find the number of rectangles that can be drawn such that the
// corners of each rectangle lie on any 4 of the points in the given set. Note that the rectangles do not have to be aligned
// with the x and y axes.

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

class Point {
public:

    Point() =default;

    Point(double x, double y)
            :x_(x), y_(y)
    {}

    friend double dist(Point& A, Point& B) {return sqrt((A.x_ - B.x_)*(A.x_ - B.x_) + (A.y_ - B.y_)*(A.y_ - B.y_));}

    friend Point midpoint(Point&A, Point& B) {return {0.5* (A.x_ + B.x_), 0.5* (A.y_ + B.y_)};}

    friend Point diff(Point& A, Point& B) {return {A.x_ - B.x_, A.y_ - B.y_};}

    friend double dot(Point& A, Point& B) {return A.x_ * B.x_ + A.y_*B.y_;}

    bool operator == (const Point& rhs) {return x_ == rhs.x_ && y_ == rhs.y_;}

private:
    double x_{0};
    double y_{0};
};

// this returns malloced memory!
double** distances(vector<Point> pts_arr)
{
    size_t N = pts_arr.size();

    auto distances = new double*[N];

    for (size_t i = 0; i < N; i++)
    {
        distances[i] = new double[N]{0};
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            distances[i][j] = dist(pts_arr[i], pts_arr[j]);
        }
    }

    return distances;
}

size_t count(size_t i, size_t j, double** distances, vector<Point> pts)
{

    size_t N = pts.size();

    size_t ans = 0;

    double dist = distances[i][j];

    for (size_t m = 0; m < N ; m++)
    {
        if (m == i) {continue;}
        for (size_t n = 0; n < m; n++)
        {
            if (n == j) { continue; }

            // if distances are equal
            if (dist == distances[m][n])
            {
                // if midpoints are equal
                if (midpoint(pts[m], pts[n]) == midpoint(pts[i], pts[j]))
                {
                        ans += 1;
                }
            }
        }
    }

    return ans;
}

vector<Point> to_Point(vector<int> x, vector<int> y)
{
    auto pts = vector<Point>(x.size());

    for (size_t i = 0; i < x.size(); i++)
    {
        pts[i] = Point(x[i], y[i]);
    }

    return pts;
}

size_t num_Rectangles(vector<int> x, vector<int> y)
{
    if (x.size() != y.size()) {exit(1);}

    // number of points on the plane
    size_t N = x.size();

    // array of (x,y) points
    vector<Point> pts = to_Point(x,y);

    // dists[i][j] returns the distance between point i and point j (j must be less than i)
    double** dists = distances(pts);

    size_t answer = 0;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j <i; j++)
        {
            answer += count(i,j, dists, pts);
        }
    }

    // free memory
    for (size_t i = 0; i < N; i++){delete[] dists[i]; }
    delete[] dists;

    // return answer
    return answer/2;
}

int main() {

    vector<int> x = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    vector<int> y = {1,   0, -1, 1, 0,-1, 0, 1, -1};

    std::cout << "Number of Rectangles: " << num_Rectangles(x,y);
}