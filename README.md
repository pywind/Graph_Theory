# **Graph Theory**
## General theory 
>  Lý thuyết đồ thị :
### Một đồ thị kí hiệu G = (V, E)
## Trong đó: 
* V: tập các đỉnh, |V| = n = số đỉnh
* E: Tập các cạnh, |E| = m = số đỉnh
* e thuộc E liên kết với một cặp đỉnh v, w thuộc V và được kí hiệu e = (v, w)  
                                      (v)______e_____(w)
* e1 = (v, w), e2 = (w, v) là 2 **cạnh song song**
* e = (v, v) là **một vòng**
* d(v) là **bậc của đỉnh v**, là số cạnh kề với v, *vòng được tính là 2*
* Đỉnh có bậc 0 là **đỉnh cô lập**
* Đỉnh bậc là 1 là **đỉnh treo** 

### Một đồ thị lưu thông 
![Graph](https://lh3.googleusercontent.com/proxy/7MvOFYG_CAIWtWiqiA7MeS6717P1uUeSzrNpqZ6BYJpBlcJ3cbJcvv5fZo-r5D-bLGcFLYzzbnaUid6ulw54hlh1gHbSMzOYkdkDj3SAhd_VhFMrKyuFEHn8)
* G luôn là đồ thị đơn giản (không có cạnh song song và không có vòng) 
* W[u][v] = a thuộc E; u, v là các đỉnh
* a gọi là trọng số
* Đường đi: Cho G = (V, E) là đồ thị. Cho v, w thuộc V; đường đi nối đỉnh v với w ký hiệu *P(v, w)*
* |P(v, w)| = n là chiều dài đường đi
* Một đường đi gọi là ***sơ cấp*** ,nếu không có *đỉnh* nào xuất hiện quá **một** lần.
* Đỉnh v lưu thông w <=> (v = w) v P(v, w) != rỗng
### Cây 
![Tree](https://www.thecrazyprogrammer.com/wp-content/uploads/2017/08/Tree-Data-Structure.gif)
* Cây T là một đồ thị đơn giản thỏa: T liên thông và không chu trình sơ cấp.
* Trong T một đỉnh v nào đó được chọn làm gốc (duy nhất).
* Độ dài đường đi sơ cấp từ gốc đến đỉnh v được gọi mức của v. Gốc có mức 0
### Cây khung 
> Định nghĩa 
*  T là cây khung của một đồ thị G = (V, E) nếu T là một cây có tập đỉnh là tập đỉnh V và
tập cạnh là tập con của E của G.
![Spanning tree](https://miro.medium.com/proxy/1*-gNoEeTMGYnCG5SSLi1Wtg.png)
* Định lý 
  * Một đồ thị G có cây khung nếu và chỉ nếu G liên thông.
### Mô tả trong chương trình  
* Một chu trình **đỉnh v** là P(v, v) 
* D : là mảng lưu trữ độ dài đến đỉnh thứ i
* p : với p[v] = u, đỉnh kề của v là u, với D[v] - D[u] là ngắn nhất
