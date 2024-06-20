//登陆时密码需要加密-
请求接口：/api/login
请求方式：POST
请求数据示例：
    {
       username:'zhangsan',//用户名
       password:'666',//密码
       code:'1234' //校验码
    }
响应数据：
    {
        "code": 1,//成功1 失败0
        "data": {
        "id":"1237365636208922624",
        "username":"zhangsan",
        "nickName":"xiaozhang",
        "phone":"1886702304"
        }
    }

//