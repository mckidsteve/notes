# wireshark实验：http抓包

## 准备过程
- 下载安装:
> win-amd64:[wireshark.org/mirror.html](wireshark.org/mirror.html)
> ubuntu: (sudo) apt install wireshark

- 一个简单的html并将其上传至网站服务器部署
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>hello my http</title>
</head>
<body>
    <h1> hello my http </h1>
</body>
</html>
```

- wireshark配置
接口：有线以太网


## 基础HTTP GET/response交互

#### 启动捕获：
![xPTqeK.png](https://s1.ax1x.com/2022/09/20/xPTqeK.png)


#### 过滤http：
![xPTLdO.png](https://s1.ax1x.com/2022/09/20/xPTLdO.png)


#### 链接到web并成功捕获：
![xPTvJH.png](https://s1.ax1x.com/2022/09/20/xPTvJH.png)


![xP79yt.png](https://s1.ax1x.com/2022/09/20/xP79yt.png)

#### 接下来查询被捕获到的http消息

**GET报文**：
![xP7mSs.png](https://s1.ax1x.com/2022/09/20/xP7mSs.png)
**相应报文**：
![xP7EFg.png](https://s1.ax1x.com/2022/09/20/xP7EFg.png)

以上界面中显示了 帧 、 以太网 、 IP 、 TCP 、 HTTP五组信息

得到如下信息：

![xP7GY4.png](https://s1.ax1x.com/2022/09/20/xP7GY4.png)

![xPHK9H.png](https://s1.ax1x.com/2022/09/20/xPHK9H.png)

## 实验结果
1. 浏览器与服务器均运行HTTP/1.1 ； 

2. Aceept-Language: zh-CN

3. 计算机地址:192.168.1.221 服务器地址:181.214.39.236

4. 服务器返回状态代码：200 OK

5. Last-Modified: Tue , 20 Sep 2022 14:16:00 GMT(北京时间22:16)

6. HTTP响应报文中返回了文件内容，File Data 289bytes

### **当浏览器已经访问过网页并缓存后：**

![xP7tp9.png](https://s1.ax1x.com/2022/09/20/xP7tp9.png)
1. 注意到此时返回代码 304 Not Modified


2. If-Modified-Since: Tue, 20 Sep 2022 14:16:00 GMT (北京时间22:16)

3. 此时响应报文中没有返回所请求的对象，因为对象没有被修改，所以服务器并未返回


### **如果访问的是一个大文件：**

则会将一个httpget拆分为多个tcp报文段

### **如果访问网站中还含有特殊对象：**
比如挂载在其它服务器上的图片：

图片将会将其url包含在已下载的html
浏览器将从多个网站并行下载

### **若访问网站受密码保护：**

1. 初始响应：401 Unauthorized
2. 第二次响应：Authorization:*******