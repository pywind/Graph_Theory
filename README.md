# **Graph_Algorithm**
## Lý thuyết đồ thị :
### Một đồ thị kí hiệu G = (V, E)
## Trong đó: 
* V: tập các đỉnh, |V| = n = số đỉnh
* E: Tập các cạnh, |E| = m = số đỉnh
* e thuộc E liên kết với một cặp đỉnh v, w thuộc V và được kí hiệu e = (v, w)  v_____(e)_____w
* e1 = (v, w), e2 = (w, v) là 2 **cạnh song song**
* e = (v, v) là **một vòng**
* d(v) là **bậc của đỉnh v**, là số cạnh kề với v, *vòng được tính là 2*
* Đỉnh có bậc 0 là **đỉnh cô lập**
* Đỉnh bậc là 1 là **đỉnh treo** 

### Một đồ thị được lưu trữ thông qua mảng hai chiều
* G luôn là đồ thị đơn giản (không có cạnh song song và không có vòng) 
* W[u][v] = a thuộc E; u, v là các đỉnh
* a gọi là trọng số
* Đường đi: Cho G = (V, E) là đồ thị. Cho v, w thuộc V; đường đi nối đỉnh v với w ký hiệu P(v, w)
* |P(v, w)| = n là chiều dài đường đi
### Định nghĩa chu trình: 
* Một chu trình **đỉnh v** là P(v, v) 
* D : là mảng lưu trữ độ dài đến đỉnh thứ i
* p : với p[v] = u, đỉnh kề của v là u, với D[v] - D[u] là ngắn nhất
