# django
## ssh
### 添加用户
`adduser <username>`

`usermod -aG sudo <username>`

`su <username>`
### 免密登录
> ubuntu: /etc/ssh/config

> windows: /user/.ssh/config

```config
Host name
    HostName ip
    User user
    Port port
```

公钥
`ssh-copy-id servername`

## docker

### **install:**

[安装教程](https://docs.docker.com/engine/install/linux-postinstall/)

### 同步配置

scp .bashrc .vimrc .tmux.conf servername

### 上传镜像

acwing有统一的镜像，位置在：`/var/lib/acwing/docker/images/`下

1. 在`AC Terminal` 中，将django镜像上传至自己的服务器：
    
    ```shell
    scp /var/lib/acwing/docker/images/镜像包名 自己起的主机别名:想保存的自己服务器上的文件路径
    ```
    
    例如，我在别名为 `ali` 的服务器上创建了一个文件夹`docker_images`,路径为`~/docker_images`。要将`AC Terminal`中`/var/lib/acwing/docker/images/`下的`django_lesson_1_0.tar`镜像保存在服务器中的`docker_images`下，有：
    
    ```shell
     scp /var/lib/acwing/docker/images/django_lesson_1_0.tar ali:docker_images:
    ```
    
    将`docker_images`下载到本地：
    
    ```shell
    scp -r 自己起的主机别名:要下载文件夹的路径 要下载至的路径
    ```
    
2. 将镜像包导入到自己服务器的docker环境中：
    
    ```shell
    docker load -i 镜像包路径
    ```
    
    对于上例，有：
    
    ```shell
    docker load -i docker_images/django_lesson_1_0.tar
    ```
    
    待其加载好后，可以用`docker images`查看已经加载好的镜像

4. - 用镜像创建并启动一个容器
    
    ```shell
    docker run -p 20000:22 -p 8000:8000 --name django_server -itd django_lesson:1.0 
    ```
    
    这里，对于上过[Linux基础课](https://www.acwing.com/activity/content/57/)的同学，已经在20000端口运行了`docker_lesson`镜像的一个容器。
    
    对于这个问题，要给之前的容器换端口号映射。
    
    `tips:`给容器换端口号映射：
    
    1. 查看所有容器：
        
        ```
        docker ps -a
        ```
        
    2. 先将容器打包为一个镜像：
        
        ```shell
        #：将容器CONTAINER导出到本地文件xxx.tar中
        docker save -o 生成文件的存放路径(一般以.tar为后缀) 镜像名       
        ```
        
        **注意这里是`镜像名`不是`容器名`。因为导出容器实际上是导出容器的镜像，容器本身不能做迁移**
        
        `tips`:注意这两组语句的区别：
        
        ```shell
        #下面两句都是导出镜像/容器的镜像
        docker save -o 生成文件的存放路径(一般以.tar为后缀) 镜像名
        docker export -o 生成文件的存放路径(一般以.tar为后缀) 镜像名
        
        #下面两句都是加载镜像/容器的镜像
        docker load -i 要加载的镜像包的路径
        docker import 要加载的镜像包的路径 给该镜像起的别名
        
        ```
        
        **区别：  
        `export/import`会丢弃历史记录和元数据信息，仅保存容器当时的快照状态  
        `save/load`会保存完整记录，体积更大**
        
    3. 将这个容器删除，删除前要保证该容器已经停止运行
        
        ```shell
        # 查看所有容器
        docker ps -a
        
        #关闭某个容器
        docker stop 正在运行中的容器名
        
        #删除某个容器
        docker rm 容器名
        ```
        
    4. 用原来的镜像创建并启动一个容器，这时，就可以重新映射端口号：
        
        ```shell
        docker run -p 端口号映射 --name 镜像名 -itd 给该镜像重命名的名字 
        ```
        
5. - 启动并进入容器
    
    ```shell
    #启动容器
    docker start django_server
    
    #进入容器
    docker attach django_server 
    ```
    
6. - 重复`1.1创建新用户`和`1.2配置免密登录`的过程，使`AC Terminal`或电脑上的`git bash`能直接登录到容器上
    
7. - **必须`attach`后，先按`Ctrl-p`，再按`Ctrl-q`挂起容器,`ssh`才能登录成功**


## Django项目
### 创建django项目

```shell
django-admin startproject 项目名
```

如：

```shell
django-admin startproject acapp
```

`acapp`的项目结构：

```shell
.
`-- acapp
    |-- acapp
    |   |-- __init__.py
    |   |-- asgi.py
    |   |-- settings.py
    |   |-- urls.py
    |   `-- wsgi.py
    `-- manage.py
```

### 用git维护该项目

1. 进到`acapp`文件夹下，执行命令：
    
    ```shell
    git init
    ```
    
2. 生成密钥，用来连接仓库：
    
    ```
    ssh-keygen
    ```
    
3. 在[acgit](https://git.acwing.com/)上创建一个账号，并创建一个新项目  
    **注意：创建时要把`使用自述文件初始化仓库`的勾去掉**
    
4. 跳转后，将![](https://img-blog.csdnimg.cn/img_convert/630c042279485f66dfd4c9ac2c86ebf3.png)
    
    的两行命令执行一遍
    
5. 将初始生成的文件提交git
    
    ```shell
    git add .
    git commit -m "cerat project"
    ```
    
6. 创建并编写`readme.md`文件
    
7. 将自己服务器的公钥上传至[acgit](https://git.acwing.com/)：
    
    ```shell
    cat ~/.ssh/id_rsa.pub
    ```
    
    把公钥粘贴到：![](https://img-blog.csdnimg.cn/img_convert/07e1c63def314abf515958449006ea40.png)
    
    中的：![](https://img-blog.csdnimg.cn/img_convert/8e1a130b98fff4f0e2d09d3a0cef5238.png)
    
    点击添加密钥
    
8. 执行下图的箭头指的命令![](https://img-blog.csdnimg.cn/img_convert/2b230bfc8ca77087a9257d1ca8987717.png)
    
9. 再执行：
    
    ```shell
    git push
    ```
    
    根据提示，再执行：
    
    ```shell
    git push --set-upstream origin master
    ```
    

至此，服务器的项目与远程的仓库连接了起来

### 运行项目

1. 执行：
    
    ```shell
    python3 manage.py runserver 0.0.0.0:8000
    ```
    
    会发现项目顺利的跑了起来，但是，在地址栏里输入地址访问会报错。原因是**没有把公网`ip`加到`ALLOWED_HOSTS`里**
    
2. 配置`ALLOWED_HOSTS`:
    
    ```shell
    #全局搜索哪些文件里有字符串
    ag 字符串
    ```
    
    去到对应文件夹下，对应位置把自己的公网ip的`字符串`写进python的列表中
    
    在git仓库的根目录下，创建`.gitignore`文件，来配置`不需要git管理的文件`，如：
    
    ```shell
    */__pycache__
    ```
    
    然后可以将该版本提交git
    

### 创建一个app

再开一个tmux窗口用来写项目，对应操作为：`按下Ctrl + a后手指松开，然后按c：在当前session中创建一个新的window`

切换窗口的操作为：`按下ctrl + a后手指松开，然后按s：`,再`按下方向键右键展开所有window`，再`用方向键上下选择对应window`

执行：

```shell
python3 manage.py startapp app名字
```

y总建议：一个项目只创建一个app

就生成了一个`game`文件夹：

```shell
|-- __init__.py         
|-- admin.py            #管理员页面能看到哪些数据库
|-- apps.py             
|-- migrations
|   `-- __init__.py
|-- models.py						#定义网站的各种数据库表
|-- tests.py
`-- views.py						#存放视图层操作给各种函数
```

然后可以将该版本提交git

### 查看管理员页面

1. 回到tumx中后台 的window
    
2. 先把项目停止运行，然后把数据库的数据更新上去:
    
    ```
    python3 manage.py migrate
    ```
    
3. 再把项目跑起来:
    
    ```shell
    python3 manage.py runserver 0.0.0.0:8000
    ```
    
4. 在地址栏里输入`http://8.130.31.115:8000/admin`,进入管理员登录界面
    
5. 创建管理员账户：
    
    ```shell
    python3 manage.py createsuperuser
    ```
    

### 编写具体业务

1. 在`game`文件夹下创建`urls.py`文件，和`templates`文件夹
    
2. 在`game`下各个文件的作用：
    
    ```shell
    ├── game
    │   ├── __init__.py    
    │   ├── admin.py
    │   ├── apps.py
    │   ├── migrations       #存放html文件
    │   │   └── __init__.py
    │   ├── models.py         
    │   ├── tests.py
    │   ├── urls.py           #存放路由
    │   └── views.py					#存放视图操作的函数
    
    ```
    
3. 编写`game`下的 `views.py`:
    
    ```python
    from django.shortcuts import render
    from django.http import HttpResponse
    
    
    def index(request):
        line1 = '<h1 style="text-align: center">我的博客</h1>'
        line4 = '<a href="https://www.acwing.com/user/myspace/index/82975/">进入我的空间</a>'
        line5 = '<a href="https://git.acwing.com/codeRokie/acapp">进入项目仓库</a>'
        line3 = '<div><a href="/play/">测试跳转和返回</a></div>'
        line2 = '<img src="https://gitee.com/liuyutaocode/tao-blog-image/raw/master/img/bg_mask.jpg" width=2000>'
        return HttpResponse(line1 + line4 + line3 + line2 + line5)
    
    
    def play(request):
        line1 = '<h1 style="text-align: center">游戏界面</h1>'
        line3 = '<a href="/">返回主页面</a>'
        line2 = '<img src="https://cdn.acwing.com/media/user/profile/photo/82975_lg_521a445e8a.jpg" width=2000>'
        return HttpResponse(line1 + line3 + line2)
    
    
    ```
    
4. 编写`game`下的`urls.py`:
    
    ```python
    from django.urls import path
    from game.views import index
    
    
    urlpatterns = [
        path("", index, name="index")
    ]
    
    ```
    
5. 编写`acapp`下的`urls.py`:
    
    ```python
    from django.contrib import admin
    from django.urls import path, include
    import game
    
    urlpatterns = [
        path('',include('game.urls')),
        path('admin/', admin.site.urls),
    ]
    
    ```
    

#### 访问过程：

`用户请求`—>`acapp/url.py`—>`game/url.py`—>`game/views.py`下的函数中