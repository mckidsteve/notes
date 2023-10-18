# html元素与文档结构
## 一.文档结构

```html
<!DOCTYPE html>
<html>
    <head> 

    </head>

    <body>

    </body>

</html>

```

## 二.文本标签

1. div
2. span
3. h
4. p
5. pre
6. br
7. hr
8. i
9. b
10. del
11. ins

## 三.多媒体
#### 图片img
```html
<img src="/path" alt = "description" height = 300px width = 300px>
```

#### 音频audio
```html
<audio controls src = "path"> 无法播放 </audio>
```
<b> 或者

```html
<audio controls>
    <source src = "path" type = "audio/mpeg">
    <source src = "path2" type = "audio/mpeg">
</audio>
```

<audio controls src = "path"> 无法播放 </audio>


#### 视频video
```html
<video controls width src = ></video>
```

<video controls width = 300px src = "path">show only in web</video>

多行同上

## 四.表单

`input`
```html
<form>
    <label for="id"> input </label>
    <input type = "text" name = "inputtext" id="id">
    <button type = "submit> submit </button>
</form>
```
`<textarea>`
```html
<textarea name = "" id = "" rows= ...>
```

`<select>` `<option>`
```html
<select name = "" id = "">
    <option value = ""></option>
    <option selected value = "">op1</option>
    <option value="">op2</option>
</select>
```

## 五.列表

1.ul
```html
<ul>
    <li> 1 </li>
    <li> 2 </li>
</ul>
```
    ·  1
    ·  2

2.ol
```html
<ol>
    <li> 1 </li>
    <li> 2 </li>
</ol>
```
    1.1
    1.2

3.dl & dt/dd
```html
<dl>
    <dt> </dt>
    <dd> </dd>
</dl>
```

## 六.表格
```html
<table>
    <caption>title</caption>
    <thead>
        <tr>      <!--表头-->
            <th>b1</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td></td>
        </tr>
    </tbody>
</table>
```

## 七.语义标签

```html
<div class=""header></div>
```
等价于
```html
<header></header>
```
![Img](https://cdn.acwing.com/media/article/image/2022/03/03/1_ecfee0ac9a-img_sem_elements.gif)

1. `<header>`

 `<header>` 元素用于展示标题元素，


2. `<nav>`

`<nav>`元素表示导航部分,常见示例是菜单，目录和索引。

3. `<section>`

`<section>`元素表示一个包含在 HTML 文档中的独立内容区域

4. `<figure>`

`<figure>` 元素代表一段独立的内容，经常与说明（caption）`<figcaption>` 配合使用.这个标签经常是在主文中引用的图片，插图，表格，代码段等等.

5. `<figcaption>`

`<figcaption>` 元素是与其相关联的图片的说明/标题.

6. `<article>`

`<article>`元素表示文档、页面、应用或网站中的独立结构.

7. `<aside>`

`<aside>` 元素表示一个侧边栏或者标注框

8. `<footer>`

`<footer>` 元素表示包含该章节作者、版权数据或者与文档相关的链接等信息。


## 八.特殊符号
| HTML源代码 | 显示结果 | 描述 |
| --- | --- | --- |
| `&lt;` | < | 小于号或显示标记 |
| `&gt;` | \> | 大于号或显示标记 |
| `&amp;` | & | 可用于显示其它特殊字符 |
| `&quot;` | “ | 引号 |
| `&reg;` | ® | 已注册 |
| `&copy;` | © | 版权 |
| `&trade;` | ™ | 商标 |
| `&nbsp;` |  | 不断行的空白 |