// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'
import axios from 'axios'
import $ from 'jquery'
import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap/dist/js/bootstrap'


import 'owl-carousel/owl-carousel/owl.carousel.js'
import 'owl-carousel/owl-carousel/owl.carousel.css'
import 'owl-carousel/owl-carousel/owl.theme.css'

import './js/photo-gallery.js'

import './css/style.css'
import SockJS from "sockjs-client";
import Stomp from "stompjs";


Vue.config.productionTip = false
Vue.prototype.$ajax = axios;

/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  components: { App },
  template: '<App/>'
})
