require("./common/manifest.js");
require("./common/vendor.js");
global.webpackJsonp([12],{

/***/ 51:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
Object.defineProperty(__webpack_exports__, "__esModule", { value: true });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_babel_runtime_core_js_object_assign__ = __webpack_require__(52);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_babel_runtime_core_js_object_assign___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_0_babel_runtime_core_js_object_assign__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_vue__ = __webpack_require__(4);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_vue___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_1_vue__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__App__ = __webpack_require__(63);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__utils_request__ = __webpack_require__(2);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4__utils_api__ = __webpack_require__(1);






__WEBPACK_IMPORTED_MODULE_1_vue___default.a.config.productionTip = false;
__WEBPACK_IMPORTED_MODULE_2__App__["a" /* default */].mpType = 'app';

__WEBPACK_IMPORTED_MODULE_1_vue___default.a.mixin({
  onUnload: function onUnload() {
    if (this.$options.data) {
      __WEBPACK_IMPORTED_MODULE_0_babel_runtime_core_js_object_assign___default()(this.$data, this.$options.data()); // 重置组件数据状态
    }
  }
});

// 所有页面都转发
// ref：https://blog.csdn.net/lhy349/article/details/81188332
__WEBPACK_IMPORTED_MODULE_1_vue___default.a.mixin({
  onShareAppMessage: function onShareAppMessage() {
    Object(__WEBPACK_IMPORTED_MODULE_3__utils_request__["a" /* request */])(__WEBPACK_IMPORTED_MODULE_4__utils_api__["b" /* FORWARD_URL */], 'GET', {});
    return {
      title: 'IT牧场',
      path: 'pages/share/list/main',
      imageUrl: '/static/img/xuanchuan.png'
    };
  }
});

var app = new __WEBPACK_IMPORTED_MODULE_1_vue___default.a(__WEBPACK_IMPORTED_MODULE_2__App__["a" /* default */]);
app.$mount();

/***/ }),

/***/ 63:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_App_vue__ = __webpack_require__(66);
var disposed = false
function injectStyle (ssrContext) {
  if (disposed) return
  __webpack_require__(64)
}
var normalizeComponent = __webpack_require__(0)
/* script */

/* template */
var __vue_template__ = null
/* styles */
var __vue_styles__ = injectStyle
/* scopeId */
var __vue_scopeId__ = null
/* moduleIdentifier (server only) */
var __vue_module_identifier__ = null
var Component = normalizeComponent(
  __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_App_vue__["a" /* default */],
  __vue_template__,
  __vue_styles__,
  __vue_scopeId__,
  __vue_module_identifier__
)
Component.options.__file = "src/App.vue"
if (Component.esModule && Object.keys(Component.esModule).some(function (key) {return key !== "default" && key.substr(0, 2) !== "__"})) {console.error("named exports are not supported in *.vue files.")}

/* hot reload */
if (false) {(function () {
  var hotAPI = require("vue-hot-reload-api")
  hotAPI.install(require("vue"), false)
  if (!hotAPI.compatible) return
  module.hot.accept()
  if (!module.hot.data) {
    hotAPI.createRecord("data-v-1fa12cac", Component.options)
  } else {
    hotAPI.reload("data-v-1fa12cac", Component.options)
  }
  module.hot.dispose(function (data) {
    disposed = true
  })
})()}

/* harmony default export */ __webpack_exports__["a"] = (Component.exports);


/***/ }),

/***/ 64:
/***/ (function(module, exports) {

// removed by extract-text-webpack-plugin

/***/ }),

/***/ 66:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";

/* harmony default export */ __webpack_exports__["a"] = ({
  created: function created() {}
});

/***/ })

},[51]);
//# sourceMappingURL=app.js.map