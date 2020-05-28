# **Breadth-First Search**
> Thuật toán tìm kiếm theo chiều rộng
### Mục đích: 
* tìm kiếm đường đi từ một đỉnh khác hoặc ngược lại, hoặc tìm kiếm đường đi từ đỉnh gốc tới tất cả cách đỉnh khác. 
* Dùng tìm các thành phần liên thông của đồ thị, hoặc kiểm tra đồ thị hai phía.
## Thuật toán
> Sử dụng cấu trúc dữ liệu ***queue*** *(hàng đợi)*
### Queue là CTDL cho phép lưu trữ và truy xuất dữ liệu ***First In First Out***
1. C++ library 
``` C++ 
#include <queue> 
```
2. Constructor
``` C++
 queue <data_type> name_queue
 /// declare from list
 queue <int, list <int>> name_queue
 ```
 3. Function
 
 > .empty() : *Return true if queue is empty*

 > .size() : *Return size of queue*

 > .front() : *Reference to the first element*

 > .back() : *Reference to the last element*

 > .push(val) : *Copy value and insert on the last of queue*

 > .pop() : *delete the first index of queue*
* C++11 :
 > .emplace() : construct and insert value

 > .swap(name_queue2) : *swap 2 queue*

 4. Algorithm
 #### Source code C++ :
 ``` C++ 
 void BFS(int W[][50], int n, int m, int s) {
    D[1] = 1;
    p[1] = -1;
    queue <int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v = 1; v <= n; ++v) {
            if (W[u][v] > 0 && D[v] == 0) {
                D[v] = 1;
                p[v] = u;
                Q.push(v);
            }
        }
    }
}
``` 
5. **Complexity**
* Space: $2|V|$ , $|V|$ is number of vertices
* Time: $O(|V|+|E|)$ 
6. Tracing
### If you have had declared array p, you would have traced and found the way of spanning tree
### p[v] = u is the shortest way between u and v


