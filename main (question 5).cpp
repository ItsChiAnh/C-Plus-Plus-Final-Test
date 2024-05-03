#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Hướng đi cho việc kiểm tra các ô xung quanh: xuống, lên, phải, trái
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); // số hàng của lưới
        int n = grid[0].size(); // số cột của lưới
        int countFreshOrange = 0; // đếm số cam tươi
        queue<pair<int,int>> q; // hàng đợi để lưu vị trí của các cam thối

        // Duyệt qua lưới để đếm cam tươi và thêm cam thối vào hàng đợi
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) countFreshOrange++; // nếu là cam tươi thì tăng đếm
                if (grid[i][j] == 2) q.push({i, j}); // nếu là cam thối thì thêm vào hàng đợi
            }
        }

        // Nếu không có cam tươi nào, trả về 0 vì không cần thời gian để lan truyền
        if (!countFreshOrange) return 0;

        int minutes = 0; // biến đếm thời gian cần thiết để tất cả cam tươi thành thối

        // Xử lý hàng đợi bằng cách lan truyền sự thối 
        while (!q.empty()) {
            int l = q.size(); // số lượng cam thối trong hàng đợi tại thời điểm hiện tại
            while (l--) {
                auto [i, j] = q.front(); q.pop(); // lấy vị trí cam thối ra khỏi hàng đợi
                // Kiểm tra các ô xung quanh cam thối hiện tại
                for (auto [a, b] : dirs) {
                    int x = i + a, y = j + b; // tính toán vị trí mới sau khi di chuyển
                    // Kiểm tra xem vị trí mới có nằm trong lưới, và là cam tươi hay không
                    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1) continue;
                    grid[x][y] = 2; // làm cho cam tươi trở thành thối
                    countFreshOrange--; // giảm số lượng cam tươi đi 1
                    // Nếu không còn cam tươi nào, trả về số phút cộng thêm 1 (vì bắt đầu từ 0)
                    if (!countFreshOrange) return minutes + 1;
                    q.push({x, y}); // thêm cam mới thối vào hàng đợi để tiếp tục quá trình
                }
            }
            minutes++; // tăng số phút sau khi xử lý xong một lớp
        }

        // Nếu vẫn còn cam tươi sau khi xử lý hết hàng đợi, trả về -1 (không thể thối hết được)
        return -1;
    }
};

