import Vue from 'vue'
import App from './app.vue'
import router from './router'
import axios from 'axios'
import filter from './filters/filter'

Vue.config.productionTip = false
Vue.prototype.$ajax = axios;


/**
 * axios拦截器
 */

axios.interceptors.request.use(function(config){
  console.log("请求：",config);
  return config;
},error => {});

axios.interceptors.response.use(function(response){
  console.log("返回结果：",response);
  return response;
},error => {});

// 全局过滤器
Object.keys(filter).forEach(key => {
  Vue.filter(key,filter[key])
});


// import可以是对象，可以接口
new Vue({
  router,
  /**
   * //render是一个函数
   * @param h是函数参数，h也是一个函数，App是一个对象{}，
   * 交给vue处理调用构造函数的参数名.render.(传入一个函数)
   * @returns 返回任意类型
   */
  render: h => h(App),
}).$mount('#app')//$mount是一个初始化方法，#app是一个字符串


/**
 * Vue执行流程：
 * 0、 浏览器先解析原始的index.html
 * 1、 执行main.js文件里面的代码，实例化一个Vue对象
 * 2、 vue对象内部可能调用render渲染函数，渲染成App组件的数据，形成缓存，也就是虚拟的dom
 * 3、 调用Vue对象的$mount初始化方法要渲染的虚拟的dom写入到id为#app元素里面去
 * 4、 所以组件里面不用导入要渲染到那个html文件元素的css、js外部文件，
 * 5、 因为组件的数据是放在html文件的，里面自有引入了css、js外部文件
 * 6、 总结：先执行index.html，后执行main.js、后执行index.html
 */

console.log("环境：",process.env.NODE_ENV)