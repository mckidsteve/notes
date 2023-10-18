# Trie树
Trie树又称字典树，单词查找树。
是一种能够高效存储和查找字符串集合的数据结构。
![Img](https://cdn.acwing.com/media/article/image/2020/06/13/31041_aa11ff2cad-Trie1.PNG)

![Img](https://cdn.acwing.com/media/article/image/2020/06/13/31041_aed49a42ad-Trie2.PNG)
## 插入操作
向下遍历字母结点，若该结点不存在，则创建结点，值为idx；

其构造数组为:

    son[p][u]

其中p为父节点所对应的idx，u为字母数字

```c++
void insert(string x){
    int p = 0;
    for(int i = 0;x[i] ; i++){
        int u = x[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p] ++;
}
```

## 查找操作
类似
```c++
int query(string x){
    int p = 0;
    for(int i = 0 ;x[i] ; i ++){
        int u = x[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
```

# 最大异或对
## 异或
bit 位不同则true
bit 位相同则false
```
0^0 = 0
1^0 = 1
0^1 = 1
1^1 = 0
```
按位异或的三个特点：
- 0异或任何数 = 原数
- 1异或任何数 = 原数取反
- 任何数异或任何数 = 0

用途：
- 使特定位翻转：
    xor：000xx00
- 使两个整数交换值：
    a = a^b
    b = b^a
    a = a^b
- 使变量置零：
    xor a , a
- 判断是否相等：
    return (a^b) == 0

