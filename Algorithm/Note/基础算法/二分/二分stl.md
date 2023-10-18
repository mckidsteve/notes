# 二分stl
C++ 标准库中实现了查找首个不小于给定值的元素的函数 std::lower_bound 和查找首个大于给定值的元素的函数 std::upper_bound，二者均定义于头文件 <algorithm> 中。
二者均采用二分实现，所以调用前必须保证元素有序。



``STL::lower_bound``

``auto lower = std::lower_bound(data.begin(), data.end(), i);``

``STL::upper_bound``

``auto upper = std::upper_bound(data.begin(), data.end(), i);``

[oiwiki](https://oi-wiki.org/basic/binary/)