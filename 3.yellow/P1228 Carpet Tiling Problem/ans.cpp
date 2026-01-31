#include <iostream>
using namespace std;

/*
    分析 code.cpp 的主要错误 / Analysis of errors in code.cpp:

    1. 分治策略错误 / Incorrect Divide & Conquer Strategy:
       原代码尝试将矩阵不断划分，直到大小为 2x2 (rx-lx <= 1) 才开始放置地毯。
       这是错误的。标准的分治算法需要在每一层递归中，先在中心放置一个地毯，
       填补三个不包含特殊点（公主/缺口）的子区域的角，从而构造出 4 个都包含一个特殊点的子问题。
       The original code only tries to place carpets when the recursion reaches the base case (2x2).
       This is incorrect. The standard algorithm places a carpet at the center *at each level* 
       to cover the corners of the 3 quadrants that don't have the hole, creating 4 valid subproblems.

    2. 缺少“中心覆盖”步骤 / Missing "Center Coverage" Step:
       由于没有在每一层放置中心地毯，原本完整的子矩形（不含特殊点）无法变成合法的子问题
       （即缺少一个格子的矩形）。导致无法继续正确递归。
       Without placing the central carpet, the full sub-rectangles (those without the hole)
       remain full squares, which cannot be tiled by L-trominoes alone (area % 3 != 0).

    3. 坐标计算复杂且可能出错 / Complex and prone-to-error coordinate calculations:
       原代码使用了 lx, ly, rx, ry 和 mid_len，逻辑较为混乱。
       标准写法通常使用 (x, y) 作为左上角坐标，len 作为边长，逻辑更清晰。
*/

// x, y: 当前矩阵左上角坐标 / Top-left coordinate of current square
// hx, hy: 特殊点（公主或已被覆盖的点）坐标 / Coordinate of the special point (princess or covered)
// len: 当前矩阵边长 / Length of the current square side
void solve(int x, int y, int hx, int hy, int len) {
    if (len == 1) return; // 递归基 / Base case

    int mid = len / 2;
    
    // 计算四个子矩阵的中心交界点附近的四个格子坐标
    // The four cells at the center intersection
    // 左上 Top-Left: (x+mid-1, y+mid-1)
    // 右上 Top-Right: (x+mid-1, y+mid)
    // 左下 Bottom-Left: (x+mid, y+mid-1)
    // 右下 Bottom-Right: (x+mid, y+mid)

    // 判断特殊点在哪个子矩阵中 / Check which quadrant contains the special point
    
    // 1. 特殊点在左上角子矩阵 / Hole in Top-Left
    if (hx < x + mid && hy < y + mid) {
        // 放置地毯类型 1（覆盖右上、左下、右下），拐角在 (x+mid, y+mid)
        cout << x + mid << " " << y + mid << " " << 1 << endl;
        
        solve(x, y, hx, hy, mid);                 // 递归左上（包含原特殊点）
        solve(x, y + mid, x + mid - 1, y + mid, mid); // 递归右上（特殊点为刚才被覆盖的左下角）
        solve(x + mid, y, x + mid, y + mid - 1, mid); // 递归左下（特殊点为刚才被覆盖的右上角）
        solve(x + mid, y + mid, x + mid, y + mid, mid); // 递归右下（特殊点为刚才被覆盖的左上角）
    }
    // 2. 特殊点在右上角子矩阵 / Hole in Top-Right
    else if (hx < x + mid && hy >= y + mid) {
        // 放置地毯类型 2（覆盖左上、左下、右下），拐角在 (x+mid, y+mid-1)
        cout << x + mid << " " << y + mid - 1 << " " << 2 << endl;
        
        solve(x, y, x + mid - 1, y + mid - 1, mid); // 递归左上
        solve(x, y + mid, hx, hy, mid);           // 递归右上（包含原特殊点）
        solve(x + mid, y, x + mid, y + mid - 1, mid); // 递归左下
        solve(x + mid, y + mid, x + mid, y + mid, mid); // 递归右下
    }
    // 3. 特殊点在左下角子矩阵 / Hole in Bottom-Left
    else if (hx >= x + mid && hy < y + mid) {
        // 放置地毯类型 3（覆盖左上、右上、右下），拐角在 (x+mid-1, y+mid)
        cout << x + mid - 1 << " " << y + mid << " " << 3 << endl;
        
        solve(x, y, x + mid - 1, y + mid - 1, mid); // 递归左上
        solve(x, y + mid, x + mid - 1, y + mid, mid); // 递归右上
        solve(x + mid, y, hx, hy, mid);           // 递归左下（包含原特殊点）
        solve(x + mid, y + mid, x + mid, y + mid, mid); // 递归右下
    }
    // 4. 特殊点在右下角子矩阵 / Hole in Bottom-Right
    else {
        // 放置地毯类型 4（覆盖左上、右上、左下），拐角在 (x+mid-1, y+mid-1)
        cout << x + mid - 1 << " " << y + mid - 1 << " " << 4 << endl;
        
        solve(x, y, x + mid - 1, y + mid - 1, mid); // 递归左上
        solve(x, y + mid, x + mid - 1, y + mid, mid); // 递归右上
        solve(x + mid, y, x + mid, y + mid - 1, mid); // 递归左下
        solve(x + mid, y + mid, hx, hy, mid);       // 递归右下（包含原特殊点）
    }
}

int main() {
    // 优化 I/O / Optimize I/O
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int k, x, y;
    if (cin >> k >> x >> y) {
        int n = 1 << k; // 2^k
        solve(1, 1, x, y, n);
    }
    return 0;
}
