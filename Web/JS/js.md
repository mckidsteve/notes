# js
## 变量与运算符
### let & const
- let 
- const

### 变量
- number:数值
- string:字符串
- boolean:布尔值
- object:对象
- undefined：未定义

### 运算符
=== 等于 
!== 不等于

## 输入与输出
### 输入
- html交互
- ajax或websocket的服务端输入
- 标准输入
### 输出
- console.log调试
- 改变html与css
- Ajax或websocket的返回

### 格式化字符串
1. 
```js
s = `var is ${var}`
```

2. 
```js
s = 
`<div>
    <h2></h2>
/div>`
```

3. 
```js
s = `${s.toFixed(2)}`
```
## 判断
if else
&& 
||
!

## 循环
1. for
```js
for(let i = 0;i < n;i ++)
{    
}
```
2. for key in array
3. for value of array
4. while
5. do while

## 对象
1. object.key
2. object.keyfunc()
3. object["key"]
4. object["keyfunc"]()
5. this.key

## 数组
1. arr.length //长度
2. push() // 推入元素
3. pop() //弹出元素
4. splice(a , b) //删除从a开始的b个元素
5. sort(cmp) //排序
## 函数
function func(){

}

## 类
定义
```js
class Point{
    constructor(x , y){
        this.x = x;
        this.y = y;

        this.init();
    }

    init(){
        this.sum = this.x + this.y;
    }

    tostring(){
        return '(' + this.x + ',' + this.y + ')'
    }
}

```

继承
```js
class sonpoint extends point{
    super()//父类构造函数
    super.func()//父类调用函数
}
```
静态
```js
class point{
    static func(){}
}

let p = new point();
point.func() //
p.func() //error
```
## 事件

可以通过`addEventListener`函数为元素绑定事件的触发函数。

常见的触发函数有：

### 鼠标

- `click`：鼠标左键点击
- `dblclick`：鼠标左键双击
- `contextmenu`：鼠标右键点击
- `mousedown`：鼠标按下，包括左键、滚轮、右键
    - `event.button`：0表示左键，1表示中键，2表示右键
- `mouseup`：鼠标弹起，包括左键、滚轮、右键
    - `event.button`：0表示左键，1表示中键，2表示右键

-

### 键盘

- `keydown`：某个键是否被按住，事件会连续触发
    - `event.code`：返回按的是哪个键
    - `event.altKey`、`event.ctrlKey`、`event.shiftKey`分别表示是否同时按下了alt、ctrl、shift键。
- `keyup`：某个按键是否被释放
    - `event`常用属性同上
- `keypress`：紧跟在`keydown`事件后触发，只有按下字符键时触发。适用于判定用户输入的字符。
    - `event`常用属性同上

`keydown`、`keyup`、`keypress`的关系类似于鼠标的`mousedown`、`mouseup`、`click`

-

### 表单

- `focus`：聚焦某个元素
- `blur`：取消聚焦某个元素
- `change`：某个元素的内容发生了改变

-

### 窗口

需要作用到`window`元素上。

- `resize`：当窗口大小放生变化
- `scroll`：滚动指定的元素
- `load`：当元素被加载完成