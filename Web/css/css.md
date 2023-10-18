# CSS

## 一.css样式定义方式
### 行内样式表
直接定义在tag的style属性中
```CSS
<img scr="" alt="" style="width:300px;height:200px">
```
### 内部样式表
定义在head的style标签中，再通过选择器来影响对应的标签
```css
<style>
    img  {
        width:300px;
        height:200px;
    }
</style>

<img class="big" ...>
```
### 外部样式表
定义在外部上style标签上，可以通过link应用到多个文件上
```css
/*`file:style.css`*/
img {
    width:50px;
    height:200px;
}
```
```html
<!-- main.html -->
<link rel="stylesheet" href="/path" type="text/css">
```

## 二.选择器

### 标签选择器
1. div 选择器
可以应用至所有的div标签
```css
div{
    ...
}
```

2. ID 选择器
仅选择ID为xxx的标签
```css
xxx {

}

<div id = "xxx">
```

3. 类选择器
选择所有xxx类的标签
```css
.xxx {
    ...
}

<div class="xxx">
```

4. 伪类选择器
伪类用于定义元素的特殊状态。

- `:link`：链接访问前的样式
- `:visited`：链接访问后的样式
- `:hover`：鼠标悬停时的样式
- `:active`：鼠标点击后长按时的样式
- `:focus`：聚焦后的样式

位置伪类选择器：

- `:nth-child(n)`：选择是其父标签第`n`个子元素的所有元素。

目标伪类选择器：

- `:target`：当url指向该元素时生效。

5. 复合选择器
由两个及以上基础选择器组合而成的选择器。

- `element1, element2`：同时选择元素`element1`和元素`element2`。
- `element.class`：选则包含某类的`element`元素。
- `element1 + element2`：选择紧跟`element1`的`element2`元素。
- `element1 element2`：选择`element1`内的所有`element2`元素。
- `element1 > element2`：选择父标签是`element1`的所有`element2`元素。


6. 通配符选择器

- `*`：选择所有标签
- `[attribute]`：选择具有某个属性的所有标签
- `[attribute=value]`：选择`attribute`值为`value`的所有标签

7. 伪元素选择器
将特定内容当做一个元素，选择这些元素的选择器被称为伪元素选择器。

- `::first-letter`：选择第一个字母
- `::first-line`：选择第一行
- `::selection`：选择已被选中的内容
- `::after`：可以在元素后插入内容
- `::before`：可以在元素前插入内容\

### 样式渲染优先级
- 越具体的选择器权重越大
- 权重相同时，后一个样式覆盖前一个样式
- 继承自父元素的权最低

## 三.颜色
1. 预定义颜色
如black，white等 
2. 16进制表示
 #AABBCC
 第1-2位表示红色
 第3-4位表示绿色
 第5-6位表示蓝色
3. RGB表示
 rgb(r_num,g_num,b_num)
4. RGBA表示
 rgba(r,g,b,a)
5. 取色模式
 网页模式可用chrome调试模式获取

## 四.文本

附录：
| 单位 | 描述 |
| --- | --- |
| px | 设备上的像素点 |
| % | 相对于父元素的百分比 |
| em | 相对于当前元素的字体大小 |
| rem | 相对于根元素的字体大小 |
| vw | 相对于视窗宽度的百分比 |
| vh | 相对于视窗高度的百分比 |

---


1. `text-align`
 控制对齐方式
 center:居中
 ...
2. `line-height`
 控制行间距
3. `letter-spacing`
 控制文本字符占地大小（间距）
4. `text-indent`
 控制缩进量
5. `text-decoration`
 修饰线外观
 -line
 -color
 -style
 -thickness

6. `text-shadow`
 添加阴影

## 五.字体
1. font-size
 字体大小
2. font-style
 字体风格(粗/斜)
3. font-weight
 字体粗细
4. font-family
 字体(带衬线/草书)

## 六.背景
1.  background-color
 背景颜色
2.background-image
 背景图
3. background-size
 背景图片大小
4. background-repeat
 背景图重复方式
5. background-position
 背景图初始位置
6. background-attachment
 背景图像是否固定

## 七.边框
1. `border-style`
 设定边框的样式。

2. `border-width`
 设置边框宽度。

3. `border-color`
 设置元素四个边框颜色的快捷属性：top,bottom,left,right

4. `border-radius`
 设置边框圆角。

5. `border-collapse`
 决定边框是分开的还是合并的。

## 八.元素展示格式
1. `display`
    - `block`
        - 独占一行
        - w，h，margin，padding可控
        - w默认100%
    - `inline`
        - 共占一行
        - w与h无关，m与p水平有关
        - w默认为内容宽度
    - `inline-block`
        - 共占一行
        - w，h，m，p可控
        - w默认为内容长度

2. `white-space`
 处理空白
3. `text-overflow`
 处理内容溢出
 (如果超出行宽则用...代替)
4. `overflow`
 处理溢出
 (如果超出则用滚轮等代替)
 可-x，-y指定

## 九.边界
1.  `margin`

`margin`属性为给定元素设置所有四个（上下左右）方向的外边距属性。

- 可以接受1~4个值（上、右、下、左的顺序）
- 可以分别指明四个方向：`margin-top`、`margin-right`、`margin-bottom`、`margin-left`
- 可取值
    - `length`：固定值
    - `percentage`：相对于包含块的宽度，以百分比值为外边距。
    - `auto`：让浏览器自己选择一个合适的外边距。有时，在一些特殊情况下，该值可以使元素居中。
- 外边距重叠
    - 块的上外边距(margin-top)和下外边距(margin-bottom)有时合并(折叠)为单个边距，其大小为单个边距的最大值(或如果它们相等，则仅为其中一个)，这种行为称为边距折叠。
    - 父元素与后代元素：父元素没有上边框和padding时，后代元素的`margin-top`会溢出，溢出后父元素的`margin-top`会与后代元素取最大值。

2. `padding`

`padding` CSS 简写属性控制元素所有四条边的内边距区域。

- 可以接受1~4个值（上、右、下、左的顺序）
- 可以分别指明四个方向：`padding-top`、`padding-right`、`padding-bottom`、`padding-left`
- 可取值
    - `length`：固定值
    - `percentage`：相对于包含块的宽度，以百分比值为内边距。

## 十.盒子模型
1. `box-sizing`

CSS 中的 `box-sizing` 属性定义了 user agent 应该如何计算一个元素的总宽度和总高度。

- `content-box`：是默认值，设置`border`和`padding`均会增加元素的宽高。
- `border-box`：设置`border`和`padding`不会改变元素的宽高，而是挤占内容区域。
