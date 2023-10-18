# django概述

> django由两部分构成
> - 向访客开放的前端访问页面
> - 向管理员开放的后端控制界面

## How to create a django project?

1. install
1. cd a directory
1. run cmd:
    ``django-admin start project mysite``
    
    ```
    mysite/             //根目录
        manage.py       //管理项目用的命令行工具
        mysite/         //子项目包(含有构建项目用的py包)
            __init__.py //init.py
            setting.py  //项目的配置文件
            urls.py     //url声明(目录,链接路由的作用)
            asgi.py     //asgi兼容性web服务器的入口
            wsgi.py     //wsgi兼容性web服务器的入口
    ```
1. run cmd:
    ``python manage.py runserver IP:PORT``


**now a website run in your server!**

## edit your webapp
``python manage.py startapp djapp``
   ```
   djapp/
        __init__.py
        admin.py
        apps.py
        migrations/
            __init__.py
        models.py
        tests.py
        urls.py
        views.py
  ```

### first step : views & urls
```
views.py
def index(){} =>
return HttpResponse("text")

djapp/urls.py
urlpatterns = [
    path('' , views.index , name='index')
]

mysite/urls.py
urlpatterns = [
    path('djapps/' , include('djapps.urls')),
    path('admin/' , admin.site.urls),
]

```

> path(route : a url , view : 视图函数 , kwargs : 附加参数 , name : ID);



### second step : settings

- TIME_ZONE                         // 时区
- INSTALLED_APPS                    // 启用的项目
    - django.contrib.admin          //管理员站点
    - django.contrib.auth           // 认证系统
    - django.contrib.contenttypes   //内容类型框架
    - django.contrib.sessions       // 会话框架
    - django.contrib.messages       // 消息框架
    - django.contrib.staticfiles    //静态文件管理框架
- MIDDLEWARE                        //中间件:修改传入传出的response对象
- ROOT_URLCONF // 根目录url
- TEMPLATES // 
- DATABASES
- STATIC_ROOT
- STATIC_URL