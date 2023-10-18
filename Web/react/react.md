# react
## 环境搭建
> win: git bash 环境下create-react-app 'appname'
> 依赖：nodejs

## ES6语法补充
1. bind()绑定this的取值

*在js里，this指向的是执行时的调用者，而非定义所在的对象*

eg：
```js
const item - {
    talk: function(){
        console.log(this);
    }
}

item.talk() // log：{talk:f}
const talk = item.talk;
talk() // log: {window}
```

2. 箭头函数
`f = (x) => {return y};`

> ps: 箭头函数不会绑定this
    所以会向上查找this对象
    避免混淆

3. 对象的解构
```
const {name : new_name} = item;
// new_name作为name的别名存在
```

4. 数组和对象的展开
```js
let a = [1 , 2 , 3];
let b = [...a]; // b copy a
let c = [...a, 4 , 5 ,6]; // extend a and add
```
5. export
- Default Export: 最多export一个,不需要加大括号，可以定义别名
- Named Export: 可以export多个，需要加大括号，名称需要匹配

## 组件components
### 类组件
