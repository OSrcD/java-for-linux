<template>
  <div>
    <div class="container">

        <h2 class="form-signin-heading">请登录</h2>
        <label for="username" class="sr-only">username</label>
        <input type="username" id="username" name="username" v-model="username" class="form-control" placeholder="用户名" required autofocus>
        <label for="password" class="sr-only">password</label>
        <input type="password" id="password" name="password" v-model="password" class="form-control" placeholder="密码" required>
        <div class="checkbox">
          <label>
            <input type="checkbox" value="remember-me"> 记住我
          </label>
        </div>
        <button class="btn btn-lg btn-primary btn-block" @click="doLogin()">登录</button>

    </div> <!-- /container -->
  </div>
</template>

<script>

import '../js/app.js'

export default {
  name: "Login",
  data(){
    return {
      username: null,
      password: null,
    }
  },
  created(){
    // console.log(app.serverUrl)
  },
  methods:{
    doLogin(){
      var _this = this;
      var userBo = {
        username: _this.username,
        password: _this.password
      }
      alert("userBo="+userBo.username);
      var serverUrl = app.serverUrl;
      _this.$ajax.defaults.withCredentials = true;
      serverUrl = "https://192.168.43.15:8080"
      _this.$ajax.post(serverUrl + '/login',userBo)
        .then(res => {
          if(res.data.status == 200) {
            alert(JSON.stringify(res.data))
          }else if(res.data.status == 500) {
            alert(res.data.msg);
            return;
          }

        })


    }
  }
}
</script>

<style scoped>
body {
  padding-top: 40px;
  padding-bottom: 40px;
  background-color: #eee;
}

.form-signin {
  max-width: 330px;
  padding: 15px;
  margin: 0 auto;
}
.form-signin .form-signin-heading,
.form-signin .checkbox {
  margin-bottom: 10px;
}
.form-signin .checkbox {
  font-weight: normal;
}
.form-signin .form-control {
  position: relative;
  height: auto;
  -webkit-box-sizing: border-box;
  -moz-box-sizing: border-box;
  box-sizing: border-box;
  padding: 10px;
  font-size: 16px;
}
.form-signin .form-control:focus {
  z-index: 2;
}
.form-signin input[type="username"] {
  margin-bottom: -1px;
  border-bottom-right-radius: 0;
  border-bottom-left-radius: 0;
}
.form-signin input[type="password"] {
  margin-bottom: 10px;
  border-top-left-radius: 0;
  border-top-right-radius: 0;
}

</style>
