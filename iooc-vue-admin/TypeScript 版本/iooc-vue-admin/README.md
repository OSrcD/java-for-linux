<div align="center"><img width="200" src="https://vue3-element-admin.oss-cn-beijing.aliyuncs.com/app/logo.png"/>
<h1> iooc-admin（element-plus） </h1>
</div>

## 演示地址（数据库五分钟重置一次）

- [⚡️ vue3.x + element-plus + TypeScript](https://iooc-admin.com:5120/)

## 项目地址

- [⚡️ vue3.x + element-plus + TypeScript](https://github.com/MyJacking/iooc-vue-admin)
- [⚡️ vue3.x + element-plus + JavaScript (开发中...)](https://github.com/MyJacking/iooc-vue-admin/tree/V3Js)

## iooc-admin 前端讨论 QQ 群 741396149

感谢您的支持和信任，群内提供 iooc-admin 项目开发文档

## 使用说明

```bash
- node版本 > v8.6.0

# 克隆项目
git clone https://github.com/MyJacking/iooc-admin.git
# 进入项目目录
cd iooc-admin
# 安装依赖
yarn
# 本地开发 启动项目
yarn dev
```

## 鸣谢

| Project                                                          |
| ---------------------------------------------------------------- |
| [vue](https://github.com/vuejs/vue)                              |
| [element-ui](https://github.com/ElemeFE/element)                 |
| [element-plus](https://github.com/element-plus/element-plus)     |
| [axios](https://github.com/axios/axios)                          |


## 特性

IOOC-ADMIN 是一个用于快速开发后台的框架，我们可以用它来开发后台管理、后台权限管理、后台api接口等系统的开发，开发人员只需关心核心业务功能开发。

```
1. 支持前端控制路由,接口权限
2. 极速编码：单表增删改查、分页、模糊查询等只需少量配置即可完成接口编码和页面展示
3. 高性能：支持方法级注解式缓存
4. axios 高精度封装、支持多种传参方式、文件上传默认采用阿里云OSS
```

## 目录结构
```
iooc-admin/src
    ├── main.js (主要文件)
    ├── Home.vue (首页)
    ├── App.tsx (页面入口文件)
    ├── assets (资源文件)
    ├── api (接口文件 备用)
    ├── components (业务组件)
    ├── config (全局配置)
    ├── admin (核心文件)
    ├── icons (字体、图标库)
    │   ├── svg (存放svg文件，对应icon-svg组件使用)
    │   └── index.ts 配置入口
    ├── pages (基础页面)
    │   ├── layout (整体布局)
    │   │   ├── process (任务栏)
    │   │   ├── slider (侧边)
    │   │   ├── topbar (顶部)
    │   │   └── index.tsx
    │   ├── iframe (外链)
    │   ├── 403
    │   ├── 404
    │   ├── 500
    │   ├── 503
    │   ├── Login (登录)
    │   ├── my
    │       └── info(个人信息)
    ├── views (视图页面)
    │   ├── system (系统管理页面)
    │   └── ... 
    ├── router (路由)
    │   ├── routes (公共路由)
    │   └── index.js 路由业务事件处理
    ├── service (请求服务接口)
    │   ├── system (系统管理接口)
    │   ├── common (通用接口)
    │   ├── ... 
    │   └── request.js (请求处理)
    ├── store (本地存储)
    └── utils (工具)
```


## 请求地址
baseUrl: string

## 代理请求
<div align="left"><img width="200" src="https://vue3-element-admin.oss-cn-beijing.aliyuncs.com/app/img_1.png"/>
</div>

访问地址添加参数 proxy，可替换请求代理，方便前后端各自调试。示例:

http://localhost:8889?proxy=dev 本地环境

http://localhost:8889?proxy=pro 线上环境

## 应用配置 (Store/app)

是否显示一级菜单栏
```
showAMenu: boolean
```

是否显示路由导航栏
```
showRouteNav: boolean
```

是否显示页面进程栏
```
showProcess: boolean
```

## 上传配置 upload

上传的地址
```
action: ""
```

上传的文件类型
```
accept: ""
```

上传的文件字段名
```
name: "file"
```

尺寸
```
size: "128px"
```

显示图标
```
icon: "el-icon-upload"
```

显示文案
```
text: "选择文件"
```


## service

服务层负责处理发起的请求, 并返回对服务端的响应。程序自动加载 service 下所有的模块。

创建一个简单的用户服务类。

```javascript
// @/service/system/user.js

import { BaseService, Service, Permission } from "@/admin";

@Service("sys/user")
export default extends BaseService {
    @Permission('start')
	start(data) {
		return this.request({
			url: '/start',
			method: 'POST',
			data
		});
	}
}
```

- 这是一个基于 `BaseService` 的基本类，默认包含 `page`, `add`, `update`, `delete`, `info`, `list` 基本请求方式。
- `@Service` 处理请求地址 `${baseUrl}/crm/user/${url}`
- `@Permission` 给接口添加权限。每一个 `service` 都有对应的 `permission` 对象，这是一个可控制接口权限的集合。

```javascript
// 获取所有列表
list(params) {
    return this.apiAxios({
        url: '/list',
        params: {
            ...params
        }
    });
}

// 以分页类型获取对应列表
page(params) {
    return this.apiAxios({
        url: '/page',
        params: {
            ...params
        }
    });
}

// 获取选中的信息
info(params) {
    return this.apiAxios({
        url: '/info',
        params: {
            ...params
        }
    });
}

// 更新选中的信息
update(params) {
    return this.apiAxios({
        url: '/update',
        method: 'POST',
        data: {
            ...params
        }
    });
}

// 删除选择的数据，默认使用 ids: string
delete(params) {
    return this.apiAxios({
        url: '/delete',
        method: 'POST',
        data: {
            ...params
        }
    });
}

// 添加新数据
add(params) {
    return this.apiAxios({
        url: '/add',
        method: 'POST',
        data: {
            ...params
        }
    });
}
```

## use
如果文件名是 index，则绑定在上一级目录下，否则绑定为当前文件名。如：

1. service/common/index.js

```javascript
export default class extends BaseService {
	userLogin(params) {
		return this.apiAxios({
			url: "/comm/login",
			method: "POST",
			data: {
				...params
			}
		});
	}
}

// 使用

this.$service.common.userLogin({ account: "admin", password: "123456" });
```

2. service/system/user.js

```javascript
export default class extends BaseService {
	move(data) {
		return this.apiAxios({
			url: "/move",
			method: "POST",
			data
		});
	}
}

// 使用
this.$service.system.user.move();
```

## proxy

可针对不同 service 层配置不同代理，示例：

```javascript
// /src/service/test/index.js
import { BaseService, Service } from "@/admin/index";

@Service({
    namespace: "sys/task",
    proxy: '/order'
})
export default extends BaseService {}

// vue.config.js
proxy: {
    '/order': {
        target: 'https://order.iooc-admin.com',

        changeOrigin: true,
        pathRewrite: { '^/order': '/' }
    }
}
```

## --ignore & request

- 忽略 文件 或 目录 的引入，如 /service/business/analy--fix.js
- 详细看文件@/service/request.js，根据需求处理返回结果

## 权限控制

### v-permission

| 参数 | 类型 | 说明|
| -----| --- | --- |
| or   | 数组 | 用于检测数组中的元素是否满足指定条件 |
| and  | 数组 | 用于检测数组中的元素是否全部满足指定条件 |

前面说到每个service都有对应的permission权限对象，如需控制权限对应的标签，可使用：

```vue
<el-button
	v-permission="{
    or: [$service.user.permission.add]
}"
	>新增</el-button
>
```

## crud相关文档群内查看

## 商用注意事项

- 如果您将此项目用于商业用途，请遵守Apache2.0协议并保留作者技术支持声明。

最后感谢您使用 IOOC-ADMIN
