# js常用库
## JQuery

- `在<head>中添加：<script src="https://cdn.acwing.com/static/jquery/js/jquery-3.3.1.min.js"></script>`
- 按[jQuery官网](https://jquery.com/download/)提示下载

### 选择器
`$(selector)`

```js
let main = function(){
    let $div = $('div');
}
```
### 事件
`$(selector).on(event , func)`
`$(selector).off(event , func)`

```js
$div.on("click.name1",function(){
    console.log("click div");
    $div.off("click.name1");
});

$div.on("click.name2",function(){
    console.log();
    $div.off("click.name2");
});
```

事件触发：
- e.stopPropagation() 阻止向上传递
- e.preventDefault() 阻止事件默认行为

### 元素的隐藏和展现
- `$A.hide()`
- `$A.show()`
- `$A.fadeOut()`
- `$A.fadeIn(`

```js
$btn.on("click",function(){
    $div.hide(time);
    $div.show(time);
    $div.fadeOut(time);
    $div.fadeIn(time);
});
```
### 元素的添加和删除
```js
let $a = $('<a></a>')

let $a = $(`
<a>
    <span>
    </span>
</a>
`)
```

```js
$div.click(() =>{
    $div.append($a);
    $div.prepend($a);
    $div.remove();
    $div.empty() 
});
```

### 对类的操作
- $a.addClass(class_name);//添加
- $a.removeClass(class_name); //删除
- $a.hasClass(class_name);//判断是否存在

### css操作
- css
```js
$("div").css({
    'css'
});
```

### 标签操作
- $div.attr('id') //获取
- $div.attr('id' , 'ID) //更改

### 内容操作
带了参数就是设置
无参则返回

- $a.html() // 返回html内容
- $a.text() // 返回文本信息
- $a.val() // 返回值信息

### 查找
- `$(selector).parent(filter)`：查找父元素
- `$(selector).parents(filter)`：查找所有祖先元素
- `$(selector).children(filter)`：在所有子元素中查找
- `$(selector).find(filter)`：在所有后代元素中查找

### ajax
在不刷新页面的情况下获取某些数据
#### GET
```js
$.ajax({
    url:url, //调用连接
    type:"GET", //
    data:{

    }, //传入属性
    dataType:"json", //
    success:fuction(resp){

    }, //调用成功后后端传入淑君为resp
});
```
#### POST
```js
$.ajax({
    url:url,
    type:"POST",
    data:{

    },
    dataType:"json",
    success:function(resp){

    },
});
```




## setTimeout & serInterval

- setTimeout(func , delay) // delay时间后执行
- serInterval(func , delay) //每delay执行一次

- clearTimeout() // 关闭timeout定时器
- clearInterval() //关闭interval定时器

## requestAnimationFrame

requestAnimationFrame(func)
该函数会在下次浏览器刷新页面之前执行一次，通常会用递归写法使其每秒执行60次`func`函数。调用时会传入一个参数，表示函数执行的时间戳，单位为毫秒。

例如：

```
let step = (timestamp) => {  // 每帧将div的宽度增加1像素
    let div = document.querySelector('div');
    div.style.width = div.clientWidth + 1 + 'px';
    requestAnimationFrame(step);
};

requestAnimationFrame(step);
```

与`setTimeout`和`setInterval`的区别：

- `requestAnimationFrame`渲染动画的效果更好，性能更加。  
    该函数可以保证每两次调用之间的时间间隔相同，但`setTimeout`与`setInterval`不能保证这点。`setTmeout`两次调用之间的间隔包含回调函数的执行时间；`setInterval`只能保证按固定时间间隔将回调函数压入栈中，但具体的执行时间间隔仍然受回调函数的执行时间影响。
- 当页面在后台时，因为页面不再渲染，因此`requestAnimationFrame`不再执行。但`setTimeout`与`setInterval`函数会继续执行。


## Map & Set
#### `Map`

Map 对象保存键值对。

- 用`for...of`或者`forEach`可以按插入顺序遍历。
- 键值可以为任意值，包括函数、对象或任意基本类型。

常用API：

- `set(key, value)`：插入键值对，如果`key`已存在，则会覆盖原有的`value`
- `get(key)`：查找关键字，如果不存在，返回`undefined`
- `size`：返回键值对数量
- `has(key)`：返回是否包含关键字`key`
- `delete(key)`：删除关键字`key`
- `clear()`：删除所有元素

-

#### `Set`

Set 对象允许你存储任何类型的唯一值，无论是原始值或者是对象引用。

- 用`for...of`或者`forEach`可以按插入顺序遍历。

常用API：

- `add()`：添加元素
- `has()`：返回是否包含某个元素
- `size`：返回元素数量
- `delete()`：删除某个元素
- `clear()`：删除所有元素


## localStorage
- `setItem(key, value)`：插入
- `getItem(key)`：查找
- `removeItem(key)`：删除
- `clear()`：清空

## json
JSON对象用于序列化对象、数组、数值、字符串、布尔值和`null`。

常用API：

- `JSON.parse()`：将字符串解析成对象
- `JSON.stringify()`：将对象转化为字符串

## Date
- `new Date()`：返回现在时刻。
- `new Date("2022-04-15T15:30:00.000+08:00")`：返回北京时间2022年4月15日 15:30:00的时刻。
- 两个`Date`对象实例的差值为毫秒数
- `getDay()`：返回星期，0表示星期日，1-6表示星期一至星期六
- `getDate()`：返回日，数值为1-31
- `getMonth()`：返回月，数值为0-11
- `getFullYear()`：返回年份
- `getHours()`：返回小时
- `getMinutes()`：返回分钟
- `getSeconds()`：返回秒
- `getMilliseconds()`：返回毫秒

## websocket
- `new WebSocket('ws://localhost:8080');` ： 建立ws连接。
- `send()`：向服务器端发送一个字符串。一般用JSON将传入的对象序列化为字符串。
- `onopen`：类似于`onclick`，当连接建立时触发。
- `onmessage`：当从服务器端接收到消息时触发。
- `close()`：关闭连接。
- `onclose`：当连接关闭后触发。
## window
- `window.open("https://www.acwing.com")`在新标签栏中打开页面。
- `location.reload()`刷新页面。
- `location.href = "https://www.acwing.com"`：在当前标签栏中打开页面。

## canvas
[canvas教程](https://developer.mozilla.org/zh-CN/docs/Web/API/Canvas_API/Tutorial)